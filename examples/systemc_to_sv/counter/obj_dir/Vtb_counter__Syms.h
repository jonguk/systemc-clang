// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_COUNTER__SYMS_H_
#define VERILATED_VTB_COUNTER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_counter.h"

// INCLUDE MODULE CLASSES
#include "Vtb_counter___024root.h"
#include "Vtb_counter_top_wrap_sc_module_0_if.h"
#include "Vtb_counter_counter_sc_module_1_if.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_counter__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_counter* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_counter___024root          TOP;
    Vtb_counter_counter_sc_module_1_if TOP__tb_counter__DOT__dut__DOT__u_counter_itf;
    Vtb_counter_top_wrap_sc_module_0_if TOP__tb_counter__DOT__itf;

    // CONSTRUCTORS
    Vtb_counter__Syms(VerilatedContext* contextp, const char* namep, Vtb_counter* modelp);
    ~Vtb_counter__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
