// Adapted from TimEx generated files for the purpose of testing vcd_assert
`timescale 1ps/100fs
module tb_basic_and;
    reg a = 0;
    reg b = 0;
    reg clk = 0;

    initial begin
        $sdf_annotate("../and.sdf", tb_basic_and);    
        $dumpfile("tb_basic_and.vcd");
        $dumpvars;

        #20 a = !a;
        #10 a = !a;
        #10 b = !b;
        #10 clk = !clk;
        #10 b = !b;
        #10 a = !a;
    end

    initial begin
        $display("\t\ttime,\ta,\tb,\tclk,\tout");
        $monitor("%d,\t%b,\t%b,\t%b,\t%b",$time,a,b,clk,out);
    end

    basic_and DUT (a, b, clk, out);

    initial #80 $finish;
endmodule
