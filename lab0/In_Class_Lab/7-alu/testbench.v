module testbench;
    reg [31:0] a;
    reg [31:0] b;
    reg [3:0] instruction;
    wire [31:0] calc_result;

    alu alu1(.i_clk(1'd1), .i_rst_n(1'd0), .i_data_a(a), .i_data_b(b), .i_inst(instruction), .i_valid(1'd1), .o_data(calc_result));

    initial begin
        $dumpfile("alu.vcd");
        $dumpvars(0, testbench);
    end

    initial begin
        a = 0;
        b = 1;
        instruction = 5;
        #10;
        $display("a b instruction result");
        $display("%32d %32d %4d %32d", a, b, instruction, calc_result);
    end

endmodule