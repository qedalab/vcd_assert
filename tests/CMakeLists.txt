set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

# configure_file(${CMAKE_SOURCE_DIR}/examples  ${CMAKE_BINARY_DIR}/examples COPYONLY)
file(COPY ${CMAKE_SOURCE_DIR}/examples DESTINATION ${CMAKE_BINARY_DIR})

add_custom_target(
  iverilog_examples
  ALL
  COMMAND ./run_iverilog_all.sh
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/
)

#Basic and fail
add_test(
  NAME basic_and_fail
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_and_fail/iverilog_out/
  COMMAND vcd_assert tb_basic_and.vcd --node tb_basic_and --sdf ../and.sdf
)

# Basic and succeed
add_test(
  NAME basic_and_success
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/examples/basic_and_success/iverilog_out/
  COMMAND vcd_assert tb_basic_and.vcd --node tb_basic_and --sdf ../and.sdf
)

# Failing tests
set_tests_properties(
  basic_and_fail
  PROPERTIES WILL_FAIL TRUE
)

# Basic DRO
# set(BASIC_DRO_SOURCE ${INTEGRATION_DIR}/dro/dro.v ${INTEGRATION_DIR}/dro/tb_dro.v)
# create_vcd_from_verilog(basic_dro tb_basic_dro "${BASIC_DRO_SOURCE}")
# set_vcd_variable(basic_dro)
# add_test(NAME integration_basic_dro COMMAND vcd_assert ${basic_dro} -s ${INTEGRATION_DIR}/dro/dro.sdf)

# # Basic And
# set(BASIC_AND_SOURCE ${INTEGRATION_DIR}/and/and.v ${INTEGRATION_DIR}/and/tb_and.v)
# create_vcd_from_verilog(basic_and tb_basic_and "${BASIC_AND_SOURCE}")
# set_vcd_variable(basic_and)
# add_test(NAME integration_basic_and COMMAND vcd_assert ${basic_and})

# # Basic Jtl
# set(BASIC_JTL_SOURCE ${INTEGRATION_DIR}/jtl/jtl.v ${INTEGRATION_DIR}/jtl/tb_jtl.v)
# create_vcd_from_verilog(basic_jtl tb_basic_jtl "${BASIC_JTL_SOURCE}")
# set_vcd_variable(basic_jtl)
# add_test(NAME integration_basic_jtl COMMAND vcd_assert ${basic_jtl})

# # Basic NDRO
# set(BASIC_NDRO_SOURCE ${INTEGRATION_DIR}/ndro/ndro.v ${INTEGRATION_DIR}/ndro/tb_ndro.v)
# create_vcd_from_verilog(basic_ndro tb_basic_ndro "${BASIC_NDRO_SOURCE}")
# set_vcd_variable(basic_ndro)
# add_test(NAME integration_ndro COMMAND vcd_asser:t ${basic_ndro})

# # Basic Splitter
# set(BASIC_SPLIT_SOURCE ${INTEGRATION_DIR}/splitter/splitter.v ${INTEGRATION_DIR}/splitter/tb_splitter.v)
# create_vcd_from_verilog(basic_splitter tb_basic_splitter "${BASIC_SPLIT_SOURCE}")
# set_vcd_variable(basic_splitter)
# add_test(NAME integration_splitter COMMAND vcd_assert ${basic_splitter})

# # Basic Xor
# set(BASIC_XOR_SOURCE ${INTEGRATION_DIR}/xor/xor.v ${INTEGRATION_DIR}/xor/tb_xor.v)
# create_vcd_from_verilog(basic_xor tb_basic_xor "${BASIC_XOR_SOURCE}")
# set_vcd_variable(basic_xor)
# add_test(NAME integration_xor COMMAND vcd_assert ${basic_xor})

add_subdirectory(unit)
add_subdirectory(bench)
