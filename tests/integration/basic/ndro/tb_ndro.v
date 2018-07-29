// Adapted from timEx generated files for vcd_assert testing
`timescale 1ps/100fs
module tb_basic_ndro;
  reg set = 0;
  reg reset = 0;
  reg clk = 0;

  initial begin
      $dumpfile("tb_basic_ndro.vcd");
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

  initial begin
      $display("\t\ttime,\tset,\treset,\tclk,\tout");
      $monitor("%d,\t%b,\t%b,\t%b,\t%b",$time,set,reset,clk,out);
  end

  basic_ndro DUT (set, reset, clk, out);

  initial #70 $finish;
endmodule