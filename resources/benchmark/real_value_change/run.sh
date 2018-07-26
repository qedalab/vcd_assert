#!/bin/sh

mkdir -p results
iverilog real_value_change.v -o results/real_value_change
cd ./results
./real_value_change
