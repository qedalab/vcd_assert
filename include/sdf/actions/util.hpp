
#ifndef LIBSDF_ACTIONS_UTIL_HPP_
#define LIBSDF_ACTIONS_UTIL_HPP_

namespace SDF {
namespace Actions {

template <class... To, class From, size_t N, size_t... Is>
std::tuple<To...> as_tuple(std::array<char *, N> const &arr,
                             std::index_sequence<Is...>) {
  return std::make_tuple(To{arr[Is]}...);
}

template <class... To, class From, size_t N,
          class = std::enable_if_t<(N == sizeof...(To))>>
std::tuple<To...> as_tuple(std::array<From, N> const &arr) {
  return as_tuple<To...>(arr, std::make_index_sequence<N>{});
}

} // namespace Actions
} // namespace SDF

#endif // LIBSDF_ACTIONS_UTIL_HPP_
