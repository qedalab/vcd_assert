#ifndef TEST_SDF_TYPES_TIMING_HPP
#define TEST_SDF_TYPES_TIMING_HPP

#include <catch2/catch.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/timing.hpp>
#include <sdf/serialize/base.hpp>
#include <sdf/serialize/enum/base.hpp>
#include <sdf/serialize/enum/timing.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <range/v3/utility/iterator.hpp>

#include <fmt/format.h>
#include <string>
#include <string_view>

#include "parse/util/static_string.hpp"

namespace SDF::Test {

using namespace Parse::Util;

// constexpr auto posedge_prepend(const sstr::string input){
// }

// constexpr auto negedge_prepend(const sstr::string input){
// }

// constexpr auto enable_append(const sstr::string input){
// }

constexpr auto port_1_str = static_string("CP");
inline const Node port_1{NodeType::port, "CP"};

constexpr auto port_2_str = static_string("D");
inline const Node port_2{NodeType::port, "D"};

constexpr auto port_3_str = static_string("E");
inline const Node port_3{NodeType::port, "E"};

constexpr auto port_4_str = static_string("F");
inline const Node port_4{NodeType::port, "F"};

constexpr auto node_1_str = static_string("D_ENABLE");
inline const Node node_1{NodeType::port, "D_ENABLE"};

constexpr auto node_2_str = static_string("E_ENABLE");
inline const Node node_2{NodeType::port, "E_ENABLE"};

constexpr auto node_3_str = static_string("F_ENABLE");
inline const Node node_3{NodeType::port, "F_ENABLE"};

constexpr auto port_1_posedge_str = static_string("(posedge CP)");
inline const Node port_1_posedge{NodeType::port, "CP", EdgeType::posedge};

constexpr auto port_2_posedge_str = static_string("(posedge D)");
inline const Node port_2_posedge{NodeType::port, "D", EdgeType::posedge};

constexpr auto port_3_posedge_str = static_string("(posedge E)");
inline const Node port_3_posedge{NodeType::port, "E", EdgeType::posedge};

constexpr auto port_4_posedge_str = static_string("(posedge F)");
inline const Node port_4_posedge{NodeType::port, "F", EdgeType::posedge};

constexpr auto node_1_posedge_str = static_string("(posedge D_ENABLE)");
inline const Node node_1_posedge{NodeType::port, "D_ENABLE", EdgeType::posedge};

constexpr auto node_2_posedge_str = static_string("(posedge E_ENABLE)");
inline const Node node_2_posedge{NodeType::port, "E_ENABLE", EdgeType::posedge};

constexpr auto node_3_posedge_str = static_string("(posedge E_ENABLE)");
inline const Node node_3_posedge{NodeType::port, "E_ENABLE", EdgeType::posedge};

constexpr auto port_1_negedge_str = static_string("(negedge CP)");
inline const Node port_1_negedge{NodeType::port, "CP", EdgeType::negedge};

constexpr auto port_2_negedge_str = static_string("(negedge D)");
inline const Node port_2_negedge{NodeType::port, "D", EdgeType::negedge};

constexpr auto port_3_negedge_str = static_string("(negedge E)");
inline const Node port_3_negedge{NodeType::port, "E", EdgeType::negedge};

constexpr auto port_4_negedge_str = static_string("(negedge F)");
inline const Node port_4_negedge{NodeType::port, "F", EdgeType::negedge};



inline const Node node_complex_1{
  NodeType::port,
  port_1.basename_identifier,
  {},
  HierarchicalIdentifier{
    HChar::slash, 
    {"root"}
  }
};

inline const Node node_complex_2{
  NodeType::port,
  "D_ENABLE",
  {},
  HierarchicalIdentifier{
    HChar::slash, 
    {"root", "scope"}
  }
};

inline const Node node_complex_3{
  NodeType::port,
  port_3.basename_identifier,
  {},
  HierarchicalIdentifier{
    HChar::dot,
    {"root", "scope"}
  }
};

inline const Node node_complex_4{
  NodeType::port,
  port_4.basename_identifier,
  {},
  HierarchicalIdentifier{
    HChar::slash, 
    {"root", "scope", "counter"}
  },
  4
};

// void read_in_test_timing(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_timing(SDF::DelayFile &header, SDF::Cell &scope, TestCell &test);
void catch_test_node(SDF::Node wanted, SDF::Node test);

} // namespace SDF::Test

#endif // TEST_SDF_TYPES_TIMING_HPP
