#ifndef LIBSDF_GRAMMAR_CONSTANTS_HPP 
#define LIBSDF_GRAMMAR_CONSTANTS_HPP 

#include <sdf/grammar/base.hpp>

namespace SDF {
namespace Grammar {

// clang-format off

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

// clang-format on

} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_CONSTANTS_HPP 
