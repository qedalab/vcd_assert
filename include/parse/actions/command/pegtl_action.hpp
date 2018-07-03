#ifndef LIBPARSE_ACTIONS_COMMAND_PEGTL_ACTION_HPP
#define LIBPARSE_ACTIONS_COMMAND_PEGTL_ACTION_HPP

#include <tao/pegtl/apply_mode.hpp>
#include <tao/pegtl/internal/action_input.hpp>
#include <tao/pegtl/internal/duseltronik.hpp>
#include <tao/pegtl/normal.hpp>
#include <tao/pegtl/rewind_mode.hpp>

namespace Parse::Actions {

template <template <typename...> class PEGTLAction>
struct pegtl_action {
  using rewind_mode = tao::pegtl::rewind_mode;
  using apply_mode = tao::pegtl::apply_mode;

  template <class Rule, rewind_mode M, template <typename...> class Action,
            template <typename...> class Control, class Input, typename State>
  static bool command(Input &input, State &state) {
    using normal = tao::pegtl::normal<Rule>;

    return normal::template match<apply_mode::ACTION, M, PEGTLAction, Control>(
        input, state);
  }
};

} // namespace Parse::Actions

#endif // LIBPARSE_ACTIONS_COMMAND_PEGTL_ACTION_HPP
