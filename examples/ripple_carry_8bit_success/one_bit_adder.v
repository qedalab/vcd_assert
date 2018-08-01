`timescale 1ps/100fs
module basic_one_bit_adder (cin, a, b, clk, sum, cout);

  input cin, a, b, clk;

  output sum, cout;
  wire sum, cout;

  // Internal clock wires
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
       internal_clk_14;

  wire internal_1,
       internal_2,
       internal_3,
       internal_4,
       internal_5,
       internal_6,
       internal_7,
       internal_8,
       internal_9,
       internal_10,
       internal_11,
       internal_12,
       internal_13,
       internal_14;

  wire clk_1,
       clk_2,
       clk_3,
       clk_4,
       clk_5,
       clk_6,
       clk_7,
       clk_8;

  assign clk_1 = internal_clk_7;
  assign clk_2 = internal_clk_8;
  assign clk_3 = internal_clk_9;
  assign clk_4 = internal_clk_10;
  assign clk_5 = internal_clk_11;
  assign clk_6 = internal_clk_12;
  assign clk_7 = internal_clk_13;
  assign clk_8 = internal_clk_14;

  // Start of clock tree: level 0
  basic_splitter clk_splitter_1 (clk, internal_clk_1, internal_clk_2);

  // Clock tree level 1
  basic_splitter clk_splitter_2 (internal_clk_1, internal_clk_3, internal_clk_4);
  basic_splitter clk_splitter_3 (internal_clk_2, internal_clk_5, internal_clk_6);

  // Clock tree level 2
  basic_splitter clk_splitter_4 (internal_clk_3, internal_clk_7, internal_clk_8);
  basic_splitter clk_splitter_5 (internal_clk_4, internal_clk_9, internal_clk_10);
  basic_splitter clk_splitter_6 (internal_clk_5, internal_clk_11, internal_clk_12);
  basic_splitter clk_splitter_7 (internal_clk_6, internal_clk_13, internal_clk_14);

  // Basic adder
  basic_dro dff_1 (cin, clk_1, internal_1);
  basic_dro dff_2 (internal_3, clk_7, sum);
  basic_dro dff_3 (internal_12, clk_6, internal_13);
  basic_splitter splitter_1 (internal_1, internal_2, internal_4);
  basic_splitter splitter_2 (a, internal_8, internal_10);
  basic_splitter splitter_3 (b, internal_9, internal_11);
  basic_splitter splitter_4 (internal_7, internal_5, internal_6);
  basic_xor xor_1 (internal_2, internal_5, clk_2, internal_3);
  basic_xor xor_2 (internal_8, internal_9, clk_3, internal_7);
  basic_and and_1 (internal_10, internal_11, clk_5, internal_12);
  basic_and and_2 (internal_4, internal_6, clk_4, internal_14);
  basic_or or_1 (internal_13, internal_14, clk_8, cout);
endmodule

