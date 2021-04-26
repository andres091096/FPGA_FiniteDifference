// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+32,"i_clk",-1);
	vcdp->declBit  (c+33,"i_reset",-1);
	vcdp->declBit  (c+34,"i_start",-1);
	vcdp->declBit  (c+35,"o_valid",-1);
	vcdp->declBus  (c+36,"o_datax",-1,31,0);
	vcdp->declBus  (c+37,"o_datay",-1,31,0);
	vcdp->declBit  (c+32,"top i_clk",-1);
	vcdp->declBit  (c+33,"top i_reset",-1);
	vcdp->declBit  (c+34,"top i_start",-1);
	vcdp->declBit  (c+35,"top o_valid",-1);
	vcdp->declBus  (c+36,"top o_datax",-1,31,0);
	vcdp->declBus  (c+37,"top o_datay",-1,31,0);
	vcdp->declBus  (c+17,"top w_data",-1,31,0);
	vcdp->declBus  (c+18,"top w_address",-1,11,0);
	vcdp->declBus  (c+19,"top w_Dxaddr",-1,11,0);
	vcdp->declBit  (c+1,"top w_bussy",-1);
	vcdp->declBit  (c+20,"top w_DxValid",-1);
	vcdp->declBit  (c+21,"top w_DyValid",-1);
	vcdp->declBit  (c+32,"top rom_int clk",-1);
	vcdp->declBus  (c+18,"top rom_int addr",-1,11,0);
	vcdp->declBus  (c+17,"top rom_int data",-1,31,0);
	// Tracing: top rom_int memory // Ignored: Wide memory > --trace-max-array ents at rtl/rom.v:7
	vcdp->declBus  (c+38,"top diff2d_inst WIDTH",-1,31,0);
	vcdp->declBus  (c+39,"top diff2d_inst ADD_W",-1,31,0);
	vcdp->declBus  (c+40,"top diff2d_inst l",-1,31,0);
	vcdp->declBit  (c+32,"top diff2d_inst i_clk",-1);
	vcdp->declBit  (c+33,"top diff2d_inst i_reset",-1);
	vcdp->declBus  (c+17,"top diff2d_inst i_data",-1,31,0);
	vcdp->declBit  (c+34,"top diff2d_inst i_start",-1);
	vcdp->declBus  (c+36,"top diff2d_inst o_datax",-1,31,0);
	vcdp->declBus  (c+37,"top diff2d_inst o_datay",-1,31,0);
	vcdp->declBus  (c+18,"top diff2d_inst o_address",-1,11,0);
	vcdp->declBus  (c+19,"top diff2d_inst o_Dx_addr",-1,11,0);
	vcdp->declBit  (c+21,"top diff2d_inst o_DyValid",-1);
	vcdp->declBit  (c+20,"top diff2d_inst o_DxValid",-1);
	vcdp->declBit  (c+1,"top diff2d_inst o_bussy",-1);
	vcdp->declBus  (c+22,"top diff2d_inst r_datax",-1,31,0);
	vcdp->declBus  (c+23,"top diff2d_inst r_datay",-1,31,0);
	vcdp->declBus  (c+24,"top diff2d_inst r_DyOp1",-1,31,0);
	vcdp->declBus  (c+25,"top diff2d_inst r_DyOp2",-1,31,0);
	vcdp->declBus  (c+26,"top diff2d_inst r_DyOp0",-1,31,0);
	vcdp->declBus  (c+27,"top diff2d_inst r_OutFIFO",-1,31,0);
	vcdp->declBus  (c+18,"top diff2d_inst counter",-1,11,0);
	vcdp->declBus  (c+19,"top diff2d_inst w_DxAddr",-1,11,0);
	vcdp->declBus  (c+28,"top diff2d_inst column_counter",-1,5,0);
	vcdp->declBus  (c+29,"top diff2d_inst fifo_counter",-1,5,0);
	vcdp->declBit  (c+2,"top diff2d_inst counter_en",-1);
	vcdp->declBit  (c+3,"top diff2d_inst column_en",-1);
	vcdp->declBit  (c+21,"top diff2d_inst r_DyValid",-1);
	vcdp->declBit  (c+20,"top diff2d_inst r_DxValid",-1);
	vcdp->declBit  (c+4,"top diff2d_inst DyOp1_en",-1);
	vcdp->declBit  (c+5,"top diff2d_inst DyOp2_en",-1);
	vcdp->declBit  (c+6,"top diff2d_inst datay_en",-1);
	vcdp->declBit  (c+7,"top diff2d_inst datax_en",-1);
	vcdp->declBit  (c+5,"top diff2d_inst FIFO_wr",-1);
	vcdp->declBit  (c+8,"top diff2d_inst FIFO_rd",-1);
	vcdp->declBit  (c+1,"top diff2d_inst r_bussy",-1);
	vcdp->declBit  (c+30,"top diff2d_inst full_FIFO",-1);
	vcdp->declBus  (c+31,"top diff2d_inst w_op1",-1,31,0);
	vcdp->declBus  (c+41,"top diff2d_inst IDLE",-1,3,0);
	vcdp->declBus  (c+42,"top diff2d_inst S1",-1,3,0);
	vcdp->declBus  (c+43,"top diff2d_inst S2",-1,3,0);
	vcdp->declBus  (c+44,"top diff2d_inst S3",-1,3,0);
	vcdp->declBus  (c+45,"top diff2d_inst S4",-1,3,0);
	vcdp->declBus  (c+46,"top diff2d_inst S5",-1,3,0);
	vcdp->declBus  (c+47,"top diff2d_inst S6",-1,3,0);
	vcdp->declBus  (c+48,"top diff2d_inst S7",-1,3,0);
	vcdp->declBus  (c+49,"top diff2d_inst S8",-1,3,0);
	vcdp->declBus  (c+50,"top diff2d_inst S9",-1,3,0);
	vcdp->declBus  (c+51,"top diff2d_inst S10",-1,3,0);
	vcdp->declBus  (c+52,"top diff2d_inst S11",-1,3,0);
	vcdp->declBus  (c+53,"top diff2d_inst S12",-1,3,0);
	vcdp->declBus  (c+9,"top diff2d_inst state",-1,3,0);
	vcdp->declBus  (c+38,"top diff2d_inst f0 WIDTH",-1,31,0);
	vcdp->declBus  (c+40,"top diff2d_inst f0 M_WIDTH",-1,31,0);
	vcdp->declBit  (c+32,"top diff2d_inst f0 i_clk",-1);
	vcdp->declBit  (c+5,"top diff2d_inst f0 i_wr",-1);
	vcdp->declBus  (c+24,"top diff2d_inst f0 i_data",-1,31,0);
	vcdp->declBit  (c+8,"top diff2d_inst f0 i_rd",-1);
	vcdp->declBus  (c+27,"top diff2d_inst f0 o_data",-1,31,0);
	vcdp->declBit  (c+10,"top diff2d_inst f0 o_full",-1);
	vcdp->declBit  (c+11,"top diff2d_inst f0 o_empty",-1);
	// Tracing: top diff2d_inst f0 fifo_mem // Ignored: Wide memory > --trace-max-array ents at rtl/fifo.v:44
	vcdp->declBit  (c+12,"top diff2d_inst f0 w_wr",-1);
	vcdp->declBit  (c+13,"top diff2d_inst f0 w_rd",-1);
	vcdp->declBus  (c+14,"top diff2d_inst f0 wr_addr",-1,6,0);
	vcdp->declBus  (c+15,"top diff2d_inst f0 rd_addr",-1,6,0);
	vcdp->declBus  (c+16,"top diff2d_inst f0 o_fill",-1,6,0);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBit  (c+1,(vlTOPp->top__DOT__diff2d_inst__DOT__r_bussy));
	vcdp->fullBit  (c+2,(vlTOPp->top__DOT__diff2d_inst__DOT__counter_en));
	vcdp->fullBit  (c+3,(vlTOPp->top__DOT__diff2d_inst__DOT__column_en));
	vcdp->fullBit  (c+4,(vlTOPp->top__DOT__diff2d_inst__DOT__DyOp1_en));
	vcdp->fullBit  (c+5,(vlTOPp->top__DOT__diff2d_inst__DOT__DyOp2_en));
	vcdp->fullBit  (c+6,(vlTOPp->top__DOT__diff2d_inst__DOT__datay_en));
	vcdp->fullBit  (c+7,(vlTOPp->top__DOT__diff2d_inst__DOT__datax_en));
	vcdp->fullBit  (c+8,(vlTOPp->top__DOT__diff2d_inst__DOT__FIFO_rd));
	vcdp->fullBus  (c+9,(vlTOPp->top__DOT__diff2d_inst__DOT__state),4);
	vcdp->fullBit  (c+10,((0x40U == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill))));
	vcdp->fullBit  (c+11,((0U == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill))));
	vcdp->fullBit  (c+12,(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_wr));
	vcdp->fullBit  (c+13,(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__w_rd));
	vcdp->fullBus  (c+14,(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__wr_addr),7);
	vcdp->fullBus  (c+15,(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__rd_addr),7);
	vcdp->fullBus  (c+16,(vlTOPp->top__DOT__diff2d_inst__DOT__f0__DOT__o_fill),7);
	vcdp->fullBus  (c+17,(vlTOPp->top__DOT__w_data),32);
	vcdp->fullBus  (c+18,(vlTOPp->top__DOT__diff2d_inst__DOT__counter),12);
	vcdp->fullBus  (c+19,(vlTOPp->top__DOT__diff2d_inst__DOT__w_DxAddr),12);
	vcdp->fullBit  (c+20,(vlTOPp->top__DOT__diff2d_inst__DOT__r_DxValid));
	vcdp->fullBit  (c+21,(vlTOPp->top__DOT__diff2d_inst__DOT__r_DyValid));
	vcdp->fullBus  (c+22,(vlTOPp->top__DOT__diff2d_inst__DOT__r_datax),32);
	vcdp->fullBus  (c+23,(vlTOPp->top__DOT__diff2d_inst__DOT__r_datay),32);
	vcdp->fullBus  (c+24,(vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp1),32);
	vcdp->fullBus  (c+25,(vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp2),32);
	vcdp->fullBus  (c+26,(vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp0),32);
	vcdp->fullBus  (c+27,(vlTOPp->top__DOT__diff2d_inst__DOT__r_OutFIFO),32);
	vcdp->fullBus  (c+28,(vlTOPp->top__DOT__diff2d_inst__DOT__column_counter),6);
	vcdp->fullBus  (c+29,(vlTOPp->top__DOT__diff2d_inst__DOT__fifo_counter),6);
	vcdp->fullBit  (c+30,((0x3fU == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__fifo_counter))));
	vcdp->fullBus  (c+31,(((0x3fU == (IData)(vlTOPp->top__DOT__diff2d_inst__DOT__column_counter))
			        ? vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp0
			        : vlTOPp->top__DOT__diff2d_inst__DOT__r_DyOp1)),32);
	vcdp->fullBit  (c+32,(vlTOPp->i_clk));
	vcdp->fullBit  (c+33,(vlTOPp->i_reset));
	vcdp->fullBit  (c+34,(vlTOPp->i_start));
	vcdp->fullBit  (c+35,(vlTOPp->o_valid));
	vcdp->fullBus  (c+36,(vlTOPp->o_datax),32);
	vcdp->fullBus  (c+37,(vlTOPp->o_datay),32);
	vcdp->fullBus  (c+38,(0x20U),32);
	vcdp->fullBus  (c+39,(0xcU),32);
	vcdp->fullBus  (c+40,(6U),32);
	vcdp->fullBus  (c+41,(0U),4);
	vcdp->fullBus  (c+42,(1U),4);
	vcdp->fullBus  (c+43,(2U),4);
	vcdp->fullBus  (c+44,(3U),4);
	vcdp->fullBus  (c+45,(4U),4);
	vcdp->fullBus  (c+46,(5U),4);
	vcdp->fullBus  (c+47,(6U),4);
	vcdp->fullBus  (c+48,(7U),4);
	vcdp->fullBus  (c+49,(8U),4);
	vcdp->fullBus  (c+50,(9U),4);
	vcdp->fullBus  (c+51,(0xaU),4);
	vcdp->fullBus  (c+52,(0xbU),4);
	vcdp->fullBus  (c+53,(0xcU),4);
    }
}
