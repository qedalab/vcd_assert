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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_GRAMMAR_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_GRAMMAR_HPP

// #include <verilog/ieeel1364_2005/grammar/source_text.hpp>
// #include "./source_text.hpp"
// #include "./attribute.hpp"
#include "./base.hpp"
#include "./keywords.hpp"
#include "./commands.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

struct sdf_annotate_task;

struct ignored;
struct ignored_content : 
  sor<
    qstring,
    plus<character>,
    plus_blank,
    // hierarchical_identifier,
    special_character_without_brackets,
    ignored
> {};

struct ignored : seq<
  star<ignored_content>
> {};

struct op_sep_ignored : plus<
  opt<sps>,
  tao::pegtl::list<ignored,opt<sps>>
> {};

struct unimplemented : if_must<
  open,
  star<ignored>,
  star<ignored_content>,
  star<ignored>,
  until<close>
> {};

struct unimplemented_brackets : if_must<
  seq<open>,
  star<bracket_contents>,
  star<bracket_pairs>,
  star<bracket_contents>,
  until<close>
> {};

struct begin_end_pair;
// struct begin_end_pairs;

struct begin_end_contents : 
  sor<
    qstring,
    separator,
    one<'`'>,
    plus<special_character>,
    // seq<blank,any_character,blank>,
    plus<not_at<sor<begin_keyword,end_keyword>>, any_character>,
    // hierarchical_identifier,
    begin_end_pair
> {};

struct begin_end_pair : if_must<
  begin_keyword,
  star<begin_end_contents>,
  end_keyword
> {};

// struct begin_end_pairs : plus<
//   opt<sps>,
//   tao::pegtl::list<begin_end_pair,opt<sps>>
// > {};

struct unimplemented_begin_end : if_must<
  begin_keyword,
  star<begin_end_contents>,
  // star<begin_end_pairs>,
  // star<begin_end_contents>,
  until<end_keyword>
> {};

// struct _module_item_ : sor<
//   op_sep_ignored,
//   until<eol>
// > {};



struct include_statement : seq< 
  include_keyword,
  seq<
    plus_blank,
    one<'"'>, 
    file_path_spec,
    one<'"'>
  >
>{};


struct compiler_directive : seq<
  one<'`'>, //one<'‘'>,
  sor<
    include_statement
  >
> {};


// struct net_declaration : seq<
//   net_keyword,
//   until<one<';'>>
// >{};
// struct reg_declaration : seq<
//   reg_keyword,
//   until<one<';'>>
// >{};
// struct integer_declaration : seq<
//   integer_keyword,
//   until<one<';'>>
// >{};
// struct real_declaration : seq<
//   real_keyword,
//   until<one<';'>>
// >{};
// struct time_declaration : seq<
//   time_keyword,
//   until<one<';'>>
// >{};
// struct realtime_declaration : seq<
//   realtime_keyword,
//   until<one<';'>>
// >{};
// struct event_declaration : seq<
//   event_keyword,
//   until<one<';'>>
// >{};
// struct genvar_declaration : seq<
//   genvar_keyword,
//   until<one<';'>>
// >{};
// struct task_declaration : seq<
//   task_keyword,
//   until<one<';'>>
// >{};
// struct function_declaration : seq<
//   function_keyword,
//   until<one<';'>>
// >{};

// struct module_or_generate_item_declaration : sor< 
//   net_declaration,
//   reg_declaration,
//   integer_declaration,
//   real_declaration,
//   time_declaration,
//   realtime_declaration,
//   event_declaration,
//   genvar_declaration,
//   task_declaration,
//   function_declaration
// > {};

struct module_instance_identifier : alias<identifier>{};

struct fake_bus_range : seq<
  one<'['>,
  until<one<']'>>
>{};

struct name_of_instance : seq < 
  module_instance_identifier, 
  opt<fake_bus_range>
>{};

struct module_instance : seq<
  name_of_instance, opt<separator>, seq<one<'('>, /*opt<list_of_port_connections>,*/ until<one<')'>>>
>{};

struct module_identifier : alias<identifier> {};

struct module_instantiation : seq<
  // opt< parameter_value_assignment> 
  module_identifier,
  plus_blank,
  list<module_instance, one<','>, separator>,
  // opt< list<module_instance, one<','> > >,
  opt<separator>,
  one<';'>
> {};

struct at_least_blank_separator : seq<
  opt<separator>,  
  plus_blank,
  opt<separator>
>{};

struct initial_block : seq < //causes parse errors when if_must
  initial_keyword,
  // at_least_blank_separator,
  separator,
  begin_keyword,
  star<
    until<
      sor<
        sdf_annotate_task,
        unimplemented_begin_end
      >
    >
  >,
  until<end_keyword>
> {};

struct _module_declaration_ : if_must<
  module_keyword,
  plus_blank,
  module_identifier,
  until<one<';'>>,
  opt<separator>,
  star<
    until<
      sor<
        initial_block,
        module_instantiation
      >
    >
  >,
  until<endmodule_keyword>
> {};

struct _module_description_ : sor<
  _module_declaration_ //,
  // udp_declaration
> {};

struct _grammar_ : must<
  opt<separator>,
  opt<list<
    until<
      sor<compiler_directive,_module_description_>
    >,
    opt<separator>
  >>,
  opt<separator>
  
  // opt<eof>
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_GRAMMAR_HPP
