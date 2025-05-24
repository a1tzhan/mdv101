module branch_logic(
    input wire run,
    input wire [15:0] instruction,
    input wire [15:0] last_alu_result,
    input wire [7:0] pc,
    input wire done,
    output wire en_pc,
    output wire bitty_core_run,
    output wire [7:0] new_pc
    );

    reg  [7:0] reg_new_pc;
    
    // avoid warning
    wire [3:0] empty_holder = instruction[15:12];
    wire _unused_holder_used = |empty_holder;

    assign new_pc = reg_new_pc;
    assign bitty_core_run = (instruction[1:0] != 2'b10);
    assign en_pc = (done | ~bitty_core_run) & run;

    always @(*) begin
        if(instruction[1:0] == 2'b10) begin
            case(instruction[3:2])
                2'b00: begin
                    if(last_alu_result == 16'd0) begin
                        reg_new_pc = instruction[11:4];
                    end else begin
                        reg_new_pc = pc + 1;
                    end
                end
                2'b01: begin
                    if(last_alu_result == 16'd1) begin
                        reg_new_pc = instruction[11:4];
                    end else begin
                        reg_new_pc = pc + 1;
                    end
                end
                2'b10: begin
                    if(last_alu_result == 16'd2) begin
                        reg_new_pc = instruction[11:4];
                    end else begin
                        reg_new_pc = pc + 1;
                    end
                end
                default: reg_new_pc = pc + 1;
            endcase
        end else reg_new_pc = pc + 1;
    end

endmodule

