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

#ifndef PARSE_grammar_BASE_H_
#define PARSE_grammar_BASE_H_

#include <tao/pegtl/ascii.hpp>
#include <tao/pegtl/nothing.hpp>
#include <tao/pegtl/rules.hpp>

namespace Parse::Grammar {

inline namespace Base {

// Import into local scope
template <char... Chars>
using istring = tao::pegtl::istring<Chars...>;

template <char... Chars>
using string = tao::pegtl::string<Chars...>;

template <typename Rule>
using nothing = tao::pegtl::nothing<Rule>;

template <typename... Rules>
using sor = tao::pegtl::sor<Rules...>;

template <typename Rule>
using alias = tao::pegtl::seq<Rule>;

template <typename... Rules>
using seq = tao::pegtl::seq<Rules...>;

template <typename... Rules>
using opt = tao::pegtl::opt<Rules...>;

template <typename... Rules>
using plus = tao::pegtl::plus<Rules...>;

template <typename... Rules>
using star = tao::pegtl::star<Rules...>;

template <char Lo, char Hi>
using range = tao::pegtl::range<Lo, Hi>;

template <char... String>
using one = tao::pegtl::one<String...>;

template <char... String>
using two = tao::pegtl::two<String...>;

template <typename... Rules>
using must = tao::pegtl::must<Rules...>;

template <typename... Rules>
using if_must = tao::pegtl::if_must<Rules...>;

template <typename Rule>
using until = tao::pegtl::until<Rule>;

template <typename... Rules>
using at = tao::pegtl::at<Rules...>;

template <typename... Rules>
using not_at = tao::pegtl::not_at<Rules...>;

template <typename Padding, typename First, typename... Rules>
using delimited_seq = seq<First, seq<Padding, Rules>...>;

template <typename Padding, typename Rule>
using delimited_plus = seq<Rule, star<Padding, Rule>>;

template <typename Padding, typename Rule>
using delimited_star = opt<delimited_plus<Padding, Rule>>;

template <typename Padding, typename First, typename... Rules>
using delimited_must = must<First, must<Padding, Rules>...>;

template<auto Min, auto Max, typename... Rules>
using rep_min_max = tao::pegtl::rep_min_max<Min, Max, Rules...>;

using eol = tao::pegtl::eol;
using eof = tao::pegtl::eof;
using eolf = tao::pegtl::eolf;
using bof = tao::pegtl::bof;
using bol = tao::pegtl::bol;
using printable_ascii = tao::pegtl::print;

} // namespace Base
} // namespace Parse::Grammar

#endif // PARSE_GRAMMAR_BASE_H_
