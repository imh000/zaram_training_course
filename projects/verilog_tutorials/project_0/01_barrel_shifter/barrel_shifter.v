// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: HyeRyun Lim (imh2880@gmail.com)
//	* Filename		: barrel_shifter.v
//	* Date			: 2024-06-28 15:04:07
//	* Description	: 
//	num_shift = number to shift
//	direction = 0: left , 1: right
//	sel : 0: logical shift , 1: arithmetic shift, 2:rotate
//	overflow = logical and arithmetic overflow
// ==================================================
module barrel_shifter
#(
	parameter bit_size = 4
)
(
	input  		 [bit_size-1:0]           data,
	input  		 [$clog2(bit_size)-1:0]   num_shift,
	input  						   		 direction,
	input		 [1:0]			 sel,
	output reg	 [bit_size-1:0] out,
	output reg							 overflow
);
	
	always @ (*) begin
		case(sel)
			0 : {overflow, out} = direction ? (data >> num_shift) : (data << num_shift);
			1 : {overflow, out} = direction ? (data >>> num_shift) : (data <<< num_shift);
			2 : out = direction ? ((data >> num_shift) | (data << (bit_size-num_shift))) :  ((data << num_shift) | (data >> (bit_size-num_shift))); 
			default : out = 0;
			endcase
		end
	
	`ifdef	DEBUG
		reg [8*32-1:0] directMonitor;
		reg [8*32-1:0] selMonitor;
		always @ (*) begin
			case(direction)
				0 : directMonitor = "left";
				1 : directMonitor = "right";
			endcase
			case(sel)
				0 : selMonitor = "logical shift";
				1 : selMonitor = "arith shift";
				2 : selMonitor = "rotate";
			endcase
		end
	`endif

endmodule

