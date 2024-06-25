
`define CLKFREQ		10 //MHz
`define SIMCYCLE	20

`include "bin_to_gray.v"

module bin_to_gray_tb();
	reg [2:0] bin;
	wire	 [2:0] gray;

	bin_to_gray
	u_bin_to_gray(
		.bin				(bin				),
		.gray				(gray				)
	);

	integer i;
	initial begin
		bin = 0;
		#(1000/`CLKFREQ);
		bin = 3'd1;
		#(1000/`CLKFREQ);
		bin = 3'd2;
		#(1000/`CLKFREQ);
		bin = 3'd3;
		#(1000/`CLKFREQ);
		bin = 3'd4;
		#(1000/`CLKFREQ);
		bin = 3'd5;
		#(1000/`CLKFREQ);
		bin = 3'd6;
		#(1000/`CLKFREQ);
		bin = 3'd7;
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
