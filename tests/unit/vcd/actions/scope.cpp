#include "vcd/actions/scope.hpp"
#include "vcd/grammar/commands.hpp"
#include "parse/test/parse.hpp"

#include <catch2/catch.hpp>

using namespace VCD;

constexpr char scope_str[] = "$scope\n    module top\n$end";

TEST_CASE("VCD.Events.Scope", "[VCD][Events][Scope]")
{
  using Parse::Test::require_parse;

  ScopeDataView event{};
  require_parse<Grammar::scope_command, Actions::ScopeAction>(scope_str, event);

  CHECK(event.identifier == "top");
  CHECK(event.type == ScopeType::module);
}

