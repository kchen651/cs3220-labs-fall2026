// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpipeline__Syms.h"


VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+137,"clk", false,-1);
    tracep->declBit(c+138,"reset", false,-1);
}

VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__pipeline__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_sub__TOP__pipeline__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+137,"clk", false,-1);
    tracep->declBit(c+138,"reset", false,-1);
    tracep->declBus(c+1,"cycle_count", false,-1, 31,0);
    tracep->declArray(c+2,"FE_latch_out", false,-1, 128,0);
    tracep->declArray(c+7,"DE_latch_out", false,-1, 237,0);
    tracep->declArray(c+15,"AGEX_latch_out", false,-1, 140,0);
    tracep->declArray(c+20,"MEM_latch_out", false,-1, 140,0);
    tracep->declBus(c+25,"from_DE_to_FE", false,-1, 0,0);
    tracep->declQuad(c+179,"from_AGEX_to_FE", false,-1, 32,0);
    tracep->declBus(c+181,"from_MEM_to_FE", false,-1, 0,0);
    tracep->declBus(c+182,"from_WB_to_FE", false,-1, 0,0);
    tracep->declBus(c+181,"from_AGEX_to_DE", false,-1, 0,0);
    tracep->declBus(c+181,"from_MEM_to_DE", false,-1, 0,0);
    tracep->declQuad(c+26,"from_WB_to_DE", false,-1, 37,0);
    tracep->declBus(c+181,"from_MEM_to_AGEX", false,-1, 0,0);
    tracep->declBus(c+182,"from_WB_to_AGEX", false,-1, 0,0);
    tracep->declBus(c+182,"from_WB_to_MEM", false,-1, 0,0);
    tracep->pushNamePrefix("my_AGEX_stage ");
    tracep->declBit(c+137,"clk", false,-1);
    tracep->declBit(c+138,"reset", false,-1);
    tracep->declBus(c+181,"from_MEM_to_AGEX", false,-1, 0,0);
    tracep->declBus(c+182,"from_WB_to_AGEX", false,-1, 0,0);
    tracep->declArray(c+7,"from_DE_latch", false,-1, 237,0);
    tracep->declArray(c+15,"AGEX_latch_out", false,-1, 140,0);
    tracep->declQuad(c+179,"from_AGEX_to_FE", false,-1, 32,0);
    tracep->declBus(c+181,"from_AGEX_to_DE", false,-1, 0,0);
    tracep->declArray(c+15,"AGEX_latch", false,-1, 140,0);
    tracep->declArray(c+28,"AGEX_latch_contents", false,-1, 140,0);
    tracep->declBit(c+33,"valid_AGEX", false,-1);
    tracep->declBus(c+34,"inst_AGEX", false,-1, 31,0);
    tracep->declBus(c+35,"PC_AGEX", false,-1, 31,0);
    tracep->declBus(c+36,"inst_count_AGEX", false,-1, 31,0);
    tracep->declBus(c+37,"pcplus_AGEX", false,-1, 31,0);
    tracep->declBus(c+38,"op_I_AGEX", false,-1, 5,0);
    tracep->declBit(c+39,"br_cond_AGEX", false,-1);
    tracep->declBit(c+183,"is_br_AGEX", false,-1);
    tracep->declBit(c+184,"wr_reg_AGEX", false,-1);
    tracep->declBus(c+185,"wregno_AGEX", false,-1, 4,0);
    tracep->declBus(c+186,"regval1_AGEX", false,-1, 31,0);
    tracep->declBus(c+187,"regval2_AGEX", false,-1, 31,0);
    tracep->declBus(c+188,"sxt_imm_AGEX", false,-1, 31,0);
    tracep->declBus(c+189,"br_target_AGEX", false,-1, 31,0);
    tracep->declBit(c+40,"br_mispred_AGEX", false,-1);
    tracep->declArray(c+41,"de_latch_rest", false,-1, 102,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_DE_stage ");
    tracep->declBit(c+137,"clk", false,-1);
    tracep->declBit(c+138,"reset", false,-1);
    tracep->declArray(c+2,"from_FE_latch", false,-1, 128,0);
    tracep->declBus(c+181,"from_AGEX_to_DE", false,-1, 0,0);
    tracep->declBus(c+181,"from_MEM_to_DE", false,-1, 0,0);
    tracep->declQuad(c+26,"from_WB_to_DE", false,-1, 37,0);
    tracep->declBus(c+25,"from_DE_to_FE", false,-1, 0,0);
    tracep->declArray(c+7,"DE_latch_out", false,-1, 237,0);
    tracep->declArray(c+7,"DE_latch", false,-1, 237,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+104+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->declBit(c+45,"valid_DE", false,-1);
    tracep->declBus(c+46,"inst_DE", false,-1, 31,0);
    tracep->declBus(c+47,"PC_DE", false,-1, 31,0);
    tracep->declBus(c+48,"pcplus_DE", false,-1, 31,0);
    tracep->declBus(c+49,"inst_count_DE", false,-1, 31,0);
    tracep->declArray(c+94,"DE_latch_contents", false,-1, 237,0);
    tracep->declBus(c+50,"F3_DE", false,-1, 2,0);
    tracep->declBus(c+51,"F7_DE", false,-1, 6,0);
    tracep->declBus(c+52,"op_DE", false,-1, 6,0);
    tracep->declBus(c+53,"op_I_DE", false,-1, 5,0);
    tracep->declBus(c+54,"type_I_DE", false,-1, 3,0);
    tracep->declBus(c+55,"type_immediate_DE", false,-1, 2,0);
    tracep->declBus(c+56,"sxt_imm_DE", false,-1, 31,0);
    tracep->declBus(c+57,"rs1_DE", false,-1, 4,0);
    tracep->declBus(c+58,"rs2_DE", false,-1, 4,0);
    tracep->declBus(c+59,"rd_DE", false,-1, 4,0);
    tracep->declBus(c+102,"rs1_val_DE", false,-1, 31,0);
    tracep->declBus(c+103,"rs2_val_DE", false,-1, 31,0);
    tracep->declBit(c+60,"is_br_DE", false,-1);
    tracep->declBit(c+61,"wr_reg_DE", false,-1);
    tracep->declBit(c+62,"wr_reg_WB", false,-1);
    tracep->declBus(c+63,"wregno_WB", false,-1, 4,0);
    tracep->declBus(c+64,"regval_WB", false,-1, 31,0);
    tracep->declBit(c+25,"pipeline_stall_DE", false,-1);
    tracep->declBit(c+65,"use_rs1_DE", false,-1);
    tracep->declBit(c+66,"use_rs2_DE", false,-1);
    tracep->declBus(c+67,"in_use_regs", false,-1, 31,0);
    tracep->declBit(c+25,"has_data_hazards", false,-1);
    tracep->declBit(c+181,"br_mispred_AGEX", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_FE_stage ");
    tracep->declBit(c+137,"clk", false,-1);
    tracep->declBit(c+138,"reset", false,-1);
    tracep->declBus(c+25,"from_DE_to_FE", false,-1, 0,0);
    tracep->declQuad(c+179,"from_AGEX_to_FE", false,-1, 32,0);
    tracep->declBus(c+181,"from_MEM_to_FE", false,-1, 0,0);
    tracep->declBus(c+182,"from_WB_to_FE", false,-1, 0,0);
    tracep->declArray(c+2,"FE_latch_out", false,-1, 128,0);
    tracep->declArray(c+2,"FE_latch", false,-1, 128,0);
    tracep->declBit(c+190,"valid_FE", false,-1);
    tracep->declBus(c+68,"PC_FE_latch", false,-1, 31,0);
    tracep->declBus(c+69,"inst_count_FE", false,-1, 31,0);
    tracep->declBus(c+191,"inst_count_AGEX", false,-1, 31,0);
    tracep->declBus(c+70,"inst_FE", false,-1, 31,0);
    tracep->declBus(c+71,"pcplus_FE", false,-1, 31,0);
    tracep->declBit(c+25,"stall_pipe_FE", false,-1);
    tracep->declArray(c+72,"FE_latch_contents", false,-1, 128,0);
    tracep->declBit(c+181,"br_mispred_AGEX", false,-1);
    tracep->declBus(c+189,"br_target_AGEX", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_MEM_stage ");
    tracep->declBit(c+137,"clk", false,-1);
    tracep->declBit(c+138,"reset", false,-1);
    tracep->declBus(c+182,"from_WB_to_MEM", false,-1, 0,0);
    tracep->declArray(c+15,"from_AGEX_latch", false,-1, 140,0);
    tracep->declArray(c+20,"MEM_latch_out", false,-1, 140,0);
    tracep->declBus(c+181,"from_MEM_to_FE", false,-1, 0,0);
    tracep->declBus(c+181,"from_MEM_to_DE", false,-1, 0,0);
    tracep->declBus(c+181,"from_MEM_to_AGEX", false,-1, 0,0);
    tracep->declArray(c+20,"MEM_latch", false,-1, 140,0);
    tracep->declBit(c+77,"valid_MEM", false,-1);
    tracep->declArray(c+15,"MEM_latch_contents", false,-1, 140,0);
    tracep->declBus(c+78,"op_I_MEM", false,-1, 5,0);
    tracep->declBus(c+79,"inst_count_MEM", false,-1, 31,0);
    tracep->declBus(c+80,"inst_MEM", false,-1, 31,0);
    tracep->declBus(c+81,"PC_MEM", false,-1, 31,0);
    tracep->declBus(c+82,"aluout_MEM", false,-1, 31,0);
    tracep->declBus(c+83,"wregno_MEM", false,-1, 4,0);
    tracep->declBit(c+84,"wr_reg_MEM", false,-1);
    tracep->declBus(c+192,"memaddr_MEM", false,-1, 31,0);
    tracep->declBus(c+85,"rd_val_MEM", false,-1, 31,0);
    tracep->declBus(c+193,"wr_val_MEM", false,-1, 31,0);
    tracep->declBit(c+194,"wr_mem_MEM", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vpipeline___024root__trace_init_sub__TOP__pipeline__my_WB_stage__0(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_sub__TOP__pipeline__my_WB_stage__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+137,"clk", false,-1);
    tracep->declBit(c+138,"reset", false,-1);
    tracep->declArray(c+20,"from_MEM_latch", false,-1, 140,0);
    tracep->declBus(c+181,"from_WB_to_FE", false,-1, 0,0);
    tracep->declQuad(c+26,"from_WB_to_DE", false,-1, 37,0);
    tracep->declBus(c+181,"from_WB_to_AGEX", false,-1, 0,0);
    tracep->declBus(c+181,"from_WB_to_MEM", false,-1, 0,0);
    tracep->declBit(c+86,"valid_WB", false,-1);
    tracep->declBus(c+87,"op_I_WB", false,-1, 5,0);
    tracep->declBus(c+88,"inst_WB", false,-1, 31,0);
    tracep->declBus(c+89,"PC_WB", false,-1, 31,0);
    tracep->declBus(c+90,"inst_count_WB", false,-1, 31,0);
    tracep->declBit(c+91,"wr_reg_WB", false,-1);
    tracep->declBus(c+92,"wregno_WB", false,-1, 4,0);
    tracep->declBus(c+93,"regval_WB", false,-1, 31,0);
    tracep->declBus(c+93,"aluout_WB", false,-1, 31,0);
    tracep->declBus(c+195,"rd_val_WB", false,-1, 31,0);
    tracep->pushNamePrefix("last_WB_value");
    tracep->declBus(c+139,"[0]", false,-1, 31,0);
    tracep->declBus(c+140,"[1]", false,-1, 31,0);
    tracep->declBus(c+141,"[2]", false,-1, 31,0);
    tracep->declBus(c+142,"[3]", false,-1, 31,0);
    tracep->declBus(c+143,"[4]", false,-1, 31,0);
    tracep->declBus(c+144,"[5]", false,-1, 31,0);
    tracep->declBus(c+145,"[6]", false,-1, 31,0);
    tracep->declBus(c+146,"[7]", false,-1, 31,0);
    tracep->declBus(c+147,"[8]", false,-1, 31,0);
    tracep->declBus(c+148,"[9]", false,-1, 31,0);
    tracep->declBus(c+149,"[10]", false,-1, 31,0);
    tracep->declBus(c+150,"[11]", false,-1, 31,0);
    tracep->declBus(c+151,"[12]", false,-1, 31,0);
    tracep->declBus(c+152,"[13]", false,-1, 31,0);
    tracep->declBus(c+153,"[14]", false,-1, 31,0);
    tracep->declBus(c+154,"[15]", false,-1, 31,0);
    tracep->declBus(c+155,"[16]", false,-1, 31,0);
    tracep->declBus(c+156,"[17]", false,-1, 31,0);
    tracep->declBus(c+157,"[18]", false,-1, 31,0);
    tracep->declBus(c+158,"[19]", false,-1, 31,0);
    tracep->declBus(c+159,"[20]", false,-1, 31,0);
    tracep->declBus(c+160,"[21]", false,-1, 31,0);
    tracep->declBus(c+161,"[22]", false,-1, 31,0);
    tracep->declBus(c+162,"[23]", false,-1, 31,0);
    tracep->declBus(c+163,"[24]", false,-1, 31,0);
    tracep->declBus(c+164,"[25]", false,-1, 31,0);
    tracep->declBus(c+165,"[26]", false,-1, 31,0);
    tracep->declBus(c+166,"[27]", false,-1, 31,0);
    tracep->declBus(c+167,"[28]", false,-1, 31,0);
    tracep->declBus(c+168,"[29]", false,-1, 31,0);
    tracep->declBus(c+169,"[30]", false,-1, 31,0);
    tracep->declBus(c+170,"[31]", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("WB_counters");
    tracep->declBus(c+171,"[0]", false,-1, 31,0);
    tracep->declBus(c+172,"[1]", false,-1, 31,0);
    tracep->declBus(c+173,"[2]", false,-1, 31,0);
    tracep->declBus(c+174,"[3]", false,-1, 31,0);
    tracep->declBus(c+175,"[4]", false,-1, 31,0);
    tracep->declBus(c+176,"[5]", false,-1, 31,0);
    tracep->declBus(c+177,"[6]", false,-1, 31,0);
    tracep->declBus(c+178,"[7]", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+136,"i", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vpipeline___024root__trace_init_top(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_init_top\n"); );
    // Body
    Vpipeline___024root__trace_init_sub__TOP__0(vlSelf, tracep);
    tracep->pushNamePrefix("pipeline ");
    Vpipeline___024root__trace_init_sub__TOP__pipeline__0(vlSelf, tracep);
    tracep->pushNamePrefix("my_WB_stage ");
    Vpipeline___024root__trace_init_sub__TOP__pipeline__my_WB_stage__0(vlSelf, tracep);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vpipeline___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpipeline___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpipeline___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vpipeline___024root__trace_register(Vpipeline___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vpipeline___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vpipeline___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vpipeline___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vpipeline___024root__trace_full_sub_0(Vpipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpipeline___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_full_top_0\n"); );
    // Init
    Vpipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpipeline___024root*>(voidSelf);
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpipeline___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpipeline___024root__trace_full_sub_0(Vpipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vpipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpipeline___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<5>/*159:0*/ __Vtemp_h9be87141__0;
    VlWide<4>/*127:0*/ __Vtemp_hd6a2b8bd__0;
    VlWide<5>/*159:0*/ __Vtemp_hd849dd3f__0;
    VlWide<5>/*159:0*/ __Vtemp_hc8066b62__0;
    VlWide<8>/*255:0*/ __Vtemp_hf95522f7__0;
    // Body
    bufp->fullIData(oldp+1,(vlSymsp->TOP__pipeline.__PVT__cycle_count),32);
    bufp->fullWData(oldp+2,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch),129);
    bufp->fullWData(oldp+7,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch),238);
    bufp->fullWData(oldp+15,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch),141);
    bufp->fullWData(oldp+20,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch),141);
    bufp->fullBit(oldp+25,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__has_data_hazards));
    bufp->fullQData(oldp+26,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE),38);
    __Vtemp_h9be87141__0[0U] = 0U;
    __Vtemp_h9be87141__0[1U] = ((IData)((0x3fffffffffULL 
                                         & (((QData)((IData)(
                                                             vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U])) 
                                             << 0x19U) 
                                            | ((QData)((IData)(
                                                               vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U])) 
                                               >> 7U)))) 
                                << 6U);
    __Vtemp_h9be87141__0[2U] = (((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                  << 0x1fU) | (0x7ffff000U 
                                               & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[5U] 
                                                  >> 1U))) 
                                | (((IData)((0x3fffffffffULL 
                                             & (((QData)((IData)(
                                                                 vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U])) 
                                                 << 0x19U) 
                                                | ((QData)((IData)(
                                                                   vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U])) 
                                                   >> 7U)))) 
                                    >> 0x1aU) | ((IData)(
                                                         ((0x3fffffffffULL 
                                                           & (((QData)((IData)(
                                                                               vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U])) 
                                                               << 0x19U) 
                                                              | ((QData)((IData)(
                                                                                vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U])) 
                                                                 >> 7U))) 
                                                          >> 0x20U)) 
                                                 << 6U)));
    __Vtemp_h9be87141__0[3U] = ((0xfffU & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                           >> 1U)) 
                                | ((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                                    << 0x1fU) | (0x7ffff000U 
                                                 & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                                    >> 1U))));
    __Vtemp_h9be87141__0[4U] = ((0xfffU & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                                           >> 1U)) 
                                | (0x1000U & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                                              >> 1U)));
    bufp->fullWData(oldp+28,(__Vtemp_h9be87141__0),141);
    bufp->fullBit(oldp+33,((1U & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                                  >> 0xdU))));
    bufp->fullIData(oldp+34,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[7U] 
                               << 0x13U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                                            >> 0xdU))),32);
    bufp->fullIData(oldp+35,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[6U] 
                               << 0x13U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[5U] 
                                            >> 0xdU))),32);
    bufp->fullIData(oldp+36,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U] 
                               << 0x19U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U] 
                                            >> 7U))),32);
    bufp->fullIData(oldp+37,(((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[5U] 
                               << 0x13U) | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U] 
                                            >> 0xdU))),32);
    bufp->fullCData(oldp+38,((0x3fU & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U] 
                                       >> 7U))),6);
    bufp->fullBit(oldp+39,((0x1cU == (0x3fU & (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U] 
                                               >> 7U)))));
    bufp->fullBit(oldp+40,(((IData)(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__is_br_AGEX) 
                            & (0U != ((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[5U] 
                                       << 0x13U) | 
                                      (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[4U] 
                                       >> 0xdU))))));
    __Vtemp_hd6a2b8bd__0[0U] = vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[0U];
    __Vtemp_hd6a2b8bd__0[1U] = vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[1U];
    __Vtemp_hd6a2b8bd__0[2U] = vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[2U];
    __Vtemp_hd6a2b8bd__0[3U] = (0x7fU & vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__DE_latch[3U]);
    bufp->fullWData(oldp+41,(__Vtemp_hd6a2b8bd__0),103);
    bufp->fullBit(oldp+45,((1U & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[4U])));
    bufp->fullIData(oldp+46,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U]),32);
    bufp->fullIData(oldp+47,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[2U]),32);
    bufp->fullIData(oldp+48,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[1U]),32);
    bufp->fullIData(oldp+49,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U]),32);
    bufp->fullCData(oldp+50,((7U & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+51,((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                              >> 0x19U)),7);
    bufp->fullCData(oldp+52,((0x7fU & vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U])),7);
    bufp->fullCData(oldp+53,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE),6);
    bufp->fullCData(oldp+54,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_I_DE),4);
    bufp->fullCData(oldp+55,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE),3);
    bufp->fullIData(oldp+56,(((1U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                               ? (((- (IData)((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                               >> 0x1fU))) 
                                   << 0xbU) | (0x7ffU 
                                               & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                  >> 0x14U)))
                               : ((5U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                   ? (((- (IData)((
                                                   vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (
                                                   (0x800U 
                                                    & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                            >> 7U)))))
                                   : 0U))),32);
    bufp->fullCData(oldp+57,((0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+58,((0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+59,((0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                       >> 7U))),5);
    bufp->fullBit(oldp+60,(((0x1cU == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                            | ((0x1dU == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                               | ((0x1eU == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                                  | ((0x1fU == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                                     | ((0x20U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                                        | (0x21U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)))))))));
    bufp->fullBit(oldp+61,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__wr_reg_DE));
    bufp->fullBit(oldp+62,((1U & (IData)((vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE 
                                          >> 0x25U)))));
    bufp->fullCData(oldp+63,((0x1fU & (IData)((vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE 
                                               >> 0x20U)))),5);
    bufp->fullIData(oldp+64,((IData)(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__from_WB_to_DE)),32);
    bufp->fullBit(oldp+65,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__use_rs1_DE));
    bufp->fullBit(oldp+66,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__use_rs2_DE));
    bufp->fullIData(oldp+67,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__in_use_regs),32);
    bufp->fullIData(oldp+68,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch),32);
    bufp->fullIData(oldp+69,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__inst_count_FE),32);
    bufp->fullIData(oldp+70,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__imem
                             [(0x3fffU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch 
                                          >> 2U))]),32);
    bufp->fullIData(oldp+71,(((IData)(4U) + vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch)),32);
    __Vtemp_hd849dd3f__0[0U] = vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__inst_count_FE;
    __Vtemp_hd849dd3f__0[1U] = ((IData)(4U) + vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch);
    __Vtemp_hd849dd3f__0[2U] = (IData)((((QData)((IData)(
                                                         vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__imem
                                                         [
                                                         (0x3fffU 
                                                          & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch 
                                                             >> 2U))])) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch))));
    __Vtemp_hd849dd3f__0[3U] = (IData)(((((QData)((IData)(
                                                          vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__imem
                                                          [
                                                          (0x3fffU 
                                                           & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch 
                                                              >> 2U))])) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__PC_FE_latch))) 
                                        >> 0x20U));
    __Vtemp_hd849dd3f__0[4U] = 1U;
    bufp->fullWData(oldp+72,(__Vtemp_hd849dd3f__0),129);
    bufp->fullBit(oldp+77,((1U & (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[4U] 
                                  >> 0xcU))));
    bufp->fullCData(oldp+78,((0x3fU & (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] 
                                       >> 6U))),6);
    bufp->fullIData(oldp+79,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] 
                               << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[1U] 
                                            >> 6U))),32);
    bufp->fullIData(oldp+80,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[4U] 
                               << 0x14U) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[3U] 
                                            >> 0xcU))),32);
    bufp->fullIData(oldp+81,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[3U] 
                               << 0x14U) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[2U] 
                                            >> 0xcU))),32);
    bufp->fullIData(oldp+82,(((vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[1U] 
                               << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[0U] 
                                            >> 6U))),32);
    bufp->fullCData(oldp+83,((0x1fU & vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[0U])),5);
    bufp->fullBit(oldp+84,((1U & (vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__AGEX_latch[0U] 
                                  >> 5U))));
    bufp->fullIData(oldp+85,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__dmem
                             [(0x3fffU & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__memaddr_MEM 
                                          >> 2U))]),32);
    bufp->fullBit(oldp+86,((1U & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                                  >> 0xcU))));
    bufp->fullCData(oldp+87,((0x3fU & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                       >> 6U))),6);
    bufp->fullIData(oldp+88,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[4U] 
                               << 0x14U) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                                            >> 0xcU))),32);
    bufp->fullIData(oldp+89,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[3U] 
                               << 0x14U) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                                            >> 0xcU))),32);
    bufp->fullIData(oldp+90,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[2U] 
                               << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                                            >> 6U))),32);
    bufp->fullBit(oldp+91,((1U & (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                  >> 5U))));
    bufp->fullCData(oldp+92,((0x1fU & vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U])),5);
    bufp->fullIData(oldp+93,(((vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[1U] 
                               << 0x1aU) | (vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__MEM_latch[0U] 
                                            >> 6U))),32);
    __Vtemp_hc8066b62__0[0U] = ((((1U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                   ? (((- (IData)((
                                                   vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                   >> 0x1fU))) 
                                       << 0xbU) | (0x7ffU 
                                                   & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 0x14U)))
                                   : ((5U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                       ? (((- (IData)(
                                                      (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                       >> 0x1fU))) 
                                           << 0xcU) 
                                          | ((0x800U 
                                              & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 7U)))))
                                       : 0U)) << 7U) 
                                | ((((0x1cU == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                                     | ((0x1dU == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                                        | ((0x1eU == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                                           | ((0x1fU 
                                               == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                                              | ((0x20U 
                                                  == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE)) 
                                                 | (0x21U 
                                                    == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE))))))) 
                                    << 6U) | (((IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__wr_reg_DE) 
                                               << 5U) 
                                              | (0x1fU 
                                                 & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                    >> 7U)))));
    __Vtemp_hf95522f7__0[0U] = __Vtemp_hc8066b62__0[0U];
    __Vtemp_hf95522f7__0[1U] = ((((1U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                   ? (((- (IData)((
                                                   vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                   >> 0x1fU))) 
                                       << 0xbU) | (0x7ffU 
                                                   & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 0x14U)))
                                   : ((5U == (IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__type_immediate_DE))
                                       ? (((- (IData)(
                                                      (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                       >> 0x1fU))) 
                                           << 0xcU) 
                                          | ((0x800U 
                                              & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                      >> 7U)))))
                                       : 0U)) >> 0x19U) 
                                | (vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                   [(0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                              >> 0x14U))] 
                                   << 7U));
    __Vtemp_hf95522f7__0[2U] = ((vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                 [(0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                            >> 0x14U))] 
                                 >> 0x19U) | ((IData)(
                                                      (((QData)((IData)(
                                                                        vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                                                         [
                                                                         (0x1fU 
                                                                          & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                             >> 0xfU))])))) 
                                              << 7U));
    __Vtemp_hf95522f7__0[3U] = (((IData)((((QData)((IData)(
                                                           vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                                            [
                                                            (0x1fU 
                                                             & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                >> 0xfU))])))) 
                                 >> 0x19U) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                                                          [
                                                                          (0x1fU 
                                                                           & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                              >> 0xfU))]))) 
                                                       >> 0x20U)) 
                                              << 7U));
    __Vtemp_hf95522f7__0[4U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[1U] 
                                 << 0xdU) | (((IData)(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__op_I_DE) 
                                              << 7U) 
                                             | ((IData)(
                                                        ((((QData)((IData)(
                                                                           vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[0U])) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                                                                            [
                                                                            (0x1fU 
                                                                             & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                                                                >> 0xfU))]))) 
                                                         >> 0x20U)) 
                                                >> 0x19U)));
    __Vtemp_hf95522f7__0[5U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[1U] 
                                 >> 0x13U) | (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[2U] 
                                              << 0xdU));
    __Vtemp_hf95522f7__0[6U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[2U] 
                                 >> 0x13U) | (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                              << 0xdU));
    __Vtemp_hf95522f7__0[7U] = ((vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                 >> 0x13U) | (0x2000U 
                                              & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[4U] 
                                                 << 0xdU)));
    bufp->fullWData(oldp+94,(__Vtemp_hf95522f7__0),238);
    bufp->fullIData(oldp+102,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                              [(0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                         >> 0xfU))]),32);
    bufp->fullIData(oldp+103,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs
                              [(0x1fU & (vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__FE_latch[3U] 
                                         >> 0x14U))]),32);
    bufp->fullIData(oldp+104,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[0]),32);
    bufp->fullIData(oldp+105,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[1]),32);
    bufp->fullIData(oldp+106,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[2]),32);
    bufp->fullIData(oldp+107,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[3]),32);
    bufp->fullIData(oldp+108,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[4]),32);
    bufp->fullIData(oldp+109,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[5]),32);
    bufp->fullIData(oldp+110,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[6]),32);
    bufp->fullIData(oldp+111,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[7]),32);
    bufp->fullIData(oldp+112,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[8]),32);
    bufp->fullIData(oldp+113,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[9]),32);
    bufp->fullIData(oldp+114,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[10]),32);
    bufp->fullIData(oldp+115,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[11]),32);
    bufp->fullIData(oldp+116,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[12]),32);
    bufp->fullIData(oldp+117,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[13]),32);
    bufp->fullIData(oldp+118,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[14]),32);
    bufp->fullIData(oldp+119,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[15]),32);
    bufp->fullIData(oldp+120,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[16]),32);
    bufp->fullIData(oldp+121,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[17]),32);
    bufp->fullIData(oldp+122,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[18]),32);
    bufp->fullIData(oldp+123,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[19]),32);
    bufp->fullIData(oldp+124,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[20]),32);
    bufp->fullIData(oldp+125,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[21]),32);
    bufp->fullIData(oldp+126,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[22]),32);
    bufp->fullIData(oldp+127,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[23]),32);
    bufp->fullIData(oldp+128,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[24]),32);
    bufp->fullIData(oldp+129,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[25]),32);
    bufp->fullIData(oldp+130,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[26]),32);
    bufp->fullIData(oldp+131,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[27]),32);
    bufp->fullIData(oldp+132,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[28]),32);
    bufp->fullIData(oldp+133,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[29]),32);
    bufp->fullIData(oldp+134,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[30]),32);
    bufp->fullIData(oldp+135,(vlSymsp->TOP__pipeline.__PVT__my_DE_stage__DOT__regs[31]),32);
    bufp->fullIData(oldp+136,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+137,(vlSelf->clk));
    bufp->fullBit(oldp+138,(vlSelf->reset));
    bufp->fullIData(oldp+139,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0U]),32);
    bufp->fullIData(oldp+140,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[1U]),32);
    bufp->fullIData(oldp+141,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[2U]),32);
    bufp->fullIData(oldp+142,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[3U]),32);
    bufp->fullIData(oldp+143,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[4U]),32);
    bufp->fullIData(oldp+144,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[5U]),32);
    bufp->fullIData(oldp+145,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[6U]),32);
    bufp->fullIData(oldp+146,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[7U]),32);
    bufp->fullIData(oldp+147,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[8U]),32);
    bufp->fullIData(oldp+148,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[9U]),32);
    bufp->fullIData(oldp+149,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xaU]),32);
    bufp->fullIData(oldp+150,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xbU]),32);
    bufp->fullIData(oldp+151,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xcU]),32);
    bufp->fullIData(oldp+152,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xdU]),32);
    bufp->fullIData(oldp+153,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xeU]),32);
    bufp->fullIData(oldp+154,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0xfU]),32);
    bufp->fullIData(oldp+155,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x10U]),32);
    bufp->fullIData(oldp+156,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x11U]),32);
    bufp->fullIData(oldp+157,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x12U]),32);
    bufp->fullIData(oldp+158,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x13U]),32);
    bufp->fullIData(oldp+159,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x14U]),32);
    bufp->fullIData(oldp+160,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x15U]),32);
    bufp->fullIData(oldp+161,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x16U]),32);
    bufp->fullIData(oldp+162,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x17U]),32);
    bufp->fullIData(oldp+163,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x18U]),32);
    bufp->fullIData(oldp+164,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x19U]),32);
    bufp->fullIData(oldp+165,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1aU]),32);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1bU]),32);
    bufp->fullIData(oldp+167,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1cU]),32);
    bufp->fullIData(oldp+168,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1dU]),32);
    bufp->fullIData(oldp+169,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1eU]),32);
    bufp->fullIData(oldp+170,(vlSymsp->TOP__pipeline__my_WB_stage.last_WB_value[0x1fU]),32);
    bufp->fullIData(oldp+171,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[0U]),32);
    bufp->fullIData(oldp+172,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[1U]),32);
    bufp->fullIData(oldp+173,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[2U]),32);
    bufp->fullIData(oldp+174,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[3U]),32);
    bufp->fullIData(oldp+175,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[4U]),32);
    bufp->fullIData(oldp+176,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[5U]),32);
    bufp->fullIData(oldp+177,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[6U]),32);
    bufp->fullIData(oldp+178,(vlSymsp->TOP__pipeline__my_WB_stage.WB_counters[7U]),32);
    bufp->fullQData(oldp+179,(0ULL),33);
    bufp->fullBit(oldp+181,(0U));
    bufp->fullBit(oldp+182,(0U));
    bufp->fullBit(oldp+183,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__is_br_AGEX));
    bufp->fullBit(oldp+184,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__wr_reg_AGEX));
    bufp->fullCData(oldp+185,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__wregno_AGEX),5);
    bufp->fullIData(oldp+186,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__regval1_AGEX),32);
    bufp->fullIData(oldp+187,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__regval2_AGEX),32);
    bufp->fullIData(oldp+188,(vlSymsp->TOP__pipeline.__PVT__my_AGEX_stage__DOT__sxt_imm_AGEX),32);
    bufp->fullIData(oldp+189,(0U),32);
    bufp->fullBit(oldp+190,(1U));
    bufp->fullIData(oldp+191,(vlSymsp->TOP__pipeline.__PVT__my_FE_stage__DOT__inst_count_AGEX),32);
    bufp->fullIData(oldp+192,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__memaddr_MEM),32);
    bufp->fullIData(oldp+193,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__wr_val_MEM),32);
    bufp->fullBit(oldp+194,(vlSymsp->TOP__pipeline.__PVT__my_MEM_stage__DOT__wr_mem_MEM));
    bufp->fullIData(oldp+195,(vlSymsp->TOP__pipeline__my_WB_stage.__PVT__rd_val_WB),32);
}
