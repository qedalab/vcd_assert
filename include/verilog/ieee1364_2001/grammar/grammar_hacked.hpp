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
#include "./commands.hpp"
#include "./keywords.hpp"
#include "./module.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

struct sdf_annotate_task;

// struct begin_end_pairs : plus<
//   opt<sps>,
//   tao::pegtl::list<begin_end_pair,opt<sps>>
// > {};

struct include_statement : seq< 
  include_keyword,
  seq<
    plus_blank,
    one<'"'>, 
    file_path_spec,
    one<'"'>
  >
> {};

struct compiler_directive : seq<
  one<'`'>, //one<'‘'>,
  sor<
    include_statement, until<eol>
  >
> {};


// struct fake_bus_range : seq<
//   one<'['>,
//   until<one<']'>>
// > {};

// struct name_of_instance : seq < 
//   module_instance_identifier, 
//   opt<fake_bus_range>
// > {};

// struct module_instance : seq<
//   name_of_instance, opt<plus_sep>, seq<one<'('>, /*opt<list_of_port_connections>,*/ until<one<')'>>>
// > {};

// struct module_instantiation : seq<
//   opt< parameter_value_assignment> 
//   module_identifier,
//   plus_blank,
//   list<module_instance, one<','>, plus_sep>,
//   // opt< list<module_instance, one<','> > >,
//   opt<plus_sep>,
//   one<';'>
// > {};

// struct at_least_blank_separator : seq<
//   opt<plus_sep>,  
//   plus_blank,
//   opt<plus_sep>
// > {};



// struct module_declaration : if_must<
//   module_keyword,
//   plus_blank,
//   module_identifier,
//   until<one<';'>>,
//   opt<plus_sep>,
//   star<
//     tao::pegtl::until<
//       sor<
//         initial_block,
//         module_instantiation
//       >//,
//       // seq<not_at<initial_block, module_instantiation>, tao::pegtl::any>
//     >
//   >,
//   // until<endmodule_keyword>
//   tao::pegtl::until<
//     endmodule_keyword, 
//     must<
//       not_at<endmodule_keyword>, 
//       tao::pegtl::any>
//     >
// > {};

struct module_description : sor<
  module_declaration //,
  // udp_declaration
> {};

struct grammar : must<
  star<
    sor<plus_sep, module_description, compiler_directive>
  >
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_GRAMMAR_HPP
