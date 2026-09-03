`timescale 1 ns/10 ps  // time-unit = 1 ns, precision = 10 ps

// dummy implementation, please replace with your own
module combinational_circuits ( 
    input p1a, p1b, p1c, p1d, p1e, p1f,
    output p1y,
    input p2a, p2b, p2c, p2d,
    output p2y );

    assign p2ab = p2a & p2b;
    assign p2cd = p2c & p2d;
    assign cbf = p1c & p1b & p1f;

    assign p1y = cbf | fed;
    assign p2y = p2ab | p2cd;

endmodule
