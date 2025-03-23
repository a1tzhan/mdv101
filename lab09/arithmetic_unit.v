module arithmetic_unit (
    input cin,
    input [15:0] a,
    input [15:0] b,
    input [3:0] sel, 
    output reg cout, 
    output reg cmp, 
    output reg [15:0] ar_out 
); 
    reg [16:0] ar_out_temp;
    always @(*) begin
        case(sel)
            4'b0000: ar_out_temp = {1'b0, a}; 
            4'b0001: ar_out_temp = {1'b0, a | b};
            4'b0010: ar_out_temp = {1'b0, a | ~b};
            4'b0011: ar_out_temp = {1'b0, 16'hFFFF};
            4'b0100: ar_out_temp = {1'b0, a | (a & ~b)};  
            4'b0101: ar_out_temp = {1'b0, (a | b)} + {1'b0, (a & ~b)} + {16'b0, cin};
            4'b0110: ar_out_temp = {1'b0, a} - {1'b0, b} - 17'd1 - {16'b0, cin};
            4'b0111: ar_out_temp = {1'b0, (a & ~b)} - 17'd1 - {16'b0, cin};
            4'b1000: ar_out_temp = {1'b0, a} + {1'b0, (a & b)} + {16'b0, cin};
            4'b1001: ar_out_temp = {1'b0, a} + {1'b0, b} + {16'b0, cin};
            4'b1010: ar_out_temp = {1'b0, (a | ~b)} + {1'b0, (a & b)} + {16'b0, cin};
            4'b1011: ar_out_temp = {1'b0, (a & b)} - 17'd1 - {16'b0, cin};
            4'b1100: ar_out_temp = {1'b0, a} + {1'b0, a} + {16'b0, cin};
            4'b1101: ar_out_temp = {1'b0, (a | b)} + {1'b0, a} + {16'b0, cin};
            4'b1110: ar_out_temp = {1'b0, (a | ~b)} + {1'b0, a} + {16'b0, cin};
            4'b1111: ar_out_temp = {1'b0, a} - 17'd1 - {16'b0, cin};
        endcase
        cmp = a == b ? 1 : 0;
        cout = ar_out_temp[16];
        ar_out = ar_out_temp [15:0];
    end
endmodule
