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

struct Star;
using Path = std::vector<std::string>; // TODO : check for validity

// clang-format off
using InstanceVariant = std::variant<
  Star,
  Path
>;
// clang-format on

// struct TimingSpec : public TimingSpecVariant {
//   using TimingSpecVariant::TimingSpecVariant;
// };

// using TimingSpecPtr = std::unique_ptr<TimingSpec>;

struct Cell {
  std::string celltype;
  InstanceVariant cell_instance;
  std::vector<TimingSpec> timing_specs;
};

}
}

#endif LIBSDF_TYPES_CELL_HPP
