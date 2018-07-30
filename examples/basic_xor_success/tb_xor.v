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

         #20 a = !a;
         #10 a = !a;
         #10 b = !b;
         #10 b = !b;
         #10 a = !a;
         #10 clk = !clk;
         #10 a = !a;
         #10 clk = !clk;
         #10 b = !b;
         #10 clk = !clk;
      end

   initial
      begin
         $display("\t\ttime,\ta,\tb,\tclk,\tout");
         $monitor("%d,\t%b,\t%b,\t%b,\t%b",$time,a,b,clk,out);
      end

   basic_xor DUT (a, b, clk, out);

   initial
      #120 $finish;
endmodule
