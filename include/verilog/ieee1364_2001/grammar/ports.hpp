
#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_PORTS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_PORTS_HPP

#include "./base.hpp"
#include "./data.hpp"
#include "./keywords.hpp"
#include "./separator.hpp"
#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct list_of_port_declarations;
struct port;
struct port_expression;
struct port_reference;
struct port_declaration;
struct inout_declaration;
struct input_declaration;
struct output_declaration;
struct list_of_port_identifiers;
struct list_of_variable_port_identifiers;

struct list_of_ports : op_sep_must<
  one<'('>, 
  list<
    seq<port, opt<separator>>, 
    one<','>>, 
  one<')'>
> {};

struct list_of_port_declarations : op_sep_must<
  one<'('>, 
  list<
    seq<port_declaration, opt<separator>>, 
    one<','>
  >,  
  one<')'>
> {};

struct port_identifier : alias<identifier>{};

struct port : sor<
  port_expression,  //ASSUMPTION (assume not optional)
  seq<one<'.'>, port_identifier>, one<'('>, opt<port_expression>, one<')'>
> {};
struct port_expression : sor<
  port_reference, 
  list<seq<port_reference, opt<separator>>,one<','>> 
> {};
struct port_reference : sor<
  port_identifier, 
  op_sep_seq< 
    port_identifier, one<'['>, constant_expression, one<']'>
  >, 
  op_sep_seq< 
    port_identifier, one<'['>, range_expression, one<']'>
  >
> {};

struct port_declaration : sor<
  seq<list<attribute_instance, plus_blank>, inout_declaration>, 
  seq<list<attribute_instance, plus_blank>, input_declaration>, 
  seq<list<attribute_instance, plus_blank>, output_declaration>
> {};

struct inout_declaration : op_sep_seq<
  inout_keyword, 
  opt<net_type>, 
  opt<signed_keyword>, 
  opt<bus_range>, 
  list_of_port_identifiers
> {};

struct input_declaration : op_sep_seq<
  input_keyword,
  opt<net_type>,
  opt<signed_keyword>,
  opt<bus_range>,
  list_of_port_identifiers
> {};

struct output_declaration : sor<
  op_sep_seq< 
    output_keyword,
    opt<net_type>,
    opt<signed_keyword>,
    opt<bus_range>,
    list_of_port_identifiers,
  >,
  op_sep_seq< 
    output_keyword,
    opt<reg_keyword>,
    opt<signed_keyword>,
    opt<bus_range>,
    list_of_port_identifiers,
  >,
  op_sep_seq< 
    output_keyword,
    reg_keyword,
    opt<signed_keyword>,
    opt<bus_range>,
    list_of_variable_port_identifiers,
  >,
  op_sep_seq< 
    output_keyword,
    opt<output_variable_type>,
    list_of_port_identifiers,
  >,
  op_sep_seq< 
    output_keyword,
    output_variable_type,
    list_of_variable_port_identifiers
  >
> {};

struct list_of_port_identifiers : must<
  list<
    seq<port_identifier, opt<separator>>, 
    one<','>
  >
> {};

struct list_of_variable_port_identifiers : list< 
  op_sep_seq<
    port_identifier, one<'['>, one<'='>, constant_expression, one<']'>, 
  >, 
  one<','>
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_PORTS_HPP
