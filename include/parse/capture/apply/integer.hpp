#ifndef LIBPARSE_CAPTURE_APPLY_INTEGER_HPP
#define LIBPARSE_CAPTURE_APPLY_INTEGER_HPP

#include <string>

namespace Parse::Apply {

struct integer {
  template <class Rule, class ActionInput, class State>
  static bool apply(const ActionInput &input, State &state) {
    state = std::stol(input.string());
    return true;
  }
};

} // namespace Parse::Apply

#endif // PARSE_INTEGER_HPP
