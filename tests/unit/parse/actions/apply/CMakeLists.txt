set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(unit_parse PRIVATE
  ${DIR}/float.cpp
  ${DIR}/integer.cpp
  ${DIR}/rule_value.cpp
  ${DIR}/string.cpp
  ${DIR}/string_view.cpp
  ${DIR}/value.cpp
  )
