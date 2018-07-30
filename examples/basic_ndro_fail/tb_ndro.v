// Adapted from timEx generated files for vcd_assert testing
`timescale 1ps/100fs
module tb_basic_ndro;
  reg set = 0;
  reg reset = 0;
  reg clk = 0;

  initial begin
      $sdf_annotate("../ndro.sdf", tb_basic_ndro);
      $dumpfile("tb_basic_ndro.vcd");
      $dumpvars;

      #20 set = !set;
      #10 set = !set;
      #10 reset = !reset;
      #10 reset = !reset;
      #10 clk = !clk;
      #2 reset = !reset; // timing violation
  end

  initial begin
      $display("\t\ttime,\tset,\treset,\tclk,\tout");
      $monitor("%d,\t%b,\t%b,\t%b,\t%b",$time,set,reset,clk,out);
  end

  basic_ndro DUT (set, reset, clk, out);

  initial #70 $finish;
endmodule
