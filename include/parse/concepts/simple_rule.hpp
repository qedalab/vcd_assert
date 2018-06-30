#ifndef LIBPARSE_CONCEPTS_SIMPLE_RULE_HPP
#define LIBPARSE_CONCEPTS_SIMPLE_RULE_HPP

#include "./input.hpp"

#include <range/v3/utility/concepts.hpp>
#include <tao/pegtl/memory_input.hpp>

namespace Parse::Concepts {

namespace Internal {

using namespace ranges::concepts;

struct SimpleRule {
  template <typename T>
  auto requires_(Input::type input) -> decltype(valid_expr(T::match(input)));
};

} // namespace Internal

template <typename T>
constexpr bool SimpleRule = ranges::concepts::models<Internal::SimpleRule, T>();

} // namespace Parse::Concepts

#endif // LIBPARSE_CONCEPTS_RULE_HPP
