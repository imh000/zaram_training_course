`ifndef NOINC
`include "../common/riscv_configs.v"
`include "../common/riscv_mux.v"
`include "../common/riscv_imem.v"
`include "../common/riscv_adder.v"
`include "../common/riscv_register.v"
`endif

module riscv_if
#(
	parameter REGISTER_INIT = 0
)
(
	input				i_clk,
	input				i_rstn,
	input				i_if_stall,
	input  [1:0]		i_if_src_pc,
	input  [`XLEN-1:0]	i_if_pc_plus_imm,
	input  [`XLEN-1:0] 	i_if_alu_result,
	output [`XLEN-1:0]	o_if_instr,
	output [`XLEN-1:0]	o_if_pc,
	output [`XLEN-1:0]	o_if_pc_plus_4
);

	// pc update
	wire [(3*`XLEN)-1:0] mux_concat_pc;
	wire [`XLEN-1:0] next_pc;
	wire [`XLEN-1:0] current_pc;
	wire [`XLEN-1:0] pc_plus_4;

	// pc_concat
	assign mux_concat_pc = {i_if_alu_result, i_if_pc_plus_imm, pc_plus_4};

	// pc output
	assign o_if_pc = current_pc;
	assign o_if_pc_plus_4 = pc_plus_4;

	riscv_mux
	#(
		.N_MUX_IN			(3					)
	)
	u_riscv_mux_pc(
		.i_mux_sel			(i_if_src_pc		),
		.i_mux_concat_data	(mux_concat_pc		),
		.o_mux_data			(next_pc			)
	);

	riscv_register
	#(
		.REGISTER_INIT		(REGISTER_INIT		)
	)
	u_riscv_register(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_register_en		(~i_if_stall		),
		.i_register_d		(next_pc			),
		.o_register_q		(current_pc			)
	);

	riscv_adder
	u_riscv_adder(
		.i_adder_a			(current_pc			),
		.i_adder_b			(32'd4				),
		.o_adder_sum		(pc_plus_4			)
	);

	riscv_imem
	u_riscv_imem(
		.i_clk				(i_clk							),
		.i_imem_addr		(current_pc[`IMEM_ADDR_BIT-1:2]	),
		.o_imem_data		(o_if_instr						)
	);

endmodule
