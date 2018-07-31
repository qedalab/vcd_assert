#include "vcd_assert/edge_type.hpp"

#include "vcd/serialize/enums.hpp"

#include <catch2/catch.hpp>
#include <fmt/format.h>

using namespace VCDAssert;

TEST_CASE("VCDAssert::edge_type")
{
  constexpr auto one = VCD::Value::one;
  constexpr auto x = VCD::Value::x;
  constexpr auto z = VCD::Value::z;
  constexpr auto zero = VCD::Value::zero;

  constexpr auto PosEdge = EdgeType::PosEdge;
  constexpr auto NegEdge = EdgeType::NegEdge;
  constexpr auto NoEdge = EdgeType::NoEdge;

  constexpr auto Edge = EdgeType::Edge;

  constexpr auto _01 = EdgeType::_01;
  constexpr auto _0z = EdgeType::_0z;
  constexpr auto _z1 = EdgeType::_z1;
  constexpr auto _z0 = EdgeType::_z0;
  constexpr auto _1z = EdgeType::_1z;
  constexpr auto _10 = EdgeType::_10;

  SECTION("edge_type_to_string") {
    CHECK(edge_type_to_string(NoEdge) == "NoEdge");
    CHECK(edge_type_to_string(PosEdge) == "PosEdge");
    CHECK(edge_type_to_string(NegEdge) == "NegEdge");
    CHECK(edge_type_to_string(Edge) == "Edge");
    CHECK(edge_type_to_string(_01) == "01");
    CHECK(edge_type_to_string(_0z) == "0z");
    CHECK(edge_type_to_string(_z1) == "z1");
    CHECK(edge_type_to_string(_z0) == "z0");
    CHECK(edge_type_to_string(_1z) == "1z");
    CHECK(edge_type_to_string(_10) == "10");
  }

  SECTION("get_edge_type")
  {
    CHECK(get_edge_type(zero, zero) == NoEdge);
    CHECK(get_edge_type(one, zero) == NegEdge);
    CHECK(get_edge_type(x, zero) == NegEdge);
    CHECK(get_edge_type(z, zero) == NegEdge);

    CHECK(get_edge_type(zero, one) == PosEdge);
    CHECK(get_edge_type(one, one) == NoEdge);
    CHECK(get_edge_type(x, one) == PosEdge);
    CHECK(get_edge_type(z, one) == PosEdge);

    CHECK(get_edge_type(zero, x) == PosEdge);
    CHECK(get_edge_type(one, x) == NegEdge);
    CHECK(get_edge_type(x, x) == NoEdge);
    CHECK(get_edge_type(z, x) == NoEdge);

    CHECK(get_edge_type(zero, z) == PosEdge);
    CHECK(get_edge_type(one, z) == NegEdge);
    CHECK(get_edge_type(x, z) == NoEdge);
    CHECK(get_edge_type(z, z) == NoEdge);
  }

  SECTION("match_edge_type")
  {
    for (auto from : {one, x, z, zero}) {
      for (auto to : {one, x, z, zero}) {
        auto from_str = value_to_string(from);
        auto to_str = value_to_string(to);
        SECTION(fmt::format("{} -> {}", from_str, to_str))
        {
          auto edge_type = get_edge_type(from, to);

          if (edge_type == PosEdge) {
            CHECK(edge_type_matches(PosEdge, from, to));
            CHECK(edge_type_matches(Edge, from, to));

            CHECK_FALSE(edge_type_matches(NegEdge, from, to));
            CHECK_FALSE(edge_type_matches(NoEdge, from, to));
          }

          if (edge_type == NegEdge) {
            CHECK(edge_type_matches(NegEdge, from, to));
            CHECK(edge_type_matches(Edge, from, to));

            CHECK_FALSE(edge_type_matches(PosEdge, from, to));
            CHECK_FALSE(edge_type_matches(NoEdge, from, to));
          }

          if (edge_type == NoEdge) {
            CHECK(edge_type_matches(NoEdge, from, to));

            CHECK_FALSE(edge_type_matches(Edge, from, to));
            CHECK_FALSE(edge_type_matches(PosEdge, from, to));
            CHECK_FALSE(edge_type_matches(NegEdge, from, to));
          }

          if (from == zero && to == one)
            CHECK(edge_type_matches(_01, from, to));
          else
            CHECK_FALSE(edge_type_matches(_01, from, to));

          if (from == zero && to == z)
            CHECK(edge_type_matches(_0z, from, to));
          else
            CHECK_FALSE(edge_type_matches(_0z, from, to));

          if (from == z && to == one)
            CHECK(edge_type_matches(_z1, from, to));
          else
            CHECK_FALSE(edge_type_matches(_z1, from, to));

          if (from == z && to == zero)
            CHECK(edge_type_matches(_z0, from, to));
          else
            CHECK_FALSE(edge_type_matches(_z0, from, to));

          if (from == one && to == zero)
            CHECK(edge_type_matches(_10, from, to));
          else
            CHECK_FALSE(edge_type_matches(_10, from, to));

          if (from == one && to == z)
            CHECK(edge_type_matches(_1z, from, to));
          else
            CHECK_FALSE(edge_type_matches(_1z, from, to));
        }
      }
    }
  }
}
