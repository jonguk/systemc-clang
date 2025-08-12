// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_counter2__pch.h"
#include "Vtb_counter2.h"
#include "Vtb_counter2___024root.h"
#include "Vtb_counter2_top_wrap2_sc_module_0_if.h"
#include "Vtb_counter2_counter_sc_module_1_if.h"
#include "Vtb_counter2_counter_sc_module_2_if.h"

// FUNCTIONS
Vtb_counter2__Syms::~Vtb_counter2__Syms()
{
}

Vtb_counter2__Syms::Vtb_counter2__Syms(VerilatedContext* contextp, const char* namep, Vtb_counter2* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__tb_counter2__DOT__dut__DOT__u0_itf{this, Verilated::catName(namep, "tb_counter2.dut.u0_itf")}
    , TOP__tb_counter2__DOT__dut__DOT__u1_itf{this, Verilated::catName(namep, "tb_counter2.dut.u1_itf")}
    , TOP__tb_counter2__DOT__itf{this, Verilated::catName(namep, "tb_counter2.itf")}
{
        // Check resources
        Verilated::stackCheck(18);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__tb_counter2__DOT__dut__DOT__u0_itf = &TOP__tb_counter2__DOT__dut__DOT__u0_itf;
    TOP.__PVT__tb_counter2__DOT__dut__DOT__u1_itf = &TOP__tb_counter2__DOT__dut__DOT__u1_itf;
    TOP.__PVT__tb_counter2__DOT__itf = &TOP__tb_counter2__DOT__itf;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__tb_counter2__DOT__dut__DOT__u0_itf.__Vconfigure(true);
    TOP__tb_counter2__DOT__dut__DOT__u1_itf.__Vconfigure(true);
    TOP__tb_counter2__DOT__itf.__Vconfigure(true);
}
