// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_NUMBERS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_NUMBERS_HPP

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

template< class T >
struct value_base : seq< 
    one<'`'>, 
    one<'s','S'>, 
    T
> {};

struct decimal_base : value_base< one<'d','D'> > {};
struct binary_base : value_base< one<'b','B'> > {};
struct octal_base : value_base< one<'o','O'> > {};
struct hex_base : value_base< one<'h','H'> > {};

struct non_zero_decimal_digit : tao::pegtl::range<'1','9'> {};
struct decimal_digit : tao::pegtl::range<'0','9'> {};

struct x_digit : one<
  'x','X'
> {};

struct z_digit : one<
  'z','Z','?'
> {};

struct binary_digit : sor<
 x_digit , z_digit , one<'0','1'>
 > {};

struct octal_digit : sor<
 x_digit , z_digit , one<'0','1','2','3','4','5','6','7'>
> {};

struct hex_digit : sor<
  x_digit, z_digit, 
  one<
  '0','1','2','3','4','5','6','7','8','9', 
  'a','b','c','d','e','f','A','B','C','D','E','F'
  >
> {};

struct binary_value : seq <
  binary_digit,
  star<
    sor<
      one<'_'>,
      binary_digit
    >
  >
> {};

struct octal_value : seq <
  octal_digit,
  star<
    sor<
      one<'_'>,
      octal_digit
    >
  >
> {};

struct hex_value : seq <
  hex_digit,
  star<
    sor<
      one<'_'>,
      hex_digit
    >
  >
> {};

struct non_zero_unsigned_number : seq<
  non_zero_decimal_digit,
  star<
    sor<
      one<'_'>,
      decimal_digit
    >
  >
> {};

struct unsigned_number : seq <
  decimal_digit,
  star<
    sor<
      one<'_'>,
      decimal_digit
    >
  >
> {};

// struct decimal_base : seq<
//   opt<one<'s','S'>>,
//   one<'d','D'>
// > {};

// struct binary_base : seq<
//   opt<one<'s','S'>>,
//   one<'b','B'>
// > {};

struct size :  alias< non_zero_unsigned_number > {};

// struct binary_number : seq <
//   opt<size>,
//   binary_base,
//   binary_value
// > {};

struct sign : sor< one<'+'>, one <'-'> > {};

struct decimal_number : sor<
  unsigned_number, 
  one<'['>, size, one<']'>, decimal_base, unsigned_number, 
  one<'['>, size, one<']'>, decimal_base, x_digit, star<one<'_'> >, 
  one<'['>, size, one<']'>, decimal_base, z_digit, star<one<'_'> >
> {};
struct binary_number : seq<
 one<'['>, size, one<']'>, binary_base, binary_value
> {};
struct octal_number : seq<
 one<'['>, size, one<']'>, octal_base, octal_value
> {};
struct hex_number : seq<
 one<'['>, size, one<']'>, hex_base, hex_value
> {};
struct exp : one<'e','E'> {};

// FROM SDF GRAMMAR
struct integer : plus<decimal_digit> {};
struct fractional : alias<integer> {};
struct exponent : alias<integer> {};

// struct real_number : sor<
// seq< unsigned_number, one<'.'>, unsigned_number >,
// seq< unsigned_number [ . unsigned_number ] exp [ sign ] unsigned_number
// > {};

// FROM SDF GRAMMAR
struct real_number : must<
  not_at<one<'-'>>,
  opt<integer>,
  tao::pegtl::opt_must<seq<one<'.'>, fractional>>,
  tao::pegtl::opt_must<seq<one<'e'>, opt<sign>, exponent>>
> {};

// FROM SDF GRAMMAR
struct signed_real_number : must<
  opt<sign>,
  real_number
> {};

struct number : sor<
  decimal_number,
  octal_number,
  binary_number,
  hex_number,
  real_number 
> {};

// clang-format off
}
}
}

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_NUMBERS_HPP
