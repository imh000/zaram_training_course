module fsm_detect_mealy
(
	input clk,
	input rstn,
	input in,
	output out
);

	parameter IDLE=0, s1=1, s2=2, s3=3;
	reg i_in;
	reg [1:0] state;
	reg [1:0] next_state;
	

	always @ (*) begin
		case(state)
			IDLE : next_state = i_in ? s1 : IDLE;
			s1 : next_state = i_in ? s1 : s2;
			s2 : next_state = i_in ? s3 : IDLE;
			s3 : next_state = i_in ? IDLE : s2;
		endcase
	end
		
	always @ (posedge clk or negedge rstn) begin
		if(!rstn) begin 
			state <= IDLE;
			i_in <= 0;
		end
		else begin 
			state <= next_state;
			i_in <= in;
		end
	end

	assign out = (state == s3) &i_in;

	`ifdef	DEBUG
		reg [8*32-1:0] stateMonitor;
		always @ (*) begin
			case(state)
				IDLE : stateMonitor = "IDLE";
				s1 : stateMonitor = "s1";
				s2 : stateMonitor = "s2";
				s3 : stateMonitor = "s3";
			endcase
		end
	`endif

endmodule
