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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_FUNCTION_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_FUNCTION_HPP

#include "./base.hpp"
#include "./statements.hpp"
#include "./task.hpp"
// #include "./data.hpp"
// #include "./keywords.hpp"
// #include "./numbers.hpp"
// //#include "./separator.hpp"
#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;


struct function_item_declaration : sor<
  block_item_declaration, 
  opt_sep_seq<tf_input_declaration, one<';'>>
> {};

struct function_port_list : opt_sep_seq<
  star<attribute_instance>,
  tf_input_declaration,
  list<
    opt_sep_seq<
      attribute_instance, 
      tf_input_declaration
    >,
    one<','>,
    plus_sep
  >
> {};

// struct callable_declaration_w_ports
// struct callable_declaration_wo_ports

struct function_declaration : sor<
  opt_sep_seq<
    function_keyword, 
    opt<automatic_keyword, plus_sep>, 
    opt<signed_keyword, plus_sep>, 
    opt<
      sor<
        range, 
        integer_keyword, 
        real_keyword, 
        realtime_keyword, 
        time_keyword
      >, 
      plus_sep
    >, 
    opt_sep_seq<function_port_list, one<';'>>,  
    star<function_item_declaration>,
    statement,
    endfunction_keyword
  >,
  opt_sep_seq<
    function_keyword, 
    opt<automatic_keyword, plus_sep>, 
    opt<signed_keyword, plus_sep>, 
    opt<
      sor<
        range, 
        integer_keyword, 
        real_keyword, 
        realtime_keyword, 
        time_keyword
      >, 
      plus_sep
    >, 
    opt_sep_seq<one<'('>, function_port_list, one<')'>, one<';'>>,
    star<block_item_declaration>,
    statement,
    endfunction_keyword
  >
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_FUNCTION_HPP
