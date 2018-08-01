#ifndef LIBPARSE_ACTIONS_MARKER_HPP
#define LIBPARSE_ACTIONS_MARKER_HPP

#include "./apply/marker.hpp"
#include "./command/apply.hpp"
#include "./dispatch.hpp"

#include "../util/marker.hpp"

namespace Parse {

// clang-format off
struct MarkerAction : single_dispatch <
  Parse::Grammar::marker, apply<Apply::marker>
> {
  using state = Util::Marker;
};
// clang-format on

} // namespace Parse

#endif // LIBPARSE_ACTIONS_MARKER_HPP
