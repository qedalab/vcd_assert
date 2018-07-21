#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_CHARACTER_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_CHARACTER_HPP

#include "../../types/enums.hpp"

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

struct decimal_digit : tao::pegtl::range<'0','9'> {};

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
