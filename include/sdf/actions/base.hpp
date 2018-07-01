#ifndef LIBSDF_ACTIONS_BASE_HPP_
#define LIBSDF_ACTIONS_BASE_HPP_

#include <sdf/grammar/base.hpp>
#include <sdf/types/base.hpp>

#include "parse/actions/apply/value.hpp"
#include "parse/actions/apply/rule_value.hpp"
#include "parse/actions/apply/string.hpp"

#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/command/apply0.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/pegtl_action.hpp"

#include "parse/actions/dispatch.hpp"
#include "parse/action/enum.h"

#include "parse/actions/storage/member.hpp"
#include "parse/actions/storage/function.hpp"
#include "parse/actions/storage/push_back.hpp"


namespace SDF {
namespace Actions {

using namespace Parse;  
using namespace SDF::Types;  

struct HCharAction : multi_dispatch<
    Grammar::one<'.'>, apply0<Apply::value<HChar::dot>>,
    Grammar::one<'/'>, apply0<Apply::value<HChar::slash>>
> {
  using state = Path;
};

struct HierarchicalIdentifierAction : single_dispatch<
    Grammar::identifier, Storage::push_back
> {
  using state = Path;
};


struct IdentifierAction : single_dispatch<
    Grammar::identifier, apply0<Apply::string>
> {
  using state = std::string;
};


struct QStringAction : single_dispatch<
    Grammar::qstring, apply0<Apply::string>
> {
  using state = std::string;
};


// namespace Unimplemented{
// // blank
// // plus_blank
// // comment_single_line
// // comment_multi_line_cont
// // comment_multi_line
// // comment
// // sp
// // sps
// // sep_seq
// // sep_must
// // op_sep_seq
// // op_sep_must
// // open
// // close
// // block
// // special_character_without_brackets
// // special_character_without_backslash
// // special_character
// // decimal_digit
// // alphanumeric
// // sign
// // hchar
// // character
// // escaped_character
// // character
// // any_character
// // bracket_pairs
// // bracket_contents
// // bracket_pair
// // bracket_pairs
// }

}
}

#endif // LIBSDF_ACTIONS_BASE_HPP_
