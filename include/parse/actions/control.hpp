#ifndef LIBPARSE_ACTIONS_CONTROL_HPP
#define LIBPARSE_ACTIONS_CONTROL_HPP

#include "../control/base.h"
#include "../control/error.hpp"
#include "./dispatch.hpp"

#include <type_traits>

namespace Parse {

template <class Rule>
struct capture_control : public error_control<Rule> {

  template <apply_mode A, rewind_mode M,
            template <typename...> class Action,
            template <typename...> class Control, typename Input,
            typename State>
  static bool match(Input &in, State &state) {
    if constexpr (action_has_tag_dispatch<Action<Rule>, Rule>) {
      using tag_dispatch = action_tag_dispatch_decl<Action<Rule>, Rule>;
      return tag_dispatch::template command<Rule, M, Action,
                                   Control>(in, state);
    } else {
      // Just a normal matcher
      // TODO handle the case of getting a PEGTL action properly
      return tao::pegtl::internal::duseltronik<
          Rule, A, M, Action, Control>::match(in, state);
    }
  }
};

} // namespace Parse

#endif // LIBPARSE_ACTIONS_CONTORL_HPP
