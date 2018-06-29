#ifndef LIBPARSE_CAPTURE_MULTI_DISPATCH_HPP
#define LIBPARSE_CAPTURE_MULTI_DISPATCH_HPP

#include "../internal/tag.hpp"

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

} // namespace

#endif //PARSE_MULTI_DISPATCH_HPP
