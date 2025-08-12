// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_counter2.h for the primary calling header

#ifndef VERILATED_VTB_COUNTER2___024ROOT_H_
#define VERILATED_VTB_COUNTER2___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtb_counter2_counter_sc_module_1_if;
class Vtb_counter2_counter_sc_module_2_if;
class Vtb_counter2_top_wrap2_sc_module_0_if;


class Vtb_counter2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_counter2___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtb_counter2_top_wrap2_sc_module_0_if* __PVT__tb_counter2__DOT__itf;
    Vtb_counter2_counter_sc_module_1_if* __PVT__tb_counter2__DOT__dut__DOT__u0_itf;
    Vtb_counter2_counter_sc_module_2_if* __PVT__tb_counter2__DOT__dut__DOT__u1_itf;

    // DESIGN SPECIFIC STATE
    CData/*7:0*/ tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0;
    CData/*7:0*/ tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_counter2__DOT__itf__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_counter2__DOT__dut__DOT__u0__DOT__state_run;
    IData/*31:0*/ tb_counter2__DOT__dut__DOT__u0__DOT___next_state_run;
    IData/*31:0*/ tb_counter2__DOT__dut__DOT__u1__DOT__state_run;
    IData/*31:0*/ tb_counter2__DOT__dut__DOT__u1__DOT___next_state_run;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_counter2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_counter2___024root(Vtb_counter2__Syms* symsp, const char* v__name);
    ~Vtb_counter2___024root();
    VL_UNCOPYABLE(Vtb_counter2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
