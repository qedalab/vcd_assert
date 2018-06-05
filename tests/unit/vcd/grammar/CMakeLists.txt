set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(enums)

target_sources(unit_vcd PRIVATE
  ${DIR}/commands.cpp
  ${DIR}/keywords.cpp
  ${DIR}/numbers.cpp
  ${DIR}/base.cpp
  ${DIR}/value.cpp
  ${DIR}/grammar.cpp
  )
