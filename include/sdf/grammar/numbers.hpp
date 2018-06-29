#ifndef LIBSDF_GRAMMAR_NUMBERS_H
#define LIBSDF_GRAMMAR_NUMBERS_H

#include <sdf/grammar/base.hpp>

namespace SDF {
namespace Grammar {
// clang-format off

struct integer : plus<decimal_digit> {};

struct real_number : must<
  opt<integer>,
  opt<seq<one<'.'>, integer>>,
  opt<seq<one<'e'>, opt<sign>, integer>>
> {};

struct signed_real_number : must<
  opt<sign>,
  real_number
> {};

// clang-format on
} // namespace Grammar
} // namespace SDF

#endif // PARSE_CONSTANTS_H
