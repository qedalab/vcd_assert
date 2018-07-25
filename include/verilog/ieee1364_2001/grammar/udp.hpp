#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_UPD_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_UPD_HPP

#include "./base.hpp"
#include "./keywords.hpp"
#include "./module.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off


struct udp_identifier : alias<identifier> {};
struct variable_identifier : alias<identifier> {};

struct udp_input_declaration : op_seq_seq<
  star<attribute_instance>, 
  input_keyword,
  list_of_port_identifiers
> {};

struct udp_output_declaration : sor<
  op_sep_seq<
    star<attribute_instance>, 
    output_keyword, 
    port_identifier
  >,
  op_sep_seq<
    star<attribute_instance>, 
    output_keyword, 
    reg_keyword, 
    port_identifier, 
    one<'['>,  one<'='>,  constant_expression, one<']'> 
  >
> {};

struct udp_reg_declaration : op_sep_seq <
  star<attribute_instance>, 
  reg_keyword,
  variable_identifier
> {};

struct udp_declaration_port_list : sor<
  op_sep_seq<
    udp_output_declaration, 
    one<';'>
  >,
  op_sep_seq<
    udp_input_declaration, 
    one<';'>
  >,
  op_sep_seq<
    udp_reg_declaration, 
    one<';'>
  >
> {};

struct udp_body : must<

> {};

struct udp_declaration : sor<
  op_sep_seq<
    star<attribute_instance>, 
    primitive_keyword, udp_identifier, 
    one<'('>, udp_port_list, one<')'>, one<';'>,
    plus<udp_port_declaration>,
    udp_body,
    endprimitive_keyword
  >,
  op_sep_seq<
    star<attribute_instance>, 
    primitive_keyword, udp_identifier, 
    one<'('>, udp_declaration_port_list, one<')'>, one<';'>,
    udp_body,
    endprimitive_keyword
  >
> {};

// clang-format on
} // namespace IEEE1364_2001
} // namespace Grammar
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_UPD_HPP
