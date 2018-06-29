
#ifndef LIBSDF_GRAMMAR_CELL_H
#define LIBSDF_GRAMMAR_CELL_H


#include <sdf/grammar/base.hpp>
#include <sdf/grammar/keywords.hpp>
#include <sdf/grammar/timing.hpp>

namespace SDF {
namespace Grammar {

// clang-format off

struct celltype : block< 
  key_celltype,
  qstring
>{};

struct cell_instance : unimplemented< key_instance >{};
// struct cell_instance : block< 
//   pegtl::must < 
//     key_instance,
//     sor<
//       pegtl::opt<hierarchical_identifier>, one< '*' > 
//     >
//   >
// >{};

// struct cell : unimplemented< key_cell >{}; 
struct cell : block< 
  key_cell,
  celltype,
  cell_instance,
  star< timing_spec >
>{};

// clang-format on

} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_CELL_H
