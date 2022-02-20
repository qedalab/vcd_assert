function(target_add_warnings target)

if(MSVC)
  target_compile_options(${target} PRIVATE)
else()
  target_compile_options(${target} PRIVATE -pedantic -Wall -Wextra -Wshadow)
endif()

endfunction()
