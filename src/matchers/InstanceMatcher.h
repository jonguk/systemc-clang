#ifndef _INSTANCE_MATCHER_H_
#define _INSTANCE_MATCHER_H_

//#include <type_traits>
#include <vector>

#include "ModuleInstanceType.h"
#include "ArrayTypeUtils.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "llvm/Support/Debug.h"

/// Different matchers may use different DEBUG_TYPE
#undef DEBUG_TYPE
#define DEBUG_TYPE "InstanceMatcher"

using namespace clang::ast_matchers;

namespace sc_ast_matchers {
using namespace clang;
using namespace utils::array_type;

class InstanceArgumentMatcher : public MatchFinder::MatchCallback {
 private:
  clang::StringLiteral *instance_literal_;

 public:
  clang::StringLiteral *getInstanceLiteral() const { return instance_literal_; }

  void registerMatchers(MatchFinder &finder) {
    instance_literal_ = nullptr;
    // clang-format off
    auto arg_matcher = cxxConstructExpr(hasDescendant(
          cxxConstructExpr(hasArgument(0, 
            stringLiteral().bind("inst_arg")
              )
            )
          )
        ).bind("ctor_expr");
    // clang-format on

    finder.addMatcher(arg_matcher, this);
  }

  virtual void run(const MatchFinder::MatchResult &result) {
    auto ctor_expr = const_cast<clang::CXXConstructExpr *>(
        result.Nodes.getNodeAs<clang::CXXConstructExpr>("ctor_expr"));
    auto inst_arg = const_cast<clang::StringLiteral *>(
        result.Nodes.getNodeAs<clang::StringLiteral>("inst_arg"));

    LLVM_DEBUG(llvm::dbgs() << "## InstanceArgumentMatcher\n");
    if (ctor_expr && inst_arg) {
      LLVM_DEBUG(llvm::dbgs() << "@@ ctor expr\n");
      instance_literal_ = inst_arg;
    }
  }

  void dump() {
    if (instance_literal_) {
      LLVM_DEBUG(instance_literal_->dump(););
    }
  }
};

///////////////////////////////////////////////////////////////////////////////
//
/// Class InstanceMatcher
//
//
///////////////////////////////////////////////////////////////////////////////
class InstanceMatcher : public MatchFinder::MatchCallback {
 public:
  typedef std::tuple<std::string, clang::Decl *, ModuleInstanceType>
      InstanceDeclType;
  typedef std::vector<InstanceDeclType> InstanceDeclarationsType;

  /// Store all instances in a map.
  /// The map key should be the Decl*.  This will work for both FieldDecl
  /// (instances within sub-modules) and VarDecl separate modules in sc_main().
  //

  typedef std::pair<clang::Decl *, ModuleInstanceType> ModuleInstanceTuple;
  typedef std::map<clang::Decl *, ModuleInstanceType> InstanceDeclarations;

 private:
  /// Instances can come in two forms:
  /// FieldDecl: this is when they are members of a class.
  /// VarDecl  : this is when they are simply variables such as in functions or
  /// in the main().
  ///
  /// The way to identify them both together is to look at its base class Decl.
  /// Then use dyn_cast<> to detect whether it is one of the two above mentioned
  /// types.
  //
  /// deprecated
  // InstanceDeclarationsType instances_;

  /// Map of Decl* => ModuleInstanceType
  InstanceDeclarations instance_map_;

  clang::ValueDecl *parent_fd_;

 public:
  InstanceMatcher &operator=(const InstanceMatcher &from) {
    instance_map_.insert(from.instance_map_.begin(), from.instance_map_.end());
    return *this;
  }

  const InstanceDeclarations &getInstanceMap() { return instance_map_; }

  void setParentFieldDecl(clang::ValueDecl *parent_fd) {
    parent_fd_ = parent_fd;
  }
  // Finds the instance with the same type as the argument.
  // Pass by reference to the instance.

  bool findInstanceByVariableType(
      clang::CXXRecordDecl *decl,
      std::vector<InstanceDeclType> &found_instances) {
    // First check in the instance_fields.
    // Check to see if the pointer to the type is the same as the sc_module
    // type.

    LLVM_DEBUG(llvm::dbgs() << "\n[findInstance] instance size: "
                            << instance_map_.size() << "\n");

    LLVM_DEBUG(llvm::dbgs()
               << "find decl name: " << decl->getName() << " " << decl << "\n");

    // Walk through all the instances.
    for (auto const &element : instance_map_) {
      auto p_field_var_decl{element.first};
      auto instance{element.second};

      // TODO factor out this code to be handled for both.
      if (auto *p_field{clang::dyn_cast<clang::FieldDecl>(p_field_var_decl)}) {
        auto qtype{p_field->getType().getTypePtr()};
        if (qtype->isRecordType()) {
          auto rt{qtype->getAsCXXRecordDecl()};
          LLVM_DEBUG(llvm::dbgs() << "- fd " << rt << " "
                                  << p_field->getCanonicalDecl() << " ");
          LLVM_DEBUG(instance.dump());

          if (rt == decl) {
            LLVM_DEBUG(llvm::dbgs()
                       << "- Insert fieldDecl into found instance\n");
            found_instances.push_back(
                InstanceDeclType(instance.instance_name, rt, instance));
          }
        }
      } else {
        // This is a VarDecl instance.
        auto p_var{clang::dyn_cast<clang::VarDecl>(p_field_var_decl)};
        auto qtype{p_var->getType().getTypePtr()};

        std::string dbg{"[InstanceMatcher] VarDecl"};
        if (qtype->isRecordType()) {
          auto rt{qtype->getAsCXXRecordDecl()};
          LLVM_DEBUG(llvm::dbgs() << "- vd " << rt << " "
                                  << " ");
          LLVM_DEBUG(instance.dump());
          if (rt == decl) {
            LLVM_DEBUG(llvm::dbgs()
                       << "- Insert vardecl into found instance\n");
            found_instances.push_back(
                InstanceDeclType(instance.instance_name, rt, instance));
          }
        }
      }
    }
    LLVM_DEBUG(llvm::dbgs()
               << "=> found_instances: " << found_instances.size() << "\n");

    return (found_instances.size() != 0);
  }

  auto match_ctor_arg(const std::string &bind_arg_name,
                      const std::string &bind_ctor_expr) {
    return cxxConstructExpr(hasArgument(0, stringLiteral().bind(bind_arg_name)))
        .bind(bind_ctor_expr);
  }

  auto match_is_derived_sc_module(const std::string &bind_name) {
    return recordType(hasDeclaration(
        cxxRecordDecl(isDerivedFrom(hasName("::sc_core::sc_module")))
            .bind(bind_name))  // hasDeclaration
    );                         // recordType;
  }

  void registerMatchers(MatchFinder &finder) {
    parent_fd_ = nullptr;
    /// We will have two matchers.
    ///
    /// Match when the following conditions are satisifed:
    /// * It is a FieldDecl
    /// * It has a type that is a C++ class that is derived from sc_module
    ///
    /// These are field members within a class declaration.  Hence, we only need
    /// to collect their FieldDecl pointers and their variable names.  Their
    /// instance names would appear when the constructor of the class that has
    /// these field members within it.  This constructor would use the
    /// initialization list to provide an argument, which would be the instance
    /// name.
    ///
    /* clang-format off */
       auto match_cxx_ctor_init =
      cxxRecordDecl(
          hasDescendant(
            cxxConstructorDecl(
              forEachConstructorInitializer(
                  cxxCtorInitializer(
                    isMemberInitializer(),
                    forField(
                      allOf(

                        anyOf(
                          hasType(
                            hasUnqualifiedDesugaredType(match_is_derived_sc_module("submodule")
                                     )//hasUnqualifiedDesugaredType
                          )//hasType

                          ,
                          //1d
                            hasType(
                               hasUnqualifiedDesugaredType(
                                 arrayType(
                                   hasElementType(hasUnqualifiedDesugaredType(match_is_derived_sc_module("submodule")
                                                                 )//hasUnqualifiedDesugaredType
                                       )//hasElementType
                                 )//arrayType
                               )//hasUnqualifiedDesugaredType
                             )//hasType

                              , 
                            //2d
                              hasType(
                               hasUnqualifiedDesugaredType(
                                 arrayType(
                                   hasElementType(hasUnqualifiedDesugaredType(
                                       arrayType(hasElementType(hasUnqualifiedDesugaredType(match_is_derived_sc_module("submodule")
                                       //
                                         //
                                       )//hasUnqualifiedDesugaredType
                                       )//hasElementType
                                       )//arrayType
                                   )//hasUnqualifiedDesugaredType
                                   )//hasElementType
                                 )//arrayType
                               )//hasUnqualifiedDesugaredType
                             )//hasType
                             ,
                             // 3d
                             hasType(
                               hasUnqualifiedDesugaredType(
                                 arrayType(
                                   hasElementType(hasUnqualifiedDesugaredType(
                                       arrayType(hasElementType(hasUnqualifiedDesugaredType(
                                         arrayType(hasElementType(hasUnqualifiedDesugaredType(match_is_derived_sc_module("submodule")

                                       )//hasUnqualifiedDesugaredType
                                       )//hasElementType
                                       )//arrayType


                                       )//hasUnqualifiedDesugaredType
                                       )//hasElementType
                                       )//arrayType
                                   )//hasUnqualifiedDesugaredType
                                   )//hasElementType
                                 )//arrayType
                               )//hasUnqualifiedDesugaredType
                             )//hasType

                          ) //anyOf
                        ,
                      fieldDecl().bind("ctor_fd") 
                      )
                    )
                  ).bind("ctor_init")
                )
              )
            ) //hasDescendant
          ); //cxxRecordDecl



    auto match_with_parent = 
      valueDecl(hasType(
            hasUnqualifiedDesugaredType(
              recordType(
                hasDeclaration(match_cxx_ctor_init))))).bind("parent_fd");


    auto match_instances_decl = 
      valueDecl( 
        hasDescendant(
          match_ctor_arg("ctor_arg", "constructor_expr"))
        , 
        anyOf(
            // 1d
          hasType(
            hasUnqualifiedDesugaredType(match_is_derived_sc_module("var_cxx_decl").bind("record_type")

              ///
              // recordType(
                // hasDeclaration(
                  // cxxRecordDecl(
                    // isDerivedFrom("::sc_core::sc_module")
                    // ).bind("var_cxx_decl")
                  // )
                // ).bind("record_type")

              )
            ) // hasType
          // 2d
          ,
           hasType(
             hasUnqualifiedDesugaredType(
               arrayType(
                 hasElementType(hasUnqualifiedDesugaredType(

                     match_is_derived_sc_module("submodule")
                     ///
                         // recordType(
                           // hasDeclaration(
                            // cxxRecordDecl(isDerivedFrom(hasName("::sc_core::sc_module"))).bind("submodule")
                            // ) //hasDeclaration
                         // )// recordType
                         ///
                         //
                       )
                       )
                 )//arrayType
               )
             )//hasType
        )// anyOf
      ).bind("instance_vd");

   auto match_base_decl =  match_cxx_ctor_init;
    /* clang-format on */

    /// Add the two matchers.
    //
    finder.addMatcher(match_instances_decl, this);
    finder.addMatcher(match_with_parent, this);
    finder.addMatcher(match_base_decl, this);
  }

  void parseVarDecl(clang::VarDecl *instance_decl, std::string &instance_name) {
    std::string name{instance_decl->getIdentifier()->getNameStart()};

    /// This is the main object's constructor name
    auto var_name{instance_decl->getNameAsString()};
    /// We do not get the instance name from within the field declaration.
    /// Get the type of the class of the field.
    auto var_type_name{instance_decl->getType().getAsString()};
    /// auto instance_name{cast<StringLiteral>(ctor_arg)->getString().str()};

    std::string parent_name{};
    clang::ValueDecl *parent_rdecl{nullptr};

    LLVM_DEBUG(llvm::dbgs()
               << "=> VD: var_name " << var_name << " var_type_name "
               << var_type_name << " parent_name " << parent_name
               << "\n");  // instance_name "; // << instance_name << "\n";

    ModuleInstanceType parsed_instance{};
    parsed_instance.var_name = var_name;
    parsed_instance.var_type_name = var_type_name;
    // For standalone VarDecl instances (e.g., in sc_main), the canonical
    // instance name should be the string literal passed to the constructor
    // (e.g., "dut"), not the variable name (e.g., "d"). Keep the variable
    // name as an auxiliary alias in instance_names for reference.
    parsed_instance.instance_name = instance_name;
    if (!instance_name.empty()) {
      parsed_instance.add_instance_name(instance_name);
    }
    if (!var_name.empty() && var_name != instance_name) {
      parsed_instance.add_instance_name(var_name);
    }
    // This is the Type of the FieldDecl.
    parsed_instance.type_decl =
        instance_decl->getType().getTypePtr()->getAsCXXRecordDecl();
    // This is the FieldDecl.
    parsed_instance.instance_decl = instance_decl;
    parsed_instance.is_field_decl = false;
    // FIXME: No parsing of VarDecl's as arrays?
    parsed_instance.is_array = false;
    parsed_instance.parent_name = parent_name;
    parsed_instance.parent_decl = parent_rdecl;

    LLVM_DEBUG(parsed_instance.dump(););
    // Don't add repeated matches
    //    auto found_it{instance_map_.find(instance_decl)};
    //   if (found_it == instance_map_.end()) {
    LLVM_DEBUG(llvm::dbgs() << "Inserting VD instance"
                            << "\n");
    instance_map_.insert(
        std::pair<Decl *, ModuleInstanceType>(instance_decl, parsed_instance));
    //   }
  }

  void parseFieldDecl(clang::FieldDecl *instance_decl,
                      clang::ValueDecl *parent_decl, std::string instance_name,
                      IndexMapType &index_map) {
    std::string name{instance_decl->getIdentifier()->getNameStart()};

    // This is the main object's constructor name
    auto var_name{instance_decl->getNameAsString()};
    // We do not get the instance name from within the field declaration.
    // Get the type of the class of the field.
    auto var_type_name{instance_decl->getType().getAsString()};

    std::string parent_name{};
    if (parent_decl) {
      parent_name = parent_decl->getName().str();
    }

    auto array_indices{index_map[instance_name]};
    LLVM_DEBUG(llvm::dbgs()
               << "=> FD: var_name: " << var_name << " var_type_name, "
               << var_type_name << " parent_name " << parent_name
               << ", instance name " << instance_name << "[ "
               << std::get<0>(array_indices) << ", "
               << std::get<1>(array_indices) << ", "
               << std::get<2>(array_indices)
               << "]"
                  "\n");

    ModuleInstanceType parsed_instance{};
    parsed_instance.var_name = var_name;
    parsed_instance.var_type_name = var_type_name;
    LLVM_DEBUG(instance_decl->getType()->dump(););

    /// Get all the 1D, 2D and 3D array type pointers.
    const ArrayType *array_1d{
        instance_decl->getType().getTypePtrOrNull()->getAsArrayTypeUnsafe()};
    const ArrayType *array_2d{nullptr};
    const ArrayType *array_3d{nullptr};
    const ArrayType *array_type{nullptr};

    /// We need to set the array_type pointer to the deepest array. That is if
    /// it is a 3D array then we need to set it to the third dimension element
    /// type to get the correct CXXRecordDecl.
    //
    if (array_1d) {
      array_type = array_1d;
      array_2d =
          array_1d->getElementType().getTypePtrOrNull()->getAsArrayTypeUnsafe();
      if (array_2d) {
        array_type = array_2d;
        array_3d = array_2d->getElementType()
                       .getTypePtrOrNull()
                       ->getAsArrayTypeUnsafe();

        if (array_3d) {
          array_type = array_3d;
        }
      }
    }

    LLVM_DEBUG(llvm::outs() << " All dim. arrays: " << array_1d << "  "
                            << array_2d << "  " << array_3d << "\n";);

    // auto array_type{
    // instance_decl->getType().getTypePtr()->getAsArrayTypeUnsafe()};
    // Array type.
    if (array_type) {
      auto element_type{array_type->getElementType().getTypePtr()};
      parsed_instance.type_decl = element_type->getAsCXXRecordDecl();
      LLVM_DEBUG(
          llvm::dbgs()
              << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ IS ARRAY type decl null: "
              << parsed_instance.type_decl << "\n";
          element_type->dump(););
      parsed_instance.setArrayType();
      parsed_instance.addArraySizes(getConstantArraySizes(instance_decl));
      parsed_instance.setArrayParameters(index_map[instance_name]);
      LLVM_DEBUG(llvm::outs() << "Dimension of array: "
                              << parsed_instance.getArrayDimension() << "\n";);
    } else {
      // Not an array type.
      parsed_instance.type_decl =
          instance_decl->getType().getTypePtr()->getAsCXXRecordDecl();
      LLVM_DEBUG(
          llvm::dbgs()
              << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ NOT ARRAY type decl null: "
              << parsed_instance.type_decl << "\n";);
    }

    LLVM_DEBUG(
    instance_decl->dump();
    );
    parsed_instance.instance_decl = instance_decl;
    parsed_instance.is_field_decl = true;
    parsed_instance.parent_name = parent_name;
    parsed_instance.parent_decl = parent_decl;
    // If this field is an array of submodules, group under the field name.
    // Otherwise, keep the literal instance name.
    if (array_type) {
      parsed_instance.instance_name = var_name;
      parsed_instance.add_instance_name(var_name);
      if (!instance_name.empty() && instance_name != var_name) {
        parsed_instance.add_instance_name(instance_name);
      }
    } else {
      parsed_instance.instance_name = instance_name;
      if (!instance_name.empty()) {
        parsed_instance.add_instance_name(instance_name);
      }
    }

    LLVM_DEBUG(parsed_instance.dump(););
    // Don't add repeated matches
    LLVM_DEBUG(llvm::dbgs() << "Inserting FD instance\n");

    /// Find if an instance already exists. If it does exist.
    //

    auto exists_instance{instance_map_.find(instance_decl)};

    // Instance is NOT found
    if (exists_instance == instance_map_.end()) {
      instance_map_.insert(std::pair<Decl *, ModuleInstanceType>(
          instance_decl, parsed_instance));
    } else {
      // Instance IS found.

      // Preserve canonical field instance name, only accumulate element names.
      if (!instance_name.empty() && instance_name != exists_instance->second.var_name) {
        exists_instance->second.add_instance_name(instance_name);
      }
    }
  }

  virtual void run(const MatchFinder::MatchResult &result) {
    LLVM_DEBUG(llvm::dbgs()
               << " ================== INSTANCE MATCHER ================= \n");
    // General decl
    auto instance_vd = const_cast<clang::VarDecl *>(
        result.Nodes.getNodeAs<clang::VarDecl>("instance_vd"));
    auto ctor_init = const_cast<clang::CXXCtorInitializer *>(
        result.Nodes.getNodeAs<clang::CXXCtorInitializer>("ctor_init"));
    auto ctor_fd = const_cast<clang::FieldDecl *>(
        result.Nodes.getNodeAs<FieldDecl>("ctor_fd"));

    /// If parent_fd_ has been set, then use that.  Otherwise, pick it up from
    /// the matcher.
    clang::ValueDecl *parent_fd{parent_fd_};
    if (!parent_fd) {
      parent_fd = const_cast<clang::ValueDecl *>(
          result.Nodes.getNodeAs<clang::ValueDecl>("parent_fd"));
    }

    auto ctor_arg = const_cast<clang::Stmt *>(
        result.Nodes.getNodeAs<clang::Stmt>("ctor_arg"));

    /// ctor_fd:    Field initialized in the constructor.
    /// ctor_init:  Constructor initializer.
    /// parent_fd:  The FieldDecl whose CXXRecordDecl has the initialization.
    ///             Thus, it is the parent FieldDecl.
    if (ctor_fd && ctor_init && parent_fd) {
      LLVM_DEBUG(llvm::dbgs()
                 << "#### CTOR_FD: parent_fd " << parent_fd->getNameAsString()
                 << " ctor_fd " << ctor_fd->getNameAsString() << "\n");
      LLVM_DEBUG(ctor_fd->dump());

      auto index_map{getArrayInstanceIndex(ctor_init)};

      clang::Expr *expr = ctor_init->getInit()->IgnoreImplicit();
      clang::CXXConstructExpr *cexpr{
          clang::dyn_cast<clang::CXXConstructExpr>(expr)};
      clang::InitListExpr *iexpr{clang::dyn_cast<clang::InitListExpr>(expr)};

      /// For arrays, an InitListExpr is generated.
      /// For non-arrays, CXXConstructExpr is directly castable.
      ///
      /// If it is an array, then get to its InitListExpr, and then get the
      /// first element's constructor.
      //

      if ((iexpr != nullptr) && (cexpr == nullptr)) {
        LLVM_DEBUG(llvm::dbgs() << "### IEXPR is not NULL\n";

                   llvm::dbgs() << "######## Going through index map: "
                                << index_map.size() << "\n";);
        for (auto const &init : index_map) {
          auto submodule_instance_name{init.first};
          parseFieldDecl(ctor_fd, parent_fd, submodule_instance_name,
                         index_map);
          LLVM_DEBUG(llvm::dbgs() << "#==> submodule_instance_name "
                                  << submodule_instance_name << "\n");
        }

      } else {
        MatchFinder iarg_registry{};
        InstanceArgumentMatcher iarg_matcher{};
        iarg_matcher.registerMatchers(iarg_registry);
        // iarg_registry.match(*cexpr, *result.Context);

        if (ctor_fd->hasInClassInitializer()) {
          LLVM_DEBUG(llvm::dbgs() << "### In-class initializer\n";);
          const Expr *in_class_init{ctor_fd->getInClassInitializer()};
          iarg_registry.match(*in_class_init->IgnoreImplicit(),
                              *result.Context);
        } else {
          LLVM_DEBUG(llvm::dbgs() << "### Constructor initializer\n";);
          iarg_registry.match(*cexpr, *result.Context);
        }

        LLVM_DEBUG(iarg_matcher.dump();
                   llvm::dbgs()
                   << "#### IndexMap: " << index_map.size() << "\n";);
        // This retrieves the submodule instance name.
        if (auto inst_literal = iarg_matcher.getInstanceLiteral()) {
          auto submodule_instance_name = inst_literal->getString().str();
          parseFieldDecl(ctor_fd, parent_fd, submodule_instance_name,
                         index_map);
          LLVM_DEBUG(llvm::dbgs() << "=> submodule_instance_name "
                                  << submodule_instance_name << "\n");
        }
      }
    }

    // Is it a FieldDecl or VarDecl

    if (instance_vd) {
      auto instance_name{cast<StringLiteral>(ctor_arg)->getString().str()};
      LLVM_DEBUG(llvm::dbgs()
                 << "## VD: " << instance_vd->getNameAsString() << " "
                 << instance_vd << " instance_name " << instance_name << "\n");

      parseVarDecl(instance_vd, instance_name);
    }
  }

  // This is the callback function whenever there is a match.

  void dump() {
    // Instances holds both FieldDecl and VarDecl as its base class Decl.
    LLVM_DEBUG(llvm::dbgs() << "# INSTANCE MATCHER DUMP \n";);
    for (const auto &i : instance_map_) {
      auto instance{i.second};
      LLVM_DEBUG(llvm::dbgs()
                     << "decl* " << i.first << "  " << instance.instance_name;);

      auto instance_field{instance.type_decl};
      LLVM_DEBUG(llvm::dbgs()
                     << " instance_field*: " << instance_field << "\n";);
      //
      // if (clang::dyn_cast<clang::FieldDecl>(instance_field)) {
      // if (instance.is_field_decl) {
      // LLVM_DEBUG(llvm::dbgs() << " FieldDecl ";);
      // } else {
      // LLVM_DEBUG(llvm::dbgs() << " VarDecl ";);
      // }
      // }
      //
      instance.dump();
    }
  }
};
};  // namespace sc_ast_matchers
#endif
