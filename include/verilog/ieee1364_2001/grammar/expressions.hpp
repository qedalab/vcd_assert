#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_EXPRESSION_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_EXPRESSION_HPP

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;

struct expression;
struct range_expression;

struct primary : sor<
  // number, 
  hierarchical_identifier, 
  op_sep_seq<
    hierarchical_identifier, 
    list<op_sep_seq<one<'['>, expression, one<']'>>, separator>
  >
  // op_sep_seq<
  //   hierarchical_identifier, 
  //   list< 
  //     op_sep_seq<one<'['>, expression, one<']'>>, separator
  //   >, 
  //   op_sep_seq<one<'['>, range_expression, one<']'>>
  // >, 
  // op_sep_seq<hierarchical_identifier, one<'['>, range_expression, one<']'>>, 
  // concatenation, 
  // multiple_concatenation, 
  // function_call, 
  // system_function_call, 
  // constant_function_call, 
  // op_sep_seq<one<'('>, mintypmax_expression, one<')'>>
> {};

struct expression : sor <
  primary, 
  // op_sep_seq<
  //   unary_operator, 
  //   pad_op<attribute_instance, separator>, 
  //   primary
  // >, 
  // op_sep_seq<
  //   expression, 
  //   binary_operator, 
  //   pad_op<attribute_instance, separator>, 
  //   expression
  // >, 
  // conditional_expression,
  qstring
> {};

struct base_expression : alias<expression> {};
struct width_constant_expression : alias<constant_expression> {};
struct msb_constant_expression : alias<constant_expression> {};
struct lsb_constant_expression : alias<constant_expression> {};

struct range_expression : sor<
  expression, 
  op_sep_seq<msb_constant_expression, one<':'>, lsb_constant_expression>, 
  op_sep_seq<base_expression, one<'+'>, one<':'>, width_constant_expression>, 
  op_sep_seq<base_expression, one<'-'>, one<':'>, width_constant_expression>
> {};

struct concatenation : op_sep_seq<
  one<'{'>, 
  list<seq<expression, separator>, one<','>>,
  one<'}'> 
> {};

struct constant_concatenation : op_sep_seq<
  one<'{'>, 
  list<seq<constant_expression, separator>, one<','>>,
  one<'}'> 
> {};

struct constant_multiple_concatenation : op_sep_seq<
  one<'{'>, 
  constant_expression,
  constant_concatenation, 
  one<'}'> 
> {};

struct module_path_concatenation : op_sep_seq<
  one<'{'>, 
  // list<seq<module_path_expression, separator>, one<','>>,
  one<'}'> 
> {};

struct module_path_multiple_concatenation : op_sep_seq<
  one<'{'>, 
  constant_expression,
  module_path_concatenation, 
  one<'}'> 
> {};

struct multiple_concatenation : op_sep_seq<
  one<'{'>, 
  constant_expression,
  concatenation, 
  one<'}'> 
> {};

struct net_concatenation : op_sep_seq<
  one<'{'>, 
  // list<seq<net_concatenation_value, separator>, one<','>>,
  one<'}'> 
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_EXPRESSION_HPP
