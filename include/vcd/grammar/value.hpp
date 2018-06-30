#ifndef LIBVCD_GRAMMAR_VALUE_HPP
#define LIBVCD_GRAMMAR_VALUE_HPP

#include "./base.hpp"
#include "./numbers.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace VCD::Grammar {

using namespace Parse::Grammar::Base;

// clang-format off

struct scalar_value_change : seq<
  value,
  identifier_code,
  command_separator
> {};

/// Used binary_value instead of binary_number
///   binary_number has a 'b' inside it and there is clearly not
///   a double 'b' in the VCD examples
struct binary_value_change : seq<
  one<'b','B'>,
  must<
    binary_value,
    plus_blank,
    identifier_code,
    command_separator
  >
> {};

/// TODO: investigate if real_number is correct since binary_number
///       was not.
struct real_value_change : seq<
  one<'r','R'>,
  must<
    real_number,
    identifier_code,
    command_separator
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

} // namespace VCD::Grammar

#endif // LIBVCD_GRAMMAR_VALUE_HPP
