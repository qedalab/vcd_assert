#include "vcd/events/var.hpp"
#include "vcd/grammar/commands.hpp"

#include "parse/test/parse.hpp"


#include <catch2/catch.hpp>
#include <string_view>

constexpr char var_str[] = "$var\n  integer 32 (2 index\n$end";

using namespace VCD;

TEST_CASE("VCD.Events.Var", "[VCD][Events][Var]") {
  using Parse::Test::require_parse;

  VarEvent event;
  require_parse<Grammar::var_command, VarAction>(var_str, event);

  CHECK(event.size == 32);
  CHECK(event.type == VarType::integer);
  CHECK(event.reference == "index");
  CHECK(event.id_code == "(2");
}
