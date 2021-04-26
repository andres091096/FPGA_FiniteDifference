// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->top__DOT__diff2d_inst__DOT__r_bussy));
	vcdp->chgBit  (c+2,(vlTOPp->top__DOT__diff2d_inst__DOT__counter_en));
	vcdp->chgBit  (c+3,(vlTOPp->top__DOT__diff2d_inst__DOT__column_en));
	vcdp->chgBit  (c+4,(vlTOPp->top__DOT__diff2d_inst__DOT__DyOp1_en));
	vcdp->chgBit  (c+5,(vlTOPp->top__DOT__diff2d_inst__DOT__DyOp2_en));
	vcdp->chgBit  (c+6,(vlTOPp->top__DOT__diff2d_inst__DOT__datay_en));
	vcdp->chgBit  (c+7,(vlTOPp->top__DOT__diff2d_inst__DOT__datax_en));
	vcdp->chgBit  (c+8,(vlTOPp->top__DOT__diff2d_inst__DOT__FIFO_rd));
	vcdp->chgBus  (c+9,(vlTOPp->top__DOT__diff2d_inst__DOT__state),4);
	vcdp->chgBit  (c+10,((0x40U == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill))));
	vcdp->chgBit  (c+11,((0U == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill))));
	vcdp->chgBit  (c+12,(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_wr));
	vcdp->chgBit  (c+13,(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_rd));
	vcdp->chgBus  (c+14,(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr),7);
	vcdp->chgBus  (c+15,(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr),7);
	vcdp->chgBus  (c+16,(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill),7);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+17,(vlTOPp->top__DOT__w_data),32);
	vcdp->chgBus  (c+18,(vlTOPp->top__DOT__diff2d_inst__DOT__counter),12);
	vcdp->chgBus  (c+19,(vlTOPp->top__DOT__diff2d_inst__DOT__w_DxAddr),12);
	vcdp->chgBit  (c+20,(vlTOPp->top__DOT__diff2d_inst__DOT__r_DxValid));
	vcdp->chgBit  (c+21,(vlTOPp->top__DOT__diff2d_inst__DOT__r_DyValid));
	vcdp->chgBus  (c+22,(vlTOPp->top__DOT__diff2d_inst__DOT__r_datax),32);
	vcdp->chgBus  (c+23,(vlTOPp->top__DOT__diff2d_inst__DOT__r_datay),32);
	vcdp->chgBus  (c+24,(vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp1),32);
	vcdp->chgBus  (c+25,(vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp2),32);
	vcdp->chgBus  (c+26,(vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp0),32);
	vcdp->chgBus  (c+27,(vlTOPp->top__DOT__diff2d_inst__DOT__r_OutFIFO),32);
	vcdp->chgBus  (c+28,(vlTOPp->top__DOT__diff2d_inst__DOT__column_counter),6);
	vcdp->chgBus  (c+29,(vlTOPp->top__DOT__diff2d_inst__DOT__fifo_counter),6);
	vcdp->chgBit  (c+30,((0x3fU == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__fifo_counter))));
	vcdp->chgBus  (c+31,(((0x3fU == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__column_counter))
			       ? vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp0
			       : vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp1)),32);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+32,(vlTOPp->i_clk));
	vcdp->chgBit  (c+33,(vlTOPp->i_reset));
	vcdp->chgBit  (c+34,(vlTOPp->i_start));
	vcdp->chgBit  (c+35,(vlTOPp->o_valid));
	vcdp->chgBus  (c+36,(vlTOPp->o_datax),32);
	vcdp->chgBus  (c+37,(vlTOPp->o_datay),32);
    }
}
