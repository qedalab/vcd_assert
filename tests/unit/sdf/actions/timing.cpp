
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

TEST_CASE("SDF.Actions.EdgeTypeAction", "[SDF][Actions][EdgeTypeAction]") {
  SECTION("posedge"){
    EdgeType test{};
    EdgeType wanted{EdgeType::posedge};
    require_parse<Grammar::edge_identifier, Actions::EdgeTypeAction>("posedge", test);
    CAPTURE(test);
    REQUIRE(wanted == test);

  }  
}

TEST_CASE("SDF.Actions.NodeAction", "[SDF][Actions][NodeAction]") {

  SECTION(fmt::format("ScalarPort : \"{}\"", node_1_sv)) {

    Node test{};
    Node wanted{NodeType::unspecified, std::string(node_1_str.c_str())};
    INFO("Parsing " << node_1_sv);
    require_parse<Grammar::scalar_node, Actions::NodeAction>(node_1_sv, test);
    CAPTURE(test.type);
    CAPTURE(test.basename_identifier);
    catch_test_node(wanted,test);
  }


  SECTION(fmt::format("BusPort : \"{}[3:0]\"", node_1_sv)) {

    std::string test_str = fmt::format("{}[3:0]",node_1_sv);
    Node test{};
    Node wanted{NodeType::unspecified,  std::string(node_1_str.c_str()), {}, {}, 0, 3};
    INFO("Parsing " << test_str);
    require_parse<Grammar::bus_node, Actions::NodeAction>(test_str, test);
    CAPTURE(test.type);
    CAPTURE(test.basename_identifier);
    if(test.start.has_value())
      CAPTURE(test.start.value());
    if(test.end.has_value())
      CAPTURE(test.end.value());
    catch_test_node(wanted,test);
  }
}

TEST_CASE("SDF.Actions.PortAction", "[SDF][Actions][PortAction") {

  SECTION(fmt::format("ScalarPort : \"{}\"", port_1_sv)) {

    Node test{};
    Node wanted{NodeType::port, std::string(port_1_str.c_str())};
    INFO("Parsing " << port_1_sv);
    require_parse<Grammar::port, Actions::PortAction>(port_1_sv, test);
    CAPTURE(test.type);
    CAPTURE(test.basename_identifier);
    CAPTURE(test.hierarchical_identifier);
    CAPTURE(test.start);
    CAPTURE(test.end);
    REQUIRE(wanted.start == test.start);
    REQUIRE(wanted.end == test.end);
    // catch_test_node(wanted,test);
  }


  SECTION(fmt::format("BusPort : \"{}[3:0]\"", port_1_sv)) {

    std::string test_str = fmt::format("{}[3:0]",port_1_sv);
    Node test{};
    Node wanted{NodeType::port,  std::string(port_1_str.c_str()), {}, {}, 0, 3};
    INFO("Parsing " << test_str);
    require_parse<Grammar::port, Actions::PortAction>(test_str, test);
    CAPTURE(test.type);
    CAPTURE(test.basename_identifier);
    CAPTURE(test.hierarchical_identifier);
    if(test.start.has_value())
      CAPTURE(test.start.value());
    if(test.end.has_value())
      CAPTURE(test.end.value());
    catch_test_node(wanted,test);
    // catch_test_node(wanted,test);
  }
}

TEST_CASE("SDF.Actions.PortInstanceAction", "[SDF][Actions][PortInstance]") {

  SECTION(fmt::format("ScalarPort : \"{}\"", port_1_sv)) {

    Node test{};
    Node wanted{NodeType::port, std::string(port_1_str.c_str())};
    INFO("Parsing " << port_1_sv);
    require_parse<Grammar::port_instance, Actions::PortInstanceAction>(port_1_sv, test);
    CAPTURE(test.type);
    CAPTURE(test.basename_identifier);
    CAPTURE(test.hierarchical_identifier);
    catch_test_node(wanted,test);
  }


  SECTION(fmt::format("BusPort : \"{}[3:0]\"", port_1_sv)) {

    Node test{};
    Node wanted{NodeType::port, std::string(port_1_str.c_str()), {}, {}, 0, 3};
    INFO("Parsing " << fmt::format("{}[3:0]",port_1_str));
    require_parse<Grammar::port_instance, Actions::PortInstanceAction>(fmt::format("{}[3:0]",port_1_str), test);
    CAPTURE(test.type);
    CAPTURE(test.basename_identifier);
    CAPTURE(test.hierarchical_identifier);
    catch_test_node(wanted,test);
  }
}



TEST_CASE("SDF.Actions.PortSpecAction", "[SDF][Actions][PortSpec]") {

  SECTION(fmt::format("ScalarPort : \"{}\"", port_1_sv)) {

    Node test{};
    Node wanted{NodeType::port, std::string(port_1_str.c_str())};
    INFO("Parsing " << port_1_sv);
    require_parse<Grammar::port_spec, Actions::PortSpecAction>(port_1_sv, test);
    CAPTURE(test.type);
    CAPTURE(test.basename_identifier);
    CAPTURE(test.hierarchical_identifier);
    catch_test_node(wanted,test);
  }


  SECTION(fmt::format("BusPort : \"{}[3:0]\"", port_1_sv)) {

    Node test{};
    Node wanted{NodeType::port, std::string(port_1_str.c_str()), {}, {}, 0, 3};
    INFO("Parsing " << fmt::format("{}[3:0]",port_1_str));
    require_parse<Grammar::port_instance, Actions::PortInstanceAction>(fmt::format("{}[3:0]",port_1_str), test);
    CAPTURE(test.type);
    CAPTURE(test.basename_identifier);
    CAPTURE(test.hierarchical_identifier);
    catch_test_node(wanted,test);
  }
}
