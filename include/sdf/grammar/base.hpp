#ifndef LIBSDF_GRAMMAR_BASE_HPP 
#define LIBSDF_GRAMMAR_BASE_HPP 

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include "./comment.hpp"
#include "./block.hpp"
#include "./character.hpp"

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

struct qstring_content : star<
  sor< blank, any_character> 
>{};

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
>{};

struct bracket_pair : seq<
  one<'('>,
  star<bracket_contents>,
  one<')'>
>{};

struct bracket_pairs : plus<
  opt<sps>,
  tao::pegtl::list<bracket_pair,opt<sps>>
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
