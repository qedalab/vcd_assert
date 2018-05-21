#ifndef LIBSDF_GRAMMAR_BASE_H
#define LIBSDF_GRAMMAR_BASE_H

#include "parse/grammar/base.h"

namespace SDF {
namespace Grammar {

using namespace Parse::Grammar::Base;

struct blank : one<' ','\n','\t','r'> {};
struct plus_blank : plus<blank> {};

struct special_character : one<'!','#','%','&','«','(',')','*','+',',','-','.',
                               '/',':',';','<','=','>','?','@','[','\\',']','^',
                               '\'','{','|','}','~'> {};

struct decimal_digit : range<'0','9'> {};

struct alphanumeric : sor<
  range<'a','z'>,
  range<'A','Z'>,
  one<'_','$'>,
  decimal_digit
> {};

struct sign : one<'+','-'> {};
struct hchar : one<'.','/'> {};

struct escaped_character : seq<
  one<'\\'>,
  sor<
    one<'"'>,
    special_character,
    alphanumeric
  >
> {};

struct character : sor<
  alphanumeric,
  escaped_character
> {};

struct any_character : sor<
  special_character,
  character
> {};

struct qstring : seq<
  one<'"'>,
  star<any_character>,
  one<'"'>
> {};

struct identifier : plus<character> {};

struct hierarchical_identifier : seq<
  identifier,
  star<seq<
    hchar,
    identifier
  >>
> {};

}
}

#endif //PARSE_BASE_H
