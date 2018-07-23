#include "parse/util/bag.hpp"

#include <catch2/catch.hpp>

using namespace Parse::Util;

TEST_CASE("Parse.Util.Bag", "[Util]") {
  
  SECTION("Default constructed") {
    Bag<int> bag_default;
    REQUIRE(bag_default.is_empty());

    REQUIRE(bag_default.get_size() == 0);

    for([[maybe_unused]] auto& t: bag_default.as_range()) {
      REQUIRE(false);
    }
  }

  SECTION("Add then remove") {
    Bag<int> bag_add_remove;

    bag_add_remove.insert(1);
    bag_add_remove.insert(2);
    bag_add_remove.insert(3);

    REQUIRE(bag_add_remove.get_size() == 3);
    REQUIRE(bag_add_remove[0] == 1);
    REQUIRE(bag_add_remove[1] == 2);
    REQUIRE(bag_add_remove[2] == 3);
    REQUIRE_FALSE(bag_add_remove.is_empty());

    bag_add_remove.remove(1);
    REQUIRE(bag_add_remove.get_size() == 2);
    REQUIRE(bag_add_remove[0] == 1);
    REQUIRE(bag_add_remove[1] == 3);
    REQUIRE_FALSE(bag_add_remove.is_empty());

    bag_add_remove.remove(int(0));
    REQUIRE(bag_add_remove.get_size() == 1);
    REQUIRE(bag_add_remove[0] == 3);
    REQUIRE_FALSE(bag_add_remove.is_empty());

    bag_add_remove.remove(int(0));
    REQUIRE(bag_add_remove.get_size() == 0);
    REQUIRE(bag_add_remove.is_empty());
  }
}
