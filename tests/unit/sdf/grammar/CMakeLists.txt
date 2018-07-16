set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(unit_sdf PRIVATE
  ${DIR}/grammar.cpp
  # ${DIR}/base.cpp
  ${DIR}/keywords.cpp
  ${DIR}/header.cpp
  # ${DIR}/cell.cpp
  ${DIR}/timing.cpp
  ${DIR}/delayfile.cpp
  ${DIR}/values.cpp
  # ${DIR}/unimpl.cpp
)
