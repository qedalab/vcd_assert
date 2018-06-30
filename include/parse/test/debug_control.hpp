#ifndef PARSE_TEST_DEBUG_CONTROL_H
#define PARSE_TEST_DEBUG_CONTROL_H

#include "./debug_exception.hpp"
#include "../concepts/error_rule.hpp"

#include <tao/pegtl/normal.hpp>

namespace Parse::Test {

template<class Rule>
struct debug_control : public tao::pegtl::normal<Rule> {
  using apply_mode = tao::pegtl::apply_mode;
  using rewind_mode = tao::pegtl::rewind_mode;

  using normal_rule = tao::pegtl::normal<Rule>;

  template <typename Input, typename... States>
  static void raise(const Input &in, States &&... /*unused*/) {
    // throw ParseException(Rule::error(), in.position()));
    if constexpr (Concepts::ErrorRule<Rule>) {
      throw DebugException(Rule::error());
    } else {
      auto demangled = std::string(tao::pegtl::internal::demangle<Rule>());
      throw DebugException("Failed parsing Rule without error: " + demangled);
    }
  }

  template <apply_mode A, rewind_mode M, template <typename...> class Action,
      template <typename...> class Control, typename Input,
      typename... States>
  static bool match(Input &in, States &&... states) {
    auto position = in.position();

    DebugState trace {
      .rule = tao::pegtl::internal::demangle<Rule>(),
      .line = position.line,
      .col = position.byte_in_line,
    };

    try {
      return normal_rule::template match<A, M, Action, debug_control>(in, states...);
    } catch (DebugException& de){
      de.add_trace(std::move(trace));
      throw;
    }
  }

};

} // namespace Parse::Test

#endif //PARSE_DEBUG_H
