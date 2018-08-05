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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_EXPRESSION_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_EXPRESSION_HPP

#include "./attribute.hpp"
#include "./constants.hpp"
#include "./identifiers.hpp"
#include "./numbers.hpp"
#include "./operators.hpp"
#include "./ranges.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;

//forward
struct expression;
struct range_expression;
struct concatenation;
struct constant_concatenation;
struct multiple_concatenation;
struct module_path_primary; 
struct mintypmax_expression;
struct conditional_expression;
struct constant_range_expression;
struct net_concatenation;
struct variable_concatenation;
struct variable_concatenation_value;
struct constant_mintypmax_expression;
struct constant_multiple_concatenation;


struct constant_function_call : seq< 
  function_identifier, 
  star<attribute_instance>, 
  one<'('>, list<constant_expression, one<','>, plus_sep>, one<')'>
> {};

struct function_call : opt_sep_seq<
  hierarchical_function_identifier, 
  star<attribute_instance>, 
  one<'('>, list<expression, one<','>, plus_sep>, one<')'>
> {};

struct genvar_function_call : opt_sep_seq<
  genvar_function_identifier, 
  star<attribute_instance>, 
  one<'('>, list<expression, one<','>, plus_sep>, one<')'>
> {};

struct system_function_call : seq<
  system_function_identifier, 
  opt< one<'('>, list<expression, one<','>, plus_sep>, one<')'> >
> {};

struct primary : sor<
  number, 
  hierarchical_identifier, 
  opt_sep_seq<
    hierarchical_identifier, 
    list<opt_sep_seq<one<'['>, expression, one<']'>>, plus_sep>
  >,
  opt_sep_seq<
    hierarchical_identifier, 
    list< 
      opt_sep_seq<one<'['>, expression, one<']'>>, plus_sep
    >, 
    opt_sep_seq<one<'['>, range_expression, one<']'>>
  >, 
  opt_sep_seq<hierarchical_identifier, one<'['>, range_expression, one<']'>>, 
  concatenation, 
  multiple_concatenation, 
  function_call, 
  system_function_call, 
  constant_function_call, 
  opt_sep_seq<one<'('>, mintypmax_expression, one<')'>>
> {};


struct constant_primary : sor<
  constant_concatenation,
  constant_function_call,
  opt_sep_seq< one<'('>, constant_mintypmax_expression, one<')'>>,
  constant_multiple_concatenation,
  genvar_identifier,
  number,
  parameter_identifier,
  specparam_identifier
> {};


struct expression : sor <
  primary, 
  opt_sep_must<
    unary_operator, 
    tao::pegtl::pad_opt<attribute_instance, plus_sep>, 
    primary
  >, 
  opt_sep_must<
    expression, 
    binary_operator, 
    tao::pegtl::pad_opt<attribute_instance, plus_sep>, 
    expression
  >, 
  conditional_expression,
  qstring
> {};

struct base_expression : alias<expression> {};

struct constant_expression : sor<
  constant_primary,
  opt_sep_seq<
    unary_operator, 
    star< attribute_instance >, 
    constant_primary
  >,
  opt_sep_seq<
    constant_expression, 
    binary_operator, 
    star<attribute_instance>, 
    constant_expression
  >,
  opt_sep_seq<
    constant_expression, 
    one<'?'>, 
    star< attribute_instance >, 
    constant_expression, 
    one<':'>,
    constant_expression
  >, 
  qstring
> {};

struct constant_base_expression : alias<constant_expression> {};


struct width_constant_expression : alias<constant_expression> {};
struct msb_constant_expression : alias<constant_expression> {};
struct lsb_constant_expression : alias<constant_expression> {};

struct constant_range_expression : sor<
  constant_expression,
  opt_sep_seq<
    msb_constant_expression, 
    one<':'>, 
    lsb_constant_expression
  >,
  opt_sep_seq<
    constant_base_expression, 
    sor<
      seq<one<'+'>,one<':'>>,
      seq<one<'-'>,one<':'>>
    >,
    width_constant_expression
  >
> {};

struct expression1 : alias<expression> {};
struct expression2 : alias<expression> {};
struct expression3 : alias<expression> {};

struct conditional_expression : opt_sep_seq<
 expression1, one<'?'>, star< attribute_instance >, expression2, one<':'>, expression3
> {};

struct range_expression : sor<
  expression, 
  opt_sep_seq<
    msb_constant_expression, 
    one<':'>, 
    lsb_constant_expression
  >, 
  opt_sep_seq<
    base_expression, 
    sor<
      seq<one<'+'>,one<':'>>,
      seq<one<'-'>,one<':'>>
    >,
    width_constant_expression
  >
> {};


struct range : opt_sep_seq<
  one<'['>,
  msb_constant_expression, 
  one<':'>,
  lsb_constant_expression,
  one<']'>
> {};

struct bus_range : alias<range> {};

struct dimension_constant_expression : alias<constant_expression> {};

struct dimension : opt_sep_seq<
  one<'['>,
  dimension_constant_expression, 
  one<':'>,
  dimension_constant_expression,
  one<']'>
> {};

template< class T >
struct triple_min : alias<T> {};
template< class T >
struct triple_typ : alias<T> {};
template< class T >
struct triple_max : alias<T> {};

template< class T >
struct triple : seq < 
  not_at< string<':',':'>, not_at<T> >,
  opt_sep_seq<
    opt<triple_min<T>>,
    one<':'>,
    opt<triple_typ<T>>,
    one<':'>,
    opt<triple_max<T>>
  >
> {};

template< class T >
struct mintypmax : must<
    sor<triple<T>,T>
> {};

struct mintypmax_expression : mintypmax<expression> {};
struct constant_mintypmax_expression : mintypmax<constant_expression> {};

struct event_expression : sor<
  expression, 
  hierarchical_identifier, 
  seq<posedge_keyword, expression>, 
  seq<negedge_keyword, expression>, 
  seq<event_expression, seq<one<'o'>,one<'r'>>, event_expression>, 
  seq<event_expression, one<','>, event_expression>
> {};

struct concatenation : opt_sep_seq<
  one<'{'>, 
  list<seq<expression, plus_sep>, one<','>>,
  one<'}'> 
> {};

struct constant_concatenation : opt_sep_seq<
  one<'{'>, 
  list<seq<constant_expression, plus_sep>, one<','>>,
  one<'}'> 
> {};

struct constant_multiple_concatenation : opt_sep_seq<
  one<'{'>, 
  constant_expression,
  constant_concatenation, 
  one<'}'> 
> {};


struct variable_concatenation :  opt_sep_seq<
  one<'{'>, 
  list<seq<variable_concatenation_value, plus_sep>, one<','>>,
  one<'}'> 
> {};

struct variable_concatenation_value : sor<
  opt_sep_seq< 
    hierarchical_variable_identifier, 
    list<opt_sep_seq<one<'['>, expression, one<']'>>, plus_sep>, 
    opt<range_expression>
  >,
  variable_concatenation
> {};

struct variable_lvalue : alias<variable_concatenation_value> {};

struct module_path_expression : sor<
  module_path_primary,
  seq<unary_module_path_operator, star<attribute_instance>, module_path_primary>
> {};

struct module_path_mintypmax_expression : mintypmax<module_path_expression> {};

struct module_path_concatenation : opt_sep_seq<
  one<'{'>, 
  list<seq<module_path_expression, plus_sep>, one<','>>,
  one<'}'> 
> {};

struct module_path_multiple_concatenation : opt_sep_seq<
  one<'{'>, 
  constant_expression,
  module_path_concatenation, 
  one<'}'> 
> {};


struct module_path_primary : sor<
  number, 
  identifier, 
  module_path_concatenation, 
  module_path_multiple_concatenation, 
  function_call, 
  system_function_call, 
  constant_function_call, 
  seq<one<'('>, module_path_mintypmax_expression, one<')'>>
> {};


struct multiple_concatenation : opt_sep_seq<
  one<'{'>, 
  constant_expression,
  concatenation, 
  one<'}'> 
> {};

struct net_concatenation_value : sor<
  opt_sep_seq< 
    hierarchical_net_identifier, 
    list<opt_sep_seq<one<'['>, expression, one<']'>>, plus_sep>, 
    opt<range_expression>
  >,
  net_concatenation
> {};

struct net_concatenation : opt_sep_seq<
  one<'{'>, 
  list<seq<net_concatenation_value, plus_sep>, one<','>>,
  one<'}'> 
> {};

struct net_lvalue : sor<
  seq< 
    hierarchical_net_identifier, 
    plus<expression>, 
    one<'['>, constant_range_expression, one<']'> 
  >,
  net_concatenation
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_EXPRESSION_HPP
