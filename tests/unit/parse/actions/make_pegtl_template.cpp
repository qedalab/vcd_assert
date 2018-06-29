#include "parse/actions/make_pegtl_template.hpp"

#include <catch2/catch.hpp>

#include <type_traits>

using namespace Parse;

struct Foo;
struct Bar;

TEST_CASE("Parse.Actions.MakePEGTLTemplatee", "[Parse][Actions]") {
  CHECK(std::is_same_v<Foo, make_pegtl_template<Foo>::template type<Bar>>);
}
