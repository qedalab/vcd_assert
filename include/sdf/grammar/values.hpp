#ifndef LIBSDF_GRAMMAR_VALUES_HPP 
#define LIBSDF_GRAMMAR_VALUES_HPP 

#include <sdf/grammar/base.hpp>
#include <sdf/grammar/numbers.hpp>

namespace SDF {
namespace Grammar {

// clang-format off

template<class Rule, int N>
struct triple_number : Rule {};

template <class Number>
struct triple_min : Number{};
template <class Number>
struct triple_typ : Number{};
template <class Number>
struct triple_max : Number{};

template <class Number>
struct define_triple : op_sep_seq<
  // not_at<string<':',':'>, not_at<Number> >,
  opt<triple_min<Number>>,
  one<':'>,
  opt<triple_typ<Number>>,
  one<':'>,
  opt<triple_max<Number>>
> {};

struct triple : define_triple<real_number> {};
struct rtriple : define_triple<signed_real_number> {};


template <class Number, class Triple>
struct define_value : must<
    one<'('>,
    star<blank>,    
    opt<sor<Triple,Number>>,
    star<blank>,
    one<')'>
> {};

struct value : define_value<real_number, triple> {};
struct rvalue : define_value<signed_real_number, rtriple> {};

struct delval : sor<
  rvalue,
  seq<
    one<'('>,
    star<blank>,
    rvalue,
    opt<plus_blank, rvalue, opt<plus_blank, rvalue>>,
    star<blank>,
    one<')'>
  >
> {};

struct retval_list : seq<
  delval,
  rep_min_max<0, 2, plus_blank, delval>
> {};

//TODO: Should actually be either 1, 2, 3, 4-6 or 7-12 delval.
// if there is a way to know which case passed rather than have to 
// post process to figure it out, this would be better, surely?
// see LRM page 23.
struct delval_list : seq<
  delval,
  rep_min_max<0, 11, plus_blank, delval>
> {};

// clang-format on

} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_VALUES_HPP 
