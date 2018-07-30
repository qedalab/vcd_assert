#!/bin/sh

mkdir -p cver_out
cd cver_out
cver +maxerrors 0 ../tb_ndro.v -v ../ndro.v -l out.txt
