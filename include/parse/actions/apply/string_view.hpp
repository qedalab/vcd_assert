#ifndef LIBPARSE_ACTIONS_APPLY_STRING_VIEW_HPP
#define LIBPARSE_ACTIONS_APPLY_STRING_VIEW_HPP

#include <string_view>

namespace Parse::Apply {

struct string_view {
  template<class Rule, class ActionInput, class State>
  static bool apply(const ActionInput& input, State& state) {
    state = std::string_view(input.begin(), input.size());
    return true;
  }
};

} // namespace Parse::Apply

#endif // LIBPARSE_ACTIONS_APPLY_STRING_VIEW_HPP
