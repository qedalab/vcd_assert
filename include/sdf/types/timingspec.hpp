#ifndef LIBSDF_TYPES_TIMINGSPEC_HPP_
#define LIBSDF_TYPES_TIMINGSPEC_HPP_

#include <sdf/types/timingcheck.hpp>

namespace SDF {
namespace Types {

namespace Unsupported{

  struct TimingDelay{};
  struct TimingEnv{};
  struct TimingLabel{};
  
} // namespace Unsupported

// clang-format off
using TimingSpecVariant = std::variant<
  TimingCheck,
  Unsupported::TimingDelay,
  Unsupported::TimingEnv,
  Unsupported::TimingLabel
>;
// clang-format on

struct TimingSpec : public TimingSpecVariant {
  using TimingSpecVariant::TimingSpecVariant;
};

using TimingSpecPtr = std::unique_ptr<TimingSpec>;


} // namespace Types
} // namespace SDF


#endif // LIBSDF_TYPES_TIMINGSPEC_HPP_
