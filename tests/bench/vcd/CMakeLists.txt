set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(libvcd_bench_grammar bench_grammar.cpp)
target_link_libraries(libvcd_bench_grammar libvcd CLI11::CLI11)

