// Adapted from TimEx generated files for vcd_assert testing
`include "../basic_splitter/splitter.v"
`timescale 1ps/100fs
module splitter_8bit (in, out);

  input in;
  output out[7:0];

  wire net_1,
       net_2,
       net_3,
       net_4,
       net_5,
       net_6,
       net_7,
       net_8,
       net_9,
       net_10,
       net_11,
       net_12,
       net_13,
       net_14;

  assign out[0] = net_out_7;
  assign out[1] = net_out_8;
  assign out[2] = net_out_9;
  assign out[3] = net_out_10;
  assign out[4] = net_out_11;
  assign out[5] = net_out_12;
  assign out[6] = net_out_13;
  assign out[7] = net_out_14;

  // Start of tree: level 0
  basic_splitter out_splitter_1 (out, net_1, net_2);

  // tree level 1
  basic_splitter out_splitter_2 (net_1, net_3, net_4);
  basic_splitter out_splitter_3 (net_2, net_5, net_6);

  // tree level 2
  basic_splitter out_splitter_4 (net_3, net_7, net_8);
  basic_splitter out_splitter_5 (net_4, net_9, net_10);
  basic_splitter out_splitter_6 (net_5, net_11, net_12);
  basic_splitter out_splitter_7 (net_6, net_13, net_14);

endmodule
