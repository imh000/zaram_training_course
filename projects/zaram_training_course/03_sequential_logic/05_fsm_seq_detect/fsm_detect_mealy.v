module fsm_detect_mealy
(
	input clk,
	input rstn,
	input in,
	output reg out
);

	parameter IDLE=0, s1=1, s2=2, s3=3;
	reg [1:0] state;
	reg [1:0] next_state;
	

	always @ (*) begin
		case(state)
			IDLE : next_state = in ? s1 : IDLE;
			s1 : next_state = in ? s1 : s2;
			s2 : next_state = in ? s3 : IDLE;
			s3 : next_state = in ? IDLE : s2;
		endcase
	end
		
	always @ (posedge clk or negedge rstn) begin
		if(!rstn) 
			state <= IDLE;
		else 
			state <= next_state;
	end
	
	always @ (posedge clk) begin
		case(state)
			s3 : out = in; 
			default : out = 0;
		endcase
	end
endmodule
