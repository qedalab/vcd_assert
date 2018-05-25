
#ifndef LIBSDF_GRAMMAR_DELAYFILE_H
#define LIBSDF_GRAMMAR_DELAYFILE_H

#include "cell.h"
#include "header.h"
#include "keywords.h"

namespace SDF {
namespace Grammar {
// clang-format off

struct delay_file : block<
  key_delayfile,
  sdf_header,
  star< cell >
>{};

// clang-format on

} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_DELAYFILE_H
