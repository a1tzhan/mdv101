module pc(
    input wire clk,
    input wire en_pc,               // Enable PC update
    input wire reset,               // Active-low reset
    input wire [7:0] d_in,          // Input memory address (next PC value)
    output wire [7:0] d_out         // Output memory address (current PC value)
);
    reg [7:0] reg_d_out;
    assign d_out = reg_d_out;
    always @(posedge clk or negedge reset)begin
            if(!reset) reg_d_out <= 8'b0;
            else if(en_pc) reg_d_out <= d_in;
        end
endmodule