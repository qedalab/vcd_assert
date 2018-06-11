#include "vcd/events/scope.hpp"
#include "vcd/grammar/commands.hpp"
#include "parse/test/parse.hpp"

#include <catch/catch.hpp>

using namespace VCD;

constexpr char scope_str[] = "$scope\n    module top\n$end";

TEST_CASE("VCD.Events.Scope", "[VCD][Events][Scope]")
{
  using Parse::Test::require_parse;

  ScopeEvent event{};
  require_parse<Grammar::scope_command, ScopeAction>(scope_str, event);

  CHECK(event.identifier == "top");
  CHECK(event.type == ScopeType::module);
}

