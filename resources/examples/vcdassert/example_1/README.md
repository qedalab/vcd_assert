## Example of SDF back-annotation using the iverilog or cver simulators.

### iverilog : 

```bash
cd ./out/iverilog; 
iverilog -gspecify -v -s tb_dro  -o ./tb_dro.o ../../tb_dro.v ../../dro.v ; 
vvp ./tb_dro.o  -sdf-verbose; 
cd ../../;
```

### cver : 

```bash
cd ./out/cver; 
cver +printstats +verbose +maxerrors 0 +sdf_verbose ../../tb_dro.v -v ../../dro.v -l ./tb_dro.o; 
cd ../../;
```