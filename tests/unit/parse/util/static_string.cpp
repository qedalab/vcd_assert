#include "parse/util/static_string.hpp"

#include <catch2/catch.hpp>

using Parse::Util::static_string;

// Ensure that it works constexpr
constexpr auto ss1 = static_string("asdf");
// constexpr auto ss2 = ss1 + "right";
// constexpr auto ss3 = "left" + ss1;
constexpr auto ss4 = static_string("left_") + static_string("right");

TEST_CASE("Parse.Util.StaticString", "[Parse][Util]") {

  SECTION("Base") {
    CHECK(ss1.get_size() == 4);
    CHECK(ss1.to_string_view() == "asdf");
    CHECK(ss1.to_string() == "asdf");
  }

//   SECTION("Concat left") {
//     CHECK(ss2.get_size() == 9);
//     CHECK(ss2.to_string_view() == "asdfright");
//     CHECK(ss2.to_string() == "asdfright");
//   }

//   SECTION("Concat right") {
//     CHECK(ss3.get_size() == 8);
//     CHECK(ss3.to_string_view() == "leftasdf");
//     CHECK(ss3.to_string() == "leftasdf");
//   }

//   SECTION("Concat both") {
//     CHECK(ss4.get_size() == 10);
//     CHECK(ss4.to_string_view() == "left_right");
//     CHECK(ss4.to_string() == "left_right");
//   }

}
