#ifndef LIBSDF_GRAMMAR_DATA_VALUES_H
#define LIBSDF_GRAMMAR_DATA_VALUES_H

#include "parse/grammar/base.h"
#include "./numbers.h"

namespace SDF {
namespace Grammar {

using namespace Parse::Grammar::Base;

template<class Rule, int N>
struct triple_number : Rule {};

template <class Number>
struct define_triple : seq<
  not_at<string<"::">, not_at<Number>>,
  opt<triple_number<Number, 0>>,
  one<':'>,
  opt<triple_number<Number, 1>>,
  one<':'>,
  opt<triple_number<Number, 2>>
> {};

struct triple : define_triple<real_number> {};
struct rtriple : define_triple<signed_real_number> {};

template <class Number, class Triple>
struct define_value : sor<
  seq<Number, not_at<one<':'>>>,
  Triple
> {};


struct value : define_value<real_number, triple> {};
struct rvalue : define_value<signed_real_number, triple> {};

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

struct delval_list : seq<
  delval,
  rep_min_max<0, 11, plus_blank, delval>
> {};

}
}


#endif //PARSE_CONSTANTS_H
