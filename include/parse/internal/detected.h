#ifndef PARSE_INTERNAL_DETECTED_H_
#define PARSE_INTERNAL_DETECTED_H_

#include <type_traits>

namespace Parse {
namespace Internal {

/// FROM LibFundementals v2
struct nonesuch {
  nonesuch() = delete;
  ~nonesuch() = delete;
  nonesuch(nonesuch const &) = delete;
  void operator=(nonesuch const &) = delete;
};

template <class Default, class AlwaysVoid, template <class...> class Op,
          class... Args>
struct detector {
  static constexpr bool value = false;
  using type = Default;
};

template <class Default, template <class...> class Op, class... Args>
struct detector<Default, std::void_t<Op<Args...>>, Op, Args...> {
  static constexpr bool value = true;
  using type = Op<Args...>;
};

template <template <class...> class Op, class... Args>
constexpr bool is_detected = detector<nonesuch, void, Op, Args...>::value;

template <template <class...> class Op, class... Args>
using detected_t = typename detector<nonesuch, void, Op, Args...>::type;

template <class Default, template <class...> class Op, class... Args>
using detected_or = detector<Default, void, Op, Args...>;

} // namespace Internal

} // namespace Parse

#endif // PARSE_INTERNAL_DETECTED_H_
