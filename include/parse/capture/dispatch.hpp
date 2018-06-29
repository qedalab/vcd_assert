#ifndef LIBPARSE_CAPTURE_DISPATCH_HPP
#define LIBPARSE_CAPTURE_DISPATCH_HPP

#include "../internal/tag.hpp"
#include "../internal/detected.h"

namespace Parse {

template <typename Action, typename Rule>
using action_tag_dispatch_decl =
    decltype(Action::dispatch(Internal::Tag<Rule>{}));

template <typename Action, typename Rule>
constexpr bool action_has_tag_dispatch =
    Internal::is_detected<action_tag_dispatch_decl, Action, Rule>;

} // namespace Parse

#endif // PARSE_DISPATCH_HPP
