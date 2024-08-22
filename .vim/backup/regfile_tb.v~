// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		32		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"regfile.v"

module regfile_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg clk;
	reg wen;
	reg [BW_ADDR-1:0] rd_addr0;
	reg [BW_ADDR-1:0] rd_addr1;
	reg [BW_ADDR-1:0] wr_addr;
	reg [BW_DATA-1:0] wr_data;
	wire [BW_DATA-1:0] rd_data0;
	wire [BW_DATA-1:0] rd_data1;

	parameter BW_DATA = 32;
	parameter BW_ADDR = 5;

	regfile
	#(
		.BW_DATA			(BW_DATA			),
		.BW_ADDR			(BW_ADDR			)
	)
	u_regfile(
		.clk				(clk				),
		.wen				(wen				),
		.rd_addr0			(rd_addr0			),
		.rd_addr1			(rd_addr1			),
		.wr_addr			(wr_addr			),
		.wr_data			(wr_data			),
		.rd_data0			(rd_data0			),
		.rd_data1			(rd_data1			)
	);


// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg [8*32-1:0] taskState;
	integer err = 0;

	task init;
		begin
			taskState = "Init";
			clk		= 0;
			wen		= 0;
			rd_addr0 = 0;
			rd_addr1 = 0;
			wr_addr = 0;
			wr_data = 0;
		end
	endtask


	always #(500/`CLKFREQ) clk = ~clk;

	task regWR;
		input	[BW_ADDR-1:0] t_wr_addr;
		input	[BW_DATA-1:0] t_wr_data;
		begin
			@(negedge clk) begin
				taskState = "WR";
				wr_data = t_wr_data;
				wr_addr = t_wr_addr;
				wen  = 1;
			end
		end
	endtask

	task regRD;
		input	[BW_ADDR-1:0] t_rd_addr0;
		input	[BW_ADDR-1:0] t_rd_addr1;
		begin
			@(negedge clk) begin
				taskState = "RD";
				rd_addr0 = t_rd_addr0;
				rd_addr1 = t_rd_addr1;
				wen = 0;
			end
		end
	endtask
// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		#(4*1000/`CLKFREQ);

		for (i=0; i<`SIMCYCLE; i++) begin
			regWR(i, i);
		end
		for (i=0; i<`SIMCYCLE; i++) begin
			regRD(i, i);
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			regWR(i, $urandom_range(0, 2**BW_DATA-1));
			#(1000/`CLKFREQ);
			regRD(i, i);
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
			for (i=0; i<`SIMCYCLE; i++) begin
				$dumpvars(0, u_regfile.rf_arr[i]);
			end
			$dumpvars;
		end else begin
			$dumpfile("regfile_tb.vcd");
			$dumpvars;
		end
	end

endmodule
