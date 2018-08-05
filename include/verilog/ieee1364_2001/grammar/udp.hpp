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
#include "./data.hpp"
#include "./delay.hpp"
#include "./expressions.hpp"
#include "./keywords.hpp"
#include "./numbers.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;


struct udp_input_declaration : opt_sep_seq<
  star<attribute_instance>, 
  input_keyword,
  list_of_port_identifiers
> {};

struct udp_output_declaration : sor<
  opt_sep_seq<
    star<attribute_instance>, 
    output_keyword, 
    port_identifier
  >,
  opt_sep_seq<
    star<attribute_instance>, 
    output_keyword, 
    reg_keyword, 
    port_identifier, 
    one<'['>,  one<'='>,  constant_expression, one<']'> 
  >
> {};

struct udp_reg_declaration : opt_sep_seq <
  star<attribute_instance>, 
  reg_keyword,
  variable_identifier
> {};

struct udp_declaration_port_list : sor<
  opt_sep_seq<
    udp_output_declaration, 
    one<';'>
  >,
  opt_sep_seq<
    udp_input_declaration, 
    one<';'>
  >,
  opt_sep_seq<
    udp_reg_declaration, 
    one<';'>
  >
> {};

struct combinational_body; //forward
struct sequential_body; //forward

struct udp_body : sor<
  combinational_body, sequential_body
> {};

// struct combinational_body :  opt_sep_seq<table_keyword, list<combinational_entry, one<','>, plus_sep> { combinational_entry } endtable_keyword>
// struct combinational_entry :  level_input_list : output_symbol ;
// struct sequential_body :  [ udp_initial_statement ] table sequential_entry { sequential_entry } endtable
// struct udp_initial_statement :  initial output_port_identifier = init_val ;
// struct init_val :  1’b0 | 1’b1 | 1’bx | 1’bX | 1’B0 | 1’B1 | 1’Bx | 1’BX | 1 | 0
// struct sequential_entry :  seq_input_list : current_state : next_state ;
// struct seq_input_list :  level_input_list | edge_input_list
// struct level_input_list :  level_symbol { level_symbol }
// struct edge_input_list :  { level_symbol } edge_indicator { level_symbol }
// struct edge_indicator :  ( level_symbol level_symbol ) | edge_symbol
// struct current_state :  level_symbol
// struct next_state :  output_symbol | -
// struct output_symbol :  0 | 1 | x | X
// struct level_symbol :  0 | 1 | x | X | ? | b | B
// struct edge_symbol :  r | R | f | F | p | P | n | N | *



struct udp_declaration : sor<
  opt_sep_seq<
    star<attribute_instance>, 
    primitive_keyword, udp_identifier, 
    one<'('>, udp_port_list, one<')'>, one<';'>,
    plus<udp_port_declaration>,
    udp_body,
    endprimitive_keyword
  >,
  opt_sep_seq<
    star<attribute_instance>, 
    primitive_keyword, udp_identifier, 
    one<'('>, udp_declaration_port_list, one<')'>, one<';'>,
    udp_body,
    endprimitive_keyword
  >
> {};




struct name_of_udp_instance : seq<
  udp_instance_identifier, 
  opt< bus_range >
> {};

struct udp_instance : seq<
  opt< name_of_udp_instance >, 
  one<'('>, 
  output_terminal, 
  one<','>, 
  input_terminal, 
  star< 
    one<','>, 
    input_terminal 
  >, 
  one<')'>
> {};

struct udp_instantiation : seq<
  udp_identifier, 
  // opt< drive_strength >, 
  opt< delay2 >, 
  udp_instance,
  star< 
    one<','>, 
    udp_instance 
  >, 
  one<';'>
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_UPD_HPP
