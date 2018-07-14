#include "./timing.hpp"

using namespace SDF;
using namespace SDF::Test;


void SDF::Test::catch_test_node(SDF::Node wanted, SDF::Node test)
{

  SECTION("SDF Node"){

    SECTION("Member : \"type\"") {
      CAPTURE(test.type);
      REQUIRE(wanted.type == test.type); 
    }

    SECTION("Member : \"basename_identifier\"") {
      CAPTURE(test.basename_identifier);
      REQUIRE(wanted.basename_identifier == test.basename_identifier);
    }

    if(wanted.edge.has_value()){
      CAPTURE(test.edge.value());
      REQUIRE(wanted.edge.value() == test.edge.value());
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
            REQUIRE(test.hierarchical_identifier.value() ==
                          wanted.hierarchical_identifier.value());          
        }else{
          REQUIRE_FALSE(test.hierarchical_identifier);
        }
      }
    }

    SECTION("Member : \"start\"") { 
      if(wanted.start.has_value()){
        CAPTURE(wanted.start.value());
        REQUIRE(test.start.has_value());
        CAPTURE(test.start.value());
        REQUIRE(wanted.start.value() == test.start.value()); 
      }
    }
    SECTION("Member : \"end\"") { 
      if(wanted.end.has_value()){
        CAPTURE(wanted.end.value());
        REQUIRE(test.end.has_value());
        CAPTURE(test.end.value());
        REQUIRE(wanted.end.value() == test.end.value()); 
      }
    }
    CAPTURE(wanted);
    CAPTURE(test);
    // REQUIRE(wanted == test);
  }
}

