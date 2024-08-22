// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: HyeRyun Lim (imh2880@gmail.com)
//	* Filename		: ALU.v
//	* Date			: 2024-06-28 15:31:49
//	* Description	: 
// ==================================================

module ALU
(
	input		 [2:0]  F,
	input		 [31:0] A,
	input		 [31:0] B,
	output reg	 [31:0] ALUOut,
	output reg			Cout
);

	always @ (*) begin
		case(F)
			0 : ALUOut = A & B;
			1 : ALUOut = A | B;
			2 : {Cout, ALUOut} = A + B;
			4 : ALUOut = A & ~B;
			5 : ALUOut = A | ~B;
			6 : ALUOut = A - B;
			7 : ALUOut = A < B;
			default : {Cout, ALUOut} = 0;
		endcase
	end
endmodule

