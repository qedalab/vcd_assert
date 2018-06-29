#ifndef LIBSDF_ACTIONS_BASE_HPP
#define LIBSDF_ACTIONS_BASE_HPP


#include <sdf/grammar/base.hpp>
#include <sdf/types/base.hpp>


namespace SDF {

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
// qstring_cont
// qstring
// identifier
// hierarchical_identifier
// bracket_pairs
// bracket_contents
// bracket_pair
// bracket_pairs
// unimplemented

struct QStringAction : single_dispatch<
    Grammar::qstring, apply0<Apply::value<std::string>>,
> {
  using state = std::string;
};

}

#endif // LIBSDF_ACTIONS_BASE_HPP
