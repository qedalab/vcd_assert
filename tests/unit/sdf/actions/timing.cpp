
#include "../types/timing.hpp"
#include <parse/test/parse.hpp>

#include <sdf/actions/timing.hpp>
#include <sdf/grammar/timing.hpp>

#include <variant>
#include <catch2/catch.hpp>
#include <fmt/format.h>

using namespace SDF;
using namespace SDF::Test;
using Parse::Test::require_parse;

/* TODO
struct ScalarNodeAction : multi_dispatch<
struct TimingCheckCondAction : multi_dispatch<
struct PortSpecAction : single_dispatch<
struct PortCheckAction : single_dispatch<
struct HoldPortStorage  {
struct HoldPortTupleAction : single_dispatch<
struct HoldPortAction : single_dispatch<
struct HoldTimingCheckAction : multi_dispatch<
struct TimingCheckAction : single_dispatch<
struct TimingCheckArrayAction : single_dispatch<
*/

TEST_CASE("SDF.Actions.Node", "[SDF][Actions][Node]") {

  SECTION(fmt::format("ScalarPort : \"{}\"", port_1_sv)) {

    Node test{};
    Node wanted{NodeType::port, std::string(port_1_str)};
    INFO("Parsing " << port_1_sv);
    require_parse<Grammar::port_instance, Actions::PortInstanceAction>(port_1_sv, test);
    CAPTURE(test.basename_identifier);
    catch_test_node(wanted,test);
  }


  SECTION(fmt::format("BusPort : \"{}\"", port_1_sv)) {

    Node test{};
    Node wanted{NodeType::port, std::string(port_1_str)};
    INFO("Parsing " << port_1_sv);
    require_parse<Grammar::port_instance, Actions::PortInstanceAction>(port_1_sv, test);
    CAPTURE(test.basename_identifier);
    catch_test_node(wanted,test);
  }
}


