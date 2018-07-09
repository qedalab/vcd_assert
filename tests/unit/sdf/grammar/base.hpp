#ifndef LIBSDF_TEST_SDF_BASE_H
#define LIBSDF_TEST_SDF_BASE_H

#include <sdf/grammar/base.hpp>

#include <parse/util/array_append.hpp>
#include <parse/test/match.hpp>
#include <parse/test/parse.hpp>

#include <array>
#include <iostream>
#include <string>
#include <catch2/catch.hpp>
#include <fmt/format.h>


namespace Test {
namespace SDF {
namespace Grammar {

using namespace Parse::Test;
using namespace Parse::Util;


constexpr char empty_str[] = "";
constexpr char blank_1_str[] = " ";
constexpr char blank_2_str[] = "  ";
constexpr char blank_3_str[] = "   ";
constexpr char newline_1_str[] = "\n";
constexpr char newline_2_str[] = "\n";
constexpr char newline_3_str[] = "\n\n\n";
constexpr char carrage_return_1_str[] = "\r"; //??
constexpr char tab_1_str[] = "\t";
constexpr char tab_2_str[] = "\t\t";
constexpr char tab_3_str[] = "\t\t\t";

constexpr char comment_line_str[] = "//single line comment";
constexpr char comment_block_str[] = "/*multi line comment*/";

constexpr char positive_sign_str[] = "+";
constexpr char negative_sign_str[] = "-";
constexpr char separator_0[] = ".";
constexpr char separator_1[] = "/";

constexpr std::array special_character_without_bslash_str {
       "!","#","%","&","(",")", //removed ,"«"
       "*","+",",","-",".","/",":",
       ";","<","=",">","?","@","[",
       "]","^","'","{","|","}","~" };

constexpr std::array special_character_str = 
  array_append(
    special_character_without_bslash_str,
    std::array{"\\"}
  );

constexpr std::array escaped_special_character_str = 
  std::array{
  "\\!","\\#","\\%","\\&","\\(","\\)", // removed ,"\\«"
  "\\*","\\+","\\,","\\-","\\.","\\/","\\:",
  "\\;","\\<","\\=","\\>","\\?","\\@","\\[",
  "\\\\","\\]","\\^","\\'","\\{","\\|","\\}","\\~"};

constexpr std::array decimal_range_str = 
  std::array{
    "0","1","2","3","4","5","6","7","8","9"
  };

constexpr std::array escaped_decimal_range_str = 
  std::array{
    "\\0","\\1","\\2","\\3","\\4","\\5","\\6","\\7","\\8","\\9"
  };

constexpr std::array alphanumeric_str = 
  array_append(
    array_append(
      std::array{"_","$"},
      decimal_range_str
    ),
    std::array{
      "a","b","c","d","e","f","g",
      "h","i","j","k","l","m","n",
      "o","p","q","r","s","t","u",
      "v","w","x","y","z",
      "A","B","C","D","E","F","G",
      "H","I","J","K","L","M","N",
      "O","P","Q","R","S","T","U",
      "V","W","X","Y","Z"
    }
  );

constexpr std::array escaped_alphanumeric_str = 
  array_append(
    array_append(
      std::array{"\\_","\\$"},
      escaped_decimal_range_str
    ),
    std::array{
      "\\a","\\b","\\c","\\d","\\e","\\f","\\g",
      "\\h","\\i","\\j","\\k","\\l","\\m","\\n",
      "\\o","\\p","\\q","\\r","\\s","\\t","\\u",
      "\\v","\\w","\\x","\\y","\\z",
      "\\A","\\B","\\C","\\D","\\E","\\F","\\G",
      "\\H","\\I","\\J","\\K","\\L","\\M","\\N",
      "\\O","\\P","\\Q","\\R","\\S","\\T","\\U",
      "\\V","\\W","\\X","\\Y","\\Z"
    }
  );

constexpr std::array escaped_character_str = 
  array_append(
    escaped_special_character_str,
    escaped_alphanumeric_str
  );

constexpr std::array character_str = 
  array_append(
    alphanumeric_str,
    escaped_character_str
  );

constexpr std::array any_character_str = 
  array_append(
    special_character_without_bslash_str,
    character_str
  );


constexpr auto qstring_str= "\"This is a quoted string\"";
constexpr auto qstring_str_2= "\"Saturday September 30 08:30:33 PST 1990\"";
constexpr auto ident_str= "ff1";
constexpr auto hident_str= "top.ff1";


}
}
}

#endif //LIBSDF_TEST_SDF_BASE_H