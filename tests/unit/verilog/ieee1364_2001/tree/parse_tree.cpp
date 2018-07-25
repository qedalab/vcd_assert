#include <iostream>
#include <string>
#include <type_traits>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

#include "./grammar.hpp"


using namespace Parse::Test;
using namespace Verilog::IEEE1364_2001;
using namespace Test::Verilog::IEEE1364_2001::Grammar;

TEST_CASE("Verilog.IEEE1364_2001.Grammar.Grammer", "[Verilog][IEEE1364_2001][Grammar][Grammar]") {
  
  
  try{
    if( const auto root = parse_tree::parse< example::grammar, example::store >( in ) ) {
      example::print_node( *root );
    }
    else {
      std::cout << "PARSE FAILED" << std::endl;
    }
  catch( const std::exception& e ) {
      std::cout << "PARSE FAILED WITH EXCEPTION: " << e.what() << std::endl;
  }

  SECTION("identifier"){
    CAPTURE(module_keyword);
    CHECK(match_exactly<Grammar::identifier>(module_keyword));
  }

int main( int argc, char** argv )
{
   for( int i = 1; i < argc; ++i ) {
      try {

         argv_input<> in( argv, i );
         if( const auto root = parse_tree::parse< example::grammar, example::store >( in ) ) {
            example::print_node( *root );
         }
         else {
            std::cout << "PARSE FAILED" << std::endl;
         }
      }
      catch( const std::exception& e ) {
         std::cout << "PARSE FAILED WITH EXCEPTION: " << e.what() << std::endl;
      }
   }
   return 0;
}
