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

#ifndef LIBSDF_GRAMMAR_BASE_HPP
#define LIBSDF_GRAMMAR_BASE_HPP

#include "./block.hpp"
#include "./character.hpp"
#include "./comment.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace SDF {
namespace Grammar {

// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct sp : sor< plus_blank, comment > {};
struct sps : plus< sp > {};

template<typename T, typename... P>
struct sep_seq: seq<
  opt<sps>,
  seq<T, seq<sps, P>...>,
  opt<sps>
> {};

template<typename T, typename... P>
struct sep_must: must<
  opt<sps>,
  must<T, must<sps, P>...>,
  opt<sps>
> {};

template<typename... P>
struct op_sep_seq: seq<
  opt<sps>,  
  seq<P,opt<sps>>...
> {};

template<typename... P>
struct op_sep_must: must<
  opt<sps>,  
  seq<P,opt<sps>>...
> {};

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

struct identifier : plus<character> {};

struct hierarchical_identifier : seq <
  identifier,
  star<seq <
    hchar,
    identifier
  >>
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
  opt<sps>,
  tao::pegtl::list<bracket_pair,opt<sps>>
> {};

template<typename T>
struct unimplemented : if_must<
  seq<open, T>,
  star<bracket_contents>,
  star<bracket_pairs>,
  star<bracket_contents>,
  until<close>
> {};

// clang-format on

} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_BASE_HPP
