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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_PORTS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_PORTS_HPP

#include "./base.hpp"
#include "./data.hpp"
#include "./keywords.hpp"
//#include "./separator.hpp"
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
struct list_of_variable_port_identifiers;

struct list_of_ports : if_must<
  one<'('>, 
  list<
    seq<opt<plus_sep>, port, opt<plus_sep>>,
    one<','>
  >, 
  opt<plus_sep>,
  one<')'>
> {};

struct list_of_port_declarations : if_must<
  one<'('>, 
  list<
    seq<opt<plus_sep>, port_declaration, opt<plus_sep>>,
    one<','>
  >,  
  opt<plus_sep>,
  one<')'>
> {};

struct list_of_port_identifiers : list< 
  port_identifier, one<','>, plus_sep   
> {};

struct list_of_variable_port_identifiers : list< 
  opt_sep_seq< port_identifier, opt<one<'='>, constant_expression> >,
  one<','>,
  plus_sep
> {};

struct port : sor<
  port_expression,  //ASSUMPTION (assume not optional)
  seq<one<'.'>, port_identifier>, one<'('>, opt<port_expression>, one<')'>
> {};

struct port_expression : sor<
  port_reference, 
  list<seq<port_reference, opt<plus_sep>>,one<','>> 
> {};

struct port_reference : sor<
  port_identifier, 
  opt_sep_seq< 
    port_identifier, one<'['>, constant_expression, one<']'>
  >, 
  opt_sep_seq< 
    port_identifier, one<'['>, range_expression, one<']'>
  >
> {};

struct port_declaration : sor<
  opt_sep_seq<list<attribute_instance, plus_blank>, inout_declaration>, 
  opt_sep_seq<list<attribute_instance, plus_blank>, input_declaration>, 
  opt_sep_seq<list<attribute_instance, plus_blank>, output_declaration>
> {};

struct inout_declaration : opt_sep_seq<
  inout_keyword, 
  opt<net_type>, 
  opt<signed_keyword>, 
  opt<bus_range>, 
  list_of_port_identifiers
> {};

struct input_declaration : opt_sep_seq<
  input_keyword,
  opt<net_type>,
  opt<signed_keyword>,
  opt<bus_range>,
  list_of_port_identifiers
> {};

struct output_declaration : sor<
  opt_sep_seq< 
    output_keyword,
    opt<net_type>,
    opt<signed_keyword>,
    opt<bus_range>,
    list_of_port_identifiers
  >,
  opt_sep_seq< 
    output_keyword,
    opt<reg_keyword>,
    opt<signed_keyword>,
    opt<bus_range>,
    list_of_port_identifiers
  >,
  opt_sep_seq< 
    output_keyword,
    reg_keyword,
    opt<signed_keyword>,
    opt<bus_range>,
    list_of_variable_port_identifiers
  >,
  opt_sep_seq< 
    output_keyword,
    opt<output_variable_type>,
    list_of_port_identifiers
  >,
  opt_sep_seq< 
    output_keyword,
    output_variable_type,
    list_of_variable_port_identifiers
  >
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_PORTS_HPP
