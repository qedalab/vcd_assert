
#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_DATA_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_DATA_HPP

#include "./base.hpp"
#include "./constants.hpp"
#include "./expressions.hpp"
#include "./operators.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct range : op_sep_seq<
  one<'['>,
  msb_constant_expression, 
  one<':'>,
  lsb_constant_expression,
  one<']'>
> {};

struct bus_range : alias<range> {};

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

struct output_variable_type : sor<
  integer_keyword, 
  time_keyword
> {};

struct net_type : sor<
  supply0_keyword,
  supply1_keyword,
  tri_keyword,
  triand_keyword,
  trior_keyword,
  tri0_keyword,
  tri1_keyword,
  wire_keyword,
  wand_keyword,
  wor_keyword
>{};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_DATA_HPP
