// ---------------------------------------------------------------------------
// Verilog testbench file, created with TimEx v1.00.02
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// ---------------------------------------------------------------------------
`timescale 1ps/100fs
module tb_mitll_and;
   reg a = 0;
   reg b = 0;
   reg clk = 0;
   initial
      begin
         $dumpfile("tb_mitll_and.vcd");
         $dumpvars;
         // Now in state 0
         #20 a = !a;
         // Now in state 1
         #10 a = !a;
         // Now in state 1
         #10 b = !b;
         // Now in state 3
         // Input "a" leads to error state; not fired.
         // Now in state 3
         // Input "b" leads to error state; not fired.
         // Now in state 3
         #10 clk = !clk;
         // Now in state 0
         #10 b = !b;
         // Now in state 2
         #10 a = !a;
         // Now in state 3
      end

   initial
      begin
         $display("\t\ttime,\ta,\tb,\tclk,\tout");
         $monitor("%d,\t%b,\t%b,\t%b,\t%b",$time,a,b,clk,out);
      end

   mitll_and DUT (a, b, clk, out);

   initial
      #80 $finish;
endmodule
