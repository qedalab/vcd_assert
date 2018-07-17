#ifndef TEST_SDF_TYPES_DELAYFILE_HPP
#define TEST_SDF_TYPES_DELAYFILE_HPP

#include <sdf/types/base.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/delayfile.hpp>

#include "sdf/types/delayfile_reader.hpp"
#include "sdf/types/delayfile.hpp"
#include "./cell.hpp"

#include <catch2/catch.hpp>


namespace SDF::Test {

using namespace SDF;

inline const DelayFileView sdf_empty_delayfile {};

auto constexpr basic_example_delayfile = 
R"####((DELAYFILE 
  (SDFVERSION "4.0")
  (DESIGN "system")
  (DATE "Saturday September 30 08:30:33 PST 1990")
  (VENDOR "Yosemite Semiconductor")
  (PROGRAM "delay_calc")
  (VERSION "1.5")
  (DIVIDER /)
  (VOLTAGE 5.5:5.0:4.5)
  (PROCESS "worst")
  (TEMPERATURE 55:85:125)
  (TIMESCALE 1ns)
  (CELL 
    (CELLTYPE "DFF")
    (INSTANCE *)
    (TIMINGCHECK 
      (HOLD D (COND D_ENABLE (posedge CP)) (1:1:1))
      (HOLD E (posedge CP) (1:1:1))
      (HOLD F (COND ~F_ENABLE (negedge CP)) (1:1:1))
    )
  )
)
)####";

inline const DelayFileView test_delayfile_1 {
  "4.0",                                             //std::string sdf_version;
  "system",                                          //std::optional<std::string> design_name;
  "Saturday September 30 08:30:33 PST 1990",         //std::optional<std::string> date;
  "Yosemite Semiconductor",                          //std::optional<std::string> vendor;
  "delay_calc",                                      //std::optional<std::string> program_name;
  "1.5",                                             //std::optional<std::string> program_version;
  "worst",                                           //std::optional<std::string> process;
  HChar::slash,                                      //std::optional<SDF::HChar> hierarchy_divider;
  Triple{5.5,5.0,4.5},                               //std::optional<SDF::Triple> voltage;
  Triple{55.0,85.0,125.0},                           //std::optional<SDF::Triple> temperature;
  TimeScale {TimeScaleNumber::_1, TimeScaleUnit::ns},//std::optional<SDF::TimeScale> timescale;
  {test_cell_1}                                      //std::vector<SDF::Cell> cells;
};

void catch_test_delayfile(DelayFileView wanted, DelayFile &test);

}

#endif // TEST_SDF_TYPES_DELAYFILE_HPP
