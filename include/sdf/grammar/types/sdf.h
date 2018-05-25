#ifndef LIBSDF_TYPES_H_
#define LIBSDF_TYPES_H_

#include <parse/grammar/base.h>

namespace SDF {
struct Timescale;

struct Triple;

class DelayFileHeader {
  std::string sdf_version;
  std::string design_name;
  std::string date;
  std::string vendor;
  std::string program_name;
  std::string program_version;
  char hierarchy_divider;
  Triple voltage;
  std::string process;
  Triple temperature;
  Timescale time_scale;
};

enum class SpecType { Delay, TimingCheck, TimingEnv, Label };

enum class TimingCheckType {
  setup,
  hold,
  setuphold,
  recovery,
  removal,
  recrem,
  skew,
  bidirectskew,
  width,
  period,
  nochange
};

enum class DataType {
  value, triple, rvalue, rtiple, delval, delval_list, retval
};

struct Data {
  DataType dt;
};

struct TimingSpec {
  SpecType type;
  Data &&data;
};

struct Cell {
  std::string name;
  std::string instance;
  TimingSpec spec;
};

struct DelayFile {
  DelayFileHeader header;
  std : vector<Cell> cells;
};

} // namespace SDF
#endif