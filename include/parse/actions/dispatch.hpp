#ifndef LIBPARSE_ACTIONS_DISPATCH_HPP
#define LIBPARSE_ACTIONS_DISPATCH_HPP

#include "parse/util/tag.hpp"

namespace Parse {

template<class Rule, class Command>
struct single_dispatch {
  static Command dispatch(Util::Tag<Rule>);
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
  static Command dispatch(Util::Tag<Rule>);
};

} // namespace Parse

#endif // LIBPARSE_ACTIONS_DISPATCH_HPP
