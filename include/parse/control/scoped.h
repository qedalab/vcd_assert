#ifndef LIBPARSE_CONTROL_SCOPED_H_
#define LIBPARSE_CONTROL_SCOPED_H_

#include "../internal/detected.h"

#include <tao/pegtl/normal.hpp>

namespace Parse {

using tao::pegtl::apply_mode;
using tao::pegtl::rewind_mode;

template <class T>
using member_state_t = typename T::state;

template <class T, class Rule>
using member_action_t = typename T::template action<Rule>;

template<class T>
using member_error_t = decltype(T::error());

template <class Rule>
struct scoped_control : public tao::pegtl::normal<Rule> {

  using normal_rule = tao::pegtl::normal<Rule>;

  template <typename Input, typename... States>
  static void raise(const Input &in, States &&... /*unused*/) {
    // throw ParseException(Rule::error(), in.position()));
    constexpr bool has_error = Internal::is_detected<member_error_t, Rule>;
    if constexpr (has_error) {
      throw std::runtime_error(Rule::error());
    } else {
      throw std::runtime_error("Failed parsing Rule without error: " + tao::pegtl::internal::demangle<Rule>());

    }
  }

  template <apply_mode A, rewind_mode M, template <typename...> class Action,
            template <typename...> class Control, typename Input,
            typename State>
  static bool match(Input &in, State &state) {

    constexpr bool has_member_state =
        Internal::is_detected<member_state_t, Action<Rule>>;

    constexpr bool has_member_action =
            Internal::is_detected<member_action_t, Action<Rule>, void>;

    static_assert(!(has_member_state ^ has_member_action),
                  "Need both or neither scope, action");

    if constexpr (has_member_state) {
      typename Action<Rule>::state new_state;

      if (normal_rule::template match<A, M, Action<Rule>::template action, Control>(in, new_state)) {
        Action<State>::success(state, std::move(new_state));
        return true;
      }

      return false;

    } else {
      return normal_rule::template match<A, M, Action, Control>(in, state);
    }
  }
};

} // namespace Parse

#endif // LIBPARSE_CONTROL_SCOPED_H_
