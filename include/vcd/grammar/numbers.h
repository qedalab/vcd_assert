#ifndef LIBVCD_GRAMMAR_NUMBERS_H
#define LIBVCD_GRAMMAR_NUMBERS_H

#include "parse/grammar/base.h"
#include "parse/grammar/part.h"

#include "./enums/value.h"
#include "./keywords.h"

namespace VCD {
namespace Grammar {

using namespace Parse::Grammar::Base;

struct digit : Parse::Grammar::digit {};
struct non_zero_digit : Parse::Grammar::non_zero {};

struct binary_value : seq <
  value,
  star<
    sor<
      one<'_'>,
      value
    >
  >
> {};

struct unsigned_number : seq <
  digit,
  star<
    sor<
      one<'_'>,
      digit
    >
  >
> {};


struct non_zero_unsigned_number : seq <
  non_zero_digit,
  star<
    sor<
      one<'_'>,
      digit
    >
  >
> {};

struct decimal_base : seq<
  opt<one<'s','S'>>,
  one<'d','D'>
> {};

struct binary_base : seq<
  opt<one<'s','S'>>,
  one<'b','B'>
> {};

struct size : non_zero_unsigned_number {};

struct binary_number : seq <
  opt<size>,
  binary_base,
  binary_value
> {};

struct decimal_number : sor<
  seq<
    opt<size>,
    decimal_base,
    sor<
      unsigned_number,
      seq<value_x, star<one<'_'>>>,
      seq<value_z, star<one<'_'>>>
    >
  >,
  unsigned_number
> {};

struct sign : one<'+', '-'> {};

struct real_exponent_part : seq<
  one<'e','E'>,
  one<'+','-'>,
  unsigned_number
> {};

struct real_number : seq<
  unsigned_number,
  sor<
    seq<
      one<'.'>,
      unsigned_number,
      opt<real_exponent_part>
    >,
    real_exponent_part
  >
> {};

}
}

#endif // VCD_GRAMMAR_BASE_H
