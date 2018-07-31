`timescale 1ps/100fs

module two_bit_adder(cin, a1, a2, b1, b2, clk, sum1, sum2, cout)

  input cin, a1, a2, b1, b2, clk;

  output sum1, sum2, cout;
  wire sum1, sum2, cout;

  wire internal_clk_1,
       internal_clk_2,
       internal_clk_3,
       internal_clk_4,
       internal_clk_5,
       internal_clk_6,
       internal_clk_7,
       internal_clk_8,
       internal_clk_9,
       internal_clk_10,
       internal_clk_11,
       internal_clk_12,
       internal_clk_13,
       internal_clk_14,
       internal_clk_15,
       internal_clk_16,
       internal_clk_17,
       internal_clk_18,
       internal_clk_19,
       internal_clk_20,
       internal_clk_21,
       internal_clk_22,
       internal_clk_23,
       internal_clk_24,
       internal_clk_25,
       internal_clk_26,
       internal_clk_27;

  wire clk_1,
       clk_2,
       clk_3,
       clk_4,
       clk_5,
       clk_6,
       clk_7,
       clk_8,
       clk_9,
       clk_10,
       clk_11,
       clk_12,
       clk_13;

  assign clk_1 = internal_clk_7;
  assign clk_2 = internal_clk_8;
  assign clk_3 = internal_clk_9;
  assign clk_4 = internal_clk_10;
  assign clk_5 = internal_clk_11;
  assign clk_6 = internal_clk_12;
  assign clk_7 = internal_clk_13;
  assign clk_8 = internal_clk_14;
  assign clk_9 = internal_clk_23;
  assign clk_10 = internal_clk_24;
  assign clk_11 = internal_clk_25;
  assign clk_12 = internal_clk_26;
  assign clk_13 = internal_clk_27;

endmodule
