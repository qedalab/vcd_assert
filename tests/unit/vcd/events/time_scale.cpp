#include "vcd/events/time_scale.hpp"
#include "vcd/grammar/commands.hpp"
#include "parse/test/parse.hpp"

#include <catch2/catch.hpp>

using namespace VCD;

constexpr char timescale_str[] = "$timescale 10 ns $end";

TEST_CASE("VCD.Events.TimeScale", "[VCD][Events][TimeScale]")
{
  using Parse::Test::require_parse;

  TimeScaleView event{};
  require_parse<Grammar::timescale_command, TimeScaleAction>(timescale_str, event);

  CHECK(event.unit == TimeUnit::ns);
  CHECK(event.number == TimeNumber::_10);
}
