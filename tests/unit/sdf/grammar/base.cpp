#include "./base.hpp"

using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;


#include <range/v3/algorithm/copy.hpp>
#include <string_view>
#include <range/v3/iterator/insert_iterators.hpp>

TEST_CASE("SDF.Grammar.Base", "[!hide][SDF][Grammar][Base]") {

  SECTION("Blank Space") {

    //single
    CHECK(match_exactly<blank>(blank_1_str));
    CHECK(match_exactly<blank>(tab_1_str));
    CHECK(match_exactly<blank>(newline_1_str));

    //multi
    CHECK(match_exactly<plus_blank>(blank_2_str));
    CHECK(match_exactly<plus_blank>(blank_3_str));
    CHECK(match_exactly<plus_blank>(newline_2_str));
    CHECK(match_exactly<plus_blank>(newline_3_str));
    CHECK(match_exactly<plus_blank>(tab_2_str));
    CHECK(match_exactly<plus_blank>(tab_3_str));
  }

  SECTION("Comments") {
    CHECK(match_exactly<comment>(comment_line_str));
    CHECK(match_exactly<comment>(comment_block_str));
  }

  SECTION("Token Separators") {
    CHECK(match_exactly<sp>(comment_line_str));
    CHECK(match_exactly<sp>(comment_block_str));
    CHECK(match_exactly<sps>(comment_line_str));
    CHECK(match_exactly<sps>(comment_block_str));
    CHECK(match_exactly<sps>(fmt::format(" {}",comment_block_str)));
    CHECK(match_exactly<sps>(fmt::format(" {} ",comment_block_str)));
    CHECK(match_exactly<sps>(fmt::format("{} ",comment_block_str)));
    CHECK(match_exactly<sps>(fmt::format("{} {}",comment_block_str, comment_block_str)));

    //single
    CHECK(match_exactly<sp>(blank_1_str));
    CHECK(match_exactly<sp>(tab_1_str));
    CHECK(match_exactly<sp>(newline_1_str));

    //multi
    CHECK(match_exactly<sps>(blank_2_str));
    CHECK(match_exactly<sps>(blank_3_str));
    CHECK(match_exactly<sps>(newline_2_str));
    CHECK(match_exactly<sps>(newline_3_str));
    CHECK(match_exactly<sps>(tab_2_str));
    CHECK(match_exactly<sps>(tab_3_str));
  }

  SECTION("Decimals") {
    for(auto&& a : decimal_range_str){ 
      SECTION(std::string(a)) {
        INFO("Checking : " << a); 
        CHECK(match_exactly<decimal_digit>(a));
      }
    }
  }

  SECTION("Alphanumeric Characters") {
    for(auto&& a : alphanumeric_str){ 
      SECTION(std::string(a)){
        INFO("Checking : " << a); 
        CHECK(match_exactly<alphanumeric>(a));
      }
    }
  }

  SECTION("Escaped Alphanumerics Characters") {
    for(auto&& a : escaped_alphanumeric_str){ 
      SECTION(std::string(a)){
        INFO("Checking : " << a); 
        CHECK(match_exactly<escaped_character>(a));
      }
    }
  }

  SECTION("Special Characters") {
    for(auto&& a : special_character_str){ 
      SECTION(std::string(a)){
        INFO("Checking : " << a);
        CHECK(match_exactly<special_character>(a));
      }
    }
  }

  SECTION("Escaped Special Characters") {
    for(auto&& a : escaped_special_character_str){ 
      SECTION(std::string(a)){
        INFO("Checking : " << a); 
        CHECK(match_exactly<escaped_character>(a));
      }
    }
  }
  
  SECTION("Normal Characters") {
    for(auto&& a : character_str){ 
      SECTION(std::string(a)){
        INFO("Checking : " << a); 
        CHECK(match_exactly<character>(a));
      }
    }
  }

  SECTION("All Characters") {
    for(auto&& a : any_character_str){ 
      
      SECTION(std::string(a)){
        INFO("Checking : " << a); 
        CHECK(match_exactly<any_character>(a));
      }
    }
  }
  

  SECTION("Signs") {
    CHECK_FALSE(match_exactly<sign>(empty_str));
    CHECK(match_exactly<sign>(positive_sign_str));
    CHECK(match_exactly<sign>(negative_sign_str));
  }


  SECTION("Quoted Characters") {

    SECTION("Double Backslash") {
      INFO("Checking : \"\\\"");
      CHECK_THROWS(match_exactly<qstring>(fmt::format(R"("\")")));
    }
    
    for(auto&& a : any_character_str){ 
      std::string test;
      ranges::copy(std::string_view("\""), ranges::back_inserter(test));
      ranges::copy(std::string(a), ranges::back_inserter(test));
      ranges::copy(std::string_view("\""), ranges::back_inserter(test));

      INFO("Checking : "<< test);
      CHECK(match_exactly<qstring>(test));
    }
  }

  SECTION("Quoted Strings") {
    CHECK(match_exactly<qstring>(qstring_str));
    CHECK(match_exactly<qstring>(qstring_str_2));
    CHECK(match_exactly<qstring>("\"4.0\""));
  }

  SECTION("General Identifier") {
    INFO("Checking : " << ident_str); 
    CHECK(match_exactly<identifier>(ident_str));
  }
  SECTION("Hierarchical Identifier") {
    using hi =  hierarchical_identifier;
    INFO("Checking : " << hident_str); 
    CHECK(match_exactly<hi>(hident_str));
  }
}

TEST_CASE("SDF.Grammar.Base.Extra", "[!hide][SDF][Grammar][Base][Extra]") {

  SECTION("Bracket Matching -- Correct Cases") {
    CHECK(match_exactly<bracket_pairs>("()"));
    CHECK(match_exactly<bracket_pairs>("(())"));
    CHECK(match_exactly<bracket_pairs>("((()))"));
    CHECK(match_exactly<bracket_pairs>("( (()))"));
    CHECK(match_exactly<bracket_pairs>("(( ()))"));
    CHECK(match_exactly<bracket_pairs>("((( )))"));
    CHECK(match_exactly<bracket_pairs>("((() ))"));
    CHECK(match_exactly<bracket_pairs>("((()) )"));
    CHECK(match_exactly<bracket_pairs>("((()) )"));
    CHECK(match_exactly<bracket_pairs>("( ( ( ) ) )"));
    CHECK(match_exactly<bracket_pairs>("()()"));
    CHECK(match_exactly<bracket_pairs>("(()())"));
    CHECK(match_exactly<bracket_pairs>("(())()"));
    CHECK(match_exactly<bracket_pairs>("(())(())"));
    CHECK(match_exactly<bracket_pairs>("((()()))"));
    CHECK(match_exactly<bracket_pairs>("( (()()))"));
    CHECK(match_exactly<bracket_pairs>("(( ()()))"));
    CHECK(match_exactly<bracket_pairs>("((( )()))"));
    CHECK(match_exactly<bracket_pairs>("((() ()))"));
    CHECK(match_exactly<bracket_pairs>("((() ( )))"));
    CHECK(match_exactly<bracket_pairs>("((() () ))"));
    CHECK(match_exactly<bracket_pairs>("((() () ) )"));
    CHECK(match_exactly<bracket_pairs>("()()()"));
    CHECK(match_exactly<bracket_pairs>("( )()()"));
    CHECK(match_exactly<bracket_pairs>("() ()()"));
    CHECK(match_exactly<bracket_pairs>("() () ()"));
    CHECK(match_exactly<bracket_pairs>("( ) ( ) ( )"));
  }

  SECTION("Bracket Matching -- Incorrect Cases (Unbalanced LHS)") {

    CHECK_FALSE(match_exactly<bracket_pair>("(()")); 
    CHECK_FALSE(match_exactly<bracket_pair>("((())")); 
    CHECK_FALSE(match_exactly<bracket_pair>("((()())")); 
    CHECK_FALSE(match_exactly<bracket_pair>("(()(()())")); 
    CHECK_FALSE(match_exactly<bracket_pair>("(()(()()())")); 
    CHECK_FALSE(match_exactly<bracket_pair>("((((() () ) ))")); 
    CHECK_FALSE(match_exactly<bracket_pair>("((((((() () ) ))")); 
    CHECK_FALSE(match_exactly<bracket_pair>("(()) (((((( ()() )))")); 

    CHECK_FALSE(match_exactly<bracket_pairs>("(()")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("((())")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("((()())")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("(()(()())")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("(()(()()())")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("((((() () ) ))")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("((((((() () ) ))")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("(()) (((((( ()() )))")); 
  }
  SECTION("Bracket Matching -- Incorrect Cases (Unbalanced RHS)") { 
    CHECK_FALSE(match_exactly<bracket_pairs>("())")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("()())")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("(()()))")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("()()())")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("((() () ) ))")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("((() () )) ))")); 
    CHECK_FALSE(match_exactly<bracket_pairs>("((()) () ) ))")); 
  }
}
