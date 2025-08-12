// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_counter2.h for the primary calling header

#ifndef VERILATED_VTB_COUNTER2_TOP_WRAP2_SC_MODULE_0_IF_H_
#define VERILATED_VTB_COUNTER2_TOP_WRAP2_SC_MODULE_0_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_counter2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_counter2_top_wrap2_sc_module_0_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ clk;
    CData/*0:0*/ reset_n;
    CData/*0:0*/ en;

    // INTERNAL VARIABLES
    Vtb_counter2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_counter2_top_wrap2_sc_module_0_if(Vtb_counter2__Syms* symsp, const char* v__name);
    ~Vtb_counter2_top_wrap2_sc_module_0_if();
    VL_UNCOPYABLE(Vtb_counter2_top_wrap2_sc_module_0_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtb_counter2_top_wrap2_sc_module_0_if* obj);

#endif  // guard
