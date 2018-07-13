#include "./values.hpp"



void SDF::Test::catch_test_triple(SDF::Triple wanted, SDF::Triple test)
{

  SECTION("SDF Triple"){

      REQUIRE(test.min == Approx(wanted.min)); 

      REQUIRE(test.typ == Approx(wanted.typ)); 

      REQUIRE(test.max == Approx(wanted.max));
  }
}