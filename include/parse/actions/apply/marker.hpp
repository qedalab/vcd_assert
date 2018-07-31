#ifndef LIBPARSE_ACTIONS_APPLY_MARKER_HPP
#define LIBPARSE_ACTIONS_APPLY_MARKER_HPP

#include "../../util/marker.hpp"

namespace Parse::Apply {

struct marker {
  template <class Rule, class ActionInput, class... Stack>
  static bool apply(const ActionInput &input, Util::Marker &marker,
                    const Stack &... /*unused*/
  )
  {
    auto &it = input.iterator();
    marker.byte_in_line = it.byte_in_line;
    marker.line = it.line;

    return true;
  }
};

} // namespace Parse::Apply

#endif // LIBPARSE_ACTIONS_APPLY_MARKER_HPP
