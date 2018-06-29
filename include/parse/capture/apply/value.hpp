#ifndef LIBPARSE_CAPTURE_VALUE_HPP
#define LIBPARSE_CAPTURE_VALUE_HPP

namespace Parse::Apply {

template<auto Value>
struct value {
  template<class Rule, class State>
  static bool apply0(State& state) {
    state = Value;
    return true;
  }
};

} // namespace Parse::Apply

#endif // LIBPARSE_CAPTURE_VALUE_HPP
