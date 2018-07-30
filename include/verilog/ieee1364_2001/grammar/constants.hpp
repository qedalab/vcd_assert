
#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_CONSTANTS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_CONSTANTS_HPP

#include "./attribute.hpp"
#include "./base.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;
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

struct constant_primary : sor<
  constant_concatenation
  // constant_function_call,
  // op_sep_seq< one<'('>, constant_mintypmax_expression, one<')'>>,
  // constant_multiple_concatenation,
  // genvar_identifier,
  // number,
  // parameter_identifier,
  // specparam_identifier
> {};

struct constant_expression : sor<
  constant_primary,
  op_sep_seq<
    unary_operator, 
    star< attribute_instance >, 
    constant_primary
  >,
  op_sep_seq<
    constant_expression, 
    binary_operator, 
    star<attribute_instance>, 
    constant_expression
  >,
  op_sep_seq<
    constant_expression, 
    one<'?'>, 
    star< attribute_instance >, 
    constant_expression
  >, 
  constant_expression,
  qstring
> {};


// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_CONSTANTS_HPP
