#!/bin/sh

mkdir -p cver_out
cd cver_out
cver +maxerrors 0 +sdf_annotate ../*.sdf ../tb_xor.v -v ../xor.v -l out.txt
