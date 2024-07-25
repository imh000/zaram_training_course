`include "../common/riscv_configs.v"

module riscv_immdecode
(
	input	   [2:0]		i_imm_scr,
	input	   [`XLEN-1:0]  i_imm_instr,
	output reg [`XLEN-1:0]  o_imm_decode
);

	always @ (*) begin
		case(i_imm_scr)
			`SRC_IMM_I : o_imm_decode =  {{20{i_imm_instr[31]}}, i_imm_instr[31:20]};
			`SRC_IMM_S : o_imm_decode =  {{20{i_imm_instr[31]}}, i_imm_instr[31:25], i_imm_instr[11:7]};
			`SRC_IMM_B : o_imm_decode =  {{20{i_imm_instr[31]}}, i_imm_instr[7], i_imm_instr[30:25], i_imm_instr[11:8], 1'b0};
			`SRC_IMM_U : o_imm_decode =  {i_imm_instr[31:12], 12'b0};
			`SRC_IMM_J : o_imm_decode =  {{12{i_imm_instr[31]}}, i_imm_instr[19:12], i_imm_instr[20], i_imm_instr[30:21], 1'b0};
			default : o_imm_decode = {`XLEN{1'bx}};
		endcase
	end

endmodule
