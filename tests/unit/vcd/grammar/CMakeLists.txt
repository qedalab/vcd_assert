set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(enums)

set(UNIT_GRAMMER_SRC
  ${UNIT_VCD_GRAMMER_ENUMS_SRC}
  ${DIR}/commands.cpp
  ${DIR}/keywords.cpp
  ${DIR}/numbers.cpp
  ${DIR}/base.cpp
  ${DIR}/value.cpp
  ${DIR}/grammar.cpp
  PARENT_SCOPE
)
