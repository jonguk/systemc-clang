// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter.h for the primary calling header

#include "Vtb_counter__pch.h"
#include "Vtb_counter__Syms.h"
#include "Vtb_counter___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_counter___024root___eval_initial__TOP__Vtiming__0(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__tb_counter__DOT__itf.reset_n = 0U;
    vlSymsp->TOP__tb_counter__DOT__itf.en = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x4e20ULL, 
                                         nullptr, "tb_counter.sv", 
                                         12);
    vlSymsp->TOP__tb_counter__DOT__itf.reset_n = 1U;
    vlSymsp->TOP__tb_counter__DOT__itf.en = 1U;
}

VL_INLINE_OPT VlCoroutine Vtb_counter___024root___eval_initial__TOP__Vtiming__2(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "tb_counter.sv", 
                                             7);
        vlSymsp->TOP__tb_counter__DOT__itf.clk = (1U 
                                                  & (~ (IData)(vlSymsp->TOP__tb_counter__DOT__itf.clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_counter___024root___dump_triggers__act(Vtb_counter___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_counter___024root___eval_triggers__act(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_triggers__act\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSymsp->TOP__tb_counter__DOT__itf.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__itf__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__itf__clk__0 
        = vlSymsp->TOP__tb_counter__DOT__itf.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_counter___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_counter___024root___act_sequent__TOP__0(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___act_sequent__TOP__0\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_next 
        = vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_reg;
    if ((0U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run)) {
        vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_next = 0U;
    } else if (((1U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run) 
                || (2U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run))) {
        if (vlSymsp->TOP__tb_counter__DOT__itf.reset_n) {
            if (vlSymsp->TOP__tb_counter__DOT__itf.en) {
                vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_next 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_reg)));
            }
        } else {
            vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_next = 0U;
        }
    } else {
        vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_next = 0U;
    }
}

VL_INLINE_OPT void Vtb_counter___024root___nba_sequent__TOP__0(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___nba_sequent__TOP__0\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("%0t,%0#\n",0,64,VL_TIME_UNITED_Q(1000),
                 -9,8,(IData)(vlSymsp->TOP__tb_counter__DOT__dut__DOT__u_counter_itf.q));
    if (vlSymsp->TOP__tb_counter__DOT__itf.reset_n) {
        vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_reg 
            = vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_next;
        vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run 
            = vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__next_state_run;
    } else {
        vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_reg = 0U;
        vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run = 0U;
    }
    if ((1U & (~ VL_ONEHOT_I((((2U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run) 
                               << 2U) | (((1U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run) 
                                          << 1U) | 
                                         (0U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run))))))) {
        if ((0U != (((2U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run) 
                     << 2U) | (((1U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run) 
                                << 1U) | (0U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: TopWrap_sc_module_0.sv:47: Assertion failed in %Ntb_counter.dut.u_counter: unique case, but multiple matches found for '32'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),32,
                             vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run);
                VL_STOP_MT("TopWrap_sc_module_0.sv", 47, "");
            }
        }
    }
    vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__next_state_run 
        = ((0U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run)
            ? 1U : (((1U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run) 
                     || (2U == vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__state_run))
                     ? 2U : 0U));
}

VL_INLINE_OPT void Vtb_counter___024root___nba_sequent__TOP__1(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___nba_sequent__TOP__1\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__tb_counter__DOT__dut__DOT__u_counter_itf.q 
        = ((IData)(vlSymsp->TOP__tb_counter__DOT__itf.reset_n)
            ? (IData)(vlSelfRef.tb_counter__DOT__dut__DOT__u_counter__DOT__counter_next)
            : 0U);
}
