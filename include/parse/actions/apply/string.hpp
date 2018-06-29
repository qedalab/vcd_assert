#ifndef LIBPARSE_ACTIONS_APPLY_STRING_HPP
#define LIBPARSE_ACTIONS_APPLY_STRING_HPP

#include <string>

namespace Parse::Apply {

struct string {
  template <class Rule, class ActionInput, class State>
  static bool apply(const ActionInput &input, State &state) {
    state = input.string();
    return true;
  }
};

} // namespace Parse::Apply

#endif // LIBPARSE_ACTIONS_APPLY_STRING_HPP
