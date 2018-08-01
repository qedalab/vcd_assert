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

// #ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_MODULE_HPP
// #define LIBVERILOG_IEEE1364_2001_GRAMMAR_MODULE_HPP

// #include "./attribute.hpp"
// #include "./base.hpp"
// #include "./block.hpp"
// #include "./data.hpp"
// #include "./keywords.hpp"
// #include "./ports.hpp"
// #include "./separator.hpp"

// #include <parse/grammar/base.h>
// #include <parse/grammar/part.h>

// namespace Verilog {
// namespace IEEE1364_2001 {
// namespace Grammar {
// // clang-format off

// using namespace Parse::Grammar::Base;
// using namespace Parse::Grammar::Part;
 
// struct param_identifier : alias<identifier> {};

// struct param_assignment : op_sep_seq<
//  param_identifier, one<'='>, constant_expression
// > {};

// struct list_of_param_assignments : list<
//   seq<param_assignment, opt<separator>>, one<','> 
// > {};

// struct parameter_declaration : sor<
//   op_sep_seq<
//     parameter_keyword, 
//     one<'['>, signed_keyword, one<']'>, 
//     one<'['>, range, one<']'>, 
//     list_of_param_assignments
//   >,
//   op_sep_seq<
//     parameter_keyword, 
//     integer_keyword,
//     list_of_param_assignments
//   >,
//   op_sep_seq<
//     parameter_keyword, 
//     real_keyword,
//     list_of_param_assignments
//   >,
//   op_sep_seq<
//     parameter_keyword, 
//     realtime_keyword,
//     list_of_param_assignments
//   >,
//   op_sep_seq<
//     parameter_keyword, 
//     time_keyword,
//     list_of_param_assignments
//   >
// > {};

// /*# ( parameter_declaration { , parameter_declaration } )*/
// struct module_parameter_port_list : op_sep_seq<
//   seq<one<'#'>, one<'('>>,
//   list< 
//     seq<
//       parameter_declaration, 
//       opt<separator>
//     >, 
//     one<','>
//   >,
//   one<')'>
// > {};

// struct module_identifier : alias<identifier> {};

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

// struct module_instance_identifier : alias<identifier>{};

// struct name_of_instance : seq < 
//   module_instance_identifier, 
//   one<'['>, 
//   bus_range, 
//   one<']'>
// >{};

// struct module_instance : seq<
//   name_of_instance, one<'('>, opt<list_of_port_connections>, one<')'>
// >{};

// struct module_instantiation : seq<
//   // opt< parameter_value_assignment> 
//   until<module_identifier>,
//   plus_blank,
//   opt<separator>,
//   list<module_instance, one<','>, separator>,
//   one<';'>
// > {};


// struct module_or_generate_item : seq<
//   star<attribute_instance>, 
//   sor<
//     module_or_generate_item_declaration,
//     module_instantiation,
//     // udp_instantiation,
//     until<one<';'>>
//     // parameter_override,
//     // continuous_assign,
//     // gate_instantiation,
//     // initial_construct,
//     // always_construct
//   >
// > {};

// struct module_item : sor<
//   module_or_generate_item,
//   seq<port_declaration, one<';'>>,
//   seq<
//     star<attribute_instance>, 
//     sor<
//       generated_instantiation,
//       local_parameter_declaration,
//       parameter_declaration,
//       specify_block,
//       specparam_declaration
//     >
//   >
// >{};

// struct module_declaration : seq<
//   // star<attribute_instance>,
//   if_must<
//     module_keyword,
//     module_identifier,
//     opt<module_parameter_port_list>,
//     opt<list_of_ports>,
//     one<';'>,
//     // star<module_item>,
//     endmodule_keyword
//   >
// > {};

// // clang-format on
// } // namespace Grammar
// } // namespace IEEE1364_2001
// } // namespace Verilog

// #endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_MODULE_HPP
