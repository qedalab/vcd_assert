#ifndef LIBSDF_GRAMMAR_CONSTANTS_H
#define LIBSDF_GRAMMAR_CONSTANTS_H

#include "parse/grammar/base.h"

namespace SDF {
namespace Grammar {

using namespace Parse::Grammar::Base;

struct scalar_constant_b_prefix : one<'b','B'> {};
struct scalar_constant_1b_prefix : seq<one<'1'>, one<'b','B'>> {};
struct scalar_constant_0 : one<'0'> {};
struct scalar_constant_b0 : seq<scalar_constant_b_prefix, scalar_constant_0> {};
struct scalar_constant_1b0 : seq<scalar_constant_1b_prefix, scalar_constant_0> {};
struct scalar_constant_1 : one<'1'> {};
struct scalar_constant_b1 : seq<scalar_constant_b_prefix, scalar_constant_1> {};
struct scalar_constant_1b1 : seq<scalar_constant_1b_prefix, scalar_constant_1> {};

struct scalar_constant : sor<
  scalar_constant_1b0,
  scalar_constant_1b1,
  scalar_constant_b0,
  scalar_constant_b1,
  scalar_constant_0,
  scalar_constant_1
> {};

}
}


#endif //PARSE_CONSTANTS_H
