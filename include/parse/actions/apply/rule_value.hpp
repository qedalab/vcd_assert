#ifndef LIBPARSE_ACTIONS_APPLY_RULE_VALUE_HPP
#define LIBPARSE_ACTIONS_APPLY_RULE_VALUE_HPP

#include "../../internal/detected.h"

namespace Parse::Apply {

struct rule_value {
  template <class Rule>
  using value_decl = decltype(Rule::value);

public:
  template <typename Rule, typename State>
  static bool apply0(State &state) {
    if constexpr (Parse::Internal::is_detected<value_decl, Rule>) {
      state = Rule::value;
    }

    return true;
  }
};

} // namespace Parse::Apply

#endif // LIBPARSE_ACTIONS_APPLY_RULE_VALUE_HPP
