function(create_vcd_from_verilog vcd_target main_module input_files)
  file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/vcd/${vcd_target})

  add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/vcd/${vcd_target}/output.vcd
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/vcd/${vcd_target}/
    USES_TERMINAL
    DEPENDS ${input_files}
    COMMAND iverilog -s ${main_module} -o run ${input_files}
    COMMAND ${CMAKE_BINARY_DIR}/vcd/${vcd_target}/run
    COMMAND mv *.vcd output.vcd
  )

endfunction()
