#ifndef LIBSDF_GRAMMAR_SEPARATOR_HPP
#define LIBSDF_GRAMMAR_SEPARATOR_HPP

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include "./comment.hpp"

namespace SDF::Grammar {

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

// clang-format off
struct separator : plus<
  sor<
    comment,
    plus<blank>
  >
> {};

// clang-format on

} // namespace SDF::Grammar

#endif // LIBSDF_GRAMMAR_SEPARATOR_HPP
