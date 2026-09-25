//module `include "fp32.v"
`default_nettype none

/*
    input                   i_clk,
    input                   i_rst_n,
    input  [DATA_WIDTH-1:0] i_data_a,
    input  [DATA_WIDTH-1:0] i_data_b,
    input  [INST_WIDTH-1:0] i_inst,
    input                   i_valid,
    output [DATA_WIDTH-1:0] o_data,
    output                  o_valid
*/

module tb_fpvvp32 #(
    parameter DATA_WIDTH = 32,
    parameter INST_WIDTH = 2
    );

reg test_clk;
reg test_rst_n;
reg [DATA_WIDTH-1:0] test_a;
reg [DATA_WIDTH-1:0] test_b;
reg [INST_WIDTH-1:0] test_i_inst;
reg test_i_valid;
wire [DATA_WIDTH-1:0] test_data;
wire test_valid;

fp32 dut
(
    .i_clk (test_clk),
    .i_rst_n (test_rst_n),
    .i_data_a(test_a),
    .i_data_b(test_b),
    .i_inst(test_i_inst),
    .i_valid(test_i_valid),
    .o_data(test_data),
    .o_valid(test_valid)
);

localparam test_clk_PERIOD = 10;
always #(test_clk_PERIOD/2) test_clk=~test_clk;

initial begin
    $dumpfile("tb_fp32.vcd");
    $dumpvars(0, tb_fp32);
end

/*
initial begin
    #1 test_rst_n<=1'bx;test_clk<=1'bx;
    #(test_clk_PERIOD*3) test_rst_n<=1;
    #(test_clk_PERIOD*3) test_rst_n<=0;test_clk<=0;
    repeat(5) @(posedge test_clk);
    test_rst_n<=1;
    @(posedge test_clk);
    repeat(2) @(posedge test_clk);
    $finish(2);
end
*/

always @(posedge test_clk) begin
    $display("Hello");
end

endmodule
`default_nettype wire