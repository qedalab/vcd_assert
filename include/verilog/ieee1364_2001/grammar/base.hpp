
#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_BASE_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_BASE_HPP

#include "./character.hpp"
#include "./comment.hpp"
#include "./block.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

template <typename... Rules>
using list = tao::pegtl::list<Rules...>;


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


struct escaped_identifier : must<
  one<'\\'>,
  plus<tao::pegtl::identifier_other>
> {};

struct simple_identifier : must<
  tao::pegtl::identifier_first,
  star<tao::pegtl::identifier_other>
> {};

struct identifier : sor<simple_identifier, escaped_identifier > {};

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
struct unimplemented_block : if_must<
  seq<open, T>,
  star<bracket_contents>,
  star<bracket_pairs>,
  star<bracket_contents>,
  until<close>
> {};

// struct unimplemented_item : if_must<

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_BASE_HPP
