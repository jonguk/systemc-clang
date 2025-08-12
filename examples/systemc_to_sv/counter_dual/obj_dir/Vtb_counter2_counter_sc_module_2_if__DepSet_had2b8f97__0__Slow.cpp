// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter2.h for the primary calling header

#include "Vtb_counter2__pch.h"
#include "Vtb_counter2_counter_sc_module_2_if.h"

VL_ATTR_COLD void Vtb_counter2_counter_sc_module_2_if___ctor_var_reset(Vtb_counter2_counter_sc_module_2_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtb_counter2_counter_sc_module_2_if___ctor_var_reset\n"); );
    Vtb_counter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8861071527689086543ull);
}
