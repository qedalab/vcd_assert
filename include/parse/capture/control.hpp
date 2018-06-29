#ifndef PARSE_CONTROL_HPP
#define PARSE_CONTROL_HPP

#include "../internal/detected.h"
#include "../control/base.h"
#include "../control/error.hpp"
#include "inner_action.hpp"
#include "make_pegtl_template.hpp"
#include "./dispatch.hpp"

#include <tao/pegtl/normal.hpp>
#include <type_traits>
#include <iostream>

namespace Parse {

template <class Rule>
struct capture_control : public error_control<Rule> {

  template <apply_mode A /*unused*/, rewind_mode M,
            template <typename...> class Action,
            template <typename...> class Control, typename Input,
            typename State>
  static bool match(Input &in, State &state) {
    using apply_mode = tao::pegtl::apply_mode;


    if constexpr (action_has_tag_dispatch<Action<Rule>, Rule>) {
      using tag_dispatch = action_tag_dispatch_decl<Action<Rule>, Rule>;
      return tag_dispatch::template command<Rule, M, Action,
                                   Control>(in, state);
    } else {
      // Just a normal matcher
      return tao::pegtl::internal::duseltronik<
          Rule, apply_mode::NOTHING, M, Action, Control>::match(in, state);
    }
  }
};

} // namespace Parse

#endif //PARSE_CONTROL_HPP
