// Adapted from TimEx generated files for vcd_assert testing
`timescale 1ps/100fs

module tb_basic_jtl;
    reg in = 0;

    initial begin
        $dumpfile("tb_basic_jtl.vcd");
        $dumpvars;
        // Now in state 0
        #20 in = !in;
        // Now in state 0
    end

    initial begin
        $display("\t\ttime,\tin,\tout");
        $monitor("%d,\t%b,\t%b",$time,in,out);
    end

    basic_jtl DUT (in, out);

    initial #30 $finish;
endmodule
