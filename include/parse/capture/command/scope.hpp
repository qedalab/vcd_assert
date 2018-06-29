#ifndef LIBPARSE_CAPTURE_COMMAND_INNER_ACTION_HPP
#define LIBPARSE_CAPTURE_COMMAND_INNER_ACTION_HPP

#include "../make_pegtl_template.hpp"

#include <tao/pegtl/rewind_mode.hpp>
#include <tao/pegtl/apply_mode.hpp>
#include <tao/pegtl/internal/duseltronik.hpp>
#include <tao/pegtl/internal/action_input.hpp>

namespace Parse {

template <typename InnerAction, typename Storage>
struct InnerActionCommand {
  using rewind_mode = tao::pegtl::rewind_mode;
  using apply_mode = tao::pegtl::apply_mode;

  template <class Rule, rewind_mode M, template <typename...> class Action,
      template <typename...> class Control, class Input,
      typename State>
  static bool command(Input &input, State& state) {

    typename InnerAction::state inner_state;

    if(Control<Rule>::template match<apply_mode::NOTHING, M, make_pegtl_template<InnerAction>::template type, Control>(input, inner_state)) {
      return Storage::store(state, std::move(inner_state));
    }

    return false;
  }
};

} // namespace Parse

#endif //PARSE_APPLY_HPP

