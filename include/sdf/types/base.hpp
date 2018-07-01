#ifndef LIBSDF_TYPES_BASE_HPP_
#define LIBSDF_TYPES_BASE_HPP_

#include <sdf/types/enums.hpp>

#include <string>
#include <vector>

namespace SDF {
namespace Types {

struct Star{};

using Path = std::vector<std::string>; // TODO : check for validity

struct TimeScale {
  TimeScaleNumber number;
  TimeScaleUnit unit;
};

} // namespace Types
} // namespace SDF

#endif // LIBSDF_TYPES_BASE_HPP_

