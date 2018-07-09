#ifndef LIBSDF_GRAMMAR_BASE_HPP 
#define LIBSDF_GRAMMAR_BASE_HPP 

#include <parse/grammar/base.h>
#include <tao/pegtl.hpp>

namespace SDF {
namespace Grammar {

// clang-format off

using namespace Parse::Grammar::Base;

using namespace tao;

using tao::pegtl::seq;

struct blank : one<' ','\n','\t','\r'> {};
struct plus_blank : plus<blank> {};

struct comment_single_line : seq< 
    two< '/' >, until< eolf > 
>{};

struct comment_multi_line_cont : until< 
  sor< eof, TAO_PEGTL_STRING( "*/" ) > 
>{};

struct comment_multi_line : if_must<
  TAO_PEGTL_STRING( "/*" ), 
  comment_multi_line_cont
>{};

struct comment : sor <
  comment_single_line,
  comment_multi_line
>{};

struct sp : sor< plus<blank>, comment > {};
struct sps : plus< sp > {};

template<typename T, typename... P>
struct sep_seq: seq<
  opt<sps>,
  seq<T, seq<sps, P>...>,
  opt<sps>
>{};

template<typename T, typename... P>
struct sep_must: must<
  opt<sps>,
  must<T, must<sps, P>...>,
  opt<sps>
>{};

template<typename... P>
struct op_sep_seq: seq<
  opt<sps>,  
  seq<P,opt<sps>>...
>{};

template<typename... P>
struct op_sep_must: must<
  opt<sps>,  
  seq<P,opt<sps>>...
>{};

struct open : seq <
  opt<sps>,
  one< '(' >,
  opt<sps>
>{};

struct close : seq <
  opt<sps>,
  one< ')' >,
  opt<sps>
>{};

template<typename T, typename... P>
struct block: if_must<
  seq< open, T >,
  seq< opt< sps >, P >...,
  close
>{};

//removed '«' temporarily due to char overflow will need utf8?
struct special_character_without_brackets : one<
  '!','#','%','&','*','+',',','-','.',
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

struct sign : one<'+','-'> {};
struct hchar : sor<one<'.'>,one<'/'>> {};

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

struct qstring_cont : seq<
  star<sor< blank, any_character> >,
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
>{};

struct bracket_pair : seq<
  one<'('>,
  star<bracket_contents>,
  one<')'>
>{};

struct bracket_pairs : plus<
  opt<sps>,
  pegtl::list<bracket_pair,opt<sps>>
>{};

template<typename T>
struct unimplemented : if_must<
  seq<open, T>,
  star<bracket_contents>,
  star<bracket_pairs>,
  star<bracket_contents>,
  until<close>
>{};

// clang-format on

} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_BASE_HPP 
