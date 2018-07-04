#ifndef TEST_SDF_TYPES_DELAYFILE_HPP
#define TEST_SDF_TYPES_DELAYFILE_HPP

// #include "./cell.hpp"
#include <sdf/types/enums.hpp>
#include <sdf/types/delayfile.hpp>

namespace SDF::Test {

struct TestDelayFile {
  std::string sdf_version;
  std::optional<std::string> design_name;
  std::optional<std::string> date;
  std::optional<std::string> vendor;
  std::optional<std::string> program_name;
  std::optional<std::string> program_version;
  std::optional<std::string> process;
  std::optional<HChar> hierarchy_divider;
  std::optional<Triple> voltage;
  std::optional<Triple> temperature;
  std::optional<TimeScale> timescale;
  std::vector<Cell> cells;
};

void read_in_test_delayfile(SDF::DelayFileReader &reader, TestDelayFile &test);
void catch_test_delayfile(SDF::DelayFile &delayfile, TestDelayFile &test);

} // namespace SDF::Test

#endif // TEST_SDF_TYPES_DELAYFILE_HPP
