set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(input)
add_subdirectory(vcd)
add_subdirectory(parse)

set(SRC
  ${VCD_SRC}
  ${INPUT_SRC}
  ${PARSE_SRC}
  PARENT_SCOPE
)
