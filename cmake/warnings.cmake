function(target_add_warnings target)

if(MSVC)
  target_compile_options(${target} PRIVATE /W4 /WX /utf-8)
else()
  target_compile_options(${target} PRIVATE -pedantic -Wall -Wextra -Wshadow -Werror)
endif()

endfunction()
