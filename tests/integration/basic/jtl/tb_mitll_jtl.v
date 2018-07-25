// ---------------------------------------------------------------------------
// Verilog testbench file, created with TimEx v1.00.02
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// ---------------------------------------------------------------------------
`timescale 1ps/100fs
module tb_mitll_jtl;
   reg in = 0;
   initial
      begin
         $dumpfile("tb_mitll_jtl.vcd");
         $dumpvars;
         // Now in state 0
         #20 in = !in;
         // Now in state 0
      end

   initial
      begin
         $display("\t\ttime,\tin,\tout");
         $monitor("%d,\t%b,\t%b",$time,in,out);
      end

   mitll_jtl DUT (in, out);

   initial
      #30 $finish;
endmodule
