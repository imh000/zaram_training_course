`ifndef NOINC
`include "../common/riscv_configs.v"
`include "riscv_if.v"
`include "riscv_id.v"
`include "riscv_ex.v"
`include "riscv_mem.v"
`include "riscv_wb.v"
`include "riscv_ifid_reg.v"
`include "riscv_idex_reg.v"
`include "riscv_exmem_reg.v"
`include "riscv_memwb_reg.v"
`include "riscv_hazard_unit.v"
`include "riscv_control_unit.v"
`endif

module riscv_top
#(
	parameter REGISTER_INIT = 0
)
(
	input i_clk,
	input i_rstn,

	output o_riscv_dmem_wr_en,
	output [`XLEN-1:0] o_riscv_imem_pc,
	output [`XLEN-1:0] o_riscv_imem_instr,
	output [`XLEN-1:0] o_riscv_dmem_addr,
	output [`XLEN-1:0] o_riscv_dmem_wr_data,
	output [`XLEN-1:0] o_riscv_dmem_rd_data,
	output [`XLEN/8-1:0] o_riscv_dmem_byte_sel
);

	//if stage
	wire [`XLEN-1:0] if_pc_plus_4;
	wire if_stall;

	//if id register
	wire id_stall;
	wire id_flush;
	wire [`XLEN-1:0] id_pc;
	wire [`XLEN-1:0] id_pc_plus_4;
	wire [`XLEN-1:0] id_instr;
	
	// id stage
	wire [`XLEN-1:0] id_rd_data;
	wire [`XLEN-1:0] id_rs1_data;
	wire [`XLEN-1:0] id_rs2_data;
	wire [`XLEN-1:0] id_imm;

	wire [4:0] id_rs1_addr;
	wire [4:0] id_rs2_addr;
	wire [4:0] id_rd_addr;

	wire id_ctrl_reg_write;
	wire [1:0] id_ctrl_result_src;
	wire id_ctrl_mem_write;
	wire [1:0] id_ctrl_jump;
	wire id_ctrl_branch;
	wire [3:0] id_ctrl_byte_sel;
	wire [3:0] id_ctrl_alu_control;
	wire id_ctrl_alu_b_src;
	wire id_ctrl_rd_src;

	// id ex register
	wire ex_flush;

	wire ex_ctrl_reg_write;
	wire [1:0] ex_ctrl_result_src;
	wire ex_ctrl_mem_write;
	wire [1:0] ex_ctrl_jump;
	wire ex_ctrl_branch;
	wire [3:0] ex_ctrl_byte_sel;
	wire [3:0] ex_ctrl_alu_control;
	wire ex_ctrl_alu_b_src;
	wire ex_ctrl_rd_src;

	wire [`XLEN-1:0] ex_rs1_data;
	wire [`XLEN-1:0] ex_rs2_data;
	wire [4:0] ex_rs1_addr;
	wire [4:0] ex_rs2_addr;
	wire [4:0] ex_rd_addr;

	wire [`XLEN-1:0] ex_pc;
	wire [`XLEN-1:0] ex_pc_plus_4;
	wire [`XLEN-1:0] ex_imm;

	// ex stage
	wire [1:0] forwardAE;
	wire [1:0] forwardBE;
	wire [`XLEN-1:0] ex_forward_rd_data;
	wire [`XLEN-1:0] ex_forward_alu_result;

	wire [1:0] ex_src_pc;
	wire ex_alu_zero;
	wire [`XLEN-1:0] ex_alu_result;
	wire [`XLEN-1:0] ex_write_data;
	wire [`XLEN-1:0] ex_pc_plus_imm;

	// ex mem register
	wire mem_ctrl_rd_src;
	wire mem_ctrl_reg_write;
	wire mem_ctrl_mem_write;
	wire [1:0] mem_ctrl_result_src;
	wire [3:0] mem_ctrl_byte_sel;
	wire [4:0] mem_rd_addr;
	wire [`XLEN-1:0] mem_imm;
	wire [`XLEN-1:0] mem_alu_result;
	wire [`XLEN-1:0] mem_pc_plus_4;
	wire [`XLEN-1:0] mem_pc_plus_imm;
	wire [`XLEN-1:0] mem_write_data;

	// mem stage
	wire [`XLEN-1:0] mem_rd_result;
	wire [`XLEN-1:0] mem_read_data;

	// mem wb register
	wire wb_ctrl_reg_write;
	wire [1:0] wb_ctrl_result_src;

	wire [4:0] wb_rd_addr;
	wire [`XLEN-1:0] wb_imm;
	wire [`XLEN-1:0] wb_pc_plus_4;
	wire [`XLEN-1:0] wb_alu_result;
	wire [`XLEN-1:0] wb_read_data;

	wire [`XLEN-1:0] wb_rd_data;

	wire [2:0] id_funct3;
	wire [2:0] ex_funct3;
	wire [2:0] mem_funct3;

	assign o_riscv_dmem_wr_en = mem_ctrl_mem_write;
	assign o_riscv_dmem_addr = mem_alu_result;
	assign o_riscv_dmem_wr_data = mem_write_data;
	assign o_riscv_dmem_rd_data = mem_read_data;

	riscv_hazard_unit
	u_riscv_hazard_unit(
		.i_clk					(i_clk				),
		.i_id_rs1_addr			(id_rs1_addr		),
		.i_id_rs2_addr			(id_rs2_addr		),
		.i_ex_rs1_addr			(ex_rs1_addr		),
		.i_ex_rs2_addr			(ex_rs2_addr		),
		.i_ex_rd_addr			(ex_rd_addr			),
		.i_mem_rd_addr			(mem_rd_addr		),
		.i_wb_rd_addr			(wb_rd_addr			),
		.i_ex_ctrl_pc_src		(ex_src_pc			),
		.i_mem_ctrl_reg_write	(mem_ctrl_reg_write	),
		.i_wb_ctrl_reg_write	(wb_ctrl_reg_write	),
		.i_ex_ctrl_rd_src		(ex_ctrl_rd_src		),
		.o_if_stall				(if_stall			),
		.o_id_stall				(id_stall			),
		.o_id_flush				(id_flush			),
		.o_ex_flush				(ex_flush			),
		.o_ForwardAE			(forwardAE			),
		.o_ForwardBE			(forwardBE			)
	);

	riscv_if
	#(
		.REGISTER_INIT		(REGISTER_INIT		)
	)
	u_riscv_if(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_if_stall			(if_stall			),
		.i_if_src_pc		(ex_src_pc			),
		.i_if_pc_plus_imm	(ex_pc_plus_imm		),
		.i_if_alu_result	(ex_alu_result		),
		.o_if_instr			(o_riscv_imem_instr	),
		.o_if_pc			(o_riscv_imem_pc	),
		.o_if_pc_plus_4		(if_pc_plus_4		)
	);

	riscv_ifid_reg
	u_riscv_ifid_reg(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_id_stall			(id_stall			),
		.i_id_flush			(id_flush			),
		.i_if_instr			(o_riscv_imem_instr	),
		.i_if_pc			(o_riscv_imem_pc	),
		.i_if_pc_plus_4		(if_pc_plus_4		),
		.o_id_instr			(id_instr			),
		.o_id_pc			(id_pc				),
		.o_id_pc_plus_4		(id_pc_plus_4		)
	);

	riscv_id
	u_riscv_id(
		.i_clk					(i_clk				),
		.i_rstn					(i_rstn				),
		.i_id_rd_addr			(wb_rd_addr			),
		.i_id_wb_reg_write		(wb_ctrl_reg_write	),
		.i_id_instr				(id_instr			),
		.i_id_rd_data			(wb_rd_data			),
		.o_id_rs1_data			(id_rs1_data		),
		.o_id_rs2_data			(id_rs2_data		),
		.o_id_rs1_addr			(id_rs1_addr		),
		.o_id_rs2_addr			(id_rs2_addr		),
		.o_id_rd_addr			(id_rd_addr			),
		.o_id_imm				(id_imm				),
		.o_id_funct3			(id_funct3			),
		.o_id_ctrl_reg_write	(id_ctrl_reg_write	),
		.o_id_ctrl_result_src	(id_ctrl_result_src	),
		.o_id_ctrl_mem_write	(id_ctrl_mem_write	),
		.o_id_ctrl_jump			(id_ctrl_jump		),
		.o_id_ctrl_branch		(id_ctrl_branch		),
		.o_id_ctrl_alu_control	(id_ctrl_alu_control),
		.o_id_ctrl_byte_sel		(id_ctrl_byte_sel	),
		.o_id_ctrl_alu_b_src	(id_ctrl_alu_b_src	),
		.o_id_ctrl_rd_src		(id_ctrl_rd_src		)
	);

	riscv_idex_reg
	u_riscv_idex_reg(
		.i_clk					(i_clk					),
		.i_rstn					(i_rstn					),
		.i_flushE				(ex_flush				),
		.i_id_funct3			(id_funct3				),
		.o_ex_funct3			(ex_funct3				),
		.i_id_ctrl_reg_write	(id_ctrl_reg_write		),
		.i_id_ctrl_result_src	(id_ctrl_result_src		),
		.i_id_ctrl_mem_write	(id_ctrl_mem_write		),
		.i_id_ctrl_jump			(id_ctrl_jump			),
		.i_id_ctrl_branch		(id_ctrl_branch			),
		.i_id_ctrl_byte_sel		(id_ctrl_byte_sel		),
		.i_id_ctrl_alu_ctrl		(id_ctrl_alu_control	),
		.i_id_ctrl_alu_b_src	(id_ctrl_alu_b_src		),
		.i_id_ctrl_rd_src		(id_ctrl_rd_src			),
		.o_ex_ctrl_reg_write	(ex_ctrl_reg_write		),
		.o_ex_ctrl_result_src	(ex_ctrl_result_src		),
		.o_ex_ctrl_mem_write	(ex_ctrl_mem_write		),
		.o_ex_ctrl_jump			(ex_ctrl_jump			),
		.o_ex_ctrl_branch		(ex_ctrl_branch			),
		.o_ex_ctrl_byte_sel		(ex_ctrl_byte_sel		),
		.o_ex_ctrl_alu_ctrl		(ex_ctrl_alu_control	),
		.o_ex_ctrl_alu_b_src	(ex_ctrl_alu_b_src		),
		.o_ex_ctrl_rd_src		(ex_ctrl_rd_src			),
		.i_id_rs1_data			(id_rs1_data			),
		.i_id_rs2_data			(id_rs2_data			),
		.i_id_rs1_addr			(id_rs1_addr			),
		.i_id_rs2_addr			(id_rs2_addr			),
		.i_id_rd_addr			(id_rd_addr				),
		.i_id_imm				(id_imm					),
		.i_id_pc				(id_pc					),
		.i_id_pc_plus_4			(id_pc_plus_4			),
		.o_ex_rs1_data			(ex_rs1_data			),
		.o_ex_rs2_data			(ex_rs2_data			),
		.o_ex_rs1_addr			(ex_rs1_addr			),
		.o_ex_rs2_addr			(ex_rs2_addr			),
		.o_ex_rd_addr			(ex_rd_addr				),
		.o_ex_imm				(ex_imm					),
		.o_ex_pc				(ex_pc					),
		.o_ex_pc_plus_4			(ex_pc_plus_4			)
	);

	riscv_ex
	u_riscv_ex(
		.i_clk					(i_clk					),
		.i_rstn					(i_rstn					),
		.i_ex_ctrl_jump			(ex_ctrl_jump			),
		.i_ex_ctrl_branch		(ex_ctrl_branch			),
		.i_ex_ctrl_alu_b_src	(ex_ctrl_alu_b_src		),
		.i_ex_funct3			(ex_funct3				),
		.i_ForwardAE			(forwardAE				),
		.i_ForwardBE			(forwardBE				),
		.i_ex_forward_rd_data	(wb_rd_data				),
		.i_ex_forward_alu_result(mem_rd_result			),
		.i_ex_rs1_data			(ex_rs1_data			),
		.i_ex_rs2_data			(ex_rs2_data			),
		.i_ex_imm				(ex_imm					),
		.i_ex_pc				(ex_pc					),
		.i_ex_ctrl_alu_ctrl		(ex_ctrl_alu_control 	),
		.o_ex_alu_zero			(ex_alu_zero			),
		.o_ex_alu_result		(ex_alu_result			),
		.o_ex_write_data		(ex_write_data			),
		.o_ex_pc_plus_imm		(ex_pc_plus_imm			),
		.o_ex_ctrl_pc_src		(ex_src_pc				)
	);

	riscv_exmem_reg
	u_riscv_exmem_reg(
		.i_clk					(i_clk					),
		.i_rstn					(i_rstn					),
		.i_ex_funct3			(ex_funct3				),
		.o_mem_funct3			(mem_funct3				),
		.i_ex_ctrl_rd_src		(ex_ctrl_rd_src			),
		.i_ex_ctrl_reg_write	(ex_ctrl_reg_write		),
		.i_ex_ctrl_mem_write	(ex_ctrl_mem_write		),
		.i_ex_ctrl_result_src	(ex_ctrl_result_src		),
		.i_ex_ctrl_byte_sel		(ex_ctrl_byte_sel		),
		.o_mem_ctrl_rd_src		(mem_ctrl_rd_src		),
		.o_mem_ctrl_reg_write	(mem_ctrl_reg_write		),
		.o_mem_ctrl_mem_write	(mem_ctrl_mem_write		),
		.o_mem_ctrl_result_src	(mem_ctrl_result_src	),
		.o_mem_ctrl_byte_sel	(mem_ctrl_byte_sel		),
		.i_ex_rd_addr			(ex_rd_addr				),
		.i_ex_imm				(ex_imm					),
		.i_ex_pc_plus_4			(ex_pc_plus_4			),
		.i_ex_pc_plus_imm		(ex_pc_plus_imm			),
		.i_ex_alu_result		(ex_alu_result			),
		.i_ex_write_data		(ex_write_data			),
		.o_mem_rd_addr			(mem_rd_addr			),
		.o_mem_imm				(mem_imm				),
		.o_mem_alu_result		(mem_alu_result			),
		.o_mem_pc_plus_4		(mem_pc_plus_4			),
		.o_mem_pc_plus_imm		(mem_pc_plus_imm		),
		.o_mem_write_data		(mem_write_data			)
	);

	riscv_mem
	u_riscv_mem(
		.i_clk					(i_clk					),
		.i_rstn					(i_rstn					),
		.i_mem_funct3			(mem_funct3				),
		.i_mem_ctrl_result_src	(mem_ctrl_result_src	),
		.i_mem_ctrl_mem_write	(mem_ctrl_mem_write		),
		.i_mem_ctrl_byte_sel	(mem_ctrl_byte_sel		),
		.i_mem_write_data		(mem_write_data			),
		.i_mem_alu_result		(mem_alu_result			),
		.i_mem_imm				(mem_imm				),
		.i_mem_pc_plus_imm		(mem_pc_plus_imm		),
		.i_mem_pc_plus_4		(mem_pc_plus_4			),
		.o_mem_rd_result		(mem_rd_result			),
		.o_mem_read_data		(mem_read_data			)
	);

	wire wb_ctrl_rd_src;
	wire [`XLEN-1:0] wb_rd_result;
	riscv_memwb_reg
	u_riscv_memwb_reg(
		.i_clk					(i_clk				),
		.i_rstn					(i_rstn				),
		.i_mem_ctrl_reg_write	(mem_ctrl_reg_write	),
		.i_mem_ctrl_rd_src		(mem_ctrl_rd_src	),
		.o_wb_ctrl_reg_write	(wb_ctrl_reg_write	),
		.o_wb_ctrl_rd_src		(wb_ctrl_rd_src		),
		.i_mem_rd_addr			(mem_rd_addr		),
		.i_mem_rd_result		(mem_rd_result		),
		.i_mem_read_data		(mem_read_data		),
		.o_wb_rd_addr			(wb_rd_addr			),
		.o_wb_rd_result			(wb_rd_result		),
		.o_wb_read_data			(wb_read_data		)
	);

	riscv_wb
	u_riscv_wb(
		.i_wb_ctrl_rd_src	(wb_ctrl_rd_src		),
		.i_wb_rd_data		(wb_rd_result		),
		.i_wb_read_data		(wb_read_data		),
		.o_wb_rd_result		(wb_rd_data			)
	);

endmodule
