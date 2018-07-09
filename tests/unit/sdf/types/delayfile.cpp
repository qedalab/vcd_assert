#include "./delayfile.hpp"

using namespace SDF::Test;


// ?? Should each cpp file call its own tests (thus not from delayfile.cpp downwards.)
//      or is it enough to call 'catch_test_delayfile' only?

// TODO : Should actually mock better, create stubs that cause only chosen sections to be tested; 
// tests should not repeat for every higher level that is run.

// TODO : Empty delayfile necessary?

TEST_CASE("SDF.Types.DelayFile") {

  SECTION("Case 1: Empty DelayFile example ") {

    DelayFileTester dft = DelayFileTester();
    auto delayfile_p = dft.get_test_delayfile(sdf_empty_delayfile);

    SDF::Test::catch_test_delayfile(delayfile_p, sdf_empty_delayfile);
  }

  SECTION("Case 2: From SDF Example") {
    //Write DelayFile file with the same structure as the SDF example
    DelayFileTester dft = DelayFileTester();
    auto delayfile_p = dft.get_test_delayfile(test_delayfile_1);

    // REQUIRE(delayfile_p.operator bool());
    // auto &delayfile = *delayfile_p;
    SDF::Test::catch_test_delayfile(delayfile_p, test_delayfile_1);
  }
}

void SDF::Test::catch_test_delayfile(SDF::DelayFile &delayfile, const SDF::DelayFileView &test)
{

  SECTION("SDF File Header"){

    // SECTION("SDF Version"){
    //   auto t_sdf_version = test.sdf_version.value();
    //   CHECK(delayfile.has_sdf_version());
    //   auto sdf_version = delayfile.get_sdf_version();
    //   REQUIRE(sdf_version);
    //   CHECK(t_sdf_version == sdf_version.value());
    // }

    SECTION("Design name"){
      if(test.design_name) {
        auto t_design_name = test.design_name.value();
        CHECK(delayfile.has_design_name());
        auto design_name = delayfile.get_design_name();
        REQUIRE(design_name);
        CHECK(t_design_name == design_name.value());
      }else{
        CHECK_FALSE(delayfile.has_design_name());
        CHECK_FALSE(delayfile.get_design_name());
      }
    }

    SECTION("Date"){
      if(test.date) {
        auto t_date = test.date.value();
        CHECK(delayfile.has_date());
        auto date = delayfile.get_date();
        REQUIRE(date);
        CHECK(t_date == date.value());
      }else{
        CHECK_FALSE(delayfile.has_date());
        CHECK_FALSE(delayfile.get_date());
      }
    }

    SECTION("Vendor"){
      if(test.vendor) {
        auto t_vendor = test.vendor.value();
        CHECK(delayfile.has_vendor());
        auto vendor = delayfile.get_vendor();
        REQUIRE(vendor);
        CHECK(t_vendor == vendor.value());
      }else{
        CHECK_FALSE(delayfile.has_vendor());
        CHECK_FALSE(delayfile.get_vendor());
      }
    }

    SECTION("Program name"){
      if(test.program_name) {
        auto t_program_name = test.program_name.value();
        CHECK(delayfile.has_program_name());
        auto program_name = delayfile.get_program_name();
        REQUIRE(program_name);
        CHECK(t_program_name == program_name.value());
      }else{
        CHECK_FALSE(delayfile.has_program_name());
        CHECK_FALSE(delayfile.get_program_name());
      }
    }

    SECTION("Program version"){
      if(test.program_version) {
        auto t_program_version = test.program_version.value();
        CHECK(delayfile.has_program_version());
        auto program_version = delayfile.get_program_version();
        REQUIRE(program_version);
        CHECK(t_program_version == program_version.value());
      }else{
        CHECK_FALSE(delayfile.has_program_version());
        CHECK_FALSE(delayfile.get_program_version());
      }
    }

    SECTION("Process"){
      if(test.process) {
        auto t_process = test.process.value();
        CHECK(delayfile.has_process());
        auto process = delayfile.get_process();
        REQUIRE(process);
        CHECK(t_process == process.value());
      }else{
        CHECK_FALSE(delayfile.has_process());
        CHECK_FALSE(delayfile.get_process());
      }
    }

    SECTION("Hierarchy divider"){
      if(test.hierarchy_divider) {
        auto t_hierarchy_divider = test.hierarchy_divider.value();
        CHECK(delayfile.has_hierarchy_divider());
        auto hierarchy_divider = delayfile.get_hierarchy_divider();
        REQUIRE(hierarchy_divider);
        CHECK(t_hierarchy_divider == hierarchy_divider.value());
      }else{
        CHECK_FALSE(delayfile.has_hierarchy_divider());
        CHECK_FALSE(delayfile.get_hierarchy_divider());
      }
    }

    SECTION("Voltage"){
      if(test.voltage) {
        auto t_voltage = test.voltage.value();
        CHECK(delayfile.has_voltage());
        auto voltage = delayfile.get_voltage();
        REQUIRE(voltage);
        CHECK(t_voltage == voltage.value());
      }else{
        CHECK_FALSE(delayfile.has_voltage());
        CHECK_FALSE(delayfile.get_voltage());
      }
    }

    SECTION("Temperature"){
      if(test.temperature) {
        auto t_temperature = test.temperature.value();
        CHECK(delayfile.has_temperature());
        auto temperature = delayfile.get_temperature();
        REQUIRE(temperature);
        CHECK(t_temperature == temperature.value());
      }else{
        CHECK_FALSE(delayfile.has_temperature());
        CHECK_FALSE(delayfile.get_temperature());
      }
    }

    SECTION("Timescale"){
      if(test.timescale) {
        auto t_timescale = test.timescale.value();
        CHECK(delayfile.has_timescale());
        auto timescale = delayfile.get_timescale();
        REQUIRE(timescale);
        CHECK(t_timescale == timescale.value());
      }else{
        CHECK_FALSE(delayfile.has_timescale());
        CHECK_FALSE(delayfile.get_timescale());
      }
    }

    SECTION("TimeScale Values") {
      if(test.timescale) {
        auto ts_test = test.timescale.value();
        CHECK(delayfile.has_timescale());
        auto ts = delayfile.get_timescale();
        REQUIRE(ts);
        CHECK(ts.value().get_unit() == ts_test.get_unit());
        CHECK(ts.value().get_number() == ts_test.get_number());
      } else {
        CHECK_FALSE(delayfile.has_timescale());
        CHECK_FALSE(delayfile.get_timescale());
      }
    }
  }

  SECTION("Cells") {
    CHECK(delayfile.num_cells() > 0);
    catch_test_cells(delayfile.get_cells(), test.cells);
  }
}

