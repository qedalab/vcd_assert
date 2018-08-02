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
