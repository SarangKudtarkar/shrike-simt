// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vshrike_top.h for the primary calling header

#ifndef VERILATED_VSHRIKE_TOP___024ROOT_H_
#define VERILATED_VSHRIKE_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vshrike_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vshrike_top___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_OUT8(clk_en,0,0);
        VL_IN8(sclk,0,0);
        VL_IN8(ss_n,0,0);
        VL_IN8(mosi,0,0);
        VL_OUT8(miso,0,0);
        VL_OUT8(miso_en,0,0);
        VL_OUT8(led,0,0);
        VL_OUT8(led_en,0,0);
        CData/*3:0*/ shrike_top__DOT__rst_sr;
        CData/*2:0*/ shrike_top__DOT__sclk_s;
        CData/*1:0*/ shrike_top__DOT__ss_s;
        CData/*1:0*/ shrike_top__DOT__mosi_s;
        CData/*0:0*/ shrike_top__DOT__start_q;
        CData/*0:0*/ shrike_top__DOT__imem_we;
        CData/*0:0*/ shrike_top__DOT__hs_we;
        CData/*4:0*/ shrike_top__DOT__imem_wa;
        CData/*4:0*/ shrike_top__DOT__hs_wa;
        CData/*7:0*/ shrike_top__DOT__imem_wd;
        CData/*7:0*/ shrike_top__DOT__hs_wd;
        CData/*6:0*/ shrike_top__DOT__addr;
        CData/*4:0*/ shrike_top__DOT__hs_addr;
        CData/*0:0*/ shrike_top__DOT__busy;
        CData/*0:0*/ shrike_top__DOT__done;
        CData/*2:0*/ shrike_top__DOT__bitcnt;
        CData/*7:0*/ shrike_top__DOT__rxsh;
        CData/*7:0*/ shrike_top__DOT__rx_byte;
        CData/*7:0*/ shrike_top__DOT__tx;
        CData/*0:0*/ shrike_top__DOT__byte_done;
        CData/*0:0*/ shrike_top__DOT__first;
        CData/*0:0*/ shrike_top__DOT__rw_wr;
        CData/*0:0*/ shrike_top__DOT__ld_tx;
        CData/*3:0*/ shrike_top__DOT__core__DOT__pc;
        CData/*3:0*/ shrike_top__DOT__core__DOT__loop_pc;
        CData/*4:0*/ shrike_top__DOT__core__DOT__loop_cnt;
        CData/*1:0*/ shrike_top__DOT__core__DOT__mask;
        CData/*1:0*/ shrike_top__DOT__core__DOT__smask;
        CData/*1:0*/ shrike_top__DOT__core__DOT__pred;
        CData/*1:0*/ shrike_top__DOT__core__DOT__pend;
        CData/*0:0*/ shrike_top__DOT__core__DOT__pend_v;
        CData/*4:0*/ shrike_top__DOT__core__DOT__op;
        CData/*2:0*/ shrike_top__DOT__core__DOT__rd;
        CData/*2:0*/ shrike_top__DOT__core__DOT__rs1;
        CData/*2:0*/ shrike_top__DOT__core__DOT__rs2;
        CData/*4:0*/ shrike_top__DOT__core__DOT__imm5;
        CData/*7:0*/ shrike_top__DOT__core__DOT__simm;
        CData/*7:0*/ shrike_top__DOT__core__DOT__a;
        CData/*7:0*/ shrike_top__DOT__core__DOT__b;
        CData/*7:0*/ shrike_top__DOT__core__DOT__d;
        CData/*7:0*/ shrike_top__DOT__core__DOT__res;
        CData/*7:0*/ shrike_top__DOT__core__DOT__ad8;
        CData/*4:0*/ shrike_top__DOT__core__DOT__ad;
        CData/*4:0*/ shrike_top__DOT__core__DOT__ba0;
        CData/*4:0*/ shrike_top__DOT__core__DOT__ba1;
        CData/*0:0*/ shrike_top__DOT__core__DOT__bt0;
        CData/*0:0*/ shrike_top__DOT__core__DOT__bt1;
        CData/*0:0*/ shrike_top__DOT__core__DOT__bk;
        CData/*0:0*/ shrike_top__DOT__core__DOT__served;
        CData/*0:0*/ shrike_top__DOT__core__DOT__complete;
        CData/*1:0*/ shrike_top__DOT__core__DOT__req;
        CData/*1:0*/ shrike_top__DOT__core__DOT__defer;
        CData/*3:0*/ shrike_top__DOT__core__DOT__next_pc;
        CData/*7:0*/ __VdfgRegularize_h6e95ff9d_0_0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    };
    struct {
        CData/*0:0*/ __Vtrigprevexpr___TOP__sclk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__ss_n__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__mosi__0;
        CData/*0:0*/ __VicoDidInit;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
        SData/*15:0*/ shrike_top__DOT__cyc;
        SData/*15:0*/ shrike_top__DOT__ins_c;
        SData/*15:0*/ shrike_top__DOT__lops;
        SData/*15:0*/ shrike_top__DOT__conf;
        SData/*15:0*/ shrike_top__DOT__core__DOT__prod;
        IData/*31:0*/ shrike_top__DOT__core__DOT__pop;
        VlUnpacked<CData/*7:0*/, 16> shrike_top__DOT__core__DOT__imem_lo;
        VlUnpacked<CData/*7:0*/, 16> shrike_top__DOT__core__DOT__imem_hi;
        VlUnpacked<CData/*7:0*/, 32> shrike_top__DOT__core__DOT__scr;
        VlUnpacked<CData/*7:0*/, 16> shrike_top__DOT__core__DOT__rf;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vshrike_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vshrike_top___024root(Vshrike_top__Syms* symsp, const char* namep);
    ~Vshrike_top___024root();
    VL_UNCOPYABLE(Vshrike_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
