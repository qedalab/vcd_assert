#ifndef LIBPARSE_CAPTURE_APPLY0_HPP
#define LIBPARSE_CAPTURE_APPLY0_HPP

#include "../internal/tag.hpp"
#include "./command/apply0.hpp"

namespace Parse {

template <class Apply0>
using apply0 = Apply0Command<Apply0>;

} // namespace Parse

#endif // LIBPARSE_CAPTURE_APPLY0_HPP
