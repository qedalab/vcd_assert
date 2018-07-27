function(create_vcd_from_verilog vcd_target main_module input_files)
  file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/vcd/${vcd_target})

  add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/vcd/${vcd_target}/output.vcd
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/vcd/${vcd_target}/
    USES_TERMINAL
    DEPENDS ${input_files}
    COMMAND find . -name "*.vcd" -delete
    COMMAND iverilog -gspecify -s ${main_module} -o run ${input_files}
    COMMAND ${CMAKE_BINARY_DIR}/vcd/${vcd_target}/run
    COMMAND mv *.vcd output.vcd
  )

  add_custom_target(
    ${vcd_target}
    ALL
    DEPENDS
      ${CMAKE_BINARY_DIR}/vcd/${vcd_target}/output.vcd
  )

endfunction()

macro(set_vcd_variable vcd_target)
  set(${vcd_target} ${CMAKE_BINARY_DIR}/vcd/${vcd_target}/output.vcd)
endmacro()
