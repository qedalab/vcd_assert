#include "./delayfile.hpp"

using namespace SDF::Test;

// TODO : Should actually mock better, create stubs that cause only chosen sections to be tested; 
// tests should not repeat for every higher level that is run.

// TODO : Empty delayfile necessary?
 
TEST_CASE("SDF.Types.DelayFile") {

  SECTION("Case 1: Empty DelayFile example ") {

    DelayFileTester dft = DelayFileTester();
    auto test = dft.get_test_delayfile(sdf_empty_delayfile);
    
    CHECK(test.num_cells() == 0);
    SDF::Test::catch_test_delayfile(sdf_empty_delayfile, test);
  }

  SECTION("Case 2: From SDF Example") {

    DelayFileTester dft = DelayFileTester();
    auto test = dft.get_test_delayfile(test_delayfile_1);

    CHECK(test.num_cells() > 0);
    SDF::Test::catch_test_delayfile(test_delayfile_1, test);
  }
}

void SDF::Test::catch_test_delayfile(SDF::DelayFileView  wanted, SDF::DelayFile &test)
{

  SECTION("SDF File Header"){

    SECTION("SDF Version"){
      auto t_sdf_version = wanted.sdf_version;
      auto sdf_version = test.get_sdf_version();
      CHECK(t_sdf_version == sdf_version);
    }

    SECTION("Design name"){
      if(wanted.design_name) {
        auto t_design_name = wanted.design_name.value();
        CHECK(test.has_design_name());
        auto design_name = test.get_design_name();
        REQUIRE(design_name.has_value());
        CHECK(t_design_name == design_name.value());
      }else{
        CHECK_FALSE(test.has_design_name());
        CHECK_FALSE(test.get_design_name());
      }
    }

    SECTION("Date"){
      if(wanted.date) {
        auto t_date = wanted.date.value();
        CHECK(test.has_date());
        auto date = test.get_date();
        REQUIRE(date.has_value());
        CHECK(t_date == date.value());
      }else{
        CHECK_FALSE(test.has_date());
        CHECK_FALSE(test.get_date());
      }
    }

    SECTION("Vendor"){
      if(wanted.vendor) {
        auto t_vendor = wanted.vendor.value();
        CHECK(test.has_vendor());
        auto vendor = test.get_vendor();
        REQUIRE(vendor);
        CHECK(t_vendor == vendor.value());
      }else{
        CHECK_FALSE(test.has_vendor());
        CHECK_FALSE(test.get_vendor());
      }
    }

    SECTION("Program name"){
      if(wanted.program_name) {
        auto t_program_name = wanted.program_name.value();
        CHECK(test.has_program_name());
        auto program_name = test.get_program_name();
        REQUIRE(program_name);
        CHECK(t_program_name == program_name.value());
      }else{
        CHECK_FALSE(test.has_program_name());
        CHECK_FALSE(test.get_program_name());
      }
    }

    SECTION("Program version"){
      if(wanted.program_version) {
        auto t_program_version = wanted.program_version.value();
        CHECK(test.has_program_version());
        auto program_version = test.get_program_version();
        REQUIRE(program_version);
        CHECK(t_program_version == program_version.value());
      }else{
        CHECK_FALSE(test.has_program_version());
        CHECK_FALSE(test.get_program_version());
      }
    }

    SECTION("Process"){
      if(wanted.process) {
        auto t_process = wanted.process.value();
        CHECK(test.has_process());
        auto process = test.get_process();
        REQUIRE(process);
        CHECK(t_process == process.value());
      }else{
        CHECK_FALSE(test.has_process());
        CHECK_FALSE(test.get_process());
      }
    }

    SECTION("Hierarchy divider"){
      if(wanted.hierarchy_divider) {
        auto t_hierarchy_divider = wanted.hierarchy_divider.value();
        CHECK(test.has_hierarchy_divider());
        auto hierarchy_divider = test.get_hierarchy_divider();
        REQUIRE(hierarchy_divider);
        CHECK(t_hierarchy_divider == hierarchy_divider.value());
      }else{
        CHECK_FALSE(test.has_hierarchy_divider());
        CHECK_FALSE(test.get_hierarchy_divider());
      }
    }

    SECTION("Voltage"){
      if(wanted.voltage) {
        auto t_voltage = wanted.voltage.value();
        CHECK(test.has_voltage());
        auto voltage = test.get_voltage();
        REQUIRE(voltage);
        CHECK(t_voltage == voltage.value());
      }else{
        CHECK_FALSE(test.has_voltage());
        CHECK_FALSE(test.get_voltage());
      }
    }

    SECTION("Temperature"){
      if(wanted.temperature) {
        auto t_temperature = wanted.temperature.value();
        CHECK(test.has_temperature());
        auto temperature = test.get_temperature();
        REQUIRE(temperature);
        CHECK(t_temperature == temperature.value());
      }else{
        CHECK_FALSE(test.has_temperature());
        CHECK_FALSE(test.get_temperature());
      }
    }

    SECTION("Timescale"){
      if(wanted.timescale) {
        auto t_timescale = wanted.timescale.value();
        CHECK(test.has_timescale());
        auto timescale = test.get_timescale();
        REQUIRE(timescale);
        CHECK(t_timescale == timescale.value());
      }else{
        CHECK_FALSE(test.has_timescale());
        CHECK_FALSE(test.get_timescale());
      }
    }

    SECTION("TimeScale Values") {
      if(wanted.timescale) {
        auto ts_wanted = wanted.timescale.value();
        CHECK(test.has_timescale());
        auto ts = test.get_timescale();
        REQUIRE(ts);
        CHECK(ts.value().get_unit() == ts_wanted.get_unit());
        CHECK(ts.value().get_number() == ts_wanted.get_number());
      } else {
        CHECK_FALSE(test.has_timescale());
        CHECK_FALSE(test.get_timescale());
      }
    }
  }

  SECTION("Cells") {
    CHECK(wanted.cells.size() == test.num_cells());
    catch_test_cells(wanted.cells, test.get_cells());
  }
}

