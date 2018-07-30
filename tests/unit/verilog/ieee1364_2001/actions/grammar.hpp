#ifndef UNIT_VERILOG_TEST_DESIGN_HPP
#define UNIT_VERILOG_TEST_DESIGN_HPP

#include "verilog/types/design.hpp"

namespace Verilog::Test{
namespace Verilog::IEEE1364_2001{

using namespace Verilog;

  class CatchDesign : public Test::DesignTester
  { 
    void test();
  }

}

// void catch_test_design_via_reader(*design_p, dro_example);

}