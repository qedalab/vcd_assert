#ifndef LIBPARSE_CONCEPTS_DISPATCH_HPP
#define LIBPARSE_CONCEPTS_DISPATCH_HPP

#include "../util/tag.hpp"

#include <range/v3/utility/concepts.hpp>

namespace Parse::Concepts {

namespace Internal {
using namespace ranges::concepts;

struct DispatchRule {
  template <typename Action, typename Rule>
  auto requires_()
      -> decltype(valid_expr(Action::dispatch(Parse::Util::Tag<Rule>{})));
};
} // namespace Internal

template <typename Action, typename Rule>
constexpr bool DispatchRule =
    ranges::concepts::models<Internal::DispatchRule, Action, Rule>();

} // namespace Parse::Concepts

#endif // LIBPARSE_CONCEPTS_DISPATCH_HPP
