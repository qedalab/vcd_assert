#ifndef LIBPARSE_ACTIONS_COMMAND_APPLY0_HPP
#define LIBPARSE_ACTIONS_COMMAND_APPLY0_HPP

#include <tao/pegtl/rewind_mode.hpp>
#include <tao/pegtl/apply_mode.hpp>
#include <tao/pegtl/internal/dusel_mode.hpp>
#include <tao/pegtl/internal/duseltronik.hpp>

// TODO don't rely on pegtl::internal

namespace Parse {

template <typename Apply0>
struct apply0 {
  template <class Rule, tao::pegtl::rewind_mode M,
            template <typename...> class Action,
            template <typename...> class Control, class Input,
            typename... States>
  static bool command(Input &input, States &... states) {

    using duseltronik =
        tao::pegtl::internal::duseltronik<Rule, tao::pegtl::apply_mode::NOTHING,
                                          M, Action, Control>;
    // If it matches call apply0
    if (duseltronik::match(input, states...)) {
      return Apply0::template apply0<Rule>(states...);
    }

    // Otherwise signal failure
    return false;
  }
};

} // namespace Parse

#endif // LIBPARSE_ACTIONS_COMMAND_APPLY0_HPP
