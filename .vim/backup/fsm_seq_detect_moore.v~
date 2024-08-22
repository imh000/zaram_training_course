module fsm_seq_detect_moore
(
	input clk,
	input rstn,
	input i_seq,
	output out
);

	parameter IDLE=0, s1=1, s2=2, s3=3, s4=4;
	reg [2:0] state;
	reg [2:0] next_state;
	reg seq;
	
	always @ (posedge clk or negedge rstn) begin
		if(!rstn) begin
			state <= IDLE;
			seq <= 0;
		end
		else begin
			state <= next_state;
			seq <= i_seq;
		end
	end

	always @ (*) begin
		if(seq == 0) begin
			case(state)
				IDLE : next_state = IDLE;
				s1 : next_state = s2;
				s2 : next_state = IDLE;
				s3 : next_state = s2;
				s4 : next_state = IDLE;
			endcase
		end
		else begin
			case(state)
				IDLE : next_state = s1;
				s1 : next_state = s1;
				s2 : next_state = s3;
				s3 : next_state = s4;
				s4 : next_state = s1;
			endcase
		end
		
	end
		assign out = (state == s4);

	`ifdef	DEBUG
		reg [8*32-1:0] stateMonitor;
		always @ (*) begin
			case(state)
				IDLE : stateMonitor = "IDLE";
				s1 : stateMonitor = "s1";
				s2 : stateMonitor = "s2";
				s3 : stateMonitor = "s3";
				s4 : stateMonitor = "s4";
			endcase
		end
	`endif

endmodule

