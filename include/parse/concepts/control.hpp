#ifndef LIBPARSE_CONCEPTS_CONTROL_HPP
#define LIBPARSE_CONCEPTS_CONTROL_HPP

#include <tao/pegtl/normal.hpp>

namespace Parse::Concepts {

namespace Internal {

struct Control {
  // Example type satisfying Action
  template <typename Rule>
  using type = tao::pegtl::normal<Rule>;

  // TODO complete
};

} // namespace Internal

} // namespace Parse::Concepts

#endif // LIBPARSE_CONCEPTS_CONTROL_HPP
