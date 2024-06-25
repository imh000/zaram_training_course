
// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		10		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"even_parity.v"

module even_parity_tb();

	reg    [7:0]     a;
	wire	    parity;

	even_parity
	u_even_parity(
		.a					(a					),
		.parity				(parity				)
	);


	integer i;
	initial begin
		for (i = 0; i < `SIMCYCLE; i++) begin
			a = $random;
			#(1000/`CLKFREQ);
		end
//		#(1000/'CLKFREQ);
		$finish;
	end

	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end
	end
endmodule

