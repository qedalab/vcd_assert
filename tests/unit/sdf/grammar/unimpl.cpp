#include "./base.hpp"
#include "./unimpl.hpp"

using namespace Parse::Test;
using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;


TEST_CASE("SDF.Grammar.Unimplemented", "[SDF][Grammar][Unimplemented]") {

  SECTION("Ignored Blocks of Unimplemented Grammar ") { 
    SECTION("Should Pass ") { 
      CHECK(
        match_exactly<unimplemented<key_instance>>(
          fmt::format(" (INSTANCE top.x1)")
        )
      );
      CHECK(
        match_exactly<unimplemented<key_instance>>(
          fmt::format(" (INSTANCE () top.x1)")
        )
      );
      CHECK(
        match_exactly<unimplemented<key_instance>>(
          fmt::format(" (INSTANCE xyz (()) top.x1)")
        )
      );
      CHECK(
        match_exactly<unimplemented<key_instance>>(
          fmt::format(" (INSTANCE xyz ((xyz)) top.x1())")
        )
      );
    }
    /*
      These cases dont prove anything. Incorrectly specifying 
      blocks in a SDF file simply causes undefined behavior..
    */
    // SECTION("Incorrect Cases that ") { 
    //   CHECK(
    //     match_exactly<unimplemented<key_instance>>(
    //       fmt::format(" (INSTANCE ( top.x1)")
    //     )
    //   );
    //   CHECK(
    //     match_exactly<unimplemented<key_instance>>(
    //       fmt::format(" (INSTANCE (() top.x1)")
    //     )
    //   );
    // }
    // SECTION("Incorrect Cases that still pass.. ") { 
    //   CHECK(
    //     match_exactly<unimplemented<key_instance>>(
    //       fmt::format(" (INSTANCE ) top.x1)")
    //     )
    //   );

    //   CHECK(
    //     match_exactly<unimplemented<key_instance>>(
    //       fmt::format(" (INSTANCE ()) top.x1) ")
    //     )
    //   );
    // }
  } 
}

