
`define CLKFREQ		100
`define NVEC		50
`define SIMCYCLE	`NVEC
`include "latch_vs_dff.v"

module latch_vs_dff_tb();
	parameter num = 1;
	reg clk;
	reg	[num-1:0] d;
	wire	[num-1:0]	 q_latch;
	wire	[num-1:0]	 q_dff;

	latch
	u_latch(
		.clk				(clk				),
		.d					(d					),
		.q					(q_latch					)
	);

	dff
	u_dff(
		.clk				(clk				),
		.d					(d					),
		.q					(q_dff					)
	);



	always #(500/`CLKFREQ) clk = ~clk;

	task init;
		begin
			d				= 0;
			clk				= 0;
		end
	endtask

	integer		i, j;
	initial begin
		init();
		for (i=0; i<`SIMCYCLE; i++) begin
			j = $urandom_range(0,10);
			#(((j*0.1)) * 1000/`CLKFREQ);
			d = $random;
			#((1-(j*0.1)) * 1000/`CLKFREQ);
		end
		$finish;
	end

// --------------------------------------------------
//	Dump VCD
// --------------------------------------------------
	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end else begin
			$dumpfile("latch_vs_dff.vcd");
			$dumpvars;
		end
	end

endmodule
