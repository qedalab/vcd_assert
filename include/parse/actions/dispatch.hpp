#ifndef LIBPARSE_ACTIONS_DISPATCH_HPP
#define LIBPARSE_ACTIONS_DISPATCH_HPP

#include "../internal/tag.hpp"
#include "../internal/detected.h"

namespace Parse {

template<class Rule, class Command>
struct single_dispatch {
  static Command dispatch(Internal::Tag<Rule>);
};

template<class Rule, class Command, class... Rest>
struct multi_dispatch : single_dispatch<Rule, Command>, multi_dispatch<Rest...> {
  using multi_dispatch<Rest...>::dispatch;
  using single_dispatch<Rule, Command>::dispatch;
};

template<class Rule, class Command>
struct multi_dispatch<Rule, Command> : single_dispatch<Rule, Command> {
  using single_dispatch<Rule, Command>::dispatch;
};

template<class Command>
struct all_dispatch {
  template<class Rule>
  static Command dispatch(Internal::Tag<Rule>);
};

template <typename Action, typename Rule>
using action_tag_dispatch_decl =
    decltype(Action::dispatch(Internal::Tag<Rule>{}));

template <typename Action, typename Rule>
constexpr bool action_has_tag_dispatch =
    Internal::is_detected<action_tag_dispatch_decl, Action, Rule>;

} // namespace Parse

#endif // LIBPARSE_ACTIONS_DISPATCH_HPP
