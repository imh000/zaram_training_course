
`define CLKFREQ		10 //MHz
`define SIMCYCLE	20

`include "gray_to_bin.v"

module gray_to_bin_tb();
	reg [2:0] gray;
	wire [2:0] bin;

	gray_to_bin
	u_gray_to_bin(
		.gray				(gray				),
		.bin				(bin				)
	);


	integer i;
	initial begin
		gray = 0;
		#(1000/`CLKFREQ);
		gray = 3'd1;
		#(1000/`CLKFREQ);
		gray = 3'd3;
		#(1000/`CLKFREQ);
		gray = 3'd2;
		#(1000/`CLKFREQ);
		gray = 3'd6;
		#(1000/`CLKFREQ);
		gray = 3'd7;
		#(1000/`CLKFREQ);
		gray = 3'd5;
		#(1000/`CLKFREQ);
		gray = 3'd4;
		#(1000/`CLKFREQ);
		end

	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end 
	end
		endmodule
