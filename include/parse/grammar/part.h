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

#ifndef PARSE_GRAMMAR_PART_H_
#define PARSE_GRAMMAR_PART_H_

#include "./base.h"

namespace Parse {
namespace Grammar {

inline namespace Part {

struct sign : one<'-', '+'> {
  static constexpr auto error() { return "Expected sign value"; }
};

struct non_zero : range<'1', '9'> {
  static constexpr auto error() { return "Excepted non-zero value"; }
};

struct digit : range<'0', '9'> {
  static constexpr auto error() { return "Excepted digit"; }
};

struct int_part : sor<seq<non_zero, star<digit>>, string<'0'>> {
  static constexpr auto error() { return "Expected integer part"; }
};

struct whitespace : one<' ', '\t'> {
  static constexpr auto error() { return "Expected whitespace"; }
};

struct blank : one<' ', '\t', '\r', '\n'> {
  static constexpr auto error() { return "Expected whitespace"; }
};

struct plus_whitespace : plus<whitespace> {
  static constexpr auto error() { return "Expected at least one whitespace"; }
};

struct plus_blank : plus<blank> {
  static constexpr auto error() { return "Expected at least one whitespace"; }
};

struct star_whitespace : star<whitespace> {
  static constexpr auto error() {
    return "Internal error: Failed parsing StarWhitespace";
  }
};

struct line_end : seq<star_whitespace, eolf> {
  static constexpr auto error() { return "Expected line ending"; }
};

struct imaginary_unit : one<'i', 'j'> {
  static constexpr auto error() {
    return R"(Expected imaginary unit: 'i' or 'j')";
  }
};

} // namespace Part

} // namespace Grammar
} // namespace Parse

#endif // PARSE_GRAMMAR_PART_H_
