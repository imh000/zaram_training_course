`define CLKFREQ		100
`define SIMCYCLE	50	

`include "blockings.v"

module blockings_tb();

	reg    clk;
	reg    d;
	wire   q_block;
	wire   q_non_block;

	block
	u_block(
		.clk				(clk				),
		.d					(d					),
		.q					(q_block					)
	);

	non_block
	u_non_block(
		.clk				(clk				),
		.d					(d					),
		.q					(q_non_block		)
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
			d = $urandom;
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
			$dumpfile("blockings.vcd");
			$dumpvars;
		end
	end

endmodule
