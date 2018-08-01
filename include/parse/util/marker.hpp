#ifndef LIBPARSE_UTIL_MARKER_HPP
#define LIBPARSE_UTIL_MARKER_HPP

#include "../actions/dispatch.hpp"

#include <cstddef>

namespace Parse::Util {

struct Marker {
  std::size_t line = 0;
  std::size_t byte_in_line = 0;
};

} // namespace Parse::Util

#endif // LIBPARSE_UTIL_MARKER_HPP
