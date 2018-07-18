#ifndef LIBSDF_GRAMMAR_NUMBERS_HPP 
#define LIBSDF_GRAMMAR_NUMBERS_HPP 

#include <sdf/grammar/base.hpp>

namespace SDF {
namespace Grammar {
// clang-format off

struct integer : plus<decimal_digit> {};
struct fractional : alias<integer> {};
struct exponent : alias<integer> {};

struct real_number : must<
  not_at<one<'-'>>,
  opt<integer>,
  tao::pegtl::opt_must<seq<one<'.'>, fractional>>,
  tao::pegtl::opt_must<seq<one<'e'>, opt<sign>, exponent>>
> {};

struct signed_real_number : must<
  opt<sign>,
  real_number
> {};

// clang-format on
} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_NUMBERS_HPP 
