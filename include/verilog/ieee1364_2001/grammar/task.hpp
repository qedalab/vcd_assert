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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_TASK_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_TASK_HPP

#include "./base.hpp"
#include "./block_item.hpp"
#include "./keywords.hpp"
#include "./ports.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct task_port_list; //forward;
struct task_item_declaration; //forward;
struct task_port_type; //forward;
struct block_item_declaration; //forward;

/* (From Annex A - A.2.7) */
struct task_declaration : sor<
  opt_sep_seq<
    task_keyword, opt<automatic_keyword>, opt_sep_seq<task_port_list, one<';'>>,  
    star<task_item_declaration>,
    statement,
    endtask_keyword
  >,
    sep_seq<
    task_keyword, opt<automatic_keyword>, opt_sep_seq<one<'('>, task_port_list, one<')'>, one<';'>>,  
    star<block_item_declaration>,
    statement,
    endtask_keyword
  >
> {};

struct task_port_item; //farward
struct task_item_declaration : sor<
  block_item_declaration,
  task_port_item
> {};

struct task_port_list : list< task_port_item, one<','>, plus_sep > {};

struct tf_port_declaration : sor< 
  opt_sep_seq<
    opt<reg_keyword>, 
    opt<signed_keyword>, 
    opt<range>, 
    list_of_port_identifiers
  >,
  opt_sep_seq<
    opt<task_port_type>,
    list_of_port_identifiers
  >
> {};

struct tf_input_declaration : opt_sep_seq<
  input_keyword, plus_sep, tf_port_declaration
> {};

struct tf_output_declaration : opt_sep_seq<
  output_keyword, plus_sep, tf_port_declaration
> {};

struct tf_inout_declaration : opt_sep_seq<
  inout_keyword, plus_sep, tf_port_declaration
> {};

struct task_port_item : seq<
  star<attribute_instance>, 
  sor<
    tf_input_declaration,
    tf_output_declaration,
    tf_inout_declaration
  >,
  one<';'>
> {};

struct task_port_type : sor<
  time_keyword, 
  real_keyword, 
  realtime_keyword, 
  integer_keyword
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_TASK_HPP
