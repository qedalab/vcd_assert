set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(unit_parse PRIVATE
  ${DIR}/action.cpp
  ${DIR}/complex_rule.cpp
  ${DIR}/control.cpp
  ${DIR}/dispatch.cpp
  ${DIR}/error_rule.cpp
  ${DIR}/input.cpp
  ${DIR}/rule.cpp
  ${DIR}/simple_rule.cpp
  ${DIR}/value_rule.cpp
  )
