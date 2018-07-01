#ifndef LIBPARSE_UTIL_ARRAY_APPEND_HPP
#define LIBPARSE_UTIL_ARRAY_APPEND_HPP

#include <range/v3/algorithm/copy.hpp>

#include <array>
#include <type_traits>

namespace Parse::Util {

template <class T, std::size_t Base, std::size_t... Sizes>
constexpr auto array_append(std::array<T, Base> base) {
  return base;
};

template <class T, std::size_t Base, std::size_t... Sizes>
constexpr auto array_append(std::array<T, Base> base,
                            std::array<T, Sizes>... arrays) {

  std::array rest = array_append(arrays...);
  std::array<T, rest.size() + Base> out{};

  ranges::copy(base, out.begin());
  ranges::copy(rest, out.begin() + Base);

  return out;
};

} // namespace Parse::Util

#endif // PARSE_UTIL_ARRAY_APPEND_HPP
