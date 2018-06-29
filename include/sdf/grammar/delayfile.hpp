
#ifndef LIBSDF_GRAMMAR_DELAYFILE_HPP 
#define LIBSDF_GRAMMAR_DELAYFILE_HPP 

#include <sdf/grammar/cell.hpp>
#include <sdf/grammar/header.hpp>
#include <sdf/grammar/keywords.hpp>

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

#endif // LIBSDF_GRAMMAR_DELAYFILE_HPP 
