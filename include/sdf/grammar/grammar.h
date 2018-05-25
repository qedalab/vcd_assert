
#ifndef LIBSDF_GRAMMAR_H
#define LIBSDF_GRAMMAR_H

#include "base.h"
#include "delayfile.h"

namespace SDF {
namespace Grammar {
// clang-format off

/* The top-level grammar allows one DELAYFILE 
   block and then expects eof. */
struct grammar : must<
  delay_file, 
  eof
>{};


// clang-format on
} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_H
