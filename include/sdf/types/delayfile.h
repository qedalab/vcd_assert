#ifndef LIBSDF_TYPES_DELAYFILE_H_
#define LIBSDF_TYPES_DELAYFILE_H_

#include <sdf/types/timingdelay.h>
#include <parse/grammar/base.h>
#include <sdf/enums.h>
#include <sdf/types/values.h>
#include <sdf/types/variant.h>

namespace SDF {
namespace Types {

// clang-format off
using TimingSpecVariant = std::variant<
  Delay,
  TimingCheck,
  // TimingEnv, //unimplemented
  // Label      //unimplemented
>;
// clang-format on

struct TimingSpec : public TimingSpecVariant {
  using TimingSpecVariant::TimingSpecVariant;
};

using TimingSpecPtl = std::unique_ptr<TimingSpec>;

struct Timescale;

struct Cell {
  std::string name;
  std::string instance;
  std : vector<TimingSpec> te_specs;
};

struct DelayFile {
  std::string file_path;
  std::string sdf_version;
  std::string design_name;
  std::string date;
  std::string vendor;
  std::string program_name;
  std::string program_version;
  std::string process;
  char hierarchy_divider;
  Triple voltage;
  Triple temperature;
  Timescale time_scale;
  std::vector<Cell> cells;
};

} // namespace Types
} // namespace SDF

#endif // LIBSDF_TYPES_DELAYFILE_H_