
#ifndef LIBSDF_GRAMMAR_CELL_HPP
#define LIBSDF_GRAMMAR_CELL_HPP


#include <sdf/grammar/base.hpp>
#include <sdf/grammar/keywords.hpp>
#include <sdf/grammar/timing.hpp>

namespace SDF {
namespace Grammar {

// clang-format off

struct cell_type : block< 
  key_cell_type,
  qstring
>{};

struct cell_instance : block< 
  key_instance,
  sor<
     one< '*' >, opt<hierarchical_identifier>   /*order*/
  >
>{};

// struct cell : unimplemented< key_cell >{}; 
struct cell : block< 
  key_cell,
  cell_type,
  cell_instance,
  star< timing_spec >
>{};

// clang-format on

} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_CELL_HPP
