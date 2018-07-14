#ifndef LIBPARSE_ACTIONS_COMMAND_INNER_ACTION_HPP
#define LIBPARSE_ACTIONS_COMMAND_INNER_ACTION_HPP

#include "../make_pegtl_template.hpp"

#include <tao/pegtl/apply_mode.hpp>
#include <tao/pegtl/internal/action_input.hpp>
#include <tao/pegtl/internal/duseltronik.hpp>
#include <tao/pegtl/rewind_mode.hpp>

// TODO don't depend on pegtl::internal

namespace Parse {

template <typename InnerAction, typename Storage>
struct inner_action {
  using rewind_mode = tao::pegtl::rewind_mode;
  using apply_mode = tao::pegtl::apply_mode;

  template <class Rule, rewind_mode M, template <typename...> class Action,
            template <typename...> class Control, class Input,
            typename... Stack, typename State>
  static bool command(Input &input, State &state, Stack &... stack) {
    typename InnerAction::state inner_state;

    if (Control<Rule>::template match<
            apply_mode::NOTHING, M,
            make_pegtl_template<InnerAction>::template type, Control>(
            input, inner_state, stack...)) {
      return Storage::store(state, std::move(inner_state));
    }

    return false;
  }
};

template <typename InnerAction>
struct inner_action_passthrough {
  using rewind_mode = tao::pegtl::rewind_mode;
  using apply_mode = tao::pegtl::apply_mode;

  template <class Rule, rewind_mode M, template <typename...> class Action,
            template <typename...> class Control, class Input, typename State>
  static bool command(Input &input, State &state) {
    typename InnerAction::state inner_state;

    if (Control<Rule>::template match<
            apply_mode::NOTHING, M,
            make_pegtl_template<InnerAction>::template type, Control>(
            input, inner_state)) {
      state = std::move(inner_state);
      return true;
    }

    return false;
  }
};


} // namespace Parse

#endif // LIBPARSE_ACTIONS_COMMAND_INNER_ACTION_HPP
