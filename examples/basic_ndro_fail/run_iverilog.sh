#!/bin/sh

mkdir -p iverilog_out
cd iverilog_out
iverilog -gspecify -DIVERILOG_WORKAROUND -s tb_basic_ndro -o run ../*.v
vvp ./run
