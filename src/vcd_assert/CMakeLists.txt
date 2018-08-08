set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(libvcd_assert PRIVATE
  ${DIR}/conditional.cpp
  ${DIR}/edge_type.cpp
  ${DIR}/event.cpp
  ${DIR}/sdf_matching.cpp
  ${DIR}/state.cpp
  ${DIR}/timing_checker.cpp
  ${DIR}/triggered_timing_checker.cpp
  )

message(STATUS "Linking vcd_assert with: ${antlr4cpp_src_files_SystemVerilog}")

add_executable(vcd_assert
  ${DIR}/vcd_assert.cpp
  ${DIR}/version.cpp
)

add_custom_command(
  TARGET vcd_assert
  PRE_BUILD COMMAND touch ${DIR}/version.cpp
)

target_compile_options(vcd_assert
  PRIVATE -DVCD_ASSERT_VERSION_MACRO="${PROJECT_VERSION} ${CMAKE_BUILD_TYPE}" 
)

# try "-Isystem ${ANTLR4CPP_INCLUDE_DIRS}" ?
# target_add_warnings(vcd_assert)
target_link_libraries(vcd_assert
  libvcd_assert
  CLI11::CLI11
  fmt::fmt
)
