#include "vcd/grammar/enums/time.hpp"
#include "vcd/types/enums.hpp"

#include "parse/test/match.h"

#include <catch2/catch.hpp>

using namespace Parse::Test;
using namespace VCD::Grammar;
using VCD::TimeUnit;

constexpr char s_str[] = "s";
constexpr char ms_str[] = "ms";
constexpr char us_str[] = "us";
constexpr char ns_str[] = "ns";
constexpr char ps_str[] = "ps";
constexpr char fs_str[] = "fs";

TEST_CASE("VCD.Grammar.Enums.Time", "[VCD][Grammar][Enums][Time]") {
  SECTION("Individual") {
    CHECK(match_value_exactly<time_s>(s_str, TimeUnit::s));
    CHECK(match_value_exactly<time_ms>(ms_str, TimeUnit::ms));
    CHECK(match_value_exactly<time_us>(us_str, TimeUnit::us));
    CHECK(match_value_exactly<time_ns>(ns_str, TimeUnit::ns));
    CHECK(match_value_exactly<time_ps>(ps_str, TimeUnit::ps));
    CHECK(match_value_exactly<time_fs>(fs_str, TimeUnit::fs));
  }

  SECTION("Together") {
    CHECK(match_value_exactly<time_unit>(ms_str, TimeUnit::ms));
    CHECK(match_value_exactly<time_unit>(us_str, TimeUnit::us));
    CHECK(match_value_exactly<time_unit>(ns_str, TimeUnit::ns));
    CHECK(match_value_exactly<time_unit>(ps_str, TimeUnit::ps));
    CHECK(match_value_exactly<time_unit>(fs_str, TimeUnit::fs));

    CHECK(time_unit::error() != nullptr);
  }
}
