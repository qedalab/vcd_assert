#include "./delayfile.hpp"

#include <catch2/catch.hpp>

using namespace SDF::Test;

void SDF::Test::read_in_test_delayfile(SDF::DelayFileReader &reader, TestDelayFile &test)
{
  
  auto t_sdf_version = test.sdf_version_;
  reader.sdf_version(t_sdf_version);
    
  if(test.design_name_) {
    auto t_design_name = test.design_name_.value();
    reader.design_name(t_design_name);
  }
  
  if(test.date_) {
    auto t_date = test.date_.value();
    reader.date(t_date);
  }
  
  if(test.vendor_) {
    auto t_vendor = test.vendor_.value();
    reader.vendor(t_vendor);
  }
  
  if(test.program_name_) {
    auto t_program_name = test.program_name_.value();
    reader.program_name(t_program_name);
  }
  
  if(test.program_version_) {
    auto t_program_version = test.program_version_.value();
    reader.program_version(t_program_version);
  }
  
  if(test.process_) {
    auto t_process = test.process_.value();
    reader.process(t_process);
  }
  
  if(test.hierarchy_divider_) {
    auto t_hierarchy_divider = test.hierarchy_divider_.value();
    reader.hierarchy_divider(t_hierarchy_divider);
  }
  
  if(test.voltage_) {
    auto t_voltage = test.voltage_.value();
    reader.voltage(t_voltage);
  }
  
  if(test.temperature_) {
    auto t_temperature = test.temperature_.value();
    reader.temperature(t_temperature);
  }
  
  if(test.timescale_) {
    auto t_timescale = test.timescale_.value();
    reader.timescale(t_timescale.get_number(), t_timescale.get_unit());
  }
  auto t_cells = test.cells_;
  reader.cells(t_cells);
  // for(auto& t_cell: t_cells ){
  //   read_in_test_cell(reader, t_cell);
  // }
}

// void SDF::Test::catch_test_delayfile(SDF::DelayFile &delayfile, TestDelayFile &test)
// {

//   SECTION("Design name"){
//     if(test.design_name_) {
//       auto t_design_name = test.design_name_.value();
//       CHECK(delayfile.has_design_name());
//       auto design_name = delayfile.get_design_name();
//       REQUIRE(design_name);
//       CHECK(t_design_name == design_name.value());
//     }else{
//       CHECK_FALSE(delayfile.has_design_name());
//       CHECK_FALSE(delayfile.get_design_name());
//     }
//   }

//   SECTION("Date"){
//     if(test.date_) {
//       auto t_date = test.date_.value();
//       CHECK(delayfile.has_date());
//       auto date = delayfile.get_date();
//       REQUIRE(date);
//       CHECK(t_date == date.value());
//     }else{
//       CHECK_FALSE(delayfile.has_date());
//       CHECK_FALSE(delayfile.get_date());
//     }
//   }

//   SECTION("Vendor"){
//     if(test.vendor_) {
//       auto t_vendor = test.vendor_.value();
//       CHECK(delayfile.has_vendor());
//       auto vendor = delayfile.get_vendor();
//       REQUIRE(vendor);
//       CHECK(t_vendor == vendor.value());
//     }else{
//       CHECK_FALSE(delayfile.has_vendor());
//       CHECK_FALSE(delayfile.get_vendor());
//     }
//   }

//   SECTION("Program name"){
//     if(test.program_name_) {
//       auto t_program_name = test.program_name_.value();
//       CHECK(delayfile.has_program_name());
//       auto program_name = delayfile.get_program_name();
//       REQUIRE(program_name);
//       CHECK(t_program_name == program_name.value());
//     }else{
//       CHECK_FALSE(delayfile.has_program_name());
//       CHECK_FALSE(delayfile.get_program_name());
//     }
//   }

//   SECTION("Program version"){
//     if(test.program_version_) {
//       auto t_program_version = test.program_version_.value();
//       CHECK(delayfile.has_program_version());
//       auto program_version = delayfile.get_program_version();
//       REQUIRE(program_version);
//       CHECK(t_program_version == program_version.value());
//     }else{
//       CHECK_FALSE(delayfile.has_program_version());
//       CHECK_FALSE(delayfile.get_program_version());
//     }
//   }

//   SECTION("Process"){
//     if(test.process_) {
//       auto t_process = test.process_.value();
//       CHECK(delayfile.has_process());
//       auto process = delayfile.get_process();
//       REQUIRE(process);
//       CHECK(t_process == process.value());
//     }else{
//       CHECK_FALSE(delayfile.has_process());
//       CHECK_FALSE(delayfile.get_process());
//     }
//   }

//   SECTION("Hierarchy divider"){
//     if(test.hierarchy_divider_) {
//       auto t_hierarchy_divider = test.hierarchy_divider_.value();
//       CHECK(delayfile.has_hierarchy_divider());
//       auto hierarchy_divider = delayfile.get_hierarchy_divider();
//       REQUIRE(hierarchy_divider);
//       CHECK(t_hierarchy_divider == hierarchy_divider.value());
//     }else{
//       CHECK_FALSE(delayfile.has_hierarchy_divider());
//       CHECK_FALSE(delayfile.get_hierarchy_divider());
//     }
//   }

//   SECTION("Voltage"){
//     if(test.voltage_) {
//       auto t_voltage = test.voltage_.value();
//       CHECK(delayfile.has_voltage());
//       auto voltage = delayfile.get_voltage();
//       REQUIRE(voltage);
//       CHECK(t_voltage == voltage.value());
//     }else{
//       CHECK_FALSE(delayfile.has_voltage());
//       CHECK_FALSE(delayfile.get_voltage());
//     }
//   }

//   SECTION("Temperature"){
//     if(test.temperature_) {
//       auto t_temperature = test.temperature_.value();
//       CHECK(delayfile.has_temperature());
//       auto temperature = delayfile.get_temperature();
//       REQUIRE(temperature);
//       CHECK(t_temperature == temperature.value());
//     }else{
//       CHECK_FALSE(delayfile.has_temperature());
//       CHECK_FALSE(delayfile.get_temperature());
//     }
//   }

//   SECTION("Timescale"){
//     if(test.timescale_) {
//       auto t_timescale = test.timescale_.value();
//       CHECK(delayfile.has_timescale());
//       auto timescale = delayfile.get_timescale();
//       REQUIRE(timescale);
//       CHECK(t_timescale == timescale.value());
//     }else{
//       CHECK_FALSE(delayfile.has_timescale());
//       CHECK_FALSE(delayfile.get_timescale());
//     }
//   }

//   SECTION("TimeScale Values") {
//     if(test.timescale_) {
//       auto ts_test = test.timescale_.value();
//       CHECK(delayfile.has_timescale());
//       auto ts = delayfile.get_timescale();
//       REQUIRE(ts);
//       CHECK(ts.value().get_unit() == ts_test.get_unit_());
//       CHECK(ts.value().get_number() == ts_test.get_number_());
//     } else {
//       CHECK_FALSE(delayfile.has_timescale());
//       CHECK_FALSE(delayfile.get_timescale());
//     }
//   }

//   SECTION("Cells") {
//     REQUIRE(delayfile.num_cells() > 0);
//     catch_test_cell(delayfile, delayfile.get_cells(), test.root_cell.value());
//   }
// }
