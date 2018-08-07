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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_STATEMENTS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_STATEMENTS_HPP

#include "./assignments.hpp"
#include "./base.hpp"
#include "./block_item.hpp"
#include "./data.hpp"
#include "./delay.hpp"
#include "./expressions.hpp"
#include "./identifiers.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct statement;
struct net_lvalue;

struct variable_assignment : opt_sep_seq< 
  variable_lvalue, one<'='>, expression
> {};

struct net_assignment : opt_sep_seq<
  net_lvalue, one<'='>, expression
> {};

struct list_of_net_assignments : list<net_assignment, one<','>, plus_sep> {};

struct continuous_assign : opt_sep_seq<
  assign_keyword, opt< drive_strength >, opt< delay3 >, list_of_net_assignments, one<';'>
> {};

struct net_decl_assignment : opt_sep_seq<
  net_identifier, one<'='>, expression
> {};

template<class S>
struct loop : sor<
  opt_sep_seq<
    forever_keyword, 
    blank, 
    S
  >,
  opt_sep_seq<
    repeat_keyword, 
    blank, 
    one<'('>, 
    expression, 
    one<')'>, 
    S
  >,
  opt_sep_seq<
    while_keyword, 
    blank, 
    one<'('>, 
    expression, 
    one<')'>, 
    S
  >,
  opt_sep_seq<
    for_keyword, 
    blank, 
    one<'('>, 
    variable_assignment, 
    one<';'>, 
    expression, 
    one<';'>, 
    variable_assignment, 
    one<')'>, 
    blank, 
    blank, 
    S
>
> {};


template<class S = statement>
struct statement_or_null : sor<  
  seq<star<attribute_instance>, one<';'>>,
  S
> {};

template<class S = statement>
struct if_else_if_statement : seq<
  opt_sep_seq< 
    if_keyword, plus_blank, one<'('>, expression, one<')'>, statement_or_null<S>
  >,
  star<
    opt_sep_seq<
      else_keyword, 
      plus_blank, 
      if_keyword, 
      plus_blank, 
      one<'('>, expression, one<')'>, 
      statement_or_null<S>
    >
  >,
  opt< else_keyword, opt<plus_sep>, statement_or_null<S> >
> {};

struct case_item : sor<
  opt_sep_seq< list<expression, one<','>, plus_sep>, one<':'>, statement_or_null<> >,
  opt_sep_seq< default_keyword, opt<one<':'>>, statement_or_null<> >
> {};

struct case_statement : opt_sep_seq<
  sor< case_keyword, casez_keyword, casex_keyword >,
  one<'('>, expression, one<')'>,
  plus<case_item>,
  endcase_keyword
> {};

struct conditional_statement : sor < 
  opt_sep_seq< 
    if_keyword, 
    plus_blank,
    one<'('>, 
    expression, 
    one<')'>, 
    statement_or_null<>, 
    opt< 
      opt_sep_seq<
        else_keyword, 
        blank,
        statement_or_null<> 
      >
    >
  >,
  if_else_if_statement<>
> {};

struct event_control : if_must<
  one<'@'>, 
  sor<
    event_identifier,
    opt_sep_seq<one<'('>, event_expression, one<')'>>,
    opt_sep_seq<one<'*'>>, 
    opt_sep_seq<one<'('>, one<'*'>, one<')'>>
  >
> {};

struct delay_control : if_must< 
  one<'#'>, 
  sor<
    seq<one<'('>, opt<plus_blank>, mintypmax<expression>, opt<plus_blank>,  one<')'>>,
    delay_value
  >
> {};

struct delay_or_event_control : sor<
  delay_control,
  event_control,
  opt_sep_seq<
    repeat_keyword, 
    one<'('>, expression, one<')'>, 
    event_control
  >
> {};

struct blocking_assignment : opt_sep_if_must<
  opt_sep_seq<variable_lvalue, one<'='>, opt<delay_or_event_control>>, expression
> {};


struct function_statement; //forward

struct function_blocking_assignment : opt_sep_seq< 
  variable_lvalue, one<'='>, expression
> {};
struct function_statement_or_null : statement_or_null<function_statement> {};

struct function_case_item : sor<
  opt_sep_seq<
    list<expression, one<','>, plus_sep>, one<':'>, function_statement_or_null
  >,
  opt_sep_seq<
   default_keyword, opt<one<':'>>, function_statement_or_null
  >
> {};

struct function_case_statement : opt_sep_seq<
  sor<
    case_keyword, casez_keyword, casex_keyword
  >, 
  one<'('>, expression, one<')'>, 
  list<function_case_item, plus_blank>, 
  endcase_keyword
> {};

struct function_if_else_if_statement : if_else_if_statement<function_statement> {};

struct function_conditional_statement : sor<
  opt_sep_seq<
    if_keyword, 
    one<'('>, expression, one<')'>, 
    function_statement_or_null,
    opt< 
      opt_sep_seq< 
        else_keyword, 
        blank,
        function_statement_or_null
      >
    >
  >,
  function_if_else_if_statement
> {};

struct function_loop_statement : loop<function_statement> {};

struct function_seq_block : seq< 
  begin_keyword, 
  opt_sep_seq< 
    opt< one<':'>, block_identifier, star<block_item_declaration> >, 
    star<function_statement> 
  >, 
  end_keyword
> {};

struct system_task_enable; //forward
struct disable_statement; //forward

struct function_statement : seq<
  star<attribute_instance>, 
  sor<
    seq<function_blocking_assignment, opt<plus_sep>, one<';'>>,
    function_case_statement,
    function_conditional_statement,
    function_loop_statement,
    function_seq_block,
    disable_statement,
    system_task_enable
  >
> {};

struct disable_statement : sor<
  disable_keyword, hierarchical_task_identifier, one<';'>,
  disable_keyword, hierarchical_block_identifier, one<';'>
> {};

struct event_trigger : seq< 
  one<'-'>, 
  one<'>'>, 
  plus_blank, 
  hierarchical_event_identifier, 
  plus_blank, 
  one<';'> 
> {};

struct loop_statement : loop<statement> {};

struct nonblocking_assignment : seq<
  variable_lvalue, 
  one<'<'>, 
  one<'='>, 
  plus_blank, 
  opt<delay_or_event_control>, 
  plus_blank, 
  expression 
> {};
struct par_block : seq<
  fork_keyword, 
  opt< 
    one<':'>, 
    block_identifier, 
    star< block_item_declaration > 
  >, 
  star<statement>, 
  join_keyword
> {};

struct procedural_continuous_assignments : sor<
  sep_seq<assign_keyword, variable_assignment>, 
  sep_seq<deassign_keyword, variable_lvalue>, 
  sep_seq<force_keyword, sor<variable_assignment, net_assignment>>,
  sep_seq<release_keyword, sor<variable_assignment, net_assignment>>
> {};

struct procedural_timing_control_statement : seq<
  delay_or_event_control, 
  plus_sep, 
  statement_or_null<>
> {};


struct seq_block : sep_seq<
  begin_keyword, 
  opt< 
    one<':'>, 
    block_identifier
  >, 
  star<block_item_declaration>,
  // opt<list<statement, blank, plus_sep>>,
  star<statement>,
  end_keyword
> {};

struct system_task_enable : seq<
  system_task_identifier, 
  opt< 
    opt<plus_blank>,
    one<'('>, 
    list<expression, one<','>, plus_sep>, one<')'> 
  >, 
  opt<plus_blank>,
  one<';'>
> {};

struct task_enable : seq< 
  hierarchical_task_identifier, 
  opt< 
    one<'('>, 
    list<expression, one<','>, plus_sep>,  
    one<')'> 
  >, 
  one<';'> 
> {};

struct wait_statement : seq< 
  wait_keyword, 
  one<'('>, expression, one<')'>, 
  statement_or_null<> 
> {};

struct statement : must<
  star<attribute_instance>,
  sor<
    case_statement,
    if_must<blocking_assignment, opt<plus_sep>, one<';'>>,
    conditional_statement,
    disable_statement,
    event_trigger,
    loop_statement,
    if_must<nonblocking_assignment, opt<plus_sep>, one<';'>>,
    par_block,
    if_must<procedural_continuous_assignments, opt<plus_sep>, one<';'>>,
    procedural_timing_control_statement,
    seq_block,
    system_task_enable,
    task_enable,
    wait_statement
  >
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_STATEMENTS_HPP
