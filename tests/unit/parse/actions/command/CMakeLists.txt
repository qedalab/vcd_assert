set(DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(unit_parse PRIVATE
  ${DIR}/apply.cpp
  ${DIR}/apply0.cpp
  ${DIR}/inner_action.cpp
  ${DIR}/pegtl_action.cpp
  )
