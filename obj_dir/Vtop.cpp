// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"


//--------------------
// STATIC VARIABLES

VL_ST_SIG8(Vtop::__Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[16],0,0);
VL_ST_SIG8(Vtop::__Vtable1_top__DOT__diff2d_inst__DOT__counter_en[16],0,0);
VL_ST_SIG8(Vtop::__Vtable1_top__DOT__diff2d_inst__DOT__column_en[16],0,0);
VL_ST_SIG8(Vtop::__Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[16],0,0);
VL_ST_SIG8(Vtop::__Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[16],0,0);
VL_ST_SIG8(Vtop::__Vtable1_top__DOT__diff2d_inst__DOT__datay_en[16],0,0);
VL_ST_SIG8(Vtop::__Vtable1_top__DOT__diff2d_inst__DOT__datax_en[16],0,0);
VL_ST_SIG8(Vtop::__Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[16],0,0);

//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__top__DOT__diff2d_inst__DOT__column_counter,5,0);
    VL_SIG8(__Vdly__top__DOT__diff2d_inst__DOT__fifo_counter,5,0);
    VL_SIG8(__Vdly__top__DOT__diff2d_inst__DOT__state,3,0);
    VL_SIG8(__Vdly__top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr,6,0);
    VL_SIG8(__Vdly__top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr,6,0);
    VL_SIG8(__Vdlyvdim0__top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem__v0,5,0);
    VL_SIG8(__Vdlyvset__top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem__v0,0,0);
    VL_SIG16(__Vdly__top__DOT__diff2d_inst__DOT__counter,11,0);
    VL_SIG16(__Vdly__top__DOT__diff2d_inst__DOT__w_DxAddr,11,0);
    VL_SIG(__Vdlyvval__top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem__v0,31,0);
    // Body
    __Vdly__top__DOT__diff2d_inst__DOT__counter = vlTOPp->top__DOT__diff2d_inst__DOT__counter;
    __Vdly__top__DOT__diff2d_inst__DOT__fifo_counter 
	= vlTOPp->top__DOT__diff2d_inst__DOT__fifo_counter;
    __Vdly__top__DOT__diff2d_inst__DOT__w_DxAddr = vlTOPp->top__DOT__diff2d_inst__DOT__w_DxAddr;
    __Vdly__top__DOT__diff2d_inst__DOT__column_counter 
	= vlTOPp->top__DOT__diff2d_inst__DOT__column_counter;
    __Vdly__top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr 
	= vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr;
    __Vdly__top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr 
	= vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr;
    __Vdlyvset__top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem__v0 = 0U;
    __Vdly__top__DOT__diff2d_inst__DOT__state = vlTOPp->top__DOT__diff2d_inst__DOT__state;
    // ALWAYS at rtl/diff2d.v:318
    vlTOPp->top__DOT__diff2d_inst__DOT__r_DyValid = vlTOPp->top__DOT__diff2d_inst__DOT__datay_en;
    // ALWAYS at rtl/diff2d.v:73
    if (vlTOPp->top__DOT__diff2d_inst__DOT__counter_en) {
	__Vdly__top__DOT__diff2d_inst__DOT__counter 
	    = (0xfffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__counter)));
    }
    // ALWAYS at rtl/diff2d.v:83
    if (vlTOPp->top__DOT__diff2d_inst__DOT__DyOp1_en) {
	__Vdly__top__DOT__diff2d_inst__DOT__fifo_counter 
	    = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__fifo_counter)));
    }
    // ALWAYS at rtl/diff2d.v:89
    if (vlTOPp->top__DOT__diff2d_inst__DOT__datax_en) {
	__Vdly__top__DOT__diff2d_inst__DOT__w_DxAddr 
	    = (0xfffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__w_DxAddr)));
    }
    // ALWAYS at rtl/diff2d.v:78
    if (vlTOPp->top__DOT__diff2d_inst__DOT__column_en) {
	__Vdly__top__DOT__diff2d_inst__DOT__column_counter 
	    = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__column_counter)));
    }
    // ALWAYS at rtl/diff2d.v:318
    vlTOPp->top__DOT__diff2d_inst__DOT__r_DxValid = vlTOPp->top__DOT__diff2d_inst__DOT__datax_en;
    // ALWAYS at rtl/fifo.v:56
    if (vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_wr) {
	__Vdly__top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr 
	    = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr)));
    }
    // ALWAYS at rtl/fifo.v:56
    if (vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_rd) {
	__Vdly__top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr 
	    = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr)));
    }
    // ALWAYS at rtl/fifo.v:63
    if (vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_wr) {
	__Vdlyvval__top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem__v0 
	    = vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp1;
	__Vdlyvset__top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem__v0 = 1U;
	__Vdlyvdim0__top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem__v0 
	    = (0x3fU & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr));
    }
    // ALWAYS at rtl/diff2d.v:68
    if (vlTOPp->top__DOT__diff2d_inst__DOT__datax_en) {
	vlTOPp->top__DOT__diff2d_inst__DOT__r_datax 
	    = (vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp1 
	       - vlTOPp->top__DOT__diff2d_inst__DOT__r_OutFIFO);
    }
    // ALWAYS at rtl/diff2d.v:111
    __Vdly__top__DOT__diff2d_inst__DOT__state = ((IData)(vlTOPp->i_reset)
						  ? 0U
						  : 
						 ((8U 
						   & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						   ? 
						  ((4U 
						    & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						    ? 0U
						    : 
						   ((2U 
						     & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						      ? 0xcU
						      : 
						     ((0x3fU 
						       == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__column_counter))
						       ? 0xbU
						       : 0xaU))
						     : 
						    ((1U 
						      & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						      ? 0xaU
						      : 9U)))
						   : 
						  ((4U 
						    & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						      ? 
						     ((0xfffU 
						       == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__counter))
						       ? 8U
						       : 7U)
						      : 7U)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						      ? 6U
						      : 
						     ((0x3fU 
						       == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__fifo_counter))
						       ? 5U
						       : 4U)))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						      ? 4U
						      : 3U)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__state))
						      ? 2U
						      : 
						     ((IData)(vlTOPp->i_start)
						       ? 1U
						       : 0U))))));
    // ALWAYS at rtl/diff2d.v:64
    if (vlTOPp->top__DOT__diff2d_inst__DOT__datay_en) {
	vlTOPp->top__DOT__diff2d_inst__DOT__r_datay 
	    = (((0x3fU == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__column_counter))
		 ? vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp0
		 : vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp1) 
	       - vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp2);
    }
    vlTOPp->top__DOT__diff2d_inst__DOT__w_DxAddr = __Vdly__top__DOT__diff2d_inst__DOT__w_DxAddr;
    vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr 
	= __Vdly__top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr;
    vlTOPp->top__DOT__diff2d_inst__DOT__fifo_counter 
	= __Vdly__top__DOT__diff2d_inst__DOT__fifo_counter;
    vlTOPp->top__DOT__diff2d_inst__DOT__state = __Vdly__top__DOT__diff2d_inst__DOT__state;
    vlTOPp->o_valid = vlTOPp->top__DOT__diff2d_inst__DOT__r_DxValid;
    vlTOPp->o_datax = vlTOPp->top__DOT__diff2d_inst__DOT__r_datax;
    // ALWAYS at rtl/fifo.v:63
    if (vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_rd) {
	vlTOPp->top__DOT__diff2d_inst__DOT__r_OutFIFO 
	    = vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem
	    [(0x3fU & (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr))];
    }
    vlTOPp->o_datay = vlTOPp->top__DOT__diff2d_inst__DOT__r_datay;
    // ALWAYS at rtl/diff2d.v:48
    if ((0x3fU == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__column_counter))) {
	vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp0 
	    = vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp1;
    }
    // ALWAYS at rtl/diff2d.v:52
    if (vlTOPp->top__DOT__diff2d_inst__DOT__DyOp2_en) {
	vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp2 
	    = vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp1;
    }
    // ALWAYSPOST at rtl/fifo.v:64
    if (__Vdlyvset__top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem__v0) {
	vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem[__Vdlyvdim0__top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem__v0] 
	    = __Vdlyvval__top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem__v0;
    }
    vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr 
	= __Vdly__top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr;
    vlTOPp->top__DOT__diff2d_inst__DOT__column_counter 
	= __Vdly__top__DOT__diff2d_inst__DOT__column_counter;
    // ALWAYS at rtl/fifo.v:71
    vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill 
	= (0x7fU & ((IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr) 
		    - (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr)));
    // ALWAYS at rtl/diff2d.v:44
    if (vlTOPp->top__DOT__diff2d_inst__DOT__DyOp1_en) {
	vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp1 
	    = vlTOPp->top__DOT__w_data;
    }
    // ALWAYS at rtl/diff2d.v:173
    vlTOPp->__Vtableidx1 = vlTOPp->top__DOT__diff2d_inst__DOT__state;
    vlTOPp->top__DOT__diff2d_inst__DOT__r_bussy = vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__r_bussy
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__counter_en 
	= vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__counter_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__column_en = 
	vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__column_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__DyOp1_en = 
	vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__DyOp2_en = 
	vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__datay_en = 
	vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__datay_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__datax_en = 
	vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__datax_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__FIFO_rd = vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd
	[vlTOPp->__Vtableidx1];
    // ALWAYS at rtl/rom.v:14
    vlTOPp->top__DOT__w_data = vlTOPp->top__DOT__rom_int__DOT__memory
	[vlTOPp->top__DOT__diff2d_inst__DOT__counter];
    vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_wr 
	= ((IData)(vlTOPp->top__DOT__diff2d_inst__DOT__DyOp2_en) 
	   & (0x40U != (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill)));
    vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_rd 
	= ((IData)(vlTOPp->top__DOT__diff2d_inst__DOT__FIFO_rd) 
	   & (0U != (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill)));
    vlTOPp->top__DOT__diff2d_inst__DOT__counter = __Vdly__top__DOT__diff2d_inst__DOT__counter;
}

void Vtop::_initial__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp1,159,0,5);
    // Body
    // INITIAL at rtl/fifo.v:53
    vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr = 0U;
    // INITIAL at rtl/diff2d.v:110
    vlTOPp->top__DOT__diff2d_inst__DOT__state = 0U;
    // INITIAL at rtl/fifo.v:52
    vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr = 0U;
    // INITIAL at rtl/rom.v:9
    VL_WRITEF("Creating rom_sync from init file 'U_fixed_point.mem'.\n");
    __Vtemp1[0U] = 0x2e6d656dU;
    __Vtemp1[1U] = 0x6f696e74U;
    __Vtemp1[2U] = 0x65645f70U;
    __Vtemp1[3U] = 0x5f666978U;
    __Vtemp1[4U] = 0x55U;
    VL_READMEM_W (true,32,4096, 0,5, __Vtemp1, vlTOPp->top__DOT__rom_int__DOT__memory
		  ,0,~0);
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_valid = vlTOPp->top__DOT__diff2d_inst__DOT__r_DxValid;
    vlTOPp->o_datax = vlTOPp->top__DOT__diff2d_inst__DOT__r_datax;
    vlTOPp->o_datay = vlTOPp->top__DOT__diff2d_inst__DOT__r_datay;
    // ALWAYS at rtl/diff2d.v:173
    vlTOPp->__Vtableidx1 = vlTOPp->top__DOT__diff2d_inst__DOT__state;
    vlTOPp->top__DOT__diff2d_inst__DOT__r_bussy = vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__r_bussy
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__counter_en 
	= vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__counter_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__column_en = 
	vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__column_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__DyOp1_en = 
	vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__DyOp2_en = 
	vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__datay_en = 
	vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__datay_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__datax_en = 
	vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__datax_en
	[vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__diff2d_inst__DOT__FIFO_rd = vlTOPp->__Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd
	[vlTOPp->__Vtableidx1];
    // ALWAYS at rtl/fifo.v:71
    vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill 
	= (0x7fU & ((IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr) 
		    - (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr)));
    vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_wr 
	= ((IData)(vlTOPp->top__DOT__diff2d_inst__DOT__DyOp2_en) 
	   & (0x40U != (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill)));
    vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_rd 
	= ((IData)(vlTOPp->top__DOT__diff2d_inst__DOT__FIFO_rd) 
	   & (0U != (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill)));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
	Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((i_reset & 0xfeU))) {
	Verilated::overWidthError("i_reset");}
    if (VL_UNLIKELY((i_start & 0xfeU))) {
	Verilated::overWidthError("i_start");}
}
#endif // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    i_clk = VL_RAND_RESET_I(1);
    i_reset = VL_RAND_RESET_I(1);
    i_start = VL_RAND_RESET_I(1);
    o_valid = VL_RAND_RESET_I(1);
    o_datax = VL_RAND_RESET_I(32);
    o_datay = VL_RAND_RESET_I(32);
    top__DOT__w_data = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
	    top__DOT__rom_int__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top__DOT__diff2d_inst__DOT__r_datax = VL_RAND_RESET_I(32);
    top__DOT__diff2d_inst__DOT__r_datay = VL_RAND_RESET_I(32);
    top__DOT__diff2d_inst__DOT__r_DyOp1 = VL_RAND_RESET_I(32);
    top__DOT__diff2d_inst__DOT__r_DyOp2 = VL_RAND_RESET_I(32);
    top__DOT__diff2d_inst__DOT__r_DyOp0 = VL_RAND_RESET_I(32);
    top__DOT__diff2d_inst__DOT__r_OutFIFO = VL_RAND_RESET_I(32);
    top__DOT__diff2d_inst__DOT__counter = VL_RAND_RESET_I(12);
    top__DOT__diff2d_inst__DOT__w_DxAddr = VL_RAND_RESET_I(12);
    top__DOT__diff2d_inst__DOT__column_counter = VL_RAND_RESET_I(6);
    top__DOT__diff2d_inst__DOT__fifo_counter = VL_RAND_RESET_I(6);
    top__DOT__diff2d_inst__DOT__counter_en = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__column_en = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__r_DyValid = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__r_DxValid = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__DyOp1_en = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__DyOp2_en = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__datay_en = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__datax_en = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__FIFO_rd = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__r_bussy = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__state = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
	    top__DOT__diff2d_inst__DOT__f0__DOT__fifo_mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top__DOT__diff2d_inst__DOT__f0__DOT__w_wr = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__f0__DOT__w_rd = VL_RAND_RESET_I(1);
    top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr = VL_RAND_RESET_I(7);
    top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr = VL_RAND_RESET_I(7);
    top__DOT__diff2d_inst__DOT__f0__DOT__o_fill = VL_RAND_RESET_I(7);
    __Vtableidx1 = VL_RAND_RESET_I(4);
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[0] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[1] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[2] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[3] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[4] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[5] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[6] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[7] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[8] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[9] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[10] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[11] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[12] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[13] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[14] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__r_bussy[15] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[0] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[1] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[2] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[3] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[4] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[5] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[6] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[7] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[8] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[9] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[10] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[11] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[12] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[13] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[14] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__counter_en[15] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[0] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[1] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[2] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[3] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[4] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[5] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[6] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[7] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[8] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[9] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[10] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[11] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[12] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[13] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[14] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__column_en[15] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[0] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[1] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[2] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[3] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[4] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[5] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[6] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[7] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[8] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[9] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[10] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[11] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[12] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[13] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[14] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp1_en[15] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[0] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[1] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[2] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[3] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[4] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[5] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[6] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[7] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[8] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[9] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[10] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[11] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[12] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[13] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[14] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__DyOp2_en[15] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[0] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[1] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[2] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[3] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[4] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[5] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[6] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[7] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[8] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[9] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[10] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[11] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[12] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[13] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[14] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datay_en[15] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[0] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[1] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[2] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[3] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[4] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[5] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[6] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[7] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[8] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[9] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[10] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[11] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[12] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[13] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[14] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__datax_en[15] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[0] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[1] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[2] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[3] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[4] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[5] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[6] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[7] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[8] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[9] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[10] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[11] = 1U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[12] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[13] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[14] = 0U;
    __Vtable1_top__DOT__diff2d_inst__DOT__FIFO_rd[15] = 0U;
    __Vclklast__TOP__i_clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
