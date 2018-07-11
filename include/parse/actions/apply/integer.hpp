#ifndef LIBPARSE_ACTIONS_APPLY_INTEGER_HPP
#define LIBPARSE_ACTIONS_APPLY_INTEGER_HPP

#include <string>

namespace Parse::Apply {

struct integer {
  template <class Rule, class ActionInput, class... Stack, class State>
  static bool apply(const ActionInput &input, State &state,
                    const Stack &... /*unused*/
  ) {
    state = std::stol(input.string());
    return true;
  }
};

} // namespace Parse::Apply

#endif // LIBPARSE_ACTIONS_APPLY_INTEGER_HPP
