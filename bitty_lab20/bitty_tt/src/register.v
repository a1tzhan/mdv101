module register(
    input wire clk,
    input wire reset,
    input wire en,
    input wire [15:0] d_in,
    output wire [15:0] d_out
);
    reg [15:0] reg_d_out;
    assign d_out = reg_d_out;
    always @(posedge clk or posedge reset)begin
            if(!reset) reg_d_out <= 16'b0;
            else if(en) reg_d_out <= d_in;
        end
endmodule