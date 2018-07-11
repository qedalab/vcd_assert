#include "./values.hpp"



void SDF::Test::catch_test_triple(SDF::Triple wanted, SDF::Triple test)
{

  SECTION("SDF Triple"){

      REQUIRE(test.min == wanted.min); 

      REQUIRE(test.typ == wanted.typ); 

      REQUIRE(test.max == wanted.max);
  }
}