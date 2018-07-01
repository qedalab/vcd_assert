
#ifndef LIBSDF_GRAMMAR_GRAMMAR_HPP 
#define LIBSDF_GRAMMAR_GRAMMAR_HPP 

#include <sdf/grammar/base.hpp>
#include <sdf/grammar/delayfile.hpp>

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

#endif // LIBSDF_GRAMMAR_GRAMMAR_HPP 
