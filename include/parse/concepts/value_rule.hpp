#ifndef LIBPARSE_CONCEPTS_VALUE_RULE_HPP
#define LIBPARSE_CONCEPTS_VALUE_RULE_HPP

#include "./rule.hpp"

namespace Parse::Concepts {

namespace Internal {

using namespace ranges::concepts;

struct ValueRule : refines<Rule> {
  template <typename T>
  auto requires_() -> decltype(valid_expr(T::value));
};

} // namespace Internal

template <typename T>
constexpr bool ValueRule = ranges::concepts::models<Internal::ValueRule, T>();

} // namespace Parse::Concepts

#endif // LIBPARSE_CONCEPTS_VALUE_RULE_HPP