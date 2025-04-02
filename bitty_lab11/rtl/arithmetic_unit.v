module arithmetic_unit (
    input [15:0] a,
    input [15:0] b,
    input [3:0] sel, 
    output wire [15:0] ar_out 
); 
    reg [15:0] ar_out_temp;
    assign ar_out = ar_out_temp [15:0];
    always @(*) begin
        case(sel)
            4'b0000: ar_out_temp = a; 
            4'b0001: ar_out_temp = a | b;
            4'b0010: ar_out_temp = a | ~b;
            4'b0011: ar_out_temp = 16'hFFFF;
            4'b0100: ar_out_temp = a | (a & ~b);  
            4'b0101: ar_out_temp = (a | b) + (a & ~b);
            4'b0110: ar_out_temp = a - b - 16'd1;
            4'b0111: ar_out_temp = (a & ~b) - 16'd1;
            4'b1000: ar_out_temp =  a +  (a & b);
            4'b1001: ar_out_temp =  a +  b;
            4'b1010: ar_out_temp =  (a | ~b) +  (a & b);
            4'b1011: ar_out_temp =  (a & b) - 16'd1;
            4'b1100: ar_out_temp =  a +  a;
            4'b1101: ar_out_temp =  (a | b) +  a;
            4'b1110: ar_out_temp =  (a | ~b) +  a;
            4'b1111: ar_out_temp = a - 16'd1;
        endcase
    end
endmodule
