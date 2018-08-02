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

#ifndef LIBSDF_ACTIONS_VALUES_HPP
#define LIBSDF_ACTIONS_VALUES_HPP

#include <sdf/actions/base.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/values.hpp>
#include <sdf/grammar/values.hpp>


namespace SDF {
namespace Actions {



struct NumberAction : multi_dispatch<
    Grammar::signed_real_number, apply<Apply::float_value>,
    Grammar::real_number, apply<Apply::float_value>
> {
  using state = Number;
};

template <class Number>
struct TripleAction : multi_dispatch<
    Grammar::triple_min<Number>, inner_action< 
        NumberAction, 
        Storage::member<&Triple::min>
      >,
    Grammar::triple_typ<Number>, inner_action< 
        NumberAction, 
        Storage::member<&Triple::typ>
      >,
    Grammar::triple_max<Number>, inner_action<
        NumberAction, 
        Storage::member<&Triple::max>
      >
> {
  using state = Triple;
};

struct ValueAction : multi_dispatch<
    Grammar::rtriple, 
      inner_action_passthrough<
        TripleAction<Grammar::signed_real_number>
      >, 
    Grammar::triple, 
      inner_action_passthrough<
        TripleAction<Grammar::real_number>
      >,
    Grammar::signed_real_number, 
      inner_action_passthrough<
        NumberAction
      >, 
    Grammar::real_number, 
      inner_action_passthrough<
        NumberAction
      >
> {
  using state = Value;
};


} // namespace Actions
} // namespace SDF

#endif // LIBSDF_ACTIONS_VALUES_HPP
