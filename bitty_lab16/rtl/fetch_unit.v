module fetch_unit(
    input wire clk,
    input wire reset,
    input wire done,
    output wire [15:0] out
);

    wire [7:0] addr;
    wire [7:0] addr_new;
    reg [15:0] reg_out;
    reg [15:0] mem_out;
    wire [15:0] pc_out;
    assign addr = pc_out[7:0];

    assign out = reg_out;
    assign addr_new = addr + 8'd1;

    register pc(.clk(clk), .reset(reset), .en(done), .d_in({8'd0, addr_new}), .d_out(pc_out));

    memory memory01(
        .clk(clk),
        .addr(addr),
        .out(mem_out));

    always @(posedge clk or posedge reset)begin
            if(reset) reg_out <= 0;
            else reg_out <= mem_out;
        end
endmodule