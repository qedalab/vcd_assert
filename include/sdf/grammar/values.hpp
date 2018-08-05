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
struct triple_min : alias<Number> {};
template <class Number>
struct triple_typ : alias<Number> {};
template <class Number>
struct triple_max : alias<Number> {};

template <class Number>
struct define_triple : seq < 
  not_at< string<':',':'>, not_at<Number> >,
  op_sep_seq<
    opt<triple_min<Number>>,
    one<':'>,
    opt<triple_typ<Number>>,
    one<':'>,
    opt<triple_max<Number>>
  >
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
