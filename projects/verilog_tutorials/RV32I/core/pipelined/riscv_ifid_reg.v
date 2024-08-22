`ifndef NOINC
`include "../common/riscv_configs.v"
`endif

module riscv_ifid_reg
(
	input i_clk,
	input i_rstn,

	input i_id_stall,
	input i_id_flush,

	input [`XLEN-1:0] i_if_instr,
	input [`XLEN-1:0] i_if_pc,
	input [`XLEN-1:0] i_if_pc_plus_4,
	output reg [`XLEN-1:0] o_id_instr,
	output reg [`XLEN-1:0] o_id_pc,
	output reg [`XLEN-1:0] o_id_pc_plus_4
);

	always @ (posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_id_instr <= 0;
			o_id_pc <= 0;
			o_id_pc_plus_4 <= 0;
		end
		else if(i_id_flush) begin
			o_id_instr <= 0;
			o_id_pc <= 0;
			o_id_pc_plus_4 <= 0;
		end
		else if(!i_id_stall) begin
			o_id_instr <= i_if_instr;
			o_id_pc <= i_if_pc;
			o_id_pc_plus_4 <= i_if_pc_plus_4;
		end
		else begin
			o_id_instr <= o_id_instr;
			o_id_pc <= o_id_pc;
			o_id_pc_plus_4 <= o_id_pc_plus_4;
		end
	end
			
endmodule
