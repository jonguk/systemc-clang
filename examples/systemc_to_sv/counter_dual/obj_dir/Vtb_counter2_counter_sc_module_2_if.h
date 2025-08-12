// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_counter2.h for the primary calling header

#ifndef VERILATED_VTB_COUNTER2_COUNTER_SC_MODULE_2_IF_H_
#define VERILATED_VTB_COUNTER2_COUNTER_SC_MODULE_2_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_counter2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_counter2_counter_sc_module_2_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*7:0*/ q;

    // INTERNAL VARIABLES
    Vtb_counter2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_counter2_counter_sc_module_2_if(Vtb_counter2__Syms* symsp, const char* v__name);
    ~Vtb_counter2_counter_sc_module_2_if();
    VL_UNCOPYABLE(Vtb_counter2_counter_sc_module_2_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtb_counter2_counter_sc_module_2_if* obj);

#endif  // guard
