// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vshrike_top.h for the primary calling header

#include "Vshrike_top__pch.h"

VL_ATTR_COLD void Vshrike_top___024root___eval_static(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_static\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__sclk__0 = vlSelfRef.sclk;
    vlSelfRef.__Vtrigprevexpr___TOP__ss_n__0 = vlSelfRef.ss_n;
    vlSelfRef.__Vtrigprevexpr___TOP__mosi__0 = vlSelfRef.mosi;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vshrike_top___024root___eval_initial(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_initial\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSelfRef.clk_en = 1U;
        vlSelfRef.miso_en = 1U;
        vlSelfRef.led_en = 1U;
        vlSelfRef.shrike_top__DOT__rst_sr = 0x0fU;
        vlSelfRef.shrike_top__DOT__sclk_s = 0U;
        vlSelfRef.shrike_top__DOT__ss_s = 3U;
        vlSelfRef.shrike_top__DOT__mosi_s = 0U;
        vlSelfRef.shrike_top__DOT__bitcnt = 0U;
        vlSelfRef.shrike_top__DOT__first = 1U;
        vlSelfRef.shrike_top__DOT__tx = 0U;
        vlSelfRef.shrike_top__DOT__byte_done = 0U;
        vlSelfRef.shrike_top__DOT__ld_tx = 0U;
        vlSelfRef.shrike_top__DOT__rw_wr = 0U;
        vlSelfRef.shrike_top__DOT__addr = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshrike_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vshrike_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

VL_ATTR_COLD bool Vshrike_top___024root___eval_stl(Vshrike_top___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_stl\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vshrike_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vshrike_top___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                {
                    // Inlined CFunc: _stl_sequent__TOP__0
                    vlSelfRef.miso = (1U & ((IData)(vlSelfRef.shrike_top__DOT__tx) 
                                            >> 7U));
                    vlSelfRef.led = vlSelfRef.shrike_top__DOT__done;
                    vlSelfRef.shrike_top__DOT__core__DOT__op 
                        = (0x0000001fU & (vlSelfRef.shrike_top__DOT__core__DOT__imem_hi
                                          [vlSelfRef.shrike_top__DOT__core__DOT__pc] 
                                          >> 3U));
                    vlSelfRef.shrike_top__DOT__core__DOT__rd 
                        = (7U & vlSelfRef.shrike_top__DOT__core__DOT__imem_hi
                           [vlSelfRef.shrike_top__DOT__core__DOT__pc]);
                    vlSelfRef.shrike_top__DOT__core__DOT__rs1 
                        = (7U & (vlSelfRef.shrike_top__DOT__core__DOT__imem_lo
                                 [vlSelfRef.shrike_top__DOT__core__DOT__pc] 
                                 >> 5U));
                    vlSelfRef.shrike_top__DOT__core__DOT__rs2 
                        = (7U & (vlSelfRef.shrike_top__DOT__core__DOT__imem_lo
                                 [vlSelfRef.shrike_top__DOT__core__DOT__pc] 
                                 >> 2U));
                    vlSelfRef.shrike_top__DOT__core__DOT__imm5 
                        = (0x0000001fU & vlSelfRef.shrike_top__DOT__core__DOT__imem_lo
                           [vlSelfRef.shrike_top__DOT__core__DOT__pc]);
                    vlSelfRef.shrike_top__DOT__hs_addr 
                        = (0x0000001fU & ((IData)(vlSelfRef.shrike_top__DOT__hs_we)
                                           ? (IData)(vlSelfRef.shrike_top__DOT__hs_wa)
                                           : (IData)(vlSelfRef.shrike_top__DOT__addr)));
                    vlSelfRef.shrike_top__DOT__core__DOT__simm 
                        = ((0x000000e0U & ((- (IData)(
                                                      (1U 
                                                       & (vlSelfRef.shrike_top__DOT__core__DOT__imem_lo
                                                          [vlSelfRef.shrike_top__DOT__core__DOT__pc] 
                                                          >> 4U)))) 
                                           << 5U)) 
                           | (IData)(vlSelfRef.shrike_top__DOT__core__DOT__imm5));
                    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 
                        = ((2U == (3U & ((IData)(vlSelfRef.shrike_top__DOT__addr) 
                                         >> 5U))) ? vlSelfRef.shrike_top__DOT__core__DOT__scr
                           [vlSelfRef.shrike_top__DOT__hs_addr]
                            : 0U);
                }
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__stl(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_dump_triggers__stl\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vshrike_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshrike_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__ico(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_dump_triggers__ico\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vshrike_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshrike_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__act(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_dump_triggers__act\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vshrike_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__nba(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_dump_triggers__nba\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vshrike_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__obs(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_dump_triggers__obs\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__react(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_dump_triggers__react\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vshrike_top___024root___eval_final(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___eval_final\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshrike_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vshrike_top___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vshrike_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___trigger_anySet__stl\n"); );
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

bool Vshrike_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshrike_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vshrike_top___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( sclk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( ss_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( mosi)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vshrike_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshrike_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vshrike_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vshrike_top___024root___ctor_var_reset(Vshrike_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshrike_top___024root___ctor_var_reset\n"); );
    Vshrike_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->clk_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14950377490721119492ull);
    vlSelf->sclk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5674544339920726298ull);
    vlSelf->ss_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9458769220082243902ull);
    vlSelf->mosi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11760532154298914343ull);
    vlSelf->miso = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4240847957141628474ull);
    vlSelf->miso_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1245286851380486716ull);
    vlSelf->led = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14009161575225144129ull);
    vlSelf->led_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16250859764279730157ull);
    vlSelf->shrike_top__DOT__rst_sr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14824527436350534684ull);
    vlSelf->shrike_top__DOT__sclk_s = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3113096343219409598ull);
    vlSelf->shrike_top__DOT__ss_s = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4845451066440169811ull);
    vlSelf->shrike_top__DOT__mosi_s = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9340808788819842858ull);
    vlSelf->shrike_top__DOT__start_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9150304077925106275ull);
    vlSelf->shrike_top__DOT__imem_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1259644075423664433ull);
    vlSelf->shrike_top__DOT__hs_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16727435732905036458ull);
    vlSelf->shrike_top__DOT__imem_wa = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12607777915825920692ull);
    vlSelf->shrike_top__DOT__hs_wa = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6632334386318835441ull);
    vlSelf->shrike_top__DOT__imem_wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9668803865545745310ull);
    vlSelf->shrike_top__DOT__hs_wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15913236205419551903ull);
    vlSelf->shrike_top__DOT__addr = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 5614558097338895380ull);
    vlSelf->shrike_top__DOT__hs_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1519800356756716233ull);
    vlSelf->shrike_top__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17885436855419624790ull);
    vlSelf->shrike_top__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9284462835155477849ull);
    vlSelf->shrike_top__DOT__cyc = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6203495114271110901ull);
    vlSelf->shrike_top__DOT__ins_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4736038687689674133ull);
    vlSelf->shrike_top__DOT__lops = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4050354498921320653ull);
    vlSelf->shrike_top__DOT__conf = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4348636191718020732ull);
    vlSelf->shrike_top__DOT__bitcnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3627300948701466781ull);
    vlSelf->shrike_top__DOT__rxsh = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15393752183700889434ull);
    vlSelf->shrike_top__DOT__rx_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2316245786423157734ull);
    vlSelf->shrike_top__DOT__tx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6674913303121829593ull);
    vlSelf->shrike_top__DOT__byte_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4654787860354271165ull);
    vlSelf->shrike_top__DOT__first = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10608537712574429943ull);
    vlSelf->shrike_top__DOT__rw_wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9815053007062322457ull);
    vlSelf->shrike_top__DOT__ld_tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11887305477456615596ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->shrike_top__DOT__core__DOT__imem_lo[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5357912013929209443ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->shrike_top__DOT__core__DOT__imem_hi[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3439810639538115087ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->shrike_top__DOT__core__DOT__scr[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3078065561984414547ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->shrike_top__DOT__core__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8042793371311204489ull);
    }
    vlSelf->shrike_top__DOT__core__DOT__pc = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14941644502403079991ull);
    vlSelf->shrike_top__DOT__core__DOT__loop_pc = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17388370445809471858ull);
    vlSelf->shrike_top__DOT__core__DOT__loop_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12717335174093834118ull);
    vlSelf->shrike_top__DOT__core__DOT__mask = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17530375689740219854ull);
    vlSelf->shrike_top__DOT__core__DOT__smask = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7984570368487555277ull);
    vlSelf->shrike_top__DOT__core__DOT__pred = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4156473043513867152ull);
    vlSelf->shrike_top__DOT__core__DOT__pend = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1419107540666458862ull);
    vlSelf->shrike_top__DOT__core__DOT__pend_v = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17896255110185223864ull);
    vlSelf->shrike_top__DOT__core__DOT__op = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11947841640987675781ull);
    vlSelf->shrike_top__DOT__core__DOT__rd = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3646674939491525203ull);
    vlSelf->shrike_top__DOT__core__DOT__rs1 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6698295324135069993ull);
    vlSelf->shrike_top__DOT__core__DOT__rs2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9258221158597403232ull);
    vlSelf->shrike_top__DOT__core__DOT__imm5 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 308827785609039710ull);
    vlSelf->shrike_top__DOT__core__DOT__simm = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9161251328965333330ull);
    vlSelf->shrike_top__DOT__core__DOT__pop = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 19118471802128493ull);
    vlSelf->shrike_top__DOT__core__DOT__a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14209739067261503742ull);
    vlSelf->shrike_top__DOT__core__DOT__b = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2249573876477110647ull);
    vlSelf->shrike_top__DOT__core__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11383346732080968978ull);
    vlSelf->shrike_top__DOT__core__DOT__res = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5431770101142458532ull);
    vlSelf->shrike_top__DOT__core__DOT__ad8 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5339197334123082285ull);
    vlSelf->shrike_top__DOT__core__DOT__prod = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16593409934606593493ull);
    vlSelf->shrike_top__DOT__core__DOT__ad = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14488285847833588757ull);
    vlSelf->shrike_top__DOT__core__DOT__ba0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2059165360562576967ull);
    vlSelf->shrike_top__DOT__core__DOT__ba1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16668789236373127168ull);
    vlSelf->shrike_top__DOT__core__DOT__bt0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8434639229113764251ull);
    vlSelf->shrike_top__DOT__core__DOT__bt1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2730460678003522703ull);
    vlSelf->shrike_top__DOT__core__DOT__bk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12547724296272206970ull);
    vlSelf->shrike_top__DOT__core__DOT__served = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13348579638677597537ull);
    vlSelf->shrike_top__DOT__core__DOT__complete = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12426458367768134732ull);
    vlSelf->shrike_top__DOT__core__DOT__req = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3250849261098089975ull);
    vlSelf->shrike_top__DOT__core__DOT__defer = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6591934106728389633ull);
    vlSelf->shrike_top__DOT__core__DOT__next_pc = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17429169060161889807ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__sclk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ss_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__mosi__0 = 0;
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
