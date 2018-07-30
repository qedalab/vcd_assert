set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(libverilog PRIVATE
  ${DIR}/design_reader.cpp
  ${DIR}/design.cpp
  ${DIR}/module.cpp
  # ${DIR}/netlist.cpp
  # ${DIR}/variable.cpp
  )