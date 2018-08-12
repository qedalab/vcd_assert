`define t 17.5

`ifndef begin_time
`define begin_time 8
`endif

`timescale 1ps/100fs
module tb_one_bit_adder;
    reg a = 0;
    reg b = 0;
    reg cin = 0;
    reg clk = 0;

    initial begin
        $dumpfile("tb_one_bit_adder.vcd");
        $dumpvars;

        #`begin_time
        #`t clk = !clk;

        #`t a = !a;
        #`t clk = !clk;

        #`t b = !b;
        #`t clk = !clk;

        #`t cin = !cin;
        #`t clk = !clk;

        #`t a = !a;
        b = !b;
        #`t clk = !clk;

        #`t a = !a;
        cin = !cin;
        #`t clk = !clk;

        #`t b = !b;
        cin = !cin;
        #`t clk = !clk;

        #`t b = !b;
        a = !a;
        cin = !cin;

        #`t clk = !clk;
        #`t;
        #`t clk = !clk;
        #`t;
        #`t clk = !clk;

        #`t;
        #`t;
        #`t;
        #`t;
        #`t;

        $finish;
    end

    initial begin
        $display("\t\ttime,\tcin,\ta,\tb,\tclk,\tsum,\tcout");
        $monitor("%d,\t%b,\t%b,\t%b,\t%b,\t%b,\t%b",$time,cin,a,b,clk,sum,cout);
    end

    basic_one_bit_adder DUT (cin, a, b, clk, sum ,cout);

endmodule
