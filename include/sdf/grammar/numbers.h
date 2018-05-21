#ifndef LIBSDF_GRAMMAR_NUMBERS_H
#define LIBSDF_GRAMMAR_NUMBERS_H

#include "parse/grammar/base.h"
#include "./base.h"

namespace SDF {
namespace Grammar {

using namespace Parse::Grammar::Base;

struct integer : plus<decimal_digit> {};

struct real_number : seq<
  integer,
  opt<one<'.'>, integer>,
  opt<one<'e'>, opt<sign>, integer>
> {};

struct signed_real_number : seq<
  opt<sign>,
  real_number
> {};

}
}


#endif //PARSE_CONSTANTS_H
