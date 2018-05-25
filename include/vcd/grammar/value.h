#ifndef LIBVCD_GRAMMAR_VALUE_H_
#define LIBVCD_GRAMMAR_VALUE_H_

#include "./base.h"
#include "./numbers.h"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace VCD {
namespace Grammar {

using namespace Parse::Grammar::Base;

// clang-format off

struct scalar_value_change : seq<
  value,
  identifier_code
> {};

/// Used binary_value instead of binary_number
///   binary_number has a 'b' inside it and there is clearly not
///   a double 'b' in the VCD examples
struct binary_value_change : seq<
  one<'b','B'>,
  must<
    binary_value,
    plus<blank>,
    identifier_code
  >
> {};

/// TODO: investigate if real_number is correct since binary_number
///       was not.
struct real_value_change : seq<
  one<'r','R'>,
  must<
    real_number,
    identifier_code
  >
> {};

struct vector_value_change : sor<
  binary_value_change,
  real_value_change
> {};

struct value_change : sor<
  vector_value_change,
  scalar_value_change
> {};

// clang-format on

} // namespace Grammer
} // namespace VCD

#endif // LIBVCD_GRAMMER_ENUMS_H_
