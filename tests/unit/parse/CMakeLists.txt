set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(unit_parse ../unit_main.cpp)
target_link_libraries(unit_parse libparse Catch2::Catch2)
add_test(NAME unit_parse COMMAND unit_parse)

add_subdirectory(control)
add_subdirectory(grammar)
add_subdirectory(input)
add_subdirectory(internal)
add_subdirectory(util)
add_subdirectory(test)

