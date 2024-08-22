`ifndef NOINC
`include "../common/riscv_configs.v"
`endif

`define DEBUG

module riscv_control_unit
(
	input [6:0] opcode,
	input [2:0] funct3,
	input funct7_5b,
	output reg regwrite,
	output reg [1:0] result_src,
	output reg memwrite,
	output reg [1:0] jump,
	output reg branch,
	output reg [3:0] byte_sel,
	output reg [3:0] alu_control,
	output reg rd_src,
	output reg alu_b_src,
	output reg [2:0] imm_src
);

	// RegWrite
	always @ (*) begin
		case(opcode)
			`OPCODE_B_BRANCH,
			`OPCODE_S_STORE : regwrite = 1'b0;
			default : regwrite = 1'b1;
		endcase
	end

	// byte_sel
	always @ (*) begin
		case(opcode)
			`OPCODE_S_STORE,
			`OPCODE_I_LOAD : begin
				case(funct3)
					`FUNCT3_MEM_BYTE,
					`FUNCT3_MEM_BYTEU : byte_sel = 4'b0001;
					`FUNCT3_MEM_HALF,
					`FUNCT3_MEM_HALFU : byte_sel = 4'b0011;
					`FUNCT3_MEM_WORD : byte_sel = 4'b1111;
					default : byte_sel = 4'b1111;
				endcase
			end
			default : byte_sel = 4'b1111;
		endcase
	end
	
	// result_src
	always @ (*) begin
		case(opcode)
			`OPCODE_U_LUI  	: result_src = 2'b01;
			`OPCODE_U_AUIPC	: result_src = 2'b10;
			`OPCODE_J_JAL	,
			`OPCODE_I_JALR	: result_src = 2'b11;
			default 		: result_src = 2'b00;
		endcase
	end

	// rd_src
	always @ (*) begin
		case(opcode)
			`OPCODE_I_LOAD : rd_src = 1'b0;
			default : rd_src = 1'b1;
		endcase
	end

	// memwrite
	always @ (*) begin
		case(opcode)
			`OPCODE_S_STORE : memwrite = 1'b1;
			default : memwrite = 1'b0;
		endcase
	end

	// jump
	always @ (*) begin
		case(opcode)
			`OPCODE_J_JAL	: jump = 2'b01;
			`OPCODE_I_JALR	: jump = 2'b10;
			default : jump = 2'b00;
		endcase
	end
	
	// branch
	always @ (*) begin
		case(opcode)
			`OPCODE_B_BRANCH : branch = 1'b1;
			default : branch = 1'b0;
		endcase
	end
	
	//alu_b_src
	always @ (*) begin
		case(opcode)
			`OPCODE_R_OP		,
			`OPCODE_B_BRANCH	: alu_b_src = 1'b0;
			default				: alu_b_src = 1'b1;
		endcase
	end

	// imm_src
	always @ (*) begin
		case(opcode)
			`OPCODE_R_OP	 : imm_src = `SRC_IMM_R;
			`OPCODE_I_OP	 ,
			`OPCODE_I_LOAD	 ,
			`OPCODE_I_JALR	 : imm_src = `SRC_IMM_I;
			`OPCODE_S_STORE	 : imm_src = `SRC_IMM_S;
			`OPCODE_B_BRANCH : imm_src = `SRC_IMM_B;
			`OPCODE_J_JAL	 : imm_src = `SRC_IMM_J;
			`OPCODE_U_LUI	 ,
			`OPCODE_U_AUIPC	 : imm_src = `SRC_IMM_U;
			default			 : imm_src = `SRC_IMM_X;
		endcase
	end

	// alu_control
	always @ (*) begin
		case(opcode)
			`OPCODE_R_OP,
			`OPCODE_I_OP : begin
				case(funct3)
					`FUNCT3_ALU_ADD_SUB : alu_control = ((opcode == `OPCODE_R_OP) && funct7_5b) ? `ALU_CTRL_SUB : `ALU_CTRL_ADD;
					`FUNCT3_ALU_XOR : alu_control = `ALU_CTRL_XOR;
					`FUNCT3_ALU_OR : alu_control = `ALU_CTRL_OR;
					`FUNCT3_ALU_AND : alu_control = `ALU_CTRL_AND;
					`FUNCT3_ALU_SLL : alu_control = `ALU_CTRL_SLL;
					`FUNCT3_ALU_SRL_SRA : alu_control = funct7_5b ? `ALU_CTRL_SRA : `ALU_CTRL_SRL;
					`FUNCT3_ALU_SLT : alu_control = `ALU_CTRL_SLT;
					`FUNCT3_ALU_SLTU : alu_control = `ALU_CTRL_SLTU;
				endcase
			end
			`OPCODE_B_BRANCH : begin
				case(funct3)
					`FUNCT3_BRANCH_BEQ,
					`FUNCT3_BRANCH_BNE : alu_control = `ALU_CTRL_SUB;
					`FUNCT3_BRANCH_BLT,
					`FUNCT3_BRANCH_BGE : alu_control = `ALU_CTRL_SLT;
					`FUNCT3_BRANCH_BLTU,
					`FUNCT3_BRANCH_BGEU : alu_control = `ALU_CTRL_SLTU;
					default : alu_control = `ALU_CTRL_NOP;
				endcase
			end
			default : alu_control = `ALU_CTRL_ADD;
		endcase
	end

	`ifdef	DEBUG
	reg	[8*32-1:0]	DEBUG_INSTR;
	always @(*) begin
		case(opcode)
			`OPCODE_R_OP		: begin
				case(funct3)
					`FUNCT3_ALU_ADD_SUB	: DEBUG_INSTR = funct7_5b ? "sub" : "add" ;
					`FUNCT3_ALU_XOR		: DEBUG_INSTR = "xor"                            ;
					`FUNCT3_ALU_OR		: DEBUG_INSTR = "or"                             ;
					`FUNCT3_ALU_AND		: DEBUG_INSTR = "and"                            ;
					`FUNCT3_ALU_SLL		: DEBUG_INSTR = "sll"                            ;
					`FUNCT3_ALU_SRL_SRA	: DEBUG_INSTR = funct7_5b ? "sra" : "srl" ;
					`FUNCT3_ALU_SLT		: DEBUG_INSTR = "slt"                            ;
					`FUNCT3_ALU_SLTU	: DEBUG_INSTR = "sltu"                           ;
					default				: DEBUG_INSTR = "undef";
				endcase
			end
			`OPCODE_I_OP		: begin
				case(funct3)
					`FUNCT3_ALU_ADD_SUB	: DEBUG_INSTR = "addi"                             ;
					`FUNCT3_ALU_XOR		: DEBUG_INSTR = "xori"                             ;
					`FUNCT3_ALU_OR		: DEBUG_INSTR = "ori"                              ;
					`FUNCT3_ALU_AND		: DEBUG_INSTR = "andi"                             ;
					`FUNCT3_ALU_SLL		: DEBUG_INSTR = "slli"                             ;
					`FUNCT3_ALU_SRL_SRA	: DEBUG_INSTR = funct7_5b ? "srai" : "srli" ;
					`FUNCT3_ALU_SLT		: DEBUG_INSTR = "slti"                             ;
					`FUNCT3_ALU_SLTU	: DEBUG_INSTR = "sltui"                            ;
					default				: DEBUG_INSTR = "undef";
				endcase
			end
			`OPCODE_I_LOAD		: begin
				case(funct3)
					`FUNCT3_MEM_BYTE	: DEBUG_INSTR = "lb"  ;
					`FUNCT3_MEM_HALF	: DEBUG_INSTR = "lh"  ;
					`FUNCT3_MEM_WORD	: DEBUG_INSTR = "lw"  ;
					`FUNCT3_MEM_BYTEU	: DEBUG_INSTR = "lbu" ;
					`FUNCT3_MEM_HALFU	: DEBUG_INSTR = "lhu" ;
					default				: DEBUG_INSTR = "undef";
				endcase
			end
			`OPCODE_S_STORE		: begin
				case(funct3)
					`FUNCT3_MEM_BYTE	: DEBUG_INSTR = "sb";
					`FUNCT3_MEM_HALF	: DEBUG_INSTR = "sh";
					`FUNCT3_MEM_WORD	: DEBUG_INSTR = "sw";
					default				: DEBUG_INSTR = "undef";
				endcase
			end
			`OPCODE_B_BRANCH	: begin
				case(funct3)
					`FUNCT3_BRANCH_BEQ	: DEBUG_INSTR = "beq"  ;
					`FUNCT3_BRANCH_BNE	: DEBUG_INSTR = "bne"  ;
					`FUNCT3_BRANCH_BLT	: DEBUG_INSTR = "blt"  ;
					`FUNCT3_BRANCH_BGE	: DEBUG_INSTR = "bge"  ;
					`FUNCT3_BRANCH_BLTU	: DEBUG_INSTR = "bltu" ;
					`FUNCT3_BRANCH_BGEU	: DEBUG_INSTR = "bgeu" ;
					default				: DEBUG_INSTR = "undef";
				endcase
			end
			`OPCODE_J_JAL		: DEBUG_INSTR = "jal"   ;
			`OPCODE_I_JALR		: DEBUG_INSTR = "jalr"  ;
			`OPCODE_U_LUI		: DEBUG_INSTR = "lui"   ;
			`OPCODE_U_AUIPC		: DEBUG_INSTR = "auipc" ;
			 default				: DEBUG_INSTR = "undef";
		endcase
	end
	`endif

endmodule
