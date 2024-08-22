`include "../common/riscv_configs.v"

module riscv_register_file
(
	input i_clk,
	input i_regfile_rd_wen,
	input [4:0] i_regfile_rs1_addr,
	input [4:0] i_regfile_rs2_addr,
	input [4:0] i_regfile_rd_addr,
	input [`XLEN-1:0] i_regfile_rd_data,
	output [`XLEN-1:0] o_regfile_rs1_data,
	output [`XLEN-1:0] o_regfile_rs2_data
);

	reg [`XLEN-1:0] registers [0:31];

	assign o_regfile_rs1_data = registers[i_regfile_rs1_addr];
	assign o_regfile_rs2_data = registers[i_regfile_rs2_addr];

	initial registers[0] = `XLEN'b0;

	// pipelined
	always @ (negedge i_clk) begin
		if(i_regfile_rd_wen && (i_regfile_rd_addr != 0))
			registers[i_regfile_rd_addr] = i_regfile_rd_data;
	end
	/*
	// singlecycle
	always @ (posedge i_clk) begin
		if(i_regfile_rd_wen && (i_regfile_rd_addr != 0))
			registers[i_regfile_rd_addr] = i_regfile_rd_data;
	end
*/
endmodule
