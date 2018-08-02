#!/bin/sh

mkdir -p iverilog_out
cd iverilog_out
iverilog -Dbegin_time=20 -gspecify \
  -s tb_ripple_carry_8bit          \
  -o run                           \
  ../tb_ripple_carry_8bit.v        \
  ../ripple_carry_8bit.v           \
  ../full_adder_1bit.v             \
  ../../splitter_8bit/*.v          \
  ../../examples_cell_library.v

./run
