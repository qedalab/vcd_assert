// Adapted from TimEx generated files for vcd_assert testing
`timescale 1ps/100fs
module tb_basic_splitter;
    reg in = 0;

    initial begin
         $dumpfile("tb_basic_splitter.vcd");
         $dumpvars;
         // Now in state 0
         #20 in = !in;
         // Now in state 0
    end

    initial begin
        $display("\t\ttime,\tin,\tout1,\tout2");
        $monitor("%d,\t%b,\t%b,\t%b",$time,in,out1,out2);
    end

    basic_splitter DUT (in, out1, out2);

    initial #30 $finish;
endmodule
