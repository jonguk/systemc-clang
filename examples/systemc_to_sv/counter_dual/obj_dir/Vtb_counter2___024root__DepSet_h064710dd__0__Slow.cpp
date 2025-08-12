// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter2.h for the primary calling header

#include "Vtb_counter2__pch.h"
#include "Vtb_counter2__Syms.h"
#include "Vtb_counter2___024root.h"

VL_ATTR_COLD void Vtb_counter2___024root___eval_static(Vtb_counter2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter2___024root___eval_static\n"); );
    Vtb_counter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_counter2__DOT__itf__clk__0 
        = vlSymsp->TOP__tb_counter2__DOT__itf.clk;
}

VL_ATTR_COLD void Vtb_counter2___024root___eval_initial__TOP(Vtb_counter2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter2___024root___eval_initial__TOP\n"); );
    Vtb_counter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__tb_counter2__DOT__itf.clk = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_counter2___024root___dump_triggers__stl(Vtb_counter2___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_counter2___024root___eval_triggers__stl(Vtb_counter2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter2___024root___eval_triggers__stl\n"); );
    Vtb_counter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_counter2___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtb_counter2___024root___stl_sequent__TOP__0(Vtb_counter2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter2___024root___stl_sequent__TOP__0\n"); );
    Vtb_counter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        if ((0U == vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run)) {
            vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0 = 0U;
            vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u0_itf.q 
                = vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0;
            vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT___next_state_run = 1U;
            goto __Vlabel1;
        } else if ((1U == vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run)) {
            if (vlSymsp->TOP__tb_counter2__DOT__itf.reset_n) {
                if (vlSymsp->TOP__tb_counter2__DOT__itf.en) {
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0)));
                    vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u0_itf.q 
                        = vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0;
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT___next_state_run = 2U;
                    goto __Vlabel1;
                } else {
                    vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u0_itf.q 
                        = vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0;
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT___next_state_run = 2U;
                    goto __Vlabel1;
                }
            } else {
                vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0 = 0U;
                vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u0_itf.q 
                    = vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0;
                vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT___next_state_run = 2U;
                goto __Vlabel1;
            }
        } else if ((2U == vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run)) {
            if (vlSymsp->TOP__tb_counter2__DOT__itf.reset_n) {
                if (vlSymsp->TOP__tb_counter2__DOT__itf.en) {
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0)));
                    vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u0_itf.q 
                        = vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0;
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT___next_state_run = 2U;
                    goto __Vlabel1;
                } else {
                    vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u0_itf.q 
                        = vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0;
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT___next_state_run = 2U;
                    goto __Vlabel1;
                }
            } else {
                vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0 = 0U;
                vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u0_itf.q 
                    = vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__counter_value_scclang_global_0;
                vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT___next_state_run = 2U;
                goto __Vlabel1;
            }
        }
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((2U 
                                                 == vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run) 
                                                << 2U) 
                                               | (((1U 
                                                    == vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run) 
                                                   << 1U) 
                                                  | (0U 
                                                     == vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run))))))))) {
            if ((0U == (((2U == vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run) 
                         << 2U) | (((1U == vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run) 
                                    << 1U) | (0U == vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: TopWrap2_sc_module_0.sv:95: Assertion failed in %Ntb_counter2.dut.u0.run_func: unique case, but none matched for '32'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 32,vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run);
                    VL_STOP_MT("TopWrap2_sc_module_0.sv", 95, "");
                }
            } else if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: TopWrap2_sc_module_0.sv:95: Assertion failed in %Ntb_counter2.dut.u0.run_func: unique case, but multiple matches found for '32'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),32,
                             vlSelfRef.tb_counter2__DOT__dut__DOT__u0__DOT__state_run);
                VL_STOP_MT("TopWrap2_sc_module_0.sv", 95, "");
            }
        }
        __Vlabel1: ;
    }
    {
        if ((0U == vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run)) {
            vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0 = 0U;
            vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u1_itf.q 
                = vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0;
            vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT___next_state_run = 1U;
            goto __Vlabel2;
        } else if ((1U == vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run)) {
            if (vlSymsp->TOP__tb_counter2__DOT__itf.reset_n) {
                if (vlSymsp->TOP__tb_counter2__DOT__itf.en) {
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0)));
                    vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u1_itf.q 
                        = vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0;
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT___next_state_run = 2U;
                    goto __Vlabel2;
                } else {
                    vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u1_itf.q 
                        = vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0;
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT___next_state_run = 2U;
                    goto __Vlabel2;
                }
            } else {
                vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0 = 0U;
                vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u1_itf.q 
                    = vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0;
                vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT___next_state_run = 2U;
                goto __Vlabel2;
            }
        } else if ((2U == vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run)) {
            if (vlSymsp->TOP__tb_counter2__DOT__itf.reset_n) {
                if (vlSymsp->TOP__tb_counter2__DOT__itf.en) {
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0)));
                    vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u1_itf.q 
                        = vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0;
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT___next_state_run = 2U;
                    goto __Vlabel2;
                } else {
                    vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u1_itf.q 
                        = vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0;
                    vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT___next_state_run = 2U;
                    goto __Vlabel2;
                }
            } else {
                vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0 = 0U;
                vlSymsp->TOP__tb_counter2__DOT__dut__DOT__u1_itf.q 
                    = vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__counter_value_scclang_global_0;
                vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT___next_state_run = 2U;
                goto __Vlabel2;
            }
        }
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((2U 
                                                 == vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run) 
                                                << 2U) 
                                               | (((1U 
                                                    == vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run) 
                                                   << 1U) 
                                                  | (0U 
                                                     == vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run))))))))) {
            if ((0U == (((2U == vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run) 
                         << 2U) | (((1U == vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run) 
                                    << 1U) | (0U == vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: TopWrap2_sc_module_0.sv:196: Assertion failed in %Ntb_counter2.dut.u1.run_func: unique case, but none matched for '32'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 32,vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run);
                    VL_STOP_MT("TopWrap2_sc_module_0.sv", 196, "");
                }
            } else if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: TopWrap2_sc_module_0.sv:196: Assertion failed in %Ntb_counter2.dut.u1.run_func: unique case, but multiple matches found for '32'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),32,
                             vlSelfRef.tb_counter2__DOT__dut__DOT__u1__DOT__state_run);
                VL_STOP_MT("TopWrap2_sc_module_0.sv", 196, "");
            }
        }
        __Vlabel2: ;
    }
}
