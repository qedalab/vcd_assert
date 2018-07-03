#include "parse/test/parse.hpp"

#include "sdf/actions/time_scale.hpp"

#include "sdf/grammar/header.hpp"

#include <catch2/catch.hpp>

using namespace SDF;

constexpr char timescale_str[] = "(TIMESCALE 10ns)";

TEST_CASE("SDF.Actions.TimeScale", "[SDF][Actions][TimeScale]")
{
  using Parse::Test::require_parse;

  TimeScaleView event{};
  require_parse<Grammar::timescale, Actions::TimeScaleAction>(timescale_str, event);

  CHECK(event.unit == TimeScaleUnit::ns);
  CHECK(event.number == TimeScaleNumber::_10);
}
