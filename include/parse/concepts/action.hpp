#ifndef LIBPARSE_CONCEPTS_ACTION_HPP
#define LIBPARSE_CONCEPTS_ACTION_HPP

#include <tao/pegtl/nothing.hpp>

namespace Parse::Concepts {

namespace Internal {

struct Action {
  // Example type satisfying Action
  template <typename Rule>
  using type = tao::pegtl::nothing<Rule>;

  // TODO complete
};

} // namespace Internal

} // namespace Parse::Concepts

#endif // LIBPARSE_CONCEPTS_ACTION_HPP
