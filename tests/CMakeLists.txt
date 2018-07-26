set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Basic DRO
set(BASIC_DRO_SOURCE ${DIR}/integration/basic/dro/dro.v ${DIR}/integration/basic/dro/tb_dro.v)
create_vcd_from_verilog(basic_dro tb_dro "${BASIC_DRO_SOURCE}")
set_vcd_variable(basic_dro)
add_test(NAME integration_dro COMMAND vcd_assert ${basic_dro})

add_subdirectory(unit)
add_subdirectory(bench)
