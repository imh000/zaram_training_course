`ifndef NOINC
`include "../common/riscv_configs.v"
`include "../common/riscv_register_file.v"
`include "../common/riscv_immdecode.v"
`include "riscv_control_unit.v"
`endif

module riscv_id
(
	input i_clk,
	input i_rstn,

	input [4:0] i_id_rd_addr,
	input i_id_wb_reg_write,
	input [`XLEN-1:0] i_id_instr,
	input [`XLEN-1:0] i_id_rd_data,

	output [`XLEN-1:0] o_id_rs1_data,
	output [`XLEN-1:0] o_id_rs2_data,

	output [4:0] o_id_rs1_addr,
	output [4:0] o_id_rs2_addr,
	output [4:0] o_id_rd_addr,
	output [`XLEN-1:0] o_id_imm,

	output [2:0] o_id_funct3,

	output o_id_ctrl_reg_write,
	output [1:0] o_id_ctrl_result_src,
	output o_id_ctrl_mem_write,
	output [1:0] o_id_ctrl_jump,
	output o_id_ctrl_branch,
	output [3:0] o_id_ctrl_alu_control,
	output [3:0] o_id_ctrl_byte_sel,
	output o_id_ctrl_alu_b_src,
	output o_id_ctrl_rd_src
);

	wire [2:0] id_imm_src;

	assign o_id_rs1_addr = i_id_instr[19:15];
	assign o_id_rs2_addr = i_id_instr[24:20];
	assign o_id_rd_addr = i_id_instr[11:7];

	assign o_id_funct3 = i_id_instr[14:12];

	riscv_control_unit
	u_riscv_control_unit(
		.opcode				(i_id_instr[6:0]		),
		.funct3				(i_id_instr[14:12]		),
		.funct7_5b			(i_id_instr[30]			),
		.regwrite			(o_id_ctrl_reg_write	),
		.result_src			(o_id_ctrl_result_src	),
		.memwrite			(o_id_ctrl_mem_write	),
		.jump				(o_id_ctrl_jump			),
		.branch				(o_id_ctrl_branch		),
		.byte_sel			(o_id_ctrl_byte_sel		),
		.alu_control		(o_id_ctrl_alu_control	),
		.rd_src				(o_id_ctrl_rd_src		),
		.alu_b_src			(o_id_ctrl_alu_b_src	),
		.imm_src			(id_imm_src				)
	);

	riscv_register_file
	u_riscv_register_file(
		.i_clk				(i_clk				),
		.i_regfile_rd_wen	(i_id_wb_reg_write	),
		.i_regfile_rs1_addr	(i_id_instr[19:15]	),
		.i_regfile_rs2_addr	(i_id_instr[24:20]	),
		.i_regfile_rd_addr	(i_id_rd_addr		),
		.i_regfile_rd_data	(i_id_rd_data		),
		.o_regfile_rs1_data	(o_id_rs1_data		),
		.o_regfile_rs2_data	(o_id_rs2_data		)
	);

	riscv_immdecode
	u_riscv_immdecode(
		.i_imm_scr			(id_imm_src			),
		.i_imm_instr		(i_id_instr			),
		.o_imm_decode		(o_id_imm			)
	);

endmodule
