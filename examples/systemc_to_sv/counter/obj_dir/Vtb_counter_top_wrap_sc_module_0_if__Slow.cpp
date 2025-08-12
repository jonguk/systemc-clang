// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter.h for the primary calling header

#include "Vtb_counter__pch.h"
#include "Vtb_counter__Syms.h"
#include "Vtb_counter_top_wrap_sc_module_0_if.h"

void Vtb_counter_top_wrap_sc_module_0_if___ctor_var_reset(Vtb_counter_top_wrap_sc_module_0_if* vlSelf);

Vtb_counter_top_wrap_sc_module_0_if::Vtb_counter_top_wrap_sc_module_0_if(Vtb_counter__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_counter_top_wrap_sc_module_0_if___ctor_var_reset(this);
}

void Vtb_counter_top_wrap_sc_module_0_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_counter_top_wrap_sc_module_0_if::~Vtb_counter_top_wrap_sc_module_0_if() {
}
