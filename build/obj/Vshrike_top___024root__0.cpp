// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vshrike_top.h for the primary calling header

#include "Vshrike_top__pch.h"

void Vshrike_top___024root___eval_sample(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_sample\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshrike_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vshrike_top___024root___eval_ico(Vshrike_top___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_ico\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (IData)((IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                        (((((IData)(vlSelfRef.mosi) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mosi__0)) 
                                                           << 3U) 
                                                          | (((IData)(vlSelfRef.ss_n) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ss_n__0)) 
                                                             << 2U)) 
                                                         | ((((IData)(vlSelfRef.sclk) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sclk__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.clk) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__sclk__0 = vlSelfRef.sclk;
        vlSelfRef.__Vtrigprevexpr___TOP__ss_n__0 = vlSelfRef.ss_n;
        vlSelfRef.__Vtrigprevexpr___TOP__mosi__0 = vlSelfRef.mosi;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (4ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (8ULL | vlSelfRef.__VicoTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vshrike_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshrike_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
void Vshrike_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);

bool Vshrike_top___024root___eval_act(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_act\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((IData)(vlSelfRef.clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vshrike_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vshrike_top___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool Vshrike_top___024root___eval_inact(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_inact\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vshrike_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vshrike_top___024root___nba_sequent__TOP__0(Vshrike_top___024root* vlSelf);
void Vshrike_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vshrike_top___024root___eval_nba(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_nba\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vshrike_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vshrike_top___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        Vshrike_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vshrike_top___024root___eval_obs(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_obs\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vshrike_top___024root___eval_react(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_react\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vshrike_top___024root___eval_postponed(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_postponed\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vshrike_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

bool Vshrike_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vshrike_top___024root___nba_sequent__TOP__0(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___nba_sequent__TOP__0\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__shrike_top__DOT__rst_sr;
    __Vdly__shrike_top__DOT__rst_sr = 0;
    CData/*2:0*/ __Vdly__shrike_top__DOT__sclk_s;
    __Vdly__shrike_top__DOT__sclk_s = 0;
    CData/*1:0*/ __Vdly__shrike_top__DOT__ss_s;
    __Vdly__shrike_top__DOT__ss_s = 0;
    CData/*1:0*/ __Vdly__shrike_top__DOT__mosi_s;
    __Vdly__shrike_top__DOT__mosi_s = 0;
    CData/*0:0*/ __Vdly__shrike_top__DOT__byte_done;
    __Vdly__shrike_top__DOT__byte_done = 0;
    CData/*2:0*/ __Vdly__shrike_top__DOT__bitcnt;
    __Vdly__shrike_top__DOT__bitcnt = 0;
    CData/*0:0*/ __Vdly__shrike_top__DOT__first;
    __Vdly__shrike_top__DOT__first = 0;
    CData/*7:0*/ __Vdly__shrike_top__DOT__tx;
    __Vdly__shrike_top__DOT__tx = 0;
    CData/*0:0*/ __Vdly__shrike_top__DOT__ld_tx;
    __Vdly__shrike_top__DOT__ld_tx = 0;
    CData/*7:0*/ __Vdly__shrike_top__DOT__rxsh;
    __Vdly__shrike_top__DOT__rxsh = 0;
    CData/*7:0*/ __Vdly__shrike_top__DOT__rx_byte;
    __Vdly__shrike_top__DOT__rx_byte = 0;
    CData/*0:0*/ __Vdly__shrike_top__DOT__rw_wr;
    __Vdly__shrike_top__DOT__rw_wr = 0;
    CData/*6:0*/ __Vdly__shrike_top__DOT__addr;
    __Vdly__shrike_top__DOT__addr = 0;
    CData/*0:0*/ __Vdly__shrike_top__DOT__busy;
    __Vdly__shrike_top__DOT__busy = 0;
    CData/*0:0*/ __Vdly__shrike_top__DOT__done;
    __Vdly__shrike_top__DOT__done = 0;
    CData/*3:0*/ __Vdly__shrike_top__DOT__core__DOT__pc;
    __Vdly__shrike_top__DOT__core__DOT__pc = 0;
    CData/*3:0*/ __Vdly__shrike_top__DOT__core__DOT__loop_pc;
    __Vdly__shrike_top__DOT__core__DOT__loop_pc = 0;
    CData/*4:0*/ __Vdly__shrike_top__DOT__core__DOT__loop_cnt;
    __Vdly__shrike_top__DOT__core__DOT__loop_cnt = 0;
    CData/*1:0*/ __Vdly__shrike_top__DOT__core__DOT__mask;
    __Vdly__shrike_top__DOT__core__DOT__mask = 0;
    CData/*1:0*/ __Vdly__shrike_top__DOT__core__DOT__smask;
    __Vdly__shrike_top__DOT__core__DOT__smask = 0;
    CData/*1:0*/ __Vdly__shrike_top__DOT__core__DOT__pred;
    __Vdly__shrike_top__DOT__core__DOT__pred = 0;
    CData/*1:0*/ __Vdly__shrike_top__DOT__core__DOT__pend;
    __Vdly__shrike_top__DOT__core__DOT__pend = 0;
    CData/*0:0*/ __Vdly__shrike_top__DOT__core__DOT__pend_v;
    __Vdly__shrike_top__DOT__core__DOT__pend_v = 0;
    SData/*15:0*/ __Vdly__shrike_top__DOT__cyc;
    __Vdly__shrike_top__DOT__cyc = 0;
    SData/*15:0*/ __Vdly__shrike_top__DOT__ins_c;
    __Vdly__shrike_top__DOT__ins_c = 0;
    SData/*15:0*/ __Vdly__shrike_top__DOT__lops;
    __Vdly__shrike_top__DOT__lops = 0;
    SData/*15:0*/ __Vdly__shrike_top__DOT__conf;
    __Vdly__shrike_top__DOT__conf = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__imem_hi__v0;
    __VdlyVal__shrike_top__DOT__core__DOT__imem_hi__v0 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__imem_hi__v0;
    __VdlyDim0__shrike_top__DOT__core__DOT__imem_hi__v0 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__imem_hi__v0;
    __VdlySet__shrike_top__DOT__core__DOT__imem_hi__v0 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__scr__v0;
    __VdlyVal__shrike_top__DOT__core__DOT__scr__v0 = 0;
    CData/*4:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__scr__v0;
    __VdlyDim0__shrike_top__DOT__core__DOT__scr__v0 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__scr__v0;
    __VdlySet__shrike_top__DOT__core__DOT__scr__v0 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v0;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v0 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__rf__v16;
    __VdlyVal__shrike_top__DOT__core__DOT__rf__v16 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__rf__v16;
    __VdlyDim0__shrike_top__DOT__core__DOT__rf__v16 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v16;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v16 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__rf__v17;
    __VdlyVal__shrike_top__DOT__core__DOT__rf__v17 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__rf__v17;
    __VdlyDim0__shrike_top__DOT__core__DOT__rf__v17 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v17;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v17 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__rf__v18;
    __VdlyVal__shrike_top__DOT__core__DOT__rf__v18 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__rf__v18;
    __VdlyDim0__shrike_top__DOT__core__DOT__rf__v18 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v18;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v18 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__scr__v1;
    __VdlyVal__shrike_top__DOT__core__DOT__scr__v1 = 0;
    CData/*4:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__scr__v1;
    __VdlyDim0__shrike_top__DOT__core__DOT__scr__v1 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__scr__v1;
    __VdlySet__shrike_top__DOT__core__DOT__scr__v1 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__rf__v19;
    __VdlyVal__shrike_top__DOT__core__DOT__rf__v19 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__rf__v19;
    __VdlyDim0__shrike_top__DOT__core__DOT__rf__v19 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v19;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v19 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__scr__v2;
    __VdlyVal__shrike_top__DOT__core__DOT__scr__v2 = 0;
    CData/*4:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__scr__v2;
    __VdlyDim0__shrike_top__DOT__core__DOT__scr__v2 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__scr__v2;
    __VdlySet__shrike_top__DOT__core__DOT__scr__v2 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__rf__v20;
    __VdlyVal__shrike_top__DOT__core__DOT__rf__v20 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__rf__v20;
    __VdlyDim0__shrike_top__DOT__core__DOT__rf__v20 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v20;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v20 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__rf__v21;
    __VdlyVal__shrike_top__DOT__core__DOT__rf__v21 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__rf__v21;
    __VdlyDim0__shrike_top__DOT__core__DOT__rf__v21 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v21;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v21 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__rf__v22;
    __VdlyVal__shrike_top__DOT__core__DOT__rf__v22 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__rf__v22;
    __VdlyDim0__shrike_top__DOT__core__DOT__rf__v22 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v22;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v22 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__rf__v23;
    __VdlyVal__shrike_top__DOT__core__DOT__rf__v23 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__rf__v23;
    __VdlyDim0__shrike_top__DOT__core__DOT__rf__v23 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v23;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v23 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__rf__v24;
    __VdlyVal__shrike_top__DOT__core__DOT__rf__v24 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__rf__v24;
    __VdlyDim0__shrike_top__DOT__core__DOT__rf__v24 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v24;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v24 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__rf__v25;
    __VdlyVal__shrike_top__DOT__core__DOT__rf__v25 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__rf__v25;
    __VdlyDim0__shrike_top__DOT__core__DOT__rf__v25 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__rf__v25;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v25 = 0;
    CData/*7:0*/ __VdlyVal__shrike_top__DOT__core__DOT__imem_lo__v0;
    __VdlyVal__shrike_top__DOT__core__DOT__imem_lo__v0 = 0;
    CData/*3:0*/ __VdlyDim0__shrike_top__DOT__core__DOT__imem_lo__v0;
    __VdlyDim0__shrike_top__DOT__core__DOT__imem_lo__v0 = 0;
    CData/*0:0*/ __VdlySet__shrike_top__DOT__core__DOT__imem_lo__v0;
    __VdlySet__shrike_top__DOT__core__DOT__imem_lo__v0 = 0;
    // Body
    __Vdly__shrike_top__DOT__rst_sr = vlSelfRef.shrike_top__DOT__rst_sr;
    __Vdly__shrike_top__DOT__sclk_s = vlSelfRef.shrike_top__DOT__sclk_s;
    __Vdly__shrike_top__DOT__ss_s = vlSelfRef.shrike_top__DOT__ss_s;
    __Vdly__shrike_top__DOT__mosi_s = vlSelfRef.shrike_top__DOT__mosi_s;
    __Vdly__shrike_top__DOT__byte_done = vlSelfRef.shrike_top__DOT__byte_done;
    __Vdly__shrike_top__DOT__bitcnt = vlSelfRef.shrike_top__DOT__bitcnt;
    __Vdly__shrike_top__DOT__first = vlSelfRef.shrike_top__DOT__first;
    __Vdly__shrike_top__DOT__ld_tx = vlSelfRef.shrike_top__DOT__ld_tx;
    __Vdly__shrike_top__DOT__rxsh = vlSelfRef.shrike_top__DOT__rxsh;
    __Vdly__shrike_top__DOT__rx_byte = vlSelfRef.shrike_top__DOT__rx_byte;
    __Vdly__shrike_top__DOT__rw_wr = vlSelfRef.shrike_top__DOT__rw_wr;
    __Vdly__shrike_top__DOT__tx = vlSelfRef.shrike_top__DOT__tx;
    __Vdly__shrike_top__DOT__addr = vlSelfRef.shrike_top__DOT__addr;
    __VdlySet__shrike_top__DOT__core__DOT__imem_hi__v0 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__imem_lo__v0 = 0U;
    __Vdly__shrike_top__DOT__busy = vlSelfRef.shrike_top__DOT__busy;
    __Vdly__shrike_top__DOT__core__DOT__loop_pc = vlSelfRef.shrike_top__DOT__core__DOT__loop_pc;
    __Vdly__shrike_top__DOT__core__DOT__loop_cnt = vlSelfRef.shrike_top__DOT__core__DOT__loop_cnt;
    __Vdly__shrike_top__DOT__core__DOT__mask = vlSelfRef.shrike_top__DOT__core__DOT__mask;
    __Vdly__shrike_top__DOT__core__DOT__smask = vlSelfRef.shrike_top__DOT__core__DOT__smask;
    __Vdly__shrike_top__DOT__core__DOT__pred = vlSelfRef.shrike_top__DOT__core__DOT__pred;
    __Vdly__shrike_top__DOT__core__DOT__pend = vlSelfRef.shrike_top__DOT__core__DOT__pend;
    __Vdly__shrike_top__DOT__core__DOT__pend_v = vlSelfRef.shrike_top__DOT__core__DOT__pend_v;
    __Vdly__shrike_top__DOT__cyc = vlSelfRef.shrike_top__DOT__cyc;
    __Vdly__shrike_top__DOT__ins_c = vlSelfRef.shrike_top__DOT__ins_c;
    __Vdly__shrike_top__DOT__lops = vlSelfRef.shrike_top__DOT__lops;
    __Vdly__shrike_top__DOT__conf = vlSelfRef.shrike_top__DOT__conf;
    __Vdly__shrike_top__DOT__done = vlSelfRef.shrike_top__DOT__done;
    __VdlySet__shrike_top__DOT__core__DOT__scr__v0 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__scr__v1 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__scr__v2 = 0U;
    __Vdly__shrike_top__DOT__core__DOT__pc = vlSelfRef.shrike_top__DOT__core__DOT__pc;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v0 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v16 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v17 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v18 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v19 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v20 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v21 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v22 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v23 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v24 = 0U;
    __VdlySet__shrike_top__DOT__core__DOT__rf__v25 = 0U;
    __Vdly__shrike_top__DOT__rst_sr = (0x0000000eU 
                                       & ((IData)(vlSelfRef.shrike_top__DOT__rst_sr) 
                                          << 1U));
    __Vdly__shrike_top__DOT__sclk_s = ((6U & ((IData)(vlSelfRef.shrike_top__DOT__sclk_s) 
                                              << 1U)) 
                                       | (IData)(vlSelfRef.sclk));
    __Vdly__shrike_top__DOT__ss_s = ((2U & ((IData)(vlSelfRef.shrike_top__DOT__ss_s) 
                                            << 1U)) 
                                     | (IData)(vlSelfRef.ss_n));
    __Vdly__shrike_top__DOT__mosi_s = ((2U & ((IData)(vlSelfRef.shrike_top__DOT__mosi_s) 
                                              << 1U)) 
                                       | (IData)(vlSelfRef.mosi));
    if (vlSelfRef.shrike_top__DOT__imem_we) {
        if ((1U & (IData)(vlSelfRef.shrike_top__DOT__imem_wa))) {
            __VdlyVal__shrike_top__DOT__core__DOT__imem_hi__v0 
                = vlSelfRef.shrike_top__DOT__imem_wd;
            __VdlyDim0__shrike_top__DOT__core__DOT__imem_hi__v0 
                = (0x0000000fU & ((IData)(vlSelfRef.shrike_top__DOT__imem_wa) 
                                  >> 1U));
            __VdlySet__shrike_top__DOT__core__DOT__imem_hi__v0 = 1U;
        }
        if ((1U & (~ (IData)(vlSelfRef.shrike_top__DOT__imem_wa)))) {
            __VdlyVal__shrike_top__DOT__core__DOT__imem_lo__v0 
                = vlSelfRef.shrike_top__DOT__imem_wd;
            __VdlyDim0__shrike_top__DOT__core__DOT__imem_lo__v0 
                = (0x0000000fU & ((IData)(vlSelfRef.shrike_top__DOT__imem_wa) 
                                  >> 1U));
            __VdlySet__shrike_top__DOT__core__DOT__imem_lo__v0 = 1U;
        }
    }
    if (((IData)(vlSelfRef.shrike_top__DOT__hs_we) 
         & (~ (IData)(vlSelfRef.shrike_top__DOT__busy)))) {
        __VdlyVal__shrike_top__DOT__core__DOT__scr__v0 
            = vlSelfRef.shrike_top__DOT__hs_wd;
        __VdlyDim0__shrike_top__DOT__core__DOT__scr__v0 
            = vlSelfRef.shrike_top__DOT__hs_addr;
        __VdlySet__shrike_top__DOT__core__DOT__scr__v0 = 1U;
    }
    if ((8U & (IData)(vlSelfRef.shrike_top__DOT__rst_sr))) {
        __Vdly__shrike_top__DOT__busy = 0U;
        __Vdly__shrike_top__DOT__done = 0U;
        __Vdly__shrike_top__DOT__core__DOT__pc = 0U;
        __Vdly__shrike_top__DOT__core__DOT__loop_pc = 0U;
        __Vdly__shrike_top__DOT__core__DOT__loop_cnt = 0U;
        __Vdly__shrike_top__DOT__core__DOT__mask = 3U;
        __Vdly__shrike_top__DOT__core__DOT__smask = 3U;
        __Vdly__shrike_top__DOT__core__DOT__pred = 0U;
        __Vdly__shrike_top__DOT__core__DOT__pend = 0U;
        __Vdly__shrike_top__DOT__core__DOT__pend_v = 0U;
        __Vdly__shrike_top__DOT__cyc = 0U;
        __Vdly__shrike_top__DOT__ins_c = 0U;
        __Vdly__shrike_top__DOT__lops = 0U;
        __Vdly__shrike_top__DOT__conf = 0U;
    } else if (((IData)(vlSelfRef.shrike_top__DOT__start_q) 
                & (~ (IData)(vlSelfRef.shrike_top__DOT__busy)))) {
        __Vdly__shrike_top__DOT__busy = 1U;
        __Vdly__shrike_top__DOT__done = 0U;
        __Vdly__shrike_top__DOT__core__DOT__pc = 0U;
        __Vdly__shrike_top__DOT__core__DOT__loop_pc = 0U;
        __Vdly__shrike_top__DOT__core__DOT__loop_cnt = 0U;
        __Vdly__shrike_top__DOT__core__DOT__mask = 3U;
        __Vdly__shrike_top__DOT__core__DOT__smask = 3U;
        __Vdly__shrike_top__DOT__core__DOT__pred = 0U;
        __Vdly__shrike_top__DOT__core__DOT__pend = 0U;
        __Vdly__shrike_top__DOT__core__DOT__pend_v = 0U;
        __Vdly__shrike_top__DOT__cyc = 0U;
        __Vdly__shrike_top__DOT__ins_c = 0U;
        __Vdly__shrike_top__DOT__lops = 0U;
        __Vdly__shrike_top__DOT__conf = 0U;
        __VdlySet__shrike_top__DOT__core__DOT__rf__v0 = 1U;
    } else if (vlSelfRef.shrike_top__DOT__busy) {
        __Vdly__shrike_top__DOT__cyc = (0x0000ffffU 
                                        & ((IData)(1U) 
                                           + (IData)(vlSelfRef.shrike_top__DOT__cyc)));
        if ((0xfffeU == (IData)(vlSelfRef.shrike_top__DOT__cyc))) {
            __Vdly__shrike_top__DOT__busy = 0U;
            __Vdly__shrike_top__DOT__done = 1U;
        }
        vlSelfRef.shrike_top__DOT__core__DOT__complete = 1U;
        vlSelfRef.shrike_top__DOT__core__DOT__next_pc 
            = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__pc)));
        vlSelfRef.shrike_top__DOT__core__DOT__req = 
            ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__pend_v)
              ? (IData)(vlSelfRef.shrike_top__DOT__core__DOT__pend)
              : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask));
        vlSelfRef.shrike_top__DOT__core__DOT__pop = 
            VL_COUNTONES_I((IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask));
        if ((0x00000010U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
            if ((1U & (~ ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__op) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__op) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
                        if ((1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask))) {
                            vlSelfRef.shrike_top__DOT__core__DOT__a 
                                = vlSelfRef.shrike_top__DOT__core__DOT__rf
                                [vlSelfRef.shrike_top__DOT__core__DOT__rs1];
                            vlSelfRef.shrike_top__DOT__core__DOT__b 
                                = vlSelfRef.shrike_top__DOT__core__DOT__rf
                                [vlSelfRef.shrike_top__DOT__core__DOT__rs2];
                            vlSelfRef.shrike_top__DOT__core__DOT__d 
                                = vlSelfRef.shrike_top__DOT__core__DOT__rf
                                [vlSelfRef.shrike_top__DOT__core__DOT__rd];
                            vlSelfRef.shrike_top__DOT__core__DOT__prod 
                                = (0x0000ffffU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                  * (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)));
                            vlSelfRef.shrike_top__DOT__core__DOT__res 
                                = (0x000000ffU & ((0x00000010U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((8U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                     ? 
                                                    ((0x00000080U 
                                                      & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                      ? 0U
                                                      : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                       ? 
                                                      ((0x00000080U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                        ? 0U
                                                        : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                       : 
                                                      ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                       >> 
                                                       (7U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5))))
                                                      : 
                                                     ((0x00000080U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                       ? 0U
                                                       : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a)))))
                                                   : 
                                                  ((8U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                       ? 0U
                                                       : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                       ? 
                                                      ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                       + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                       : 
                                                      ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__d) 
                                                       + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                       ? (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod)
                                                       : 
                                                      ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                       - (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                       ? 
                                                      ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                       + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))
                                                       : 
                                                      ((0x00000080U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                        ? 0U
                                                        : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))))))));
                            __VdlyVal__shrike_top__DOT__core__DOT__rf__v16 
                                = vlSelfRef.shrike_top__DOT__core__DOT__res;
                            __VdlyDim0__shrike_top__DOT__core__DOT__rf__v16 
                                = vlSelfRef.shrike_top__DOT__core__DOT__rd;
                            __VdlySet__shrike_top__DOT__core__DOT__rf__v16 = 1U;
                        }
                        if ((2U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask))) {
                            vlSelfRef.shrike_top__DOT__core__DOT__a 
                                = vlSelfRef.shrike_top__DOT__core__DOT__rf
                                [(0x0000000fU & ((IData)(8U) 
                                                 + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs1)))];
                            vlSelfRef.shrike_top__DOT__core__DOT__b 
                                = vlSelfRef.shrike_top__DOT__core__DOT__rf
                                [(0x0000000fU & ((IData)(8U) 
                                                 + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs2)))];
                            vlSelfRef.shrike_top__DOT__core__DOT__d 
                                = vlSelfRef.shrike_top__DOT__core__DOT__rf
                                [(0x0000000fU & ((IData)(8U) 
                                                 + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rd)))];
                            vlSelfRef.shrike_top__DOT__core__DOT__prod 
                                = (0x0000ffffU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                  * (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)));
                            vlSelfRef.shrike_top__DOT__core__DOT__res 
                                = (0x000000ffU & ((0x00000010U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((8U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                     ? 
                                                    ((0x00000080U 
                                                      & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                      ? 0U
                                                      : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                       ? 
                                                      ((0x00000080U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                        ? 0U
                                                        : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                       : 
                                                      ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                       >> 
                                                       (7U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5))))
                                                      : 
                                                     ((0x00000080U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                       ? 0U
                                                       : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a)))))
                                                   : 
                                                  ((8U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                       ? 1U
                                                       : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                       ? 
                                                      ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                       + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                       : 
                                                      ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__d) 
                                                       + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                       ? (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod)
                                                       : 
                                                      ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                       - (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                       ? 
                                                      ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                       + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))
                                                       : 
                                                      ((0x00000080U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                        ? 0U
                                                        : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))))))));
                            __VdlyVal__shrike_top__DOT__core__DOT__rf__v17 
                                = vlSelfRef.shrike_top__DOT__core__DOT__res;
                            __VdlyDim0__shrike_top__DOT__core__DOT__rf__v17 
                                = (0x0000000fU & ((IData)(8U) 
                                                  + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rd)));
                            __VdlySet__shrike_top__DOT__core__DOT__rf__v17 = 1U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
                        __Vdly__shrike_top__DOT__busy = 0U;
                        __Vdly__shrike_top__DOT__done = 1U;
                    } else if ((1U < (IData)(vlSelfRef.shrike_top__DOT__core__DOT__loop_cnt))) {
                        __Vdly__shrike_top__DOT__core__DOT__loop_cnt 
                            = (0x0000001fU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__loop_cnt) 
                                              - (IData)(1U)));
                        vlSelfRef.shrike_top__DOT__core__DOT__next_pc 
                            = vlSelfRef.shrike_top__DOT__core__DOT__loop_pc;
                    }
                }
            }
        } else if ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
            if ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
                if ((2U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
                    if ((1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
                        __Vdly__shrike_top__DOT__core__DOT__loop_cnt 
                            = vlSelfRef.shrike_top__DOT__core__DOT__imm5;
                        __Vdly__shrike_top__DOT__core__DOT__loop_pc 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__pc)));
                    } else {
                        __Vdly__shrike_top__DOT__core__DOT__mask 
                            = vlSelfRef.shrike_top__DOT__core__DOT__smask;
                    }
                } else if ((1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
                    __Vdly__shrike_top__DOT__core__DOT__mask 
                        = ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__smask) 
                           & (~ (IData)(vlSelfRef.shrike_top__DOT__core__DOT__pred)));
                } else {
                    __Vdly__shrike_top__DOT__core__DOT__smask 
                        = vlSelfRef.shrike_top__DOT__core__DOT__mask;
                    __Vdly__shrike_top__DOT__core__DOT__mask 
                        = ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask) 
                           & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__pred));
                }
            } else if ((2U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
                if ((1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask))) {
                    vlSelfRef.shrike_top__DOT__core__DOT__a 
                        = vlSelfRef.shrike_top__DOT__core__DOT__rf
                        [vlSelfRef.shrike_top__DOT__core__DOT__rs1];
                    vlSelfRef.shrike_top__DOT__core__DOT__b 
                        = vlSelfRef.shrike_top__DOT__core__DOT__rf
                        [vlSelfRef.shrike_top__DOT__core__DOT__rs2];
                    __Vdly__shrike_top__DOT__core__DOT__pred 
                        = ((2U & (IData)(__Vdly__shrike_top__DOT__core__DOT__pred)) 
                           | ((0x0aU == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                               ? ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                  < (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))
                               : ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                  == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))));
                }
                if ((2U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask))) {
                    vlSelfRef.shrike_top__DOT__core__DOT__a 
                        = vlSelfRef.shrike_top__DOT__core__DOT__rf
                        [(0x0000000fU & ((IData)(8U) 
                                         + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs1)))];
                    vlSelfRef.shrike_top__DOT__core__DOT__b 
                        = vlSelfRef.shrike_top__DOT__core__DOT__rf
                        [(0x0000000fU & ((IData)(8U) 
                                         + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs2)))];
                    __Vdly__shrike_top__DOT__core__DOT__pred 
                        = ((1U & (IData)(__Vdly__shrike_top__DOT__core__DOT__pred)) 
                           | (((0x0aU == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                ? ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                   < (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))
                                : ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                   == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))) 
                              << 1U));
                }
            } else {
                vlSelfRef.shrike_top__DOT__core__DOT__defer = 0U;
                vlSelfRef.shrike_top__DOT__core__DOT__bt0 = 0U;
                vlSelfRef.shrike_top__DOT__core__DOT__bt1 = 0U;
                vlSelfRef.shrike_top__DOT__core__DOT__ba0 = 0U;
                vlSelfRef.shrike_top__DOT__core__DOT__ba1 = 0U;
                if ((1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__req))) {
                    vlSelfRef.shrike_top__DOT__core__DOT__ad8 
                        = (0x000000ffU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__rf
                                                  [vlSelfRef.shrike_top__DOT__core__DOT__rs1]) 
                                          + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5)));
                    vlSelfRef.shrike_top__DOT__core__DOT__ad 
                        = (0x0000001fU & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__ad8));
                    vlSelfRef.shrike_top__DOT__core__DOT__bk 
                        = (1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__ad));
                    if (vlSelfRef.shrike_top__DOT__core__DOT__bk) {
                        if (vlSelfRef.shrike_top__DOT__core__DOT__bt1) {
                            vlSelfRef.shrike_top__DOT__core__DOT__served 
                                = ((8U == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op)) 
                                   & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__ba1) 
                                      == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__ad)));
                        } else {
                            vlSelfRef.shrike_top__DOT__core__DOT__bt1 = 1U;
                            vlSelfRef.shrike_top__DOT__core__DOT__ba1 
                                = vlSelfRef.shrike_top__DOT__core__DOT__ad;
                            vlSelfRef.shrike_top__DOT__core__DOT__served = 1U;
                        }
                    } else if (vlSelfRef.shrike_top__DOT__core__DOT__bt0) {
                        vlSelfRef.shrike_top__DOT__core__DOT__served 
                            = ((8U == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op)) 
                               & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__ba0) 
                                  == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__ad)));
                    } else {
                        vlSelfRef.shrike_top__DOT__core__DOT__bt0 = 1U;
                        vlSelfRef.shrike_top__DOT__core__DOT__ba0 
                            = vlSelfRef.shrike_top__DOT__core__DOT__ad;
                        vlSelfRef.shrike_top__DOT__core__DOT__served = 1U;
                    }
                    if (vlSelfRef.shrike_top__DOT__core__DOT__served) {
                        if ((8U == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
                            __VdlyVal__shrike_top__DOT__core__DOT__rf__v18 
                                = vlSelfRef.shrike_top__DOT__core__DOT__scr
                                [vlSelfRef.shrike_top__DOT__core__DOT__ad];
                            __VdlyDim0__shrike_top__DOT__core__DOT__rf__v18 
                                = vlSelfRef.shrike_top__DOT__core__DOT__rd;
                            __VdlySet__shrike_top__DOT__core__DOT__rf__v18 = 1U;
                        } else {
                            __VdlyVal__shrike_top__DOT__core__DOT__scr__v1 
                                = vlSelfRef.shrike_top__DOT__core__DOT__rf
                                [vlSelfRef.shrike_top__DOT__core__DOT__rd];
                            __VdlyDim0__shrike_top__DOT__core__DOT__scr__v1 
                                = vlSelfRef.shrike_top__DOT__core__DOT__ad;
                            __VdlySet__shrike_top__DOT__core__DOT__scr__v1 = 1U;
                        }
                    } else {
                        vlSelfRef.shrike_top__DOT__core__DOT__defer 
                            = (1U | (IData)(vlSelfRef.shrike_top__DOT__core__DOT__defer));
                    }
                }
                if ((2U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__req))) {
                    vlSelfRef.shrike_top__DOT__core__DOT__ad8 
                        = (0x000000ffU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__rf
                                                  [
                                                  (0x0000000fU 
                                                   & ((IData)(8U) 
                                                      + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs1)))]) 
                                          + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5)));
                    vlSelfRef.shrike_top__DOT__core__DOT__ad 
                        = (0x0000001fU & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__ad8));
                    vlSelfRef.shrike_top__DOT__core__DOT__bk 
                        = (1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__ad));
                    if (vlSelfRef.shrike_top__DOT__core__DOT__bk) {
                        if (vlSelfRef.shrike_top__DOT__core__DOT__bt1) {
                            vlSelfRef.shrike_top__DOT__core__DOT__served 
                                = ((8U == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op)) 
                                   & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__ba1) 
                                      == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__ad)));
                        } else {
                            vlSelfRef.shrike_top__DOT__core__DOT__bt1 = 1U;
                            vlSelfRef.shrike_top__DOT__core__DOT__ba1 
                                = vlSelfRef.shrike_top__DOT__core__DOT__ad;
                            vlSelfRef.shrike_top__DOT__core__DOT__served = 1U;
                        }
                    } else if (vlSelfRef.shrike_top__DOT__core__DOT__bt0) {
                        vlSelfRef.shrike_top__DOT__core__DOT__served 
                            = ((8U == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op)) 
                               & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__ba0) 
                                  == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__ad)));
                    } else {
                        vlSelfRef.shrike_top__DOT__core__DOT__bt0 = 1U;
                        vlSelfRef.shrike_top__DOT__core__DOT__ba0 
                            = vlSelfRef.shrike_top__DOT__core__DOT__ad;
                        vlSelfRef.shrike_top__DOT__core__DOT__served = 1U;
                    }
                    if (vlSelfRef.shrike_top__DOT__core__DOT__served) {
                        if ((8U == (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
                            __VdlyVal__shrike_top__DOT__core__DOT__rf__v19 
                                = vlSelfRef.shrike_top__DOT__core__DOT__scr
                                [vlSelfRef.shrike_top__DOT__core__DOT__ad];
                            __VdlyDim0__shrike_top__DOT__core__DOT__rf__v19 
                                = (0x0000000fU & ((IData)(8U) 
                                                  + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rd)));
                            __VdlySet__shrike_top__DOT__core__DOT__rf__v19 = 1U;
                        } else {
                            __VdlyVal__shrike_top__DOT__core__DOT__scr__v2 
                                = vlSelfRef.shrike_top__DOT__core__DOT__rf
                                [(0x0000000fU & ((IData)(8U) 
                                                 + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rd)))];
                            __VdlyDim0__shrike_top__DOT__core__DOT__scr__v2 
                                = vlSelfRef.shrike_top__DOT__core__DOT__ad;
                            __VdlySet__shrike_top__DOT__core__DOT__scr__v2 = 1U;
                        }
                    } else {
                        vlSelfRef.shrike_top__DOT__core__DOT__defer 
                            = (2U | (IData)(vlSelfRef.shrike_top__DOT__core__DOT__defer));
                    }
                }
                if ((0U != (IData)(vlSelfRef.shrike_top__DOT__core__DOT__defer))) {
                    __Vdly__shrike_top__DOT__conf = 
                        (0x0000ffffU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.shrike_top__DOT__conf)));
                    vlSelfRef.shrike_top__DOT__core__DOT__complete = 0U;
                    __Vdly__shrike_top__DOT__core__DOT__pend 
                        = vlSelfRef.shrike_top__DOT__core__DOT__defer;
                    __Vdly__shrike_top__DOT__core__DOT__pend_v = 1U;
                } else {
                    __Vdly__shrike_top__DOT__core__DOT__pend_v = 0U;
                }
            }
        } else if ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
            if ((1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask))) {
                vlSelfRef.shrike_top__DOT__core__DOT__a 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [vlSelfRef.shrike_top__DOT__core__DOT__rs1];
                vlSelfRef.shrike_top__DOT__core__DOT__b 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [vlSelfRef.shrike_top__DOT__core__DOT__rs2];
                vlSelfRef.shrike_top__DOT__core__DOT__d 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [vlSelfRef.shrike_top__DOT__core__DOT__rd];
                vlSelfRef.shrike_top__DOT__core__DOT__prod 
                    = (0x0000ffffU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                      * (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)));
                vlSelfRef.shrike_top__DOT__core__DOT__res 
                    = (0x000000ffU & ((0x00000010U 
                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                       ? ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((0x00000080U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                   ? 0U
                                                   : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    >> 
                                                    (7U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5))))
                                                   : 
                                                  ((0x00000080U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    ? 0U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a)))))
                                       : ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 0U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__d) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod))))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod)
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    - (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))
                                                    : 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))))))));
                __VdlyVal__shrike_top__DOT__core__DOT__rf__v20 
                    = vlSelfRef.shrike_top__DOT__core__DOT__res;
                __VdlyDim0__shrike_top__DOT__core__DOT__rf__v20 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rd;
                __VdlySet__shrike_top__DOT__core__DOT__rf__v20 = 1U;
            }
            if ((2U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask))) {
                vlSelfRef.shrike_top__DOT__core__DOT__a 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [(0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs1)))];
                vlSelfRef.shrike_top__DOT__core__DOT__b 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [(0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs2)))];
                vlSelfRef.shrike_top__DOT__core__DOT__d 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [(0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rd)))];
                vlSelfRef.shrike_top__DOT__core__DOT__prod 
                    = (0x0000ffffU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                      * (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)));
                vlSelfRef.shrike_top__DOT__core__DOT__res 
                    = (0x000000ffU & ((0x00000010U 
                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                       ? ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((0x00000080U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                   ? 0U
                                                   : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    >> 
                                                    (7U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5))))
                                                   : 
                                                  ((0x00000080U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    ? 0U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a)))))
                                       : ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 1U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__d) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod))))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod)
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    - (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))
                                                    : 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))))))));
                __VdlyVal__shrike_top__DOT__core__DOT__rf__v21 
                    = vlSelfRef.shrike_top__DOT__core__DOT__res;
                __VdlyDim0__shrike_top__DOT__core__DOT__rf__v21 
                    = (0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rd)));
                __VdlySet__shrike_top__DOT__core__DOT__rf__v21 = 1U;
            }
        } else if ((2U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
            if ((1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask))) {
                vlSelfRef.shrike_top__DOT__core__DOT__a 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [vlSelfRef.shrike_top__DOT__core__DOT__rs1];
                vlSelfRef.shrike_top__DOT__core__DOT__b 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [vlSelfRef.shrike_top__DOT__core__DOT__rs2];
                vlSelfRef.shrike_top__DOT__core__DOT__d 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [vlSelfRef.shrike_top__DOT__core__DOT__rd];
                vlSelfRef.shrike_top__DOT__core__DOT__prod 
                    = (0x0000ffffU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                      * (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)));
                vlSelfRef.shrike_top__DOT__core__DOT__res 
                    = (0x000000ffU & ((0x00000010U 
                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                       ? ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((0x00000080U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                   ? 0U
                                                   : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    >> 
                                                    (7U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5))))
                                                   : 
                                                  ((0x00000080U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    ? 0U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a)))))
                                       : ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 0U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__d) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod))))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod)
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    - (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))
                                                    : 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))))))));
                __VdlyVal__shrike_top__DOT__core__DOT__rf__v22 
                    = vlSelfRef.shrike_top__DOT__core__DOT__res;
                __VdlyDim0__shrike_top__DOT__core__DOT__rf__v22 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rd;
                __VdlySet__shrike_top__DOT__core__DOT__rf__v22 = 1U;
            }
            if ((2U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask))) {
                vlSelfRef.shrike_top__DOT__core__DOT__a 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [(0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs1)))];
                vlSelfRef.shrike_top__DOT__core__DOT__b 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [(0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs2)))];
                vlSelfRef.shrike_top__DOT__core__DOT__d 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [(0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rd)))];
                vlSelfRef.shrike_top__DOT__core__DOT__prod 
                    = (0x0000ffffU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                      * (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)));
                vlSelfRef.shrike_top__DOT__core__DOT__res 
                    = (0x000000ffU & ((0x00000010U 
                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                       ? ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((0x00000080U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                   ? 0U
                                                   : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    >> 
                                                    (7U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5))))
                                                   : 
                                                  ((0x00000080U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    ? 0U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a)))))
                                       : ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 1U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__d) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod))))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod)
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    - (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))
                                                    : 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))))))));
                __VdlyVal__shrike_top__DOT__core__DOT__rf__v23 
                    = vlSelfRef.shrike_top__DOT__core__DOT__res;
                __VdlyDim0__shrike_top__DOT__core__DOT__rf__v23 
                    = (0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rd)));
                __VdlySet__shrike_top__DOT__core__DOT__rf__v23 = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
            if ((1U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask))) {
                vlSelfRef.shrike_top__DOT__core__DOT__a 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [vlSelfRef.shrike_top__DOT__core__DOT__rs1];
                vlSelfRef.shrike_top__DOT__core__DOT__b 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [vlSelfRef.shrike_top__DOT__core__DOT__rs2];
                vlSelfRef.shrike_top__DOT__core__DOT__d 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [vlSelfRef.shrike_top__DOT__core__DOT__rd];
                vlSelfRef.shrike_top__DOT__core__DOT__prod 
                    = (0x0000ffffU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                      * (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)));
                vlSelfRef.shrike_top__DOT__core__DOT__res 
                    = (0x000000ffU & ((0x00000010U 
                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                       ? ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((0x00000080U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                   ? 0U
                                                   : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    >> 
                                                    (7U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5))))
                                                   : 
                                                  ((0x00000080U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    ? 0U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a)))))
                                       : ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 0U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__d) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod))))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod)
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    - (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))
                                                    : 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))))))));
                __VdlyVal__shrike_top__DOT__core__DOT__rf__v24 
                    = vlSelfRef.shrike_top__DOT__core__DOT__res;
                __VdlyDim0__shrike_top__DOT__core__DOT__rf__v24 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rd;
                __VdlySet__shrike_top__DOT__core__DOT__rf__v24 = 1U;
            }
            if ((2U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__mask))) {
                vlSelfRef.shrike_top__DOT__core__DOT__a 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [(0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs1)))];
                vlSelfRef.shrike_top__DOT__core__DOT__b 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [(0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rs2)))];
                vlSelfRef.shrike_top__DOT__core__DOT__d 
                    = vlSelfRef.shrike_top__DOT__core__DOT__rf
                    [(0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rd)))];
                vlSelfRef.shrike_top__DOT__core__DOT__prod 
                    = (0x0000ffffU & ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                      * (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)));
                vlSelfRef.shrike_top__DOT__core__DOT__res 
                    = (0x000000ffU & ((0x00000010U 
                                       & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                       ? ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((0x00000080U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                   ? 0U
                                                   : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    >> 
                                                    (7U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5))))
                                                   : 
                                                  ((0x00000080U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                    ? 0U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a)))))
                                       : ((8U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                           ? ((0x00000080U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                               ? 0U
                                               : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                           : ((4U & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                               ? ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 1U
                                                    : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__simm))
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__d) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod))))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? (IData)(vlSelfRef.shrike_top__DOT__core__DOT__prod)
                                                    : 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    - (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))
                                                    ? 
                                                   ((IData)(vlSelfRef.shrike_top__DOT__core__DOT__a) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__b))
                                                    : 
                                                   ((0x00000080U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))
                                                     ? 0U
                                                     : (IData)(vlSelfRef.shrike_top__DOT__core__DOT__a))))))));
                __VdlyVal__shrike_top__DOT__core__DOT__rf__v25 
                    = vlSelfRef.shrike_top__DOT__core__DOT__res;
                __VdlyDim0__shrike_top__DOT__core__DOT__rf__v25 
                    = (0x0000000fU & ((IData)(8U) + (IData)(vlSelfRef.shrike_top__DOT__core__DOT__rd)));
                __VdlySet__shrike_top__DOT__core__DOT__rf__v25 = 1U;
            }
        }
        if (vlSelfRef.shrike_top__DOT__core__DOT__complete) {
            if ((0x11U != (IData)(vlSelfRef.shrike_top__DOT__core__DOT__op))) {
                __Vdly__shrike_top__DOT__ins_c = (0x0000ffffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.shrike_top__DOT__ins_c)));
                __Vdly__shrike_top__DOT__lops = (0x0000ffffU 
                                                 & ((IData)(vlSelfRef.shrike_top__DOT__lops) 
                                                    + vlSelfRef.shrike_top__DOT__core__DOT__pop));
            }
            __Vdly__shrike_top__DOT__core__DOT__pc 
                = vlSelfRef.shrike_top__DOT__core__DOT__next_pc;
        }
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__imem_hi__v0) {
        vlSelfRef.shrike_top__DOT__core__DOT__imem_hi[__VdlyDim0__shrike_top__DOT__core__DOT__imem_hi__v0] 
            = __VdlyVal__shrike_top__DOT__core__DOT__imem_hi__v0;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__imem_lo__v0) {
        vlSelfRef.shrike_top__DOT__core__DOT__imem_lo[__VdlyDim0__shrike_top__DOT__core__DOT__imem_lo__v0] 
            = __VdlyVal__shrike_top__DOT__core__DOT__imem_lo__v0;
    }
    vlSelfRef.shrike_top__DOT__rst_sr = __Vdly__shrike_top__DOT__rst_sr;
    vlSelfRef.shrike_top__DOT__core__DOT__loop_pc = __Vdly__shrike_top__DOT__core__DOT__loop_pc;
    vlSelfRef.shrike_top__DOT__core__DOT__loop_cnt 
        = __Vdly__shrike_top__DOT__core__DOT__loop_cnt;
    vlSelfRef.shrike_top__DOT__core__DOT__mask = __Vdly__shrike_top__DOT__core__DOT__mask;
    vlSelfRef.shrike_top__DOT__core__DOT__smask = __Vdly__shrike_top__DOT__core__DOT__smask;
    vlSelfRef.shrike_top__DOT__core__DOT__pred = __Vdly__shrike_top__DOT__core__DOT__pred;
    vlSelfRef.shrike_top__DOT__core__DOT__pend = __Vdly__shrike_top__DOT__core__DOT__pend;
    vlSelfRef.shrike_top__DOT__core__DOT__pend_v = __Vdly__shrike_top__DOT__core__DOT__pend_v;
    if (__VdlySet__shrike_top__DOT__core__DOT__scr__v0) {
        vlSelfRef.shrike_top__DOT__core__DOT__scr[__VdlyDim0__shrike_top__DOT__core__DOT__scr__v0] 
            = __VdlyVal__shrike_top__DOT__core__DOT__scr__v0;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__scr__v1) {
        vlSelfRef.shrike_top__DOT__core__DOT__scr[__VdlyDim0__shrike_top__DOT__core__DOT__scr__v1] 
            = __VdlyVal__shrike_top__DOT__core__DOT__scr__v1;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__scr__v2) {
        vlSelfRef.shrike_top__DOT__core__DOT__scr[__VdlyDim0__shrike_top__DOT__core__DOT__scr__v2] 
            = __VdlyVal__shrike_top__DOT__core__DOT__scr__v2;
    }
    vlSelfRef.shrike_top__DOT__core__DOT__pc = __Vdly__shrike_top__DOT__core__DOT__pc;
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v0) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[0U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[1U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[2U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[3U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[4U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[5U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[6U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[7U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[8U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[9U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[10U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[11U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[12U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[13U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[14U] = 0U;
        vlSelfRef.shrike_top__DOT__core__DOT__rf[15U] = 0U;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v16) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[__VdlyDim0__shrike_top__DOT__core__DOT__rf__v16] 
            = __VdlyVal__shrike_top__DOT__core__DOT__rf__v16;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v17) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[__VdlyDim0__shrike_top__DOT__core__DOT__rf__v17] 
            = __VdlyVal__shrike_top__DOT__core__DOT__rf__v17;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v18) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[__VdlyDim0__shrike_top__DOT__core__DOT__rf__v18] 
            = __VdlyVal__shrike_top__DOT__core__DOT__rf__v18;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v19) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[__VdlyDim0__shrike_top__DOT__core__DOT__rf__v19] 
            = __VdlyVal__shrike_top__DOT__core__DOT__rf__v19;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v20) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[__VdlyDim0__shrike_top__DOT__core__DOT__rf__v20] 
            = __VdlyVal__shrike_top__DOT__core__DOT__rf__v20;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v21) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[__VdlyDim0__shrike_top__DOT__core__DOT__rf__v21] 
            = __VdlyVal__shrike_top__DOT__core__DOT__rf__v21;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v22) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[__VdlyDim0__shrike_top__DOT__core__DOT__rf__v22] 
            = __VdlyVal__shrike_top__DOT__core__DOT__rf__v22;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v23) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[__VdlyDim0__shrike_top__DOT__core__DOT__rf__v23] 
            = __VdlyVal__shrike_top__DOT__core__DOT__rf__v23;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v24) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[__VdlyDim0__shrike_top__DOT__core__DOT__rf__v24] 
            = __VdlyVal__shrike_top__DOT__core__DOT__rf__v24;
    }
    if (__VdlySet__shrike_top__DOT__core__DOT__rf__v25) {
        vlSelfRef.shrike_top__DOT__core__DOT__rf[__VdlyDim0__shrike_top__DOT__core__DOT__rf__v25] 
            = __VdlyVal__shrike_top__DOT__core__DOT__rf__v25;
    }
    vlSelfRef.shrike_top__DOT__core__DOT__op = (0x0000001fU 
                                                & (vlSelfRef.shrike_top__DOT__core__DOT__imem_hi
                                                   [vlSelfRef.shrike_top__DOT__core__DOT__pc] 
                                                   >> 3U));
    vlSelfRef.shrike_top__DOT__core__DOT__rd = (7U 
                                                & vlSelfRef.shrike_top__DOT__core__DOT__imem_hi
                                                [vlSelfRef.shrike_top__DOT__core__DOT__pc]);
    vlSelfRef.shrike_top__DOT__core__DOT__rs1 = (7U 
                                                 & (vlSelfRef.shrike_top__DOT__core__DOT__imem_lo
                                                    [vlSelfRef.shrike_top__DOT__core__DOT__pc] 
                                                    >> 5U));
    vlSelfRef.shrike_top__DOT__core__DOT__rs2 = (7U 
                                                 & (vlSelfRef.shrike_top__DOT__core__DOT__imem_lo
                                                    [vlSelfRef.shrike_top__DOT__core__DOT__pc] 
                                                    >> 2U));
    vlSelfRef.shrike_top__DOT__core__DOT__imm5 = (0x0000001fU 
                                                  & vlSelfRef.shrike_top__DOT__core__DOT__imem_lo
                                                  [vlSelfRef.shrike_top__DOT__core__DOT__pc]);
    __Vdly__shrike_top__DOT__byte_done = 0U;
    vlSelfRef.shrike_top__DOT__start_q = 0U;
    vlSelfRef.shrike_top__DOT__imem_we = 0U;
    vlSelfRef.shrike_top__DOT__hs_we = 0U;
    if ((2U & (IData)(vlSelfRef.shrike_top__DOT__ss_s))) {
        __Vdly__shrike_top__DOT__bitcnt = 0U;
        __Vdly__shrike_top__DOT__first = 1U;
        __Vdly__shrike_top__DOT__tx = 0U;
        __Vdly__shrike_top__DOT__ld_tx = 0U;
    } else {
        if ((1U == (3U & ((IData)(vlSelfRef.shrike_top__DOT__sclk_s) 
                          >> 1U)))) {
            __Vdly__shrike_top__DOT__rxsh = ((0x000000feU 
                                              & ((IData)(vlSelfRef.shrike_top__DOT__rxsh) 
                                                 << 1U)) 
                                             | (1U 
                                                & ((IData)(vlSelfRef.shrike_top__DOT__mosi_s) 
                                                   >> 1U)));
            __Vdly__shrike_top__DOT__bitcnt = (7U & 
                                               ((IData)(1U) 
                                                + (IData)(vlSelfRef.shrike_top__DOT__bitcnt)));
            if ((7U == (IData)(vlSelfRef.shrike_top__DOT__bitcnt))) {
                __Vdly__shrike_top__DOT__byte_done = 1U;
                __Vdly__shrike_top__DOT__rx_byte = 
                    ((0x000000feU & ((IData)(vlSelfRef.shrike_top__DOT__rxsh) 
                                     << 1U)) | (1U 
                                                & ((IData)(vlSelfRef.shrike_top__DOT__mosi_s) 
                                                   >> 1U)));
            }
        }
        if ((IData)(((4U == (6U & (IData)(vlSelfRef.shrike_top__DOT__sclk_s))) 
                     & (0U != (IData)(vlSelfRef.shrike_top__DOT__bitcnt))))) {
            __Vdly__shrike_top__DOT__tx = (0x000000feU 
                                           & ((IData)(vlSelfRef.shrike_top__DOT__tx) 
                                              << 1U));
        }
        if (vlSelfRef.shrike_top__DOT__byte_done) {
            if (vlSelfRef.shrike_top__DOT__first) {
                __Vdly__shrike_top__DOT__first = 0U;
                __Vdly__shrike_top__DOT__rw_wr = (1U 
                                                  & ((IData)(vlSelfRef.shrike_top__DOT__rx_byte) 
                                                     >> 7U));
                __Vdly__shrike_top__DOT__addr = (0x0000007fU 
                                                 & (IData)(vlSelfRef.shrike_top__DOT__rx_byte));
                if ((1U & (~ ((IData)(vlSelfRef.shrike_top__DOT__rx_byte) 
                              >> 7U)))) {
                    __Vdly__shrike_top__DOT__ld_tx = 1U;
                }
            } else {
                if (vlSelfRef.shrike_top__DOT__rw_wr) {
                    if ((0U == (3U & ((IData)(vlSelfRef.shrike_top__DOT__addr) 
                                      >> 5U)))) {
                        if (((0U == (0x0000001fU & (IData)(vlSelfRef.shrike_top__DOT__addr))) 
                             & (IData)(vlSelfRef.shrike_top__DOT__rx_byte))) {
                            vlSelfRef.shrike_top__DOT__start_q = 1U;
                        }
                    } else if ((1U == (3U & ((IData)(vlSelfRef.shrike_top__DOT__addr) 
                                             >> 5U)))) {
                        vlSelfRef.shrike_top__DOT__imem_we = 1U;
                        vlSelfRef.shrike_top__DOT__imem_wa 
                            = (0x0000001fU & (IData)(vlSelfRef.shrike_top__DOT__addr));
                        vlSelfRef.shrike_top__DOT__imem_wd 
                            = vlSelfRef.shrike_top__DOT__rx_byte;
                    } else if ((2U == (3U & ((IData)(vlSelfRef.shrike_top__DOT__addr) 
                                             >> 5U)))) {
                        vlSelfRef.shrike_top__DOT__hs_we = 1U;
                        vlSelfRef.shrike_top__DOT__hs_wa 
                            = (0x0000001fU & (IData)(vlSelfRef.shrike_top__DOT__addr));
                        vlSelfRef.shrike_top__DOT__hs_wd 
                            = vlSelfRef.shrike_top__DOT__rx_byte;
                    }
                } else {
                    __Vdly__shrike_top__DOT__ld_tx = 1U;
                }
                __Vdly__shrike_top__DOT__addr = (0x0000007fU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.shrike_top__DOT__addr)));
            }
        }
        if (vlSelfRef.shrike_top__DOT__ld_tx) {
            __Vdly__shrike_top__DOT__tx = (0x000000ffU 
                                           & ((0x00000040U 
                                               & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                               ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
                                               : ((0x00000020U 
                                                   & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                   ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
                                                   : 
                                                  ((0x00000010U 
                                                    & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                    ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                        ? 
                                                       ((IData)(vlSelfRef.shrike_top__DOT__conf) 
                                                        >> 8U)
                                                        : (IData)(vlSelfRef.shrike_top__DOT__conf))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                        ? 
                                                       ((IData)(vlSelfRef.shrike_top__DOT__lops) 
                                                        >> 8U)
                                                        : (IData)(vlSelfRef.shrike_top__DOT__lops)))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                        ? 
                                                       ((IData)(vlSelfRef.shrike_top__DOT__ins_c) 
                                                        >> 8U)
                                                        : (IData)(vlSelfRef.shrike_top__DOT__ins_c))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                        ? 
                                                       ((IData)(vlSelfRef.shrike_top__DOT__cyc) 
                                                        >> 8U)
                                                        : (IData)(vlSelfRef.shrike_top__DOT__cyc))))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                      ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                        ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
                                                        : 0xa5U)
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.shrike_top__DOT__addr))
                                                        ? 
                                                       (((IData)(vlSelfRef.shrike_top__DOT__busy) 
                                                         << 1U) 
                                                        | (IData)(vlSelfRef.shrike_top__DOT__done))
                                                        : (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)))))))));
            __Vdly__shrike_top__DOT__ld_tx = 0U;
        }
    }
    vlSelfRef.shrike_top__DOT__core__DOT__simm = ((0x000000e0U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlSelfRef.shrike_top__DOT__core__DOT__imem_lo
                                                                     [vlSelfRef.shrike_top__DOT__core__DOT__pc] 
                                                                     >> 4U)))) 
                                                      << 5U)) 
                                                  | (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5));
    vlSelfRef.shrike_top__DOT__byte_done = __Vdly__shrike_top__DOT__byte_done;
    vlSelfRef.shrike_top__DOT__ss_s = __Vdly__shrike_top__DOT__ss_s;
    vlSelfRef.shrike_top__DOT__bitcnt = __Vdly__shrike_top__DOT__bitcnt;
    vlSelfRef.shrike_top__DOT__first = __Vdly__shrike_top__DOT__first;
    vlSelfRef.shrike_top__DOT__ld_tx = __Vdly__shrike_top__DOT__ld_tx;
    vlSelfRef.shrike_top__DOT__sclk_s = __Vdly__shrike_top__DOT__sclk_s;
    vlSelfRef.shrike_top__DOT__mosi_s = __Vdly__shrike_top__DOT__mosi_s;
    vlSelfRef.shrike_top__DOT__rxsh = __Vdly__shrike_top__DOT__rxsh;
    vlSelfRef.shrike_top__DOT__rx_byte = __Vdly__shrike_top__DOT__rx_byte;
    vlSelfRef.shrike_top__DOT__rw_wr = __Vdly__shrike_top__DOT__rw_wr;
    vlSelfRef.shrike_top__DOT__conf = __Vdly__shrike_top__DOT__conf;
    vlSelfRef.shrike_top__DOT__lops = __Vdly__shrike_top__DOT__lops;
    vlSelfRef.shrike_top__DOT__ins_c = __Vdly__shrike_top__DOT__ins_c;
    vlSelfRef.shrike_top__DOT__cyc = __Vdly__shrike_top__DOT__cyc;
    vlSelfRef.shrike_top__DOT__busy = __Vdly__shrike_top__DOT__busy;
    vlSelfRef.shrike_top__DOT__done = __Vdly__shrike_top__DOT__done;
    vlSelfRef.shrike_top__DOT__tx = __Vdly__shrike_top__DOT__tx;
    vlSelfRef.shrike_top__DOT__addr = __Vdly__shrike_top__DOT__addr;
    vlSelfRef.led = vlSelfRef.shrike_top__DOT__done;
    vlSelfRef.miso = (1U & ((IData)(vlSelfRef.shrike_top__DOT__tx) 
                            >> 7U));
    vlSelfRef.shrike_top__DOT__hs_addr = (0x0000001fU 
                                          & ((IData)(vlSelfRef.shrike_top__DOT__hs_we)
                                              ? (IData)(vlSelfRef.shrike_top__DOT__hs_wa)
                                              : (IData)(vlSelfRef.shrike_top__DOT__addr)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = ((2U 
                                                 == 
                                                 (3U 
                                                  & ((IData)(vlSelfRef.shrike_top__DOT__addr) 
                                                     >> 5U)))
                                                 ? vlSelfRef.shrike_top__DOT__core__DOT__scr
                                                [vlSelfRef.shrike_top__DOT__hs_addr]
                                                 : 0U);
}

void Vshrike_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vshrike_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

#ifdef VL_DEBUG
void Vshrike_top___024root___eval_debug_assertions(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_debug_assertions\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.sclk & 0xfeU)))) {
        Verilated::overWidthError("sclk");
    }
    if (VL_UNLIKELY(((vlSelfRef.ss_n & 0xfeU)))) {
        Verilated::overWidthError("ss_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.mosi & 0xfeU)))) {
        Verilated::overWidthError("mosi");
    }
}
#endif  // VL_DEBUG
