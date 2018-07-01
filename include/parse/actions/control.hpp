#ifndef LIBPARSE_ACTIONS_CONTROL_HPP
#define LIBPARSE_ACTIONS_CONTROL_HPP

#include "../concepts/dispatch.hpp"
#include "../concepts/error_rule.hpp"

#include <tao/pegtl/normal.hpp>

#include <type_traits>

namespace Parse {

template <class Rule>
struct capture_control : public tao::pegtl::normal<Rule> {
  using apply_mode = tao::pegtl::apply_mode;
  using rewind_mode = tao::pegtl::rewind_mode;

  template <typename Input, typename... States>
  static void raise(const Input &in, States &&... /*unused*/) {
    // throw ParseException(Rule::error(), in.position()));
    if constexpr (Concepts::ErrorRule<Rule>) {
      throw std::runtime_error(Rule::error());
    } else {
      throw std::runtime_error("Failed parsing Rule without error: " + tao::pegtl::internal::demangle<Rule>());
    }
  }

  template <apply_mode A, rewind_mode M,
            template <typename...> class Action,
            template <typename...> class Control, typename Input,
            typename State>
  static bool match(Input &in, State &state) {
    if constexpr (Concepts::DispatchRule<Action<Rule>, Rule>) {
      using Command = decltype(Action<Rule>::dispatch(Util::Tag<Rule>{}));
      return Command::template command<Rule, M, Action, Control>(in, state);
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
