#ifndef LIBSDF_GRAMMAR_CHARACTER_HPP
#define LIBSDF_GRAMMAR_CHARACTER_HPP

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
  '!','#','%','&','*','+',',','-','.',
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
struct hchar_dot : one<'.'> {};
struct hchar_slash : one<'.'> {};

struct hchar : sor<one<'.'>,one<'/'>> {
};

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
