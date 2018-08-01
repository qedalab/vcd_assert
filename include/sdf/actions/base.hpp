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

#ifndef LIBSDF_ACTIONS_BASE_HPP
#define LIBSDF_ACTIONS_BASE_HPP

#include <sdf/grammar/base.hpp>
#include <sdf/types/base.hpp>

#include "parse/actions/apply/float.hpp"
#include "parse/actions/apply/integer.hpp"
#include "parse/actions/apply/rule_value.hpp"
#include "parse/actions/apply/string.hpp"
#include "parse/actions/apply/value.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/apply0.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/command/pegtl_action.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/actions/storage/function.hpp"
#include "parse/actions/storage/member.hpp"
#include "parse/actions/storage/push_back.hpp"

namespace SDF {
namespace Actions {

using namespace Parse;  

struct QStringAction : single_dispatch<
    Grammar::qstring_content, apply<Apply::string>
> {
  using state = std::string;
};

struct HCharAction : all_dispatch<apply0<Apply::rule_value>> {
  using state = HChar;
};

struct IdentifierAction : single_dispatch<
    Grammar::identifier, apply<Apply::string>
> {
  using state = std::string;
};

struct IdentifierArrayAction : single_dispatch<
    Grammar::identifier, inner_action<
      IdentifierAction, 
      Storage::push_back
    >
> {
  using state = std::vector<std::string>;
};

struct HierarchicalIdentifierStorage{
  static bool store(HierarchicalIdentifier &hi, std::string s) {
     hi.value.push_back(std::move(s));
     return true;
   }
 };

struct HierarchicalIdentifierAction : multi_dispatch<
    Grammar::hchar, inner_action<
      HCharAction, 
      Storage::member<&HierarchicalIdentifier::sep>
    >,
    Grammar::identifier, inner_action<
      IdentifierAction, 
      HierarchicalIdentifierStorage
    >
> {
  using state = HierarchicalIdentifier;
};



// blank
// plus_blank
// comment_single_line
// comment_multi_line_cont
// comment_multi_line
// comment
// sp
// sps
// sep_seq
// sep_must
// op_sep_seq
// op_sep_must
// open
// close
// block
// special_character_without_brackets
// special_character_without_backslash
// special_character
// decimal_digit
// alphanumeric
// sign
// hchar
// character
// escaped_character
// character
// any_character

}
}

#endif // LIBSDF_ACTIONS_BASE_HPP
