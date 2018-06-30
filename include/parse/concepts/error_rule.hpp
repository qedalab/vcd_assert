#ifndef LIBPARSE_CONCEPTS_ERROR_RULE_HPP
#define LIBPARSE_CONCEPTS_ERROR_RULE_HPP

#include "./rule.hpp"

#include <range/v3/utility/concepts.hpp>

namespace Parse::Concepts {

namespace Internal {

using namespace ranges::concepts;

struct ErrorRule : refines<Rule> {
  template <typename T>
  auto requires_() -> decltype(valid_expr(T::error()));
};

} // namespace Internal

template <typename T>
constexpr bool ErrorRule = ranges::concepts::models<Internal::ErrorRule, T>();

} // namespace Parse::Concepts

#endif // LIBPARSE_CONCEPTS_ERROR_RULE_HPP
