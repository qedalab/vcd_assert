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

#ifndef LIBVCD_GRAMMAR_BASE_HPP
#define LIBVCD_GRAMMAR_BASE_HPP

#include "parse/grammar/base.h"
#include "parse/grammar/part.h"

#include "./enums/value.hpp"
#include "./keywords.hpp"

namespace VCD::Grammar {

using namespace Parse::Grammar::Base;

struct blank : one<' ', '\n', '\r', '\t', '\v', '\f'> {};
struct plus_blank : plus<blank> {
  static constexpr auto error() { return "Expected whitespace"; }
};

struct command_separator : sor<
  eof,
  plus<blank>
> {};

struct printable_ascii_except_whitespace : range<33,126> {};

// TODO be strict about what is allowed as identifiers
struct identifier_code : seq<
  not_at<command_separator>,
  until<at<command_separator>>
> {};

struct simple_identifier : seq<
  tao::pegtl::identifier_first,
  star<sor<
    tao::pegtl::alnum,
    one<'_','$'>
  >>
> {};

struct escaped_identifier : seq<
  one<'\\'>,
  plus<printable_ascii_except_whitespace>,
  must<blank>
> {};

struct identifier : sor<
  escaped_identifier,
  simple_identifier
> {};

} // namespace VCD::Grammar

#endif // LIBVCD_GRAMMAR_BASE_HPP
