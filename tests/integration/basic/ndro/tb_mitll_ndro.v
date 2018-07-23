// ---------------------------------------------------------------------------
// Verilog testbench file, created with TimEx v1.00.02
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// ---------------------------------------------------------------------------
`timescale 1ps/100fs
module tb_mitll_ndro;
   reg set = 0;
   reg reset = 0;
   reg clk = 0;
   initial
      begin
         $dumpfile("tb_mitll_ndro.vcd");
         $dumpvars;
         // Now in state 0
         #20 set = !set;
         // Now in state 1
         #10 set = !set;
         // Now in state 1
         #10 reset = !reset;
         // Now in state 0
         #10 reset = !reset;
         // Now in state 0
         #10 clk = !clk;
         // Now in state 0
      end

   initial
      begin
         $display("\t\ttime,\tset,\treset,\tclk,\tout");
         $monitor("%d,\t%b,\t%b,\t%b,\t%b",$time,set,reset,clk,out);
      end

   mitll_ndro DUT (set, reset, clk, out);

   initial
      #70 $finish;
endmodule
