
// FOR CMAKE TEST PURPOSES
`ifndef t
`define t 15
`endif

// FOR CMAKE TEST PURPOSES
`ifndef begin_time
`define begin_time 8
`endif

`timescale 1ps/100fs
module tb_full_adder_1bit;

    reg a = 0;
    reg b = 0;
    reg cin = 0;
    reg clk = 0;

    initial begin
        $dumpfile("tb_full_adder_1bit.vcd");
        
        `ifndef IVERILOG_WORKAROUND
        $sdf_annotate("../../examples_cell_library_typ.sdf", tb_full_adder_1bit);
        `endif

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

    full_adder_1bit DUT (cin, a, b, clk, sum ,cout);

endmodule
