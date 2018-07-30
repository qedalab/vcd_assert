set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_verilog PRIVATE
  ${DIR}/base.cpp
  ${DIR}/grammar.cpp
  ${DIR}/module.cpp
)
