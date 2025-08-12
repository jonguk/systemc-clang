// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_counter__pch.h"
#include "Vtb_counter.h"
#include "Vtb_counter___024root.h"
#include "Vtb_counter_top_wrap_sc_module_0_if.h"
#include "Vtb_counter_counter_sc_module_1_if.h"

// FUNCTIONS
Vtb_counter__Syms::~Vtb_counter__Syms()
{
}

Vtb_counter__Syms::Vtb_counter__Syms(VerilatedContext* contextp, const char* namep, Vtb_counter* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__tb_counter__DOT__dut__DOT__u_counter_itf{this, Verilated::catName(namep, "tb_counter.dut.u_counter_itf")}
    , TOP__tb_counter__DOT__itf{this, Verilated::catName(namep, "tb_counter.itf")}
{
        // Check resources
        Verilated::stackCheck(18);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__tb_counter__DOT__dut__DOT__u_counter_itf = &TOP__tb_counter__DOT__dut__DOT__u_counter_itf;
    TOP.__PVT__tb_counter__DOT__itf = &TOP__tb_counter__DOT__itf;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__tb_counter__DOT__dut__DOT__u_counter_itf.__Vconfigure(true);
    TOP__tb_counter__DOT__itf.__Vconfigure(true);
}
