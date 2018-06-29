set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(unit_parse PRIVATE
  ${DIR}/control.cpp
  ${DIR}/dispatch.cpp
  ${DIR}/make_pegtl_template.cpp
  )

add_subdirectory(apply)
add_subdirectory(command)
add_subdirectory(storage)
