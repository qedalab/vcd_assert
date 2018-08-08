set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(libverilog PRIVATE
  ${DIR}/command_listener.cpp
  ${DIR}/netlist_listener.cpp
  ${DIR}/preprocess_listener.cpp
)
