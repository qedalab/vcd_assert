#ifndef PARSE_ACTION_ENUM_H
#define PARSE_ACTION_ENUM_H

#include "../internal/detected.h"

namespace Parse {

namespace Internal {

template<class Rule>
using member_static_value_t = decltype(Rule::value);

template<class Rule>
constexpr bool has_member_static_value =
  is_detected<member_static_value_t, Rule>;

}

template<class Rule>
struct ValueAction {
  template<class State>
  static auto apply0(State& state) {
    if constexpr(Internal::has_member_static_value<Rule>) {
      state = Rule::value;
    }
  }
};

template<class T>
struct ScopedValueAction {
  using state = T;
  template<class Rule> using action = ValueAction<Rule>;
  void apply0(const T&) {}
};

}

#endif //PARSE_ENUM_H
