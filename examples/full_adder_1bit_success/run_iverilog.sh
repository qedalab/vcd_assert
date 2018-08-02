#!/bin/sh

mkdir -p iverilog_out
cd iverilog_out
iverilog -Dbegin_time=20 -DIVERILOG_WORKAROUND -gspecify \
  -s tb_full_adder_1bit            \
  -o run                           \
  ../tb_full_adder_1bit.v          \
  ../full_adder_1bit.v             \
  ../../splitter_8bit/*.v          \
  ../../examples_cell_library.v

./run
