#include "./timing.hpp"

using namespace SDF::Test;
using namespace SDF;


void SDF::Test::catch_test_node(SDF::Node wanted, SDF::Node test)
{

  SECTION("SDF Node"){

    SECTION("Member : \"type\"") {
      std::string output;
      ranges::copy("Testing \""sv, ranges::back_inserter(output));
      ranges::copy(nodetype_to_string(test.type),
                   ranges::back_inserter(output));
      ranges::copy("\" and \""sv, ranges::back_inserter(output));
      ranges::copy(nodetype_to_string(wanted.type),
                   ranges::back_inserter(output));
      ranges::copy("\""sv, ranges::back_inserter(output));

      INFO("Wanted");
      CAPTURE(test.type);
      SECTION(output) { 
        REQUIRE(test.type == wanted.type); 
      }
    }

    SECTION("Member : \"basename_identifier\"") {
      REQUIRE(test.basename_identifier == wanted.basename_identifier);
    }

    SECTION("Member : \"hierarchical_identifier\" : \n") {
      std::string output;
      
      ranges::copy("\fWanted : "sv, ranges::back_inserter(output));
      if(wanted.hierarchical_identifier.has_value()){
        ranges::copy("\""sv, ranges::back_inserter(output));
        serialize_hierarchical_identifier(ranges::back_inserter(output), 0,
                                          wanted.hierarchical_identifier.value());
        ranges::copy("\""sv, ranges::back_inserter(output));
      }else{
         ranges::copy("NULL"sv, ranges::back_inserter(output));      
      }

      ranges::copy("\f\r     Got : "sv, ranges::back_inserter(output));
      
      if(test.hierarchical_identifier.has_value()){

        ranges::copy("\""sv, ranges::back_inserter(output));
        serialize_hierarchical_identifier(ranges::back_inserter(output), 0,
                                          test.hierarchical_identifier.value());
        ranges::copy("\""sv, ranges::back_inserter(output));

      }else{
         ranges::copy("NULL"sv, ranges::back_inserter(output));      
      }
        
      SECTION(output){
        if(wanted.hierarchical_identifier.has_value()){
            REQUIRE(test.hierarchical_identifier.has_value());
            REQUIRE(test.hierarchical_identifier ==
                          wanted.hierarchical_identifier);          
        }else{
          REQUIRE_FALSE(test.hierarchical_identifier.has_value());
        }
      }
    }

    SECTION("Member : \"start\"") { 
      REQUIRE(test.start == wanted.start); 
    }

    SECTION("Member : \"end\"") { 
      REQUIRE(test.end == wanted.end); 
    }

    SECTION("Overall : \"end\"") { 
      REQUIRE(test == wanted);
    }
  }
}

