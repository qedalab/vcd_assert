#ifndef LIBPARSE_UTIL_DEBUG_PRINTING_HPP
#define LIBPARSE_UTIL_DEBUG_PRINTING_HPP

#ifdef VERBOSE_DEBUG_OUPUT
#include <fmt/print.h>
#endif

namespace Parse::Util {

template<typename Input>
void debug_puts(Input input){
#ifdef VERBOSE_DEBUG_OUPUT
  std::puts(input);
#else
  (void)input;
#endif
}

template<typename... Args>
#ifdef VERBOSE_DEBUG_OUPUT
void debug_print(Args... args){
  fmt::print(args...);
#else
void debug_print(Args... /*args*/){
  // (void)args;
#endif
}




} // namespace Parse::Util

#endif // LIBPARSE_UTIL_DEBUG_PRINTING_HPP
