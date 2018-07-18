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

#include <ak_toolkit/static_string.hpp>
namespace sstr = ak_toolkit::static_str;


namespace SDF::Test {


// constexpr auto posedge_prepend(const sstr::string input){
// }

// constexpr auto negedge_prepend(const sstr::string input){
// }

// constexpr auto enable_append(const sstr::string input){
// }

constexpr auto port_1_str = sstr::literal("CP");
constexpr std::string_view port_1_sv(port_1_str, std::size(port_1_str));
inline const Node port_1{NodeType::port, "CP"};

constexpr auto port_2_str = sstr::literal("D");
constexpr std::string_view port_2_sv(port_2_str, std::size(port_2_str));
inline const Node port_2{NodeType::port, "D"};

constexpr auto port_3_str = sstr::literal("E");
constexpr std::string_view port_3_sv(port_3_str, std::size(port_3_str));
inline const Node port_3{NodeType::port, "E"};

constexpr auto port_4_str = sstr::literal("F");
constexpr std::string_view port_4_sv(port_4_str, std::size(port_4_str));
inline const Node port_4{NodeType::port, "F"};

constexpr auto node_1_str = sstr::literal("D_ENABLE");
constexpr std::string_view node_1_sv(node_1_str, std::size(node_1_str));
inline const Node node_1{NodeType::port, "D_ENABLE"};

constexpr auto node_2_str = sstr::literal("E_ENABLE");
constexpr std::string_view node_2_sv(node_2_str, std::size(node_2_str));
inline const Node node_2{NodeType::port, "E_ENABLE"};

constexpr auto node_3_str = sstr::literal("F_ENABLE");
constexpr std::string_view node_3_sv(node_3_str, std::size(node_3_str));
inline const Node node_3{NodeType::port, "F_ENABLE"};

constexpr auto port_1_posedge_str = sstr::literal("(posedge CP)");
constexpr std::string_view port_1_posedge_sv(port_1_posedge_str,
                                             std::size(port_1_posedge_str));
inline const Node port_1_posedge{NodeType::port, "CP", EdgeType::posedge};

constexpr auto port_2_posedge_str = sstr::literal("(posedge D)");
constexpr std::string_view port_2_posedge_sv(port_2_posedge_str,
                                             std::size(port_2_posedge_str));
inline const Node port_2_posedge{NodeType::port, "D", EdgeType::posedge};

constexpr auto port_3_posedge_str = sstr::literal("(posedge E)");
constexpr std::string_view port_3_posedge_sv(port_3_posedge_str,
                                             std::size(port_3_posedge_str));
inline const Node port_3_posedge{NodeType::port, "E", EdgeType::posedge};

constexpr auto port_4_posedge_str = sstr::literal("(posedge F)");
constexpr std::string_view port_4_posedge_sv(port_4_posedge_str,
                                             std::size(port_4_posedge_str));
inline const Node port_4_posedge{NodeType::port, "F", EdgeType::posedge};

constexpr auto node_1_posedge_str = sstr::literal("(posedge D_ENABLE)");
constexpr std::string_view node_1_posedge_sv(node_1_posedge_str,
                                             std::size(node_1_posedge_str));
inline const Node node_1_posedge{NodeType::port, "D_ENABLE", EdgeType::posedge};

constexpr auto node_2_posedge_str = sstr::literal("(posedge E_ENABLE)");
constexpr std::string_view node_2_posedge_sv(node_2_posedge_str,
                                             std::size(node_2_posedge_str));
inline const Node node_2_posedge{NodeType::port, "E_ENABLE", EdgeType::posedge};

constexpr auto node_3_posedge_str = sstr::literal("(posedge E_ENABLE)");
constexpr std::string_view node_3_posedge_sv(node_3_posedge_str,
                                             std::size(node_3_posedge_str));
inline const Node node_3_posedge{NodeType::port, "E_ENABLE", EdgeType::posedge};

constexpr auto port_1_negedge_str = sstr::literal("(negedge CP)");
constexpr std::string_view port_1_negedge_sv(port_1_negedge_str,
                                             std::size(port_1_negedge_str));
inline const Node port_1_negedge{NodeType::port, "CP", EdgeType::negedge};

constexpr auto port_2_negedge_str = sstr::literal("(negedge D)");
constexpr std::string_view port_2_negedge_sv(port_2_negedge_str,
                                             std::size(port_2_negedge_str));
inline const Node port_2_negedge{NodeType::port, "D", EdgeType::negedge};

constexpr auto port_3_negedge_str = sstr::literal("(negedge E)");
constexpr std::string_view port_3_negedge_sv(port_3_negedge_str,
                                             std::size(port_3_negedge_str));
inline const Node port_3_negedge{NodeType::port, "E", EdgeType::negedge};

constexpr auto port_4_negedge_str = sstr::literal("(negedge F)");
constexpr std::string_view port_4_negedge_sv(port_4_negedge_str,
                                             std::size(port_4_negedge_str));
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
