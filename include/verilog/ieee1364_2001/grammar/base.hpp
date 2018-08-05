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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_BASE_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_BASE_HPP

#include "./block.hpp"
#include "./character.hpp"
#include "./comment.hpp"
#include "./keywords.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

template <typename... Rules>
using list = tao::pegtl::list<Rules...>;

template <typename... Rules>
using until = tao::pegtl::until<Rules...>;

template <typename... Rules>
using pad = tao::pegtl::pad<Rules...>;

// struct sep : sor< plus_blank, comment > {};
// struct plus_sep : pad< blank, sep> {};

struct sep : pad< plus_blank, comment> {};
struct plus_sep : plus< sep > {};

template<typename T, typename... P>
struct sep_seq: seq<
  T, seq<plus_sep, P>...
> {};

template<typename T, typename... P>
struct sep_must: must<
  T, seq<plus_sep, P>...
> {};

template<typename T, typename... P>
struct opt_sep_seq: seq<
  T, seq<opt<plus_sep>, P>...
> {};

template<typename T, typename... P>
struct opt_sep_must: must<
  T, seq<opt<plus_sep>, P>...
> {};

template<typename T, typename... P>
struct opt_sep_if_must: if_must<
  T, seq<opt<plus_sep>, P>...
> {};

// template<typename... P>
// struct opt_sep_seq: seq<
//   opt<plus_sep>>,  
//   seq<P,opt<plus_sep>>...
// > {};

// template<typename... P>
// struct opt_sep_must: must<
//   star<sep>,  
//   seq<P,opt<plus_sep>>...
// > {};

struct qstring_content : star<
  sor< blank, any_character> 
> {};

struct qstring_cont : seq<
  qstring_content,
  one<'"'>
>{
  static constexpr auto error() { return "quoted string does not terminate."; }
};

struct qstring : if_must<
  one<'"'>,
  qstring_cont
> {};


struct escaped_identifier : seq<
  not_at<keyword>, 
  one<'\\'>,
  plus<
    sor<
      tao::pegtl::identifier_other, 
      one<'$'>
    >
  >
> {};


struct simple_identifier : seq<
  not_at<keyword>, 
  tao::pegtl::identifier_first,
  plus<
    sor<
      tao::pegtl::identifier_other, 
      one<'$'>
    >
  >
> {};

struct identifier : seq< sor< simple_identifier, escaped_identifier >> {};

struct s_identifier : seq< 
  one<'$'>, 
  plus< 
    sor<
      tao::pegtl::identifier_other, 
      one<'$'>
    >
  >
> {};

struct hierarchical_identifier : seq <
  identifier,
  star<seq <
    hchar,
    identifier
  >>
> {};

struct path_star : alias<one<'*'>> {};

struct path_dot : alias<hchar_dot> {};
struct path_separator: alias<hchar_slash> {};

struct path_identifier : plus<sor<path_star, path_dot, identifier>> {};

struct file_path : list< 
  path_identifier,
  path_separator
> {};

struct file_path_spec : alias<
  file_path
> {};



struct bracket_pairs;

struct bracket_contents : 
  sor<
    qstring,
    plus<character>,
    plus_blank,
    hierarchical_identifier,
    special_character_without_brackets,
    bracket_pairs
> {};

struct bracket_pair : seq<
  one<'('>,
  star<bracket_contents>,
  one<')'>
> {};

struct bracket_pairs : plus<
  opt<plus_sep>,
  tao::pegtl::list<bracket_pair,opt<plus_sep>>
> {};

template<typename T>
struct unimplemented_block : if_must<
  seq<open, T>,
  star<bracket_contents>,
  star<bracket_pairs>,
  star<bracket_contents>,
  until<close>
> {};


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
  opt<plus_sep>,
  tao::pegtl::list<ignored,opt<plus_sep>>
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
    plus_sep,
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


struct unimplemented_begin_end : if_must<
  begin_keyword,
  star<begin_end_contents>,
  // star<begin_end_pairs>,
  // star<begin_end_contents>,
  until<end_keyword>
> {};


// struct unimplemented_item : if_must<

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_BASE_HPP
