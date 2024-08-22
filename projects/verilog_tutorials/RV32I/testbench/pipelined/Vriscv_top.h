// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VRISCV_TOP_H_
#define _VRISCV_TOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vriscv_top__Syms;
class Vriscv_top_VerilatedVcd;


//----------

VL_MODULE(Vriscv_top) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(i_clk,0,0);
    VL_IN8(i_rstn,0,0);
    VL_OUT8(o_riscv_dmem_wr_en,0,0);
    VL_OUT8(o_riscv_dmem_byte_sel,3,0);
    VL_OUT(o_riscv_imem_pc,31,0);
    VL_OUT(o_riscv_imem_instr,31,0);
    VL_OUT(o_riscv_dmem_addr,31,0);
    VL_OUT(o_riscv_dmem_wr_data,31,0);
    VL_OUT(o_riscv_dmem_rd_data,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ riscv_top__DOT__id_stall;
        CData/*0:0*/ riscv_top__DOT__id_flush;
        CData/*1:0*/ riscv_top__DOT__id_ctrl_result_src;
        CData/*3:0*/ riscv_top__DOT__id_ctrl_alu_control;
        CData/*0:0*/ riscv_top__DOT__ex_flush;
        CData/*0:0*/ riscv_top__DOT__ex_ctrl_reg_write;
        CData/*1:0*/ riscv_top__DOT__ex_ctrl_result_src;
        CData/*0:0*/ riscv_top__DOT__ex_ctrl_mem_write;
        CData/*1:0*/ riscv_top__DOT__ex_ctrl_jump;
        CData/*0:0*/ riscv_top__DOT__ex_ctrl_branch;
        CData/*3:0*/ riscv_top__DOT__ex_ctrl_byte_sel;
        CData/*3:0*/ riscv_top__DOT__ex_ctrl_alu_control;
        CData/*0:0*/ riscv_top__DOT__ex_ctrl_alu_b_src;
        CData/*0:0*/ riscv_top__DOT__ex_ctrl_rd_src;
        CData/*4:0*/ riscv_top__DOT__ex_rs1_addr;
        CData/*4:0*/ riscv_top__DOT__ex_rs2_addr;
        CData/*4:0*/ riscv_top__DOT__ex_rd_addr;
        CData/*1:0*/ riscv_top__DOT__forwardAE;
        CData/*1:0*/ riscv_top__DOT__forwardBE;
        CData/*1:0*/ riscv_top__DOT__ex_src_pc;
        CData/*0:0*/ riscv_top__DOT__mem_ctrl_rd_src;
        CData/*0:0*/ riscv_top__DOT__mem_ctrl_reg_write;
        CData/*0:0*/ riscv_top__DOT__mem_ctrl_mem_write;
        CData/*1:0*/ riscv_top__DOT__mem_ctrl_result_src;
        CData/*3:0*/ riscv_top__DOT__mem_ctrl_byte_sel;
        CData/*4:0*/ riscv_top__DOT__mem_rd_addr;
        CData/*0:0*/ riscv_top__DOT__wb_ctrl_reg_write;
        CData/*1:0*/ riscv_top__DOT__wb_ctrl_result_src;
        CData/*4:0*/ riscv_top__DOT__wb_rd_addr;
        CData/*2:0*/ riscv_top__DOT__ex_funct3;
        CData/*2:0*/ riscv_top__DOT__mem_funct3;
        CData/*0:0*/ riscv_top__DOT__wb_ctrl_rd_src;
        CData/*2:0*/ riscv_top__DOT__u_riscv_id__DOT__id_imm_src;
        CData/*0:0*/ riscv_top__DOT__u_riscv_ex__DOT__take_branch;
        CData/*3:0*/ riscv_top__DOT__u_riscv_mem__DOT__dmem_byte_sel;
        IData/*31:0*/ riscv_top__DOT__id_pc;
        IData/*31:0*/ riscv_top__DOT__id_pc_plus_4;
        IData/*31:0*/ riscv_top__DOT__id_instr;
        IData/*31:0*/ riscv_top__DOT__id_rd_data;
        IData/*31:0*/ riscv_top__DOT__id_imm;
        IData/*31:0*/ riscv_top__DOT__ex_rs1_data;
        IData/*31:0*/ riscv_top__DOT__ex_rs2_data;
        IData/*31:0*/ riscv_top__DOT__ex_pc;
        IData/*31:0*/ riscv_top__DOT__ex_pc_plus_4;
        IData/*31:0*/ riscv_top__DOT__ex_imm;
        IData/*31:0*/ riscv_top__DOT__ex_forward_rd_data;
        IData/*31:0*/ riscv_top__DOT__ex_forward_alu_result;
        IData/*31:0*/ riscv_top__DOT__ex_alu_result;
        IData/*31:0*/ riscv_top__DOT__ex_pc_plus_imm;
        IData/*31:0*/ riscv_top__DOT__mem_imm;
        IData/*31:0*/ riscv_top__DOT__mem_alu_result;
        IData/*31:0*/ riscv_top__DOT__mem_pc_plus_4;
        IData/*31:0*/ riscv_top__DOT__mem_pc_plus_imm;
        IData/*31:0*/ riscv_top__DOT__mem_write_data;
        IData/*31:0*/ riscv_top__DOT__mem_rd_result;
        IData/*31:0*/ riscv_top__DOT__mem_read_data;
        IData/*31:0*/ riscv_top__DOT__wb_imm;
        IData/*31:0*/ riscv_top__DOT__wb_pc_plus_4;
        IData/*31:0*/ riscv_top__DOT__wb_alu_result;
        IData/*31:0*/ riscv_top__DOT__wb_read_data;
        IData/*31:0*/ riscv_top__DOT__wb_rd_data;
        IData/*31:0*/ riscv_top__DOT__wb_rd_result;
        WData/*95:0*/ riscv_top__DOT__u_riscv_if__DOT__mux_concat_pc[3];
        IData/*31:0*/ riscv_top__DOT__u_riscv_if__DOT__current_pc;
    };
    struct {
        WData/*1023:0*/ riscv_top__DOT__u_riscv_if__DOT__u_riscv_imem__DOT__FILE_TEXT_MIF[32];
        WData/*255:0*/ riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR[8];
        WData/*95:0*/ riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs1[3];
        WData/*95:0*/ riscv_top__DOT__u_riscv_ex__DOT__mux_concat_src_rs2[3];
        IData/*31:0*/ riscv_top__DOT__u_riscv_ex__DOT__src_rs2_data;
        IData/*31:0*/ riscv_top__DOT__u_riscv_ex__DOT__alu_a;
        IData/*31:0*/ riscv_top__DOT__u_riscv_ex__DOT__alu_b;
        IData/*31:0*/ riscv_top__DOT__u_riscv_mem__DOT__dmem_wr_data;
        WData/*127:0*/ riscv_top__DOT__u_riscv_mem__DOT__mux_concat_src_result[4];
        IData/*31:0*/ riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data;
        WData/*1023:0*/ riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__FILE_DATA_MIF[32];
        IData/*31:0*/ riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__i;
        QData/*63:0*/ riscv_top__DOT__u_riscv_ex__DOT__mux_concat_alu_b;
        QData/*63:0*/ riscv_top__DOT__u_riscv_ex__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP;
        QData/*63:0*/ riscv_top__DOT__u_riscv_wb__DOT__mux_concat_rd;
        IData/*31:0*/ riscv_top__DOT__u_riscv_if__DOT__u_riscv_mux_pc__DOT__mux_input_arr[3];
        IData/*31:0*/ riscv_top__DOT__u_riscv_if__DOT__u_riscv_imem__DOT__imem_arr[16384];
        IData/*31:0*/ riscv_top__DOT__u_riscv_id__DOT__u_riscv_register_file__DOT__registers[32];
        IData/*31:0*/ riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs1__DOT__mux_input_arr[3];
        IData/*31:0*/ riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_rs2__DOT__mux_input_arr[3];
        IData/*31:0*/ riscv_top__DOT__u_riscv_ex__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[2];
        IData/*31:0*/ riscv_top__DOT__u_riscv_mem__DOT__u_riscv_dmem__DOT__dmem_arr[16384];
        IData/*31:0*/ riscv_top__DOT__u_riscv_mem__DOT__u_riscv_mux_rd__DOT__mux_input_arr[4];
        IData/*31:0*/ riscv_top__DOT__u_riscv_wb__DOT__u_riscv_mux__DOT__mux_input_arr[2];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*6:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    CData/*3:0*/ __Vtableidx4;
    CData/*3:0*/ __Vtableidx5;
    CData/*0:0*/ __Vclklast__TOP__i_clk;
    CData/*0:0*/ __Vclklast__TOP__i_rstn;
    SData/*10:0*/ __Vtableidx3;
    IData/*31:0*/ __Vdly__riscv_top__DOT__id_instr;
    CData/*0:0*/ __Vm_traceActivity[4];
    static CData/*1:0*/ __Vtable1_riscv_top__DOT__id_ctrl_result_src[128];
    static CData/*2:0*/ __Vtable2_riscv_top__DOT__u_riscv_id__DOT__id_imm_src[128];
    static WData/*255:0*/ __Vtable3_riscv_top__DOT__u_riscv_id__DOT__u_riscv_control_unit__DOT__DEBUG_INSTR[2048][8];
    static CData/*0:0*/ __Vtable4_riscv_top__DOT__u_riscv_ex__DOT__take_branch[16];
    static QData/*63:0*/ __Vtable5_riscv_top__DOT__u_riscv_ex__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP[16];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vriscv_top__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vriscv_top);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vriscv_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vriscv_top();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vriscv_top__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vriscv_top__Syms* symsp, bool first);
  private:
    static QData _change_request(Vriscv_top__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vriscv_top__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vriscv_top__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vriscv_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vriscv_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vriscv_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vriscv_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vriscv_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vriscv_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vriscv_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vriscv_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
