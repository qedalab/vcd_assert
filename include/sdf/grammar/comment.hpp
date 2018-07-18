#ifndef LIBSDF_GRAMMAR_COMMENT_HPP
#define LIBSDF_GRAMMAR_COMMENT_HPP

#include <parse/grammar/base.h>

namespace SDF::Grammar {

using namespace Parse::Grammar::Base;

struct comment_single_line : seq< 
    two< '/' >, until< eolf > 
>{};

struct comment_multi_line_cont : until< 
  sor< eof, TAO_PEGTL_STRING( "*/" ) > 
>{};

struct comment_multi_line : if_must<
  TAO_PEGTL_STRING( "/*" ), 
  comment_multi_line_cont
>{};

struct comment : sor <
  comment_single_line,
  comment_multi_line
>{};

} // namespace SDF::Grammar

#endif // LIBSDF_GRAMMAR_COMMENT_HPP
