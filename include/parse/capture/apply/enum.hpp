#ifndef PARSE_CAPTURE_APPLY_ENUM_HPP
#define PARSE_CAPTURE_APPLY_ENUM_HPP

namespace Parse {

struct enum_value {
  template<typename Rule, typename State>
  static bool apply0(State& state) {
    state = Rule::value;
    return true;
  }
};

} // namespace Parse

#endif //PARSE_ENUM_HPP
