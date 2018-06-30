#ifndef LIBPARSE_CONCEPTS_COMPLEX_RULE_HPP
#define LIBPARSE_CONCEPTS_COMPLEX_RULE_HPP

#include "./action.hpp"
#include "./control.hpp"
#include "./input.hpp"

#include <range/v3/utility/concepts.hpp>

namespace Parse::Concepts {

namespace Internal {

using namespace ranges::concepts;

struct ComplexRule {
  // clang-format off
  template <typename T>
  auto requires_(Input::type input) -> decltype(valid_expr(
      T::template match<
          tao::pegtl::apply_mode{},
          tao::pegtl::rewind_mode{},
          Action::type,
          Control::type
      >(input)
  ));
  // clang-format on
};

} // namespace Internal

template <typename T>
constexpr bool
    ComplexRule = ranges::concepts::models<Internal::ComplexRule, T>();

} // namespace Parse::Concepts

#endif // LIBPARSE_CONCEPTS_COMPLEX_RULE_HPP
