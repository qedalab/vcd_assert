#include "vcd/actions/time_scale.hpp"

#include "parse/test/parse.hpp"
#include "vcd/grammar/commands.hpp"

#include <catch2/catch.hpp>
#include <array>

using namespace VCD;

struct TimeScaleTest {
  std::string_view str;
  TimeNumber number;
  TimeUnit unit;
};

std::array<TimeScaleTest, 6> time_scale_tests{
    TimeScaleTest{"$timescale 1\n s $end", TimeNumber::_1, TimeUnit::s},
    TimeScaleTest{"$timescale  10 ms $end", TimeNumber::_10, TimeUnit::ms},
    TimeScaleTest{"$timescale 100 us $end", TimeNumber::_100, TimeUnit::us},
    TimeScaleTest{"$timescale 1ns $end", TimeNumber::_1, TimeUnit::ns},
    TimeScaleTest{"$timescale 10  ps  $end", TimeNumber::_10, TimeUnit::ps},
    TimeScaleTest{"$timescale 100 fs $end", TimeNumber::_100, TimeUnit::fs},
};

TEST_CASE("VCD.Events.TimeScale", "[VCD][Events][TimeScale]")
{
  using Parse::Test::require_parse;

  TimeScaleView event{};

  for (auto &&test : time_scale_tests) {
    SECTION(std::string(test.str))
    {
      require_parse<Grammar::timescale_command, Actions::TimeScaleAction>(
          test.str, event);

      CHECK(event.unit == test.unit);
      CHECK(event.number == test.number);
    }
  }
}
