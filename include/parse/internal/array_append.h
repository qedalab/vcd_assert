#ifndef PARSE_INTERNAL_ARRAY_APPEND_H
#define PARSE_INTERNAL_ARRAY_APPEND_H

#include <array>
#include <type_traits>

namespace Parse {
namespace Internal {

template<class T, std::size_t Base>
constexpr auto array_append(std::array<T, Base> base) {
  return base;
};

template<class T, std::size_t Base, std::size_t... Sizes>
constexpr auto array_append(std::array<T, Base> base, std::array<T, Sizes>... arrays) {

  std::array rest = array_append(arrays...);
  std::array<T, rest.size() + Base> out{};

  std::size_t counter = 0;

  for(auto v: base)
    out[counter++] = v;

  for(auto v: rest)
    out[counter++] = v;

  return out;
};

}
}

#endif //PARSE_INTERNAL_ARRAY_APPEND_H
