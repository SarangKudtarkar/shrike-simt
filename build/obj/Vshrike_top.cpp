// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vshrike_top__pch.h"

//============================================================
// Constructors

Vshrike_top::Vshrike_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vshrike_top__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , clk{vlSymsp->TOP.clk}
    , clk_en{vlSymsp->TOP.clk_en}
    , sclk{vlSymsp->TOP.sclk}
    , ss_n{vlSymsp->TOP.ss_n}
    , mosi{vlSymsp->TOP.mosi}
    , miso{vlSymsp->TOP.miso}
    , miso_en{vlSymsp->TOP.miso_en}
    , led{vlSymsp->TOP.led}
    , led_en{vlSymsp->TOP.led_en}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vshrike_top::Vshrike_top(const char* _vcname__)
    : Vshrike_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vshrike_top::~Vshrike_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vshrike_top___024root___eval_debug_assertions(Vshrike_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vshrike_top___024root___eval_static(Vshrike_top___024root* vlSelf);
VL_ATTR_COLD void Vshrike_top___024root___eval_initial(Vshrike_top___024root* vlSelf);
VL_ATTR_COLD bool Vshrike_top___024root___eval_stl(Vshrike_top___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vshrike_top___024root___eval_sample(Vshrike_top___024root* vlSelf);
bool Vshrike_top___024root___eval_ico(Vshrike_top___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vshrike_top___024root___eval_act(Vshrike_top___024root* vlSelf);
bool Vshrike_top___024root___eval_inact(Vshrike_top___024root* vlSelf);
bool Vshrike_top___024root___eval_nba(Vshrike_top___024root* vlSelf);
bool Vshrike_top___024root___eval_obs(Vshrike_top___024root* vlSelf);
bool Vshrike_top___024root___eval_react(Vshrike_top___024root* vlSelf);
void Vshrike_top___024root___eval_postponed(Vshrike_top___024root* vlSelf);
VL_ATTR_COLD void Vshrike_top___024root___eval_final(Vshrike_top___024root* vlSelf);
VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__stl(Vshrike_top___024root* vlSelf);
VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__ico(Vshrike_top___024root* vlSelf);
VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__act(Vshrike_top___024root* vlSelf);
VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__nba(Vshrike_top___024root* vlSelf);
VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__obs(Vshrike_top___024root* vlSelf);
VL_ATTR_COLD void Vshrike_top___024root___eval_dump_triggers__react(Vshrike_top___024root* vlSelf);

void Vshrike_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vshrike_top::eval_step\n"); );
    m_evalLoop.eval();
}

void Vshrike_top::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vshrike_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vshrike_top::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vshrike_top::evalStatic() {
    Vshrike_top___024root___eval_static(&(vlSymsp->TOP));
}

void Vshrike_top::evalInitial() {
    Vshrike_top___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vshrike_top::evalStl(bool firstIteration) {
    return Vshrike_top___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vshrike_top::evalSample() {
    Vshrike_top___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vshrike_top::evalIco(bool firstIteration) {
    return Vshrike_top___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vshrike_top::evalAct() {
    return Vshrike_top___024root___eval_act(&(vlSymsp->TOP));
}

bool Vshrike_top::evalInact() {
    return Vshrike_top___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vshrike_top::evalNba() {
    return Vshrike_top___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vshrike_top::evalObs() {
    return Vshrike_top___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vshrike_top::evalReact() {
    return Vshrike_top___024root___eval_react(&(vlSymsp->TOP));
}

void Vshrike_top::evalPostponed() {
    Vshrike_top___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vshrike_top::evalFinal() {
    Vshrike_top___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vshrike_top::dumpTriggersStl() {
    Vshrike_top___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vshrike_top::dumpTriggersIco() {
    Vshrike_top___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vshrike_top::dumpTriggersAct() {
    Vshrike_top___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vshrike_top::dumpTriggersNba() {
    Vshrike_top___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vshrike_top::dumpTriggersObs() {
    Vshrike_top___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vshrike_top::dumpTriggersReact() {
    Vshrike_top___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vshrike_top::eventsPending() { return false; }

uint64_t Vshrike_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vshrike_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vshrike_top::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vshrike_top::hierName() const { return vlSymsp->name(); }
const char* Vshrike_top::modelName() const { return "Vshrike_top"; }
unsigned Vshrike_top::threads() const { return 1; }
void Vshrike_top::prepareClone() const { contextp()->prepareClone(); }
void Vshrike_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
