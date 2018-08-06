#ifndef LIBPARSE_UTIL_DEBUG_PRINTING_HPP
#define LIBPARSE_UTIL_DEBUG_PRINTING_HPP

#define VERBOSE_DEBUG_OUTPUT

#ifdef VERBOSE_DEBUG_OUTPUT
#include <fmt/format.h>
#endif

namespace Parse::Util {

template <typename Input>
#ifdef VERBOSE_DEBUG_OUTPUT
void debug_puts(Input input)
{
  fmt::print(input);
  fmt::print("\n");
#else
void debug_puts(Input /*unused*/)
{
#endif
}

template <typename... Args>
#ifdef VERBOSE_DEBUG_OUTPUT
void debug_print(Args... args)
{
  fmt::print(args...);
#else
void debug_print(Args... /*args*/)
{
  // (void)args;
#endif
}

} // namespace Parse::Util

#endif // LIBPARSE_UTIL_DEBUG_PRINTING_HPP
