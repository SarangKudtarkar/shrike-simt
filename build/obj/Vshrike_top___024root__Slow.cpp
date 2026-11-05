// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vshrike_top.h for the primary calling header

#include "Vshrike_top__pch.h"

void Vshrike_top___024root___ctor_var_reset(Vshrike_top___024root* vlSelf);

Vshrike_top___024root::Vshrike_top___024root(Vshrike_top__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vshrike_top___024root___ctor_var_reset(this);
}

void Vshrike_top___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vshrike_top___024root::~Vshrike_top___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
