#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_ATTR_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_ATTR_HPP

#include "./base.hpp"
#include "./constants.hpp"
#include "./separator.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct attr_name : alias<identifier> {};

struct attr_spec : sor <
  attr_name,
  op_sep_must<
    attr_name,
    one<'='>,
    constant_expression
  >
> {};

struct attribute_instance : if_must<
  seq<one<'('>,one<'*'>>,
  list<
    seq<attr_spec, opt<separator>>, 
    one<','>
  >,
  seq<one<'*'>,one<')'>>,
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_ATTR_HPP
