module alu (
	input wire [15:0] in_a,
	input wire [15:0] in_b, 
	input wire [2:0] select,
	output wire [15:0] alu_out);

    reg [15:0] ar_out_temp;
    assign alu_out = ar_out_temp;
    always @(*) begin
        case(select)
            3'b000: ar_out_temp = in_a + in_b; 
            3'b001: ar_out_temp = in_a - in_b;
            3'b010: ar_out_temp = in_a & in_b;
            3'b011: ar_out_temp = in_a | in_b;
            3'b100: ar_out_temp = in_a ^ in_b;  
            3'b101: ar_out_temp = in_a << (in_b % 16);
            3'b110: ar_out_temp = in_a >> (in_b % 16);
            3'b111: begin
                    if(in_a == in_b) ar_out_temp = 16'd0;
                    else if(in_a > in_b) ar_out_temp = 16'd1;
                    else ar_out_temp = 16'd2;
            end
        endcase
    end
endmodule

