// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_COUNTER2__SYMS_H_
#define VERILATED_VTB_COUNTER2__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_counter2.h"

// INCLUDE MODULE CLASSES
#include "Vtb_counter2___024root.h"
#include "Vtb_counter2_top_wrap2_sc_module_0_if.h"
#include "Vtb_counter2_counter_sc_module_1_if.h"
#include "Vtb_counter2_counter_sc_module_2_if.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_counter2__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_counter2* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_counter2___024root         TOP;
    Vtb_counter2_counter_sc_module_1_if TOP__tb_counter2__DOT__dut__DOT__u0_itf;
    Vtb_counter2_counter_sc_module_2_if TOP__tb_counter2__DOT__dut__DOT__u1_itf;
    Vtb_counter2_top_wrap2_sc_module_0_if TOP__tb_counter2__DOT__itf;

    // CONSTRUCTORS
    Vtb_counter2__Syms(VerilatedContext* contextp, const char* namep, Vtb_counter2* modelp);
    ~Vtb_counter2__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
