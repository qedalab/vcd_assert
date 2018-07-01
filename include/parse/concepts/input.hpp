#ifndef LIBPARSE_CONCEPTS_INPUT_HPP
#define LIBPARSE_CONCEPTS_INPUT_HPP

#include <range/v3/utility/concepts.hpp>
#include <tao/pegtl/memory_input.hpp>

namespace Parse::Concepts {

namespace Internal {

using namespace ranges::concepts;

struct Input {
  // Example type satisfying Input
  using type = tao::pegtl::memory_input<>;

  // TODO complete
};

} // namespace Internal

} // namespace Parse::Concepts

#endif // LIBPARSE_CONCEPTS_INPUT_HPP
