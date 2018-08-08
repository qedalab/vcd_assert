set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_verilog PRIVATE
  ${DIR}/command_listener.cpp
  ${DIR}/netlist_listener.cpp
  ${DIR}/preprocess_listener.cpp
)
