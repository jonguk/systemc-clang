// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_counter.h for the primary calling header

#ifndef VERILATED_VTB_COUNTER___024ROOT_H_
#define VERILATED_VTB_COUNTER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtb_counter_counter_sc_module_1_if;
class Vtb_counter_top_wrap_sc_module_0_if;


class Vtb_counter__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_counter___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtb_counter_top_wrap_sc_module_0_if* __PVT__tb_counter__DOT__itf;
    Vtb_counter_counter_sc_module_1_if* __PVT__tb_counter__DOT__dut__DOT__u_counter_itf;

    // DESIGN SPECIFIC STATE
    CData/*7:0*/ tb_counter__DOT__dut__DOT__u_counter__DOT__counter_reg;
    CData/*7:0*/ tb_counter__DOT__dut__DOT__u_counter__DOT__counter_next;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_counter__DOT__itf__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_counter__DOT__dut__DOT__u_counter__DOT__state_run;
    IData/*31:0*/ tb_counter__DOT__dut__DOT__u_counter__DOT__next_state_run;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_counter__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_counter___024root(Vtb_counter__Syms* symsp, const char* v__name);
    ~Vtb_counter___024root();
    VL_UNCOPYABLE(Vtb_counter___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
