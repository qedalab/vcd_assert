#ifndef LIBSDF_TYPES_TIMINGSPEC_HPP
#define LIBSDF_TYPES_TIMINGSPEC_HPP

#include <sdf/types/timing_check.hpp>
#include <sdf/types/enums.hpp>
#include <parse/util/dependent_value.hpp>
#include <type_traits>

namespace SDF {
 
namespace Unsupported{
  struct TimingDelaySpec{};
  struct TimingEnvSpec{};
  struct TimingLabelSpec{};
} // namespace Unsupported

// clang-format off
using TimingSpecVariant = std::variant<
  Unsupported::TimingDelaySpec,
  TimingCheckSpec,
  Unsupported::TimingEnvSpec,
  Unsupported::TimingLabelSpec
>;
// clang-format on

struct TimingSpec {
  TimingSpecVariant value;

  TimingSpecType get_enum_type() const {
    return std::visit([](auto&& param) -> TimingSpecType {
      using T = typename std::decay<decltype(param)>::type;
      if constexpr (std::is_same_v<T, Unsupported::TimingDelaySpec>) {
          return TimingSpecType::delay;
      } else if constexpr (std::is_same_v<T, TimingCheckSpec>) {
          return TimingSpecType::timing_check;
      } else if constexpr (std::is_same_v<T, Unsupported::TimingEnvSpec>) {
          return TimingSpecType::timing_env;
      } else if constexpr (std::is_same_v<T, Unsupported::TimingLabelSpec>) {
          return TimingSpecType::label;
      } else {
          static_assert(Parse::Util::dependent_value<false, T>);
      }
    }, value);
  }
};

} // namespace SDF


#endif // LIBSDF_TYPES_TIMINGSPEC_HPP
