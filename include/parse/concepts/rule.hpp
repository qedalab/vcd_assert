#ifndef LIBPARSE_CONCEPTS_RULE_HPP
#define LIBPARSE_CONCEPTS_RULE_HPP

#include "./complex_rule.hpp"
#include "./simple_rule.hpp"

#include <range/v3/utility/concepts.hpp>

namespace Parse::Concepts {

namespace Internal {

using namespace ranges::concepts;

struct Rule {
  // clang-format off

  // SimpleRule and not ComplexRule
  template <typename T>
  auto requires_() -> decltype(valid_expr(
      is_false(models<ComplexRule,T>{}),
      is_true(models<SimpleRule, T>{})
  ));

  // ComplexRule and not SimpleRule
  template <typename T>
  auto requires_() -> decltype(valid_expr(
      is_true(models<ComplexRule,T>{}),
      is_false(models<SimpleRule, T>{})
  ));

  // clang-format on
};

} // namespace Internal

template <typename T>
constexpr bool Rule = ranges::concepts::models<Internal::Rule, T>();

} // namespace Parse::Concepts

#endif // LIBPARSE_CONCEPTS_RULE_HPP
