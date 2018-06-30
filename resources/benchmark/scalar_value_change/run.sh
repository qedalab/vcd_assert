#!/bin/sh

mkdir -p results
iverilog scalar_value_change.v -o results/scalar_value_change
cd ./results
./scalar_value_change
