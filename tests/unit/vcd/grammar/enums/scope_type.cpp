#include "vcd/grammar/enums/scope_type.h"
#include "vcd/types/enums.hpp"

#include "parse/test/match.h"

#include <catch.hpp>

using namespace Parse::Test;
using namespace VCD::Grammar;
using VCD::ScopeType;

constexpr char begin_str[] = "begin";
constexpr char fork_str[] = "fork";
constexpr char function_str[] = "function";
constexpr char module_str[] = "module";
constexpr char task_str[] = "task";

TEST_CASE("VCD.Grammar.Enums.ScopeType", "[VCD][Grammar][Enums][ScopeType]") {
  SECTION("Individual") {
    CHECK(match_value_exactly<scope_begin>(begin_str, ScopeType::begin));
    CHECK(match_value_exactly<scope_fork>(fork_str, ScopeType::fork));
    CHECK(match_value_exactly<scope_function>(function_str, ScopeType::function));
    CHECK(match_value_exactly<scope_module>(module_str, ScopeType::module));
    CHECK(match_value_exactly<scope_task>(task_str, ScopeType::task));
  }

  SECTION("Together") {
    CHECK(match_value_exactly<scope_type>(begin_str, ScopeType::begin));
    CHECK(match_value_exactly<scope_type>(fork_str, ScopeType::fork));
    CHECK(match_value_exactly<scope_type>(function_str, ScopeType::function));
    CHECK(match_value_exactly<scope_type>(module_str, ScopeType::module));
    CHECK(match_value_exactly<scope_type>(task_str, ScopeType::task));

    CHECK(scope_type::error() != nullptr);
  }
}
