set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(unit_parse PRIVATE
  ${DIR}/enum.cpp
  ${DIR}/float.cpp
  ${DIR}/integer.cpp
  ${DIR}/string.cpp
  ${DIR}/string_view.cpp
  ${DIR}/value.cpp
  )
