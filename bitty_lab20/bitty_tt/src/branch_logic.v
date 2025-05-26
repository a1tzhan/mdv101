module branch_logic(
    input wire [7:0] address,
    /* verilator lint_off UNUSED */
    input wire [15:0] instruction,
    input wire [15:0] last_alu_result,
    /* verilator lint_on UNUSED */
    output wire [7:0] new_pc
    );

    reg  [7:0] reg_new_pc;
    
    assign new_pc = reg_new_pc;

    always @(*) begin
        if(instruction[1:0] == 2'b10) begin
            case(instruction[3:2])
                2'b00: begin
                    if(last_alu_result == 16'd0) begin
                        reg_new_pc = instruction[11:4];
                    end else begin
                        reg_new_pc = address + 1;
                    end
                end
                2'b01: begin
                    if(last_alu_result == 16'd1) begin
                        reg_new_pc = instruction[11:4];
                    end else begin
                        reg_new_pc = address + 1;
                    end
                end
                2'b10: begin
                    if(last_alu_result == 16'd2) begin
                        reg_new_pc = instruction[11:4];
                    end else begin
                        reg_new_pc = address + 1;
                    end
                end
                default: reg_new_pc = address + 1;
            endcase
        end else reg_new_pc = address + 1;
    end

endmodule

