// Adapted 
`timescale 1ps/100fs
module tb_basic_xor;
   reg a = 0;
   reg b = 0;
   reg clk = 0;
   initial
      begin
         $dumpfile("tb_basic_xor.vcd");
         $dumpvars;
         // Now in state 0
         #20 a = !a;
         // Now in state 1
         #10 a = !a;
         // Now in state 1
         #10 b = !b;
         // Now in state 0
         #10 b = !b;
         // Now in state 2
         #10 a = !a;
         // Now in state 0
         #10 clk = !clk;
         // Now in state 0
      end

   initial
      begin
         $display("\t\ttime,\ta,\tb,\tclk,\tout");
         $monitor("%d,\t%b,\t%b,\t%b,\t%b",$time,a,b,clk,out);
      end

   basic_xor DUT (a, b, clk, out);

   initial
      #80 $finish;
endmodule
