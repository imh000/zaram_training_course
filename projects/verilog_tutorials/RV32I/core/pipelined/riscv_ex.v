`ifndef NOINC
`include "../common/riscv_configs.v"
`include "../common/riscv_mux.v"
`include "../common/riscv_adder.v"
`include "../common/riscv_alu.v"
`include "riscv_control_unit.v"
`endif

module riscv_ex
(
	input i_clk,
	input i_rstn,

	//ex_ctrl
	input [3:0] i_ex_ctrl_alu_ctrl,
	input [1:0] i_ex_ctrl_jump,
	input i_ex_ctrl_branch,
	input i_ex_ctrl_alu_b_src,
	input [2:0] i_ex_funct3,
	//hazard
	input [1:0] i_ForwardAE,
	input [1:0] i_ForwardBE,
	input [`XLEN-1:0] i_ex_forward_rd_data,
	input [`XLEN-1:0] i_ex_forward_alu_result,

	//ex input from id
	input [`XLEN-1:0] i_ex_rs1_data,
	input [`XLEN-1:0] i_ex_rs2_data,
	input [`XLEN-1:0] i_ex_imm,
	input [`XLEN-1:0] i_ex_pc,

	// alu result
	output o_ex_alu_zero,
	output [`XLEN-1:0] o_ex_alu_result,
	output [`XLEN-1:0] o_ex_write_data,

	output [`XLEN-1:0] o_ex_pc_plus_imm,
	output reg [1:0] o_ex_ctrl_pc_src
);
	
	// mux_concat
	wire [(3*`XLEN)-1:0] mux_concat_src_rs1;
	wire [(3*`XLEN)-1:0] mux_concat_src_rs2;
	wire [(2*`XLEN)-1:0] mux_concat_alu_b;

	wire [`XLEN-1:0] src_rs2_data;
	wire [`XLEN-1:0] alu_a;
	wire [`XLEN-1:0] alu_b;

	assign mux_concat_src_rs1	= {i_ex_forward_alu_result, i_ex_forward_rd_data, i_ex_rs1_data};
	assign mux_concat_src_rs2	= {i_ex_forward_alu_result, i_ex_forward_rd_data, i_ex_rs2_data};
	assign mux_concat_alu_b		= {i_ex_imm, src_rs2_data};

	// pc_src
	assign o_ex_write_data = src_rs2_data;
	
	// branch alu zero
	reg take_branch;

	always @ (*) begin
		case(i_ex_funct3)
			`FUNCT3_BRANCH_BEQ	   : take_branch = o_ex_alu_zero;
			`FUNCT3_BRANCH_BNE	   : take_branch = !o_ex_alu_zero;
			`FUNCT3_BRANCH_BLT	   : take_branch = !o_ex_alu_zero;
			`FUNCT3_BRANCH_BGE	   : take_branch = o_ex_alu_zero;
			`FUNCT3_BRANCH_BLTU    : take_branch = !o_ex_alu_zero;
			`FUNCT3_BRANCH_BGEU    : take_branch = o_ex_alu_zero;
			default				   : take_branch = 1'b0;
		endcase
	end

	// o_ex_ctrl_pc_src
	always @ (*) begin
		if(i_ex_ctrl_branch && take_branch)
			o_ex_ctrl_pc_src = 2'b01;
		else if(i_ex_ctrl_jump == 2'b01)
			o_ex_ctrl_pc_src = 2'b01;
		else if(i_ex_ctrl_jump == 2'b10)
			o_ex_ctrl_pc_src = 2'b10;
		else
			o_ex_ctrl_pc_src = 2'b00;
	end
	
	riscv_mux
	#(
		.N_MUX_IN			(3					)
	)
	u_riscv_mux_rs1(
		.i_mux_sel			(i_ForwardAE		),
		.i_mux_concat_data	(mux_concat_src_rs1	),
		.o_mux_data			(alu_a				)
	);

	riscv_mux
	#(
		.N_MUX_IN			(3					)
	)
	u_riscv_mux_rs2(
		.i_mux_sel			(i_ForwardBE		),
		.i_mux_concat_data	(mux_concat_src_rs2	),
		.o_mux_data			(src_rs2_data		)
	);

	riscv_mux
	#(
		.N_MUX_IN			(2					)
	)
	u_riscv_mux_alu_b(
		.i_mux_sel			(i_ex_ctrl_alu_b_src),
		.i_mux_concat_data	(mux_concat_alu_b	),
		.o_mux_data			(alu_b				)
	);

	riscv_alu
	u_riscv_alu(
		.i_alu_ctrl			(i_ex_ctrl_alu_ctrl	),
		.i_alu_a			(alu_a				),
		.i_alu_b			(alu_b				),
		.o_alu_zero			(o_ex_alu_zero		),
		.o_alu_result		(o_ex_alu_result	)
	);

	riscv_adder
	u_riscv_adder(
		.i_adder_a			(i_ex_pc			),
		.i_adder_b			(i_ex_imm			),
		.o_adder_sum		(o_ex_pc_plus_imm	)
	);

endmodule
