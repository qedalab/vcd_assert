#ifndef LIBPARSE_CONTROL_SCOPED_H_
#define LIBPARSE_CONTROL_SCOPED_H_

#include "./base.h"
#include "./error.hpp"
#include "../internal/detected.h"

#include <tao/pegtl/normal.hpp>

namespace Parse {

template <class Rule>
struct scoped_control : public error_control<Rule> {

  using normal_rule = tao::pegtl::normal<Rule>;

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
