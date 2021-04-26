// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated_heavy.h"

class Vtop__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(i_clk,0,0);
    VL_IN8(i_reset,0,0);
    VL_IN8(i_start,0,0);
    VL_OUT8(o_valid,0,0);
    VL_OUT(o_datax,31,0);
    VL_OUT(o_datay,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(top__DOT__diff2d_inst__DOT__column_counter,5,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__fifo_counter,5,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__counter_en,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__column_en,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__r_DyValid,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__r_DxValid,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__DyOp1_en,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__DyOp2_en,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__datay_en,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__datax_en,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__FIFO_rd,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__r_bussy,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__state,3,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__f0__DOT__w_wr,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__f0__DOT__w_rd,0,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr,6,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr,6,0);
    VL_SIG8(top__DOT__diff2d_inst__DOT__f0__DOT__o_fill,6,0);
    VL_SIG16(top__DOT__diff2d_inst__DOT__counter,11,0);
    VL_SIG16(top__DOT__diff2d_inst__DOT__w_DxAddr,11,0);
    VL_SIG(top__DOT__w_data,31,0);
    VL_SIG(top__DOT__diff2d_inst__DOT__r_datax,31,0);
    VL_SIG(top__DOT__diff2d_inst__DOT__r_datay,31,0);
    VL_SIG(top__DOT__diff2d_inst__DOT__r_DyOp1,31,0);
    VL_SIG(top__DOT__diff2d_inst__DOT__r_DyOp2,31,0);
    VL_SIG(top__DOT__diff2d_inst__DOT__r_DyOp0,31,0);
    VL_SIG(top__DOT__diff2d_inst__DOT__r_OutFIFO,31,0);
    VL_SIG(top__DOT__rom_int__DOT__memory[4096],31,0);
    VL_SIG(top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem[64],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    static VL_ST_SIG8(__Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[16],0,0);
    static VL_ST_SIG8(__Vtable1_top__DOT__diff2d_inst__DOT__counter_en[16],0,0);
    static VL_ST_SIG8(__Vtable1_top__DOT__diff2d_inst__DOT__column_en[16],0,0);
    static VL_ST_SIG8(__Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[16],0,0);
    static VL_ST_SIG8(__Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[16],0,0);
    static VL_ST_SIG8(__Vtable1_top__DOT__diff2d_inst__DOT__datay_en[16],0,0);
    static VL_ST_SIG8(__Vtable1_top__DOT__diff2d_inst__DOT__datax_en[16],0,0);
    static VL_ST_SIG8(__Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[16],0,0);
    VL_SIG8(__Vtableidx1,3,0);
    VL_SIG8(__Vclklast__TOP__i_clk,0,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vtop& operator= (const Vtop&);  ///< Copying not allowed
    Vtop(const Vtop&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vtop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void _initial__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
