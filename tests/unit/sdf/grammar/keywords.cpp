#include "./keywords.hpp"
#include <locale> 

using namespace Parse::Test;
using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;



TEST_CASE("SDF.Grammar.Keywords", "[SDF][Grammar][Keywords]") {

  SECTION("Keyword Strings") {
    for(auto&& a : sdf_keywords){ 
      SECTION(fmt::format("{} Keyword",a)) {
        CHECK(match_exactly<str_keyword>(fmt::format("{}",a)));
      }
    }
  }
  
  SECTION("Keyword Tokens") {
    for(auto&& a : sdf_keywords){ 
      SECTION(fmt::format("{} Keyword",a)) {
        CHECK(match_exactly<keyword>(fmt::format("{}",a)));
      }
    }
  }

  

}