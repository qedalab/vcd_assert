#include "parse/util/name_index_map.hpp"

#include <catch.hpp>

using namespace Parse;

std::string id_a = "abc";
std::string id_b = "def";

TEST_CASE("Parse.Util.NameIndexMap","[Parse][Util][NameIndexMap]") {
NameIndexMap name_index_map;

auto first = name_index_map.add_name(std::string{id_a});
auto again_first = name_index_map.add_name(std::string{id_a});
REQUIRE(first == again_first);

REQUIRE(name_index_map.has_name(id_a));
REQUIRE_FALSE(name_index_map.has_name(id_b));

REQUIRE(name_index_map.get_index(id_a) == first);
REQUIRE(name_index_map.get_name(first) == id_a);

REQUIRE_FALSE(name_index_map.has_index(first+1));

auto second = name_index_map.add_new_name(std::string{id_b});

REQUIRE(name_index_map.has_name(id_a));
REQUIRE(name_index_map.has_name(id_b));

REQUIRE(name_index_map.get_index(id_a) == first);
REQUIRE(name_index_map.get_index(id_b) == second);

REQUIRE_FALSE(name_index_map.has_index(second+1));
}
