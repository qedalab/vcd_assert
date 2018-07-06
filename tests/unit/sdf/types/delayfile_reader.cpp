#include "./delayfile_reader.hpp"

using namespace SDF;


void SDF::Test::read_in_test_delayfile_w_reader(SDF::DelayFileReader &reader, SDF::DelayFileView &test)
{
  
  auto t_sdf_version = test.sdf_version;
  reader.sdf_version(t_sdf_version);
    
  if(test.design_name) {
    auto t_design_name = test.design_name.value();
    reader.design_name(t_design_name);
  }
  
  if(test.date) {
    auto t_date = test.date.value();
    reader.date(t_date);
  }
  
  if(test.vendor) {
    auto t_vendor = test.vendor.value();
    reader.vendor(t_vendor);
  }
  
  if(test.program_name) {
    auto t_program_name = test.program_name.value();
    reader.program_name(t_program_name);
  }
  
  if(test.program_version) {
    auto t_program_version = test.program_version.value();
    reader.program_version(t_program_version);
  }
  
  if(test.process) {
    auto t_process = test.process.value();
    reader.process(t_process);
  }
  
  if(test.hierarchy_divider) {
    auto t_hierarchy_divider = test.hierarchy_divider.value();
    reader.hierarchy_divider(t_hierarchy_divider);
  }
  
  if(test.voltage) {
    auto t_voltage = test.voltage.value();
    reader.voltage(t_voltage);
  }
  
  if(test.temperature) {
    auto t_temperature = test.temperature.value();
    reader.temperature(t_temperature);
  }
  
  if(test.timescale) {
    auto t_timescale = test.timescale.value();
    reader.timescale(t_timescale.get_number(), t_timescale.get_unit());
  }
  auto t_cells = test.cells;
  reader.cells(t_cells);
}


TEST_CASE("SDF.Types.SDFDelayFileReader") {

// void catch_test_delayfile(SDF::DelayFile &delayfile, TestDelayFile &test);

// void catch_test_delayfile(SDF::DelayFile &delayfile, TestDelayFile &test);

  // SECTION("Case 1: Empty") {
  //   //Write DelayFile file with the same structure as the SDF example
  //   DelayFileReader reader;
  //   SDF::Test::read_in_test_delayfile(reader, sdf_empty_delayfile);
  //   auto delayfile_p = reader.release();
  //   REQUIRE(delayfile_p.operator bool());
  //   SDF::Test::catch_test_delayfile(*delayfile_p, sdf_empty_delayfile);
  // }

  // SECTION("Case 2: From SDF Example") {
  //   //Write DelayFile file with the same structure as the SDF example
  //   DelayFileReader reader;
  //   SDF::Test::read_in_test_delayfile(reader, basic_example_delayfile);
  //   auto delayfile_p = reader.release();
  //   REQUIRE(delayfile_p.operator bool());
  //   auto &delayfile = *delayfile_p;
  //   SDF::Test::catch_test_delayfile(delayfile, basic_example_delayfile);
  // }
}
