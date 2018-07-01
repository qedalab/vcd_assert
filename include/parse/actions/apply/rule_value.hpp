#ifndef LIBPARSE_ACTIONS_APPLY_RULE_VALUE_HPP
#define LIBPARSE_ACTIONS_APPLY_RULE_VALUE_HPP

#include <parse/concepts/value_rule.hpp>

namespace Parse::Apply {

struct rule_value {
  template <typename Rule, typename State>
  static bool apply0(State &state) {
    if constexpr (Concepts::ValueRule<Rule>)
      state = Rule::value;

    return true;
  }
};

} // namespace Parse::Apply

#endif // LIBPARSE_ACTIONS_APPLY_RULE_VALUE_HPP
