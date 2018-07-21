#include "vcd_assert/event.hpp"

#include <catch2/catch.hpp>

using namespace VCDAssert;

TEST_CASE("VCDAssert.Event") {
//   RegisterEventList event_list;

//   event_list.pos_edge.emplace_back(SetupEvent{});
//   event_list.pos_edge.emplace_back(SetupEvent{});

//   event_list.neg_edge.emplace_back(HoldEvent{});

//   auto no_list = event_list.get_event_list(EdgeType::NoEdge);
//   auto pos_list = event_list.get_event_list(EdgeType::PosEdge);
//   auto neg_list = event_list.get_event_list(EdgeType::NegEdge);

//   // Correct sizes
//   CHECK(no_list.size() == 0);
//   REQUIRE(pos_list.size() == 2);
//   REQUIRE(neg_list.size() == 1);

//   // Point to the same underlying values
//   CHECK(&event_list.pos_edge.front() == &pos_list.front());
//   CHECK(&event_list.neg_edge.front() == &neg_list.front());
}
