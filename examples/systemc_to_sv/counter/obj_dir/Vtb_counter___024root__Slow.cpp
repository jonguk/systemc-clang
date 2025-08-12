// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter.h for the primary calling header

#include "Vtb_counter__pch.h"
#include "Vtb_counter__Syms.h"
#include "Vtb_counter___024root.h"

void Vtb_counter___024root___ctor_var_reset(Vtb_counter___024root* vlSelf);

Vtb_counter___024root::Vtb_counter___024root(Vtb_counter__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_counter___024root___ctor_var_reset(this);
}

void Vtb_counter___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_counter___024root::~Vtb_counter___024root() {
}
