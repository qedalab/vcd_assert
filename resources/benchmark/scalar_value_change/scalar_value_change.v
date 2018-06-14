module scalar_value_change;

`define num_events 10000000
reg clock = 0;

initial begin
  $dumpfile("scalar_value_change.vcd");
  $dumpvars(1, clock);

  #`num_events $finish();
end

always begin
 #1 clock = ~clock;
end

endmodule
