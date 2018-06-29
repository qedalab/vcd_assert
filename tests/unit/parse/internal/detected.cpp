#include "parse/internal/detected.h"

#include <catch2/catch.hpp>

using namespace Parse;

template<class Struct>
using member_foo = typename Struct::foo;

struct StructWithFoo {
    using foo = double;
};

struct StructWithoutFoo {
    //No foo here
};

TEST_CASE("Parse.Internal.Detected", "[Parse][Internal][Detected]") {
    REQUIRE(Internal::is_detected<member_foo, StructWithFoo>);
    REQUIRE(!Internal::is_detected<member_foo, StructWithoutFoo>);
}
