set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_parse PRIVATE
  ${DIR}/debug_control.cpp
  ${DIR}/debug_exception.cpp
  ${DIR}/match.cpp
  ${DIR}/parse.cpp
  )
