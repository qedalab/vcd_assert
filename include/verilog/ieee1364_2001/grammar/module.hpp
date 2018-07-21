
#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_MODULE_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_MODULE_HPP

#include "./attribute.hpp"
#include "./base.hpp"
#include "./block.hpp"
#include "./data.hpp"
#include "./keywords.hpp"
#include "./ports.hpp"
#include "./separator.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;
 
struct param_identifier : alias<identifier> {};

struct param_assignment : op_sep_seq<
 param_identifier, one<'='>, constant_expression
> {};

struct list_of_param_assignments : list<
  seq<param_assignment, opt<separator>>, one<','> 
> {};

struct parameter_declaration : sor<
  op_sep_seq<
    parameter_keyword, 
    one<'['>, signed_keyword, one<']'>, 
    one<'['>, range, one<']'>, 
    list_of_param_assignments
  >,
  op_sep_seq<
    parameter_keyword, 
    integer_keyword,
    list_of_param_assignments
  >,
  op_sep_seq<
    parameter_keyword, 
    real_keyword,
    list_of_param_assignments
  >,
  op_sep_seq<
    parameter_keyword, 
    realtime_keyword,
    list_of_param_assignments
  >,
  op_sep_seq<
    parameter_keyword, 
    time_keyword,
    list_of_param_assignments
  >
> {};

/*# ( parameter_declaration { , parameter_declaration } )*/
struct module_parameter_port_list : op_sep_seq<
  one<'('>,
  list< 
    seq<
      parameter_declaration, 
      opt<separator>
    >, 
    one<','>
  >,
  one<')'>
> {};

struct module_identifier : alias<identifier> {};

// struct module_item : TODO

struct module_declaration : must<
  star<attribute_instance>,
  module_keyword,
  module_identifier,
  opt<module_parameter_port_list>,
  opt<list_of_ports>,
  one<';'>,
  // star<module_item>,
  endmodule_keyword
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_MODULE_HPP
