module logic_unit (
    input [15:0] a,
    input [15:0] b,
    input [3:0] sel,
    output wire [15:0] lo_out
);
    reg [15:0] lo_out_temp;
    assign lo_out = lo_out_temp;
    always @(*) begin
        case(sel)
            4'b0000: lo_out_temp = ~a;
            4'b0001: lo_out_temp = ~(a | b);
            4'b0010: lo_out_temp = (~a) & b;
            4'b0011: lo_out_temp = 16'b0000000000000000;
            4'b0100: lo_out_temp = ~(a & b);
            4'b0101: lo_out_temp = ~b;
            4'b0110: lo_out_temp = a ^ b;
            4'b0111: lo_out_temp = a & (~b);
            4'b1000: lo_out_temp = (~a) | b;
            4'b1001: lo_out_temp = ~(a ^ b);
            4'b1010: lo_out_temp = b;
            4'b1011: lo_out_temp = a & b;
            4'b1100: lo_out_temp = 16'b1111111111111111;
            4'b1101: lo_out_temp = a | (~b);
            4'b1110: lo_out_temp = a | b;
            4'b1111: lo_out_temp = a;
        endcase
    end
endmodule
