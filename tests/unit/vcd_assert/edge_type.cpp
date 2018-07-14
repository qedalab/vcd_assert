#include "vcd_assert/edge_type.hpp"

#include <catch2/catch.hpp>

using namespace VCDAssert;

TEST_CASE("VCDAssert::edge_type") {
  constexpr auto one = VCD::Value::one;
  constexpr auto x = VCD::Value::x;
  constexpr auto z = VCD::Value::z;
  constexpr auto zero = VCD::Value::zero;

  constexpr auto PosEdge = VCDAssert::EdgeType::PosEdge;
  constexpr auto NegEdge = VCDAssert::EdgeType::NegEdge;
  constexpr auto NoEdge = VCDAssert::EdgeType::NoEdge;

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
