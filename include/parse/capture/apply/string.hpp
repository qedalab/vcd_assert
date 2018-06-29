#ifndef LIBPARSE_CAPTURE_APPLY_STRING_VIEW_HPP
#define LIBPARSE_CAPTURE_APPLY_STRING_VIEW_HPP

#include <string>

namespace Parse::Apply {

struct string {
  template<class Rule, class ActionInput, class State>
  static bool apply(const ActionInput& input, State& state) {
    state = input.string();
    return true;
  }
};

} // namespace Parse::Apply

#endif // LIBPARSE_CAPTURE_APPLY_STRING_VIEW_HPP
