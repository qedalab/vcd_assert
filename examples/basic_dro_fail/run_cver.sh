#!/bin/sh

mkdir -p cver_out
cd cver_out
cver +maxerrors 0 ../tb_dro.v -v ../dro.v -l out.txt
