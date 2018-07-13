set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(unit_vcd PRIVATE
  ${DIR}/header.cpp
  ${DIR}/scope.cpp
  ${DIR}/variable.cpp
  )
