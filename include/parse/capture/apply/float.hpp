#ifndef LIBPARSE_CAPTURE_APPLY_FLOAT_HPP
#define LIBPARSE_CAPTURE_APPLY_FLOAT_HPP

#include <string>

namespace Parse::Apply {

struct float_value {
  template<class Rule, class ActionInput, class State>
  static bool apply(const ActionInput& input, State& state) {
    // TODO Handle possible narrowing conversion
    state = std::stod(input.string());
    return true;
  }
};

} // namespace Apply

#endif // LIBPARSE_CAPTURE_APPLY_FLOAT_HPP
