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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_KEYWORDS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_KEYWORDS_HPP

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

// struct module_str : sor<
//    TAO_PEGTL_STRING("module"),
//    TAO_PEGTL_STRING("macromodule")
// > {}; 

// misc

struct module_str         : TAO_PEGTL_STRING("module"){};
struct endmodule_str      : TAO_PEGTL_STRING("endmodule"){};
struct endprimitive_str   : TAO_PEGTL_STRING("endprimitive"){};
struct inout_str          : TAO_PEGTL_STRING("inout"){};
struct input_str          : TAO_PEGTL_STRING("input"){};
struct integer_str        : TAO_PEGTL_STRING("integer"){};
struct include_str        : TAO_PEGTL_STRING("include"){};
struct output_str         : TAO_PEGTL_STRING("output"){};
struct parameter_str      : TAO_PEGTL_STRING("parameter"){};
struct primitive_str      : TAO_PEGTL_STRING("primitive"){};
struct real_str           : TAO_PEGTL_STRING("real"){};
struct realtime_str       : TAO_PEGTL_STRING("realtime"){};
struct reg_str            : TAO_PEGTL_STRING("reg"){};
struct signed_str         : TAO_PEGTL_STRING("signed"){};
struct time_str           : TAO_PEGTL_STRING("time"){};

struct begin_str          : TAO_PEGTL_STRING("begin"){};
struct end_str            : TAO_PEGTL_STRING("end"){};
struct always_str         : TAO_PEGTL_STRING("always"){};
struct initial_str        : TAO_PEGTL_STRING("initial"){};

struct net_str            : TAO_PEGTL_STRING("net"){};
struct event_str          : TAO_PEGTL_STRING("event"){};
struct genvar_str         : TAO_PEGTL_STRING("genvar"){};
struct task_str           : TAO_PEGTL_STRING("task"){};
struct function_str       : TAO_PEGTL_STRING("function"){};

struct sdf_annotate_str   : TAO_PEGTL_STRING("sdf_annotate"){}; 

// net types
struct supply0_str        : TAO_PEGTL_STRING("supply0"){};
struct supply1_str        : TAO_PEGTL_STRING("supply1"){};
struct tri_str            : TAO_PEGTL_STRING("tri"){};
struct triand_str         : TAO_PEGTL_STRING("triand"){};
struct trior_str          : TAO_PEGTL_STRING("trior"){};
struct tri0_str           : TAO_PEGTL_STRING("tri0"){};
struct tri1_str           : TAO_PEGTL_STRING("tri1"){};
struct wire_str           : TAO_PEGTL_STRING("wire"){};
struct wand_str           : TAO_PEGTL_STRING("wand"){};
struct wor_str            : TAO_PEGTL_STRING("wor"){};

struct keyword_str: sor< 
  module_str,
  endmodule_str,
  endprimitive_str,
  inout_str,
  input_str,
  integer_str,
  include_str,
  output_str,
  parameter_str,
  primitive_str,
  real_str,
  realtime_str,
  reg_str,
  signed_str,
  time_str,
  begin_str,
  end_str,
  always_str,
  initial_str,
  net_str,
  event_str,
  genvar_str,
  task_str,
  function_str,
  sdf_annotate_str,
  supply0_str,
  supply1_str,
  tri_str,
  triand_str,
  trior_str,
  tri0_str,
  tri1_str,
  wire_str,
  wand_str,
  wor_str
> {};


template< typename Key >
struct key : seq< Key, not_at< character > > {};

struct module_keyword : key < module_str >{};
struct endmodule_keyword : key < endmodule_str >{};
struct endprimitive_keyword : key < endprimitive_str >{};
struct inout_keyword : key < inout_str >{};
struct input_keyword : key < input_str >{};
struct integer_keyword : key < integer_str >{};
struct include_keyword : key < include_str >{};
struct output_keyword : key < output_str >{};
struct parameter_keyword : key < parameter_str >{};
struct primitive_keyword : key < primitive_str >{};
struct real_keyword : key < real_str >{};
struct realtime_keyword : key < realtime_str >{};
struct reg_keyword : key < reg_str >{};
struct signed_keyword : key < signed_str >{};
struct time_keyword : key < time_str >{};
struct begin_keyword : key < begin_str >{};
struct end_keyword : key < end_str >{};
struct always_keyword : key < always_str >{};
struct initial_keyword : key < initial_str >{};
struct net_keyword : key < net_str >{};
struct event_keyword : key < event_str >{};
struct genvar_keyword : key < genvar_str >{};
struct task_keyword : key < task_str >{};
struct function_keyword : key < function_str >{};
struct sdf_annotate_keyword : key < sdf_annotate_str >{};
struct supply0_keyword : key < supply0_str >{};
struct supply1_keyword : key < supply1_str >{};
struct tri_keyword : key < tri_str >{};
struct triand_keyword : key < triand_str >{};
struct trior_keyword : key < trior_str >{};
struct tri0_keyword : key < tri0_str >{};
struct tri1_keyword : key < tri1_str >{};
struct wire_keyword : key < wire_str >{};
struct wand_keyword : key < wand_str >{};
struct wor_keyword : key < wor_str >{};


struct keyword : key< keyword_str >{}; 

// struct keyword : key< str_keyword > {};


// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_KEYWORDS_HPP
