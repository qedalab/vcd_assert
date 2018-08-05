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

// todo move all identifiers here.

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_IDENTIFIERS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_IDENTIFIERS_HPP

#include "./base.hpp"
#include "./data.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

struct bus_range; //forward

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct text_macro_identifier : alias<simple_identifier> {};

struct block_identifier : alias<identifier> {};
struct cell_identifier : alias<identifier> {};
struct config_identifier : alias<identifier> {};
struct event_identifier : alias<identifier> {};
struct function_identifier : alias<identifier> {};
struct generate_block_identifier : alias<identifier> {};
struct genvar_function_identifier : alias<identifier> {}; /* Hierarchy disallowed */
struct genvar_identifier : alias<identifier> {};
struct inout_port_identifier : alias<identifier> {};
struct input_port_identifier : alias<identifier> {};
struct instance_identifier : alias<identifier> {};
struct library_identifier : alias<identifier> {};
struct memory_identifier : alias<identifier> {};
struct module_identifier : alias<identifier> {};
struct net_identifier : alias<identifier> {};
struct output_port_identifier : alias<identifier> {};
struct parameter_identifier : alias<identifier> {};
struct port_identifier : alias<identifier> {};
struct real_identifier : alias<identifier> {};
struct specparam_identifier : alias<identifier> {};
struct task_identifier : alias<identifier> {};
struct terminal_identifier : alias<identifier> {};
struct topmodule_identifier : alias<identifier> {};
struct udp_identifier : alias<identifier> {};
struct variable_identifier : alias<identifier> {};

struct escaped_arrayed_identifier : seq<
  escaped_identifier, opt<plus_blank>, opt<bus_range>
> {};
struct simple_arrayed_identifier : seq<
  simple_identifier, opt<plus_blank>, opt<bus_range>
> {};

/*BROKEN CONSEPT, not present in SV2017*/
struct arrayed_identifier : sor< 
  simple_arrayed_identifier,
  escaped_arrayed_identifier
> {};

struct gate_instance_identifier : alias< arrayed_identifier > {};
struct udp_instance_identifier : alias< arrayed_identifier > {};
struct module_instance_identifier : alias<arrayed_identifier> {};

struct system_task_identifier : alias<s_identifier> {};
struct system_function_identifier : alias<s_identifier> {};

struct simple_hierarchical_branch : list<
  seq<
    simple_identifier, 
    opt<plus_blank>,
    opt< 
      one<'['>, 
      opt<plus_blank>,
      unsigned_number, 
      opt<plus_blank>, 
      one<']'> 
    >
  >,
  one<'.'>
> {};

struct escaped_hierarchical_branch : list<
  seq<
    escaped_identifier, 
    opt<plus_blank>,
    opt< 
      one<'['>, 
      opt<plus_blank>,
      unsigned_number, 
      opt<plus_blank>, 
      one<']'> 
    >
  >,
  one<'.'>
> {};

struct escaped_hierarchical_identifier : seq<
  escaped_hierarchical_branch, 
  star< 
    one<'.'>, sor< simple_hierarchical_branch, escaped_hierarchical_branch >
  > 
> {};

struct simple_hierarchical_identifier: seq<
  simple_hierarchical_branch, 
  star< one<'.'>, escaped_identifier >
> {};

/* hierarchical_identifier is found in base.hpp */
struct hierarchical_block_identifier : alias< hierarchical_identifier > {};
struct hierarchical_event_identifier : alias< hierarchical_identifier > {};
struct hierarchical_function_identifier : alias< hierarchical_identifier > {};
struct hierarchical_net_identifier : alias< hierarchical_identifier > {};
struct hierarchical_variable_identifier : alias< hierarchical_identifier > {};
struct hierarchical_task_identifier : alias< hierarchical_identifier > {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_IDENTIFIERS_HPP
