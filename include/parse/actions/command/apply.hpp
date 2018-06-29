#ifndef LIBPARSE_ACTIONS_COMMAND_APPLY_HPP
#define LIBPARSE_ACTIONS_COMMAND_APPLY_HPP

#include <tao/pegtl/rewind_mode.hpp>
#include <tao/pegtl/apply_mode.hpp>
#include <tao/pegtl/internal/duseltronik.hpp>
#include <tao/pegtl/internal/action_input.hpp>

// TODO don't rely on pegtl::internal

namespace Parse {

template <typename Apply>
struct apply {
  using rewind_mode = tao::pegtl::rewind_mode;
  using apply_mode = tao::pegtl::apply_mode;

  template <typename Rule, rewind_mode M, template <typename...> class Action,
            template <typename...> class Control, class Input,
            typename... States>
  static bool command(Input &input, States &&... states) {
    using duseltronik =
        tao::pegtl::internal::duseltronik<Rule, apply_mode::NOTHING, M, Action,
                                          Control>;
    auto start = input.iterator();

    if (duseltronik::match(input, states...)) {
      tao::pegtl::internal::action_input ai(start, input);
      return Apply::template apply<Rule>(ai, states...);
    }

    return false;
  }
};

} // namespace Parse

#endif // LIBPARSE_ACTIONS_COMMAND_APPLY_HPP
