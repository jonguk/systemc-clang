// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter2.h for the primary calling header

#include "Vtb_counter2__pch.h"
#include "Vtb_counter2__Syms.h"
#include "Vtb_counter2___024root.h"

void Vtb_counter2___024root___ctor_var_reset(Vtb_counter2___024root* vlSelf);

Vtb_counter2___024root::Vtb_counter2___024root(Vtb_counter2__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_counter2___024root___ctor_var_reset(this);
}

void Vtb_counter2___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_counter2___024root::~Vtb_counter2___024root() {
}
