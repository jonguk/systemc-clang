// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter2.h for the primary calling header

#include "Vtb_counter2__pch.h"
#include "Vtb_counter2__Syms.h"
#include "Vtb_counter2_counter_sc_module_1_if.h"

void Vtb_counter2_counter_sc_module_1_if___ctor_var_reset(Vtb_counter2_counter_sc_module_1_if* vlSelf);

Vtb_counter2_counter_sc_module_1_if::Vtb_counter2_counter_sc_module_1_if(Vtb_counter2__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_counter2_counter_sc_module_1_if___ctor_var_reset(this);
}

void Vtb_counter2_counter_sc_module_1_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_counter2_counter_sc_module_1_if::~Vtb_counter2_counter_sc_module_1_if() {
}
