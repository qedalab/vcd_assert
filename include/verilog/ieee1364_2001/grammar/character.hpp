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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_CHARACTER_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_CHARACTER_HPP

#include "../../types/enums.hpp"
#include "./numbers.hpp"

#include <parse/grammar/base.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;

struct special_character_without_brackets : one<
  '!','#','%','&','*','+',',','-','.',char(174) /* ASCII version of « */,
  '/',':',';','<','=','>','?','@','[','\\',']','^',
  '\'','{','|','}','~' 
> {};
struct special_character_without_backslash : one<
  '!','#','%','&','*','+',',','-','.',char(174) /* ASCII version of « */,
  '/',':',';','<','=','>','?','@','[',']','^',
  '\'','{','|','}','~','(',')'
> {};

/* '«', and '\\' fails testing*/
struct special_character : sor<
  special_character_without_brackets,
  one<'(',')'>
> {};

struct alphanumeric : sor<
  tao::pegtl::range<'a','z'>,
  tao::pegtl::range<'A','Z'>,
  one<'_','$'>,
  decimal_digit
> {};

// TODO use these instead
struct hchar_dot : one<'.'> {
  static constexpr auto value = HChar::dot;
};

struct hchar_slash : one<'/'> {
  static constexpr auto value = HChar::slash;
};

struct hchar : sor<hchar_dot, hchar_slash> {};

struct character;

struct escaped_character : seq<
  one<'\\'>,
  sor<
    character,
    special_character,
    one<'"'>
  >
> {};

struct character : sor<
  escaped_character,
  alphanumeric
> {};

//fails to match \\ in qstring without the first line.
struct any_character : sor<
  seq<one<'\\'>,one<'\\'>>,
  character, 
  special_character_without_backslash,
  seq<one<'\\'>,one<'"'>>
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_CHARACTER_HPP
