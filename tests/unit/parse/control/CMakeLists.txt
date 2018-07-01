set(DIR ${CMAKE_CURRENT_LIST_DIR})

# TODO move into actions/control and move json to parse/test
target_sources(unit_parse PRIVATE
  ${DIR}/capture.cpp
  )
