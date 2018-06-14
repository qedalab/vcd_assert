#!/bin/sh

mkdir -p results
iverilog binary_value_change.v -o results/binary_value_change
cd ./results
./binary_value_change
