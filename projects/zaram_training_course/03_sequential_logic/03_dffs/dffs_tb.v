
`define CLKFREQ		100
`define NVEC		50
`define SIMCYCLE	`NVEC
`include "dffs.v"
module dffs_tb();
	reg clk; 
	reg d;
	reg rstn;
	wire	 q_sync;
	wire	q_async;

	dff_sync
	u_dff_sync(
		.clk				(clk				),
		.d					(d					),
		.rstn				(rstn				),
		.q					(q_sync				)
	);

	dff_async
	u_dff_async(
		.clk				(clk				),
		.d					(d					),
		.rstn				(rstn				),
		.q					(q_async			)
	);

	
	always #(500/`CLKFREQ) clk = ~clk;

	task init;
		begin
			d				= 0;
			clk				= 0;
			rstn			= 0;
		end
	endtask

	task resetReleaseAfterNCycles;
		input [9:0] n;
		begin
			#(n*1000/`CLKFREQ);
			rstn = 1'b1;
		end
	endtask

	integer		i, j;
	initial begin
		init();
		resetReleaseAfterNCycles(4);
		for (i=0; i<`SIMCYCLE; i++) begin
			j = $urandom_range(0,10);
			#(((j*0.1)) * 1000/`CLKFREQ);
			d = $urandom;
			rstn = $urandom;
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
			$dumpfile("dffs.vcd");
			$dumpvars;
		end
	end

endmodule

