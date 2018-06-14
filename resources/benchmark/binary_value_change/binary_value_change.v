module binary_value_change;

`define num_events 10000000
reg[7:0] clock = 8'h99;

initial begin
  $dumpfile("binary_value_change.vcd");
  $dumpvars(1, clock);

  #`num_events $finish();
end

always begin
 #1 clock = ~clock;
end

endmodule
