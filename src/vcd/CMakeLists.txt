set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(types)

set(VCD_SRC
  ${TYPES_SRC}
  PARENT_SCOPE
  )
