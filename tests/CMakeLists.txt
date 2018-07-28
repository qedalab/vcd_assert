set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(INTEGRATION_DIR ${DIR}/integration/basic)

# Basic DRO
set(BASIC_DRO_SOURCE ${INTEGRATION_DIR}/dro/dro.v ${INTEGRATION_DIR}/dro/tb_dro.v)
create_vcd_from_verilog(basic_dro tb_basic_dro "${BASIC_DRO_SOURCE}")
set_vcd_variable(basic_dro)
add_test(NAME integration_basic_dro COMMAND vcd_assert ${basic_dro})

# Basic And
set(BASIC_AND_SOURCE ${INTEGRATION_DIR}/and/and.v ${INTEGRATION_DIR}/and/tb_and.v)
create_vcd_from_verilog(basic_and tb_basic_and "${BASIC_AND_SOURCE}")
set_vcd_variable(basic_and)
add_test(NAME integration_basic_and COMMAND vcd_assert ${basic_and})

# Basic Jtl
set(BASIC_JTL_SOURCE ${INTEGRATION_DIR}/jtl/jtl.v ${INTEGRATION_DIR}/jtl/tb_jtl.v)
create_vcd_from_verilog(basic_jtl tb_basic_jtl "${BASIC_JTL_SOURCE}")
set_vcd_variable(basic_jtl)
add_test(NAME integration_basic_jtl COMMAND vcd_assert ${basic_jtl})

# Basic NDRO
set(BASIC_NDRO_SOURCE ${INTEGRATION_DIR}/ndro/ndro.v ${INTEGRATION_DIR}/ndro/tb_ndro.v)
create_vcd_from_verilog(basic_ndro tb_basic_ndro "${BASIC_NDRO_SOURCE}")
set_vcd_variable(basic_ndro)
add_test(NAME integration_ndro COMMAND vcd_assert ${basic_ndro})

# Basic Splitter
set(BASIC_SPLIT_SOURCE ${INTEGRATION_DIR}/splitter/splitter.v ${INTEGRATION_DIR}/splitter/tb_splitter.v)
create_vcd_from_verilog(basic_splitter tb_basic_splitter "${BASIC_SPLIT_SOURCE}")
set_vcd_variable(basic_splitter)
add_test(NAME integration_splitter COMMAND vcd_assert ${basic_splitter})

# Basic Xor
set(BASIC_XOR_SOURCE ${INTEGRATION_DIR}/xor/xor.v ${INTEGRATION_DIR}/xor/tb_xor.v)
create_vcd_from_verilog(basic_xor tb_basic_xor "${BASIC_XOR_SOURCE}")
set_vcd_variable(basic_xor)
add_test(NAME integration_xor COMMAND vcd_assert ${basic_xor})

add_subdirectory(unit)
add_subdirectory(bench)
