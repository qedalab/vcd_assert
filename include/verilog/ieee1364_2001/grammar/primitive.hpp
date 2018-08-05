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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_PRIMITIVES_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_PRIMITIVES_HPP

#include "./base.hpp"
#include "./data.hpp"
#include "./expressions.hpp"
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

// FOR UDP SEE upd.hpp

/* A.3.3 Primitive terminals */
struct enable_terminal : alias<expression> {};
struct inout_terminal : alias<net_lvalue> {};
struct input_terminal : alias<expression> {};
struct ncontrol_terminal : alias<expression> {};
struct output_terminal : alias<net_lvalue> {};
struct pcontrol_terminal : alias<expression> {};

/* A.3.4 Primitive gate and switch types */
struct cmos_switchtype : sor<
  cmos_keyword, 
  rcmos_keyword 
> {};
struct enable_gatetype : sor<
  bufif0_keyword, 
  bufif1_keyword,
  notif0_keyword, 
  notif1_keyword 
> {};
struct mos_switchtype : sor<
  nmos_keyword, 
  pmos_keyword,
  rnmos_keyword, 
  rpmos_keyword 
> {};
struct n_input_gatetype : sor<
  and_keyword, 
  nand_keyword,
  or_keyword, 
  nor_keyword, 
  xor_keyword, 
  xnor_keyword 
> {};
struct n_output_gatetype : sor<
  buf_keyword, 
  not_keyword 
> {};
struct pass_en_switchtype : sor<
  tranif0_keyword, 
  tranif1_keyword,
  rtranif1_keyword, 
  rtranif0_keyword 
> {};
struct pass_switchtype : sor<
  tran_keyword, 
  rtran_keyword 
> {};

struct name_of_gate_instance; //forward;

struct cmos_switch_instance : opt_sep_seq<
  opt<name_of_gate_instance>,
  one<'('>, 
  output_terminal,
  input_terminal,
  ncontrol_terminal,
  pcontrol_terminal, 
  one<')'>
> {};

struct enable_gate_instance : opt_sep_seq<
  opt<name_of_gate_instance>,
  one<'('>, 
  output_terminal,
  input_terminal,
  enable_terminal, 
  one<')'>
> {};

struct mos_switch_instance : opt_sep_seq<
  opt<name_of_gate_instance>, 
  one<'('>, 
  output_terminal,
  input_terminal,
  enable_terminal, 
  one<')'>
> {};

struct n_input_gate_instance : opt_sep_seq<
  opt<name_of_gate_instance>, 
  one<'('>, 
  output_terminal,
  list<
    input_terminal, 
    one<','>, 
    plus_sep
  >,
  one<')'>
> {};

struct n_output_gate_instance : opt_sep_seq<
  opt<name_of_gate_instance>, 
  one<'('>, 
  list<
    output_terminal, 
    one<','>, 
    plus_sep
  >, 
  input_terminal, 
  one<')'>
> {};

struct pass_switch_instance : opt_sep_seq<
  opt<name_of_gate_instance>, 
  one<'('>, 
  inout_terminal,
  inout_terminal, 
  one<')'>
> {};

struct pass_enable_switch_instance : opt_sep_seq<
  opt<name_of_gate_instance>, 
  one<'('>, 
  inout_terminal, 
  inout_terminal, 
  enable_terminal, 
  one<')'>
> {};

struct pull_gate_instance : opt_sep_seq<
  opt<name_of_gate_instance>, 
  one<'('>, 
  output_terminal, 
  one<')'>
> {};

struct name_of_gate_instance : opt_sep_seq<
  gate_instance_identifier, 
  opt< range >
> {};

struct gate_instantiation : sor<
  opt_sep_seq<
    cmos_switchtype, 
    opt<delay3>, 
    list< 
      cmos_switch_instance, one<','>, plus_sep
    >, 
    one<';'>
  >,
  opt_sep_seq<
    enable_gatetype, 
    opt<drive_strength>, 
    opt<delay3>, 
    list< 
      enable_gate_instance, one<','>, plus_sep
    >, 
    one<';'>
  >,
  opt_sep_seq<
    mos_switchtype, 
    opt<delay3>, 
    list< 
      mos_switch_instance, one<','>, plus_sep
    >, 
    one<';'>
  >,
  opt_sep_seq<
    n_input_gatetype, 
    opt<drive_strength>, 
    opt<delay2>, 
    list< 
      n_input_gate_instance, one<','>, plus_sep>, 
    one<';'>
  >,
  opt_sep_seq<
    n_output_gatetype, 
    opt<drive_strength>, 
    opt<delay2>, 
    list< 
      n_output_gate_instance, one<','>, plus_sep>, 
    one<';'>
  >,
  opt_sep_seq<
    pass_en_switchtype, 
    opt<delay2>, 
    list< 
      pass_enable_switch_instance, one<','>, plus_sep>, 
    one<';'>
  >,
  opt_sep_seq<
    pass_switchtype, 
    list< 
      pass_switch_instance, one<','>, plus_sep>, 
    one<';'>
  >//,
  // opt_sep_seq<
  //   pulldown_keyword, 
  //   opt<pulldown_strength>, 
  //   list< 
  //     pull_gate_instance, one<','>, plus_sep>, 
  //   one<';'>
  // >,
  // opt_sep_seq<
  //   pullup_keyword, 
  //   opt<pullup_strength>, 
  //   list< 
  //     pull_gate_instance, one<','>, plus_sep>, 
  //   one<';'>
  // >
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_PRIMITIVES_HPP
