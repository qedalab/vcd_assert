#ifndef LIBPARSE_ACTIONS_APPLY_UNSIGNED_INTEGER_HPP
#define LIBPARSE_ACTIONS_APPLY_UNSIGNED_INTEGER_HPP

#include <string>

namespace Parse::Apply {

struct unsigned_integer {
  template <class Rule, class ActionInput, class... Stack, class State>
  static bool apply(const ActionInput &input, State &state,
                    const Stack &... /*unused*/
  ) {
    state = std::stoul(input.string());
    return true;
  }
};

} // namespace Parse::Apply

#endif // LIBPARSE_ACTIONS_APPLY_UNSIGNED_INTEGER_HPP
