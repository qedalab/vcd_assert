#ifndef LIBPARSE_CAPTURE_CAPTURE_HPP
#define LIBPARSE_CAPTURE_CAPTURE_HPP

#include "../internal/tag.hpp"
#include "parse/capture/command/scope.hpp"

#include <utility>

namespace Parse {

template <class Action, class Storage>
using inner_action = InnerActionCommand<Action, Storage>;

} // namespace

#endif // LIBPARSE_CAPTURE_CAPTURE_HPP
