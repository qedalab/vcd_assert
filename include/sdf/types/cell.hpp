#ifndef LIBSDF_TYPES_CELL_HPP
#define LIBSDF_TYPES_CELL_HPP

#include <tao/pegtl/nothing.hpp>

#include <sdf/types/Cell.hpp>

#include <sdf/types/timing_spec.hpp>


#include <sdf/enums.hpp>
#include <sdf/types/timingdelay.hpp>
#include <sdf/types/values.hpp>
#include <sdf/types/variant.hpp>

namespace SDF {
namespace Types {

struct Cell {
  std::string celltype;
  std::string cell_instance;
  std::vector<TimingSpec> te_specs;
};

}
}

#endif LIBSDF_TYPES_CELL_HPP
