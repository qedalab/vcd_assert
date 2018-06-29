#ifndef LIBPARSE_CAPTURE_APPLY_HPP
#define LIBPARSE_CAPTURE_APPLY_HPP

#include "../internal/tag.hpp"
#include "./command/apply.hpp"
#include "./command/apply0.hpp"

namespace Parse {

template <class Apply>
using apply = ApplyCommand<Apply>;

} // namespace Parse

#endif //PARSE_APPLY_HPP
