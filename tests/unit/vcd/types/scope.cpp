#include "vcd/types/scope.hpp"

#include "vcd/types/header_reader.hpp"
#include "./variable.hpp"
#include "./scope.hpp"

#include <catch.hpp>
#include <string>

using namespace VCD::Test;
using namespace std::literals::string_literals;

void VCD::Test::read_in_test_scope(VCD::HeaderReader &reader, TestScope &test)
{
  reader.scope(test.type, test.identifier);

  for(auto& scope: test.scopes) {
    read_in_test_scope(reader, scope);
  }

  for(auto& var: test.variables) {
    read_in_test_var(reader, var);
  }

  reader.upscope();
}

void VCD::Test::catch_test_scope(VCD::Header &header, VCD::Scope &scope,
                                 TestScope &test)
{
  CHECK(scope.get_scope_type() == test.type);
  CHECK(scope.get_identifier() == test.identifier);

  CHECK(scope.num_variables() == test.variables.size());
  CHECK(scope.num_scopes() == test.scopes.size());

  for(auto &inner_test_scope: test.scopes) {
    SECTION("Scope: "s + inner_test_scope.identifier) {
      REQUIRE(scope.contains_scope(inner_test_scope.identifier));
      auto scope_index = scope.get_scope_index(inner_test_scope.identifier);
      REQUIRE(scope_index < header.num_scopes());
      auto &inner_scope = header.get_scope(scope_index);
      catch_test_scope(header, inner_scope, inner_test_scope);
    }
  }

  for(auto &test_var: test.variables) {
    SECTION("Var: "s + test_var.ref) {
      REQUIRE(scope.contains_variable(test_var.ref));
      auto var_index = scope.get_variable_index(test_var.ref);
      REQUIRE(var_index < header.num_variables());
      auto &var = header.get_var(var_index);
      catch_test_var(header, scope, var, test_var);
    }
  }
}
