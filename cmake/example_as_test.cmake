function(example_as_test)
  set(option_args VERILOG_AS_ARGS)
  set(single_args NAME DIR SCRIPT VCD)
  set(multi_args SDF VERILOG ARGS)
  cmake_parse_arguments(EXAMPLE "${option_args}" "${single_args}" "${multi_args}" ${ARGN})

#   message("EXAMPLE_START")
#   message("NAME : ${EXAMPLE_NAME}")
#   message("DIR : ${EXAMPLE_DIR}")
#   message("SCRIPT : ${EXAMPLE_SCRIPT}")
#   message("VCD : ${EXAMPLE_VCD}")
#   message("SDF : ${EXAMPLE_SDF}")
#   message("VERILOG : ${EXAMPLE_VERILOG}")
#   message("ARGS : ${EXAMPLE_ARGS}")
#   message("EXAMPLE_END")

  # Create example directory
  set(BIN_DIR "${CMAKE_BINARY_DIR}/${EXAMPLE_DIR}")
  set(SRC_DIR "${CMAKE_SOURCE_DIR}/${EXAMPLE_DIR}")

  set(BIN_VERILOG)
  set(SRC_VERILOG)

  foreach(VERILOG_FILE ${EXAMPLE_VERILOG})
    set(BIN_VERILOG_FILE "${BIN_DIR}/${VERILOG_FILE}")
    set(SRC_VERILOG_FILE "${SRC_DIR}/${VERILOG_FILE}")

    set(BIN_VERILOG ${BIN_VERILOG} ${BIN_VERILOG_FILE})
    set(SRC_VERILOG ${SRC_VERILOG} ${SRC_VERILOG_FILE})

    configure_file(${SRC_VERILOG_FILE} ${BIN_VERILOG_FILE} COPYONLY)
  endforeach()

  # Copy SDF and make list
  set(BIN_SDF)
  set(SRC_SDF)

  foreach(SDF_FILE ${EXAMPLE_SDF})
    set(BIN_SDF_FILE "${BIN_DIR}/${SDF_FILE}")
    set(SRC_SDF_FILE "${SRC_DIR}/${SDF_FILE}")

    set(BIN_SDF ${BIN_SDF} ${BIN_SDF_FILE})
    set(SRC_SDF ${SRC_SDF} ${SRC_SDF_FILE})

    configure_file(${SRC_SDF_FILE} ${BIN_SDF_FILE} COPYONLY)
  endforeach()

  # Copy script
  configure_file("${SRC_DIR}/${EXAMPLE_SCRIPT}" "${BIN_DIR}/${EXAMPLE_SCRIPT}" COPYONLY)

  set(VCD_FILE ${BIN_DIR}/iverilog_out/${EXAMPLE_VCD})

  # TODO make it work on windows as well
  # Run Iverilog and vvp
  add_custom_command(
    OUTPUT ${VCD_FILE}
    DEPENDS ${BIN_SDF} ${BIN_VERILOG}
    WORKING_DIRECTORY ${BIN_DIR}
    COMMAND sh ${EXAMPLE_SCRIPT}
  )

  add_custom_target(
    example_${EXAMPLE_NAME}
    ALL
    DEPENDS ${VCD_FILE}
  )

  set(VCD_ASSERT_COMMAND vcd_assert ${VCD_FILE})

  if(${EXAMPLE_VERILOG_AS_ARGS})
    set(VCD_ASSERT_COMMAND ${VCD_ASSERT_COMMAND} ${BIN_VERILOG})
  endif()

  set(VCD_ASSERT_COMMAND ${VCD_ASSERT_COMMAND} ${EXAMPLE_ARGS})

  add_test(
    NAME ${EXAMPLE_NAME}
    WORKING_DIRECTORY ${BIN_DIR}/iverilog_out/
    COMMAND ${VCD_ASSERT_COMMAND}
  )

endfunction()
