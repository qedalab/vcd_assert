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

#ifndef LIBSDF_GRAMMAR_CHARACTER_HPP
#define LIBSDF_GRAMMAR_CHARACTER_HPP

#include "../types/enums.hpp"

#include "parse/grammar/base.h"

namespace SDF::Grammar {

using namespace Parse::Grammar::Base;

//removed '«' temporarily due to char overflow will need utf8?
struct special_character_without_brackets : one<
  '!','#','%','&','*','+',',','-','.',char(174) /* ASCII version of « */,
  '/',':',';','<','=','>','?','@','[','\\',']','^',
  '\'','{','|','}','~' 
>{};
struct special_character_without_backslash : one<
  '!','#','%','&','*','+',',','-','.',char(174) /* ASCII version of « */,
  '/',':',';','<','=','>','?','@','[',']','^',
  '\'','{','|','}','~','(',')'
>{};

/* '«', and '\\' fails testing*/
struct special_character : sor<
  special_character_without_brackets,
  one<'(',')'>
>{};

struct decimal_digit : range<'0','9'> {};

struct alphanumeric : sor<
  range<'a','z'>,
  range<'A','Z'>,
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

} // namespace SDF::Grammar

#endif // LIBSDF_GRAMMAR_CHARACTER_HPP
