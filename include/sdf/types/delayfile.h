#ifndef LIBSDF_TYPES_DESIGN_H_
#define LIBSDF_TYPES_DESIGN_H_

#include "delay.h"
#include "spec.h"
#include "values.h"
#include <parse/grammar/base.h>
#include <sdf/grammar/enums.h>

namespace SDF {
namespace Types {

//THIS FILE IS NOT SDF SPECIFIC. 
// scope tree constructs should be moved to 'vcdasser'(exe)
// But Cell and Delayfile should stay.
struct Timescale;

struct Cell{
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

#endif // LIBSDF_TYPES_DESIGN_H_