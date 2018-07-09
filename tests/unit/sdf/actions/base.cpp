#include "parse/test/parse.hpp"

#include "sdf/actions/time_scale.hpp"

#include "sdf/grammar/header.hpp"

#include <catch2/catch.hpp>
#include <fmt/format.h>

using namespace SDF;
using Parse::Test::require_parse;

static auto constexpr hchar_str = ".";
constexpr char hierarchicalidentifier_str[] = "root/DUT/test/DFF";
constexpr char identifier_str[] = "DFF";
constexpr char qstring_str[] = "\"This is a test qstring\"";

TEST_CASE("SDF.Actions.QString", "[SDF][Actions][QString]")
{
  std::string test{};
  std::string wanted{qstring_str};
  require_parse<Grammar::qstring, Actions::QStringAction>(qstring_str,
  test);

  SECTION("QStringAction"){
    REQUIRE(test == wanted);
  }
}

TEST_CASE("SDF.Actions.HChar", "[SDF][Actions][HChar]") {
  SECTION("HCharAction") {

    HChar test{};
    require_parse<Grammar::hchar, Actions::HCharAction>(hchar_str, test);

    REQUIRE(test == HChar::dot);
    REQUIRE_FALSE(test == HChar::slash);
  }
}

TEST_CASE("SDF.Actions.Identifier", "[SDF][Actions][Identifier]") {

    Identifier test{};
    Identifier wanted{"DFF"};
    require_parse<Grammar::identifier, Actions::IdentifierAction>(
        identifier_str, test);

  SECTION(fmt::format("IdentifierAction : {}", test)) {
    REQUIRE(test == wanted);
  }
}

TEST_CASE("SDF.Actions.HierarchicalIdentifier",
          "[SDF][Actions][HierarchicalIdentifier]"){

    HierarchicalIdentifier test{};
    std::vector<std::string> wanted{"root", "DUT", "test", "DFF"};
    require_parse<Grammar::hierarchical_identifier,
                  Actions::HierarchicalIdentifierAction>(
        hierarchicalidentifier_str, test);
  SECTION("HierarchicalIdentifierAction") {

    REQUIRE(test.value == wanted);
    REQUIRE(test.sep == HChar::slash);
    REQUIRE_FALSE(test.sep == HChar::dot);
  }
}
