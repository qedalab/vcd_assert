#include "./scope.hpp"

#include "./variable.hpp"

#include <catch2/catch.hpp>

void VCD::Test::catch_test_scope(const VCD::Header &header, const VCD::Scope &scope,
                                 TestScope &test)
{
  CHECK(scope.get_scope_type() == test.type);
  CHECK(scope.get_identifier() == test.identifier);

  CHECK(scope.num_variables() == test.variables.size());
  CHECK(scope.num_scopes() == test.scopes.size());

  for (auto &inner_test_scope : test.scopes) {
    SECTION(std::string("Scope: ") + inner_test_scope.identifier) {
      REQUIRE(scope.contains_scope(inner_test_scope.identifier));
      auto scope_index = scope.get_scope_index(inner_test_scope.identifier);
      REQUIRE(scope_index < header.num_scopes());
      auto &inner_scope = header.get_scope(scope_index);
      catch_test_scope(header, inner_scope, inner_test_scope);
    }
  }

  for (auto &test_var : test.variables) {
    SECTION(std::string("Var: ") + test_var.ref) {
      REQUIRE(scope.contains_variable(test_var.ref));
      auto var_index = scope.get_variable_index(test_var.ref);
      REQUIRE(var_index < header.num_variables());
      auto &var = header.get_var(var_index);
      catch_test_var(header, var, test_var);
    }
  }
}
