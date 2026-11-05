// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSHRIKE_TOP__SYMS_H_
#define VERILATED_VSHRIKE_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vshrike_top.h"

// INCLUDE MODULE CLASSES
#include "Vshrike_top___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vshrike_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vshrike_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    Vshrike_top___024root          TOP;

    // CONSTRUCTORS
    Vshrike_top__Syms(VerilatedContext* contextp, const char* namep, Vshrike_top* modelp);
    ~Vshrike_top__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
