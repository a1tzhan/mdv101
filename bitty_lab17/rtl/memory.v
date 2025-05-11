module memory(
    input wire [7:0] addr,
    input wire clk,
    output wire [15:0] out
);

    reg [15:0] mem [0:255];
    reg [15:0] reg_out;
    assign out = reg_out;
    
    initial begin
        $readmemh("/mnt/c/Users/Professional/Desktop/mdv101/bitty_lab16/instructions.hex", mem);
    end

    always @(posedge clk) begin
        reg_out <= mem[addr];
    end
endmodule