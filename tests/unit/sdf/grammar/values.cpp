#include "values.hpp"

using namespace Parse::Test;
using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;

TEST_CASE("SDF.Grammar.Values", "[SDF][Grammar][Values]") {

  SECTION("Single numbers"){
    SECTION(fmt::format("'single_number_unsigned_float_1 : \"{}\"\n",
      single_number_unsigned_float_1)){
      CHECK(match_exactly<signed_real_number>(single_number_unsigned_float_1));
      CHECK(match_exactly<real_number>(single_number_unsigned_float_1));
    }
    SECTION(fmt::format("'single_number_unsigned_float_2 : \"{}\"\n",
      single_number_unsigned_float_2)){
      CHECK(match_exactly<signed_real_number>(single_number_unsigned_float_2));
      CHECK(match_exactly<real_number>(single_number_unsigned_float_2));
    }
    SECTION(fmt::format("'single_number_unsigned_float_3 : \"{}\"\n",
      single_number_unsigned_float_3)){
      CHECK(match_exactly<signed_real_number>(single_number_unsigned_float_3));
      CHECK(match_exactly<real_number>(single_number_unsigned_float_3));
    }
    SECTION(fmt::format("'single_number_unsigned_float_4 : \"{}\"\n",
      single_number_unsigned_float_4)){
      CHECK(match_exactly<signed_real_number>(single_number_unsigned_float_4));
      CHECK(match_exactly<real_number>(single_number_unsigned_float_4));
    }
    SECTION(fmt::format("'single_number_unsigned_float_5 : \"{}\"\n",
      single_number_unsigned_float_5)){
      CHECK(match_exactly<signed_real_number>(single_number_unsigned_float_5));
      CHECK(match_exactly<real_number>(single_number_unsigned_float_5));
    }
    SECTION(fmt::format("'single_number_unsigned_float_6 : \"{}\"\n",
      single_number_unsigned_float_6)){
      CHECK(match_exactly<signed_real_number>(single_number_unsigned_float_6));
      CHECK(match_exactly<real_number>(single_number_unsigned_float_6));
    }
    SECTION(fmt::format("'single_number_unsigned_float_7 : \"{}\"\n",
      single_number_unsigned_float_7)){
      CHECK(match_exactly<signed_real_number>(single_number_unsigned_float_7));
      CHECK(match_exactly<real_number>(single_number_unsigned_float_7));
    }
    SECTION(fmt::format("'single_number_unsigned_float_8 : \"{}\"\n",
      single_number_unsigned_float_8)){
      CHECK(match_exactly<signed_real_number>(single_number_unsigned_float_8));
      CHECK(match_exactly<real_number>(single_number_unsigned_float_8));
    }
    SECTION(fmt::format("'single_number_unsigned_float_9 : \"{}\"\n",
      single_number_unsigned_float_9)){
      CHECK(match_exactly<signed_real_number>(single_number_unsigned_float_9));
      CHECK(match_exactly<real_number>(single_number_unsigned_float_9));
    }
    SECTION(fmt::format("'single_number_inverted_float_1 : \"{}\"\n",
      single_number_inverted_float_1)){
      CHECK(match_exactly<signed_real_number>(single_number_inverted_float_1));
      CHECK_THROWS(match_exactly<real_number>(single_number_inverted_float_1));
    }
    SECTION(fmt::format("'single_number_inverted_float_2 : \"{}\"\n",
      single_number_inverted_float_2)){
      CHECK(match_exactly<signed_real_number>(single_number_inverted_float_2));
      CHECK_THROWS(match_exactly<real_number>(single_number_inverted_float_2));
    }
    SECTION(fmt::format("'single_number_inverted_float_3 : \"{}\"\n",
      single_number_inverted_float_3)){
      CHECK(match_exactly<signed_real_number>(single_number_inverted_float_3));
      CHECK_THROWS(match_exactly<real_number>(single_number_inverted_float_3));
    }
    SECTION(fmt::format("'single_number_inverted_float_4 : \"{}\"\n",
      single_number_inverted_float_4)){
      CHECK(match_exactly<signed_real_number>(single_number_inverted_float_4));
      CHECK_THROWS(match_exactly<real_number>(single_number_inverted_float_4));
    }
    SECTION(fmt::format("'single_number_inverted_float_5 : \"{}\"\n",
      single_number_inverted_float_5)){
      CHECK(match_exactly<signed_real_number>(single_number_inverted_float_5));
      CHECK_THROWS(match_exactly<real_number>(single_number_inverted_float_5));
    }
    SECTION(fmt::format("'single_number_inverted_float_6 : \"{}\"\n",
      single_number_inverted_float_6)){
      CHECK(match_exactly<signed_real_number>(single_number_inverted_float_6));
      CHECK_THROWS(match_exactly<real_number>(single_number_inverted_float_6));
    }
    SECTION(fmt::format("'single_number_inverted_float_7 : \"{}\"\n",
      single_number_inverted_float_7)){
      CHECK(match_exactly<signed_real_number>(single_number_inverted_float_7));
      CHECK_THROWS(match_exactly<real_number>(single_number_inverted_float_7));
    }
    SECTION(fmt::format("'single_number_inverted_float_8 : \"{}\"\n",
      single_number_inverted_float_8)){
      CHECK(match_exactly<signed_real_number>(single_number_inverted_float_8));
      CHECK_THROWS(match_exactly<real_number>(single_number_inverted_float_8));
    }
    SECTION(fmt::format("'single_number_inverted_float_9 : \"{}\"\n",
      single_number_inverted_float_9)){
      CHECK(match_exactly<signed_real_number>(single_number_inverted_float_9));
      CHECK_THROWS(match_exactly<real_number>(single_number_inverted_float_9));
    }
  }

  SECTION("Triple Numbers") {

    // SECTION(fmt::format("'empty_triple' : \"{}\"\n",
    //                     empty_triple)) {
    //   INFO("Should not allow empty triples");
    //   CHECK_FALSE(match_exactly<triple>(empty_triple));
    //   CHECK_FALSE(match_exactly<rtriple>(empty_triple));
    // }

    SECTION(fmt::format("'triple_number_int_full' : \"{}\"\n",
                        triple_number_int_full)) {
      CHECK(match_exactly<triple>(triple_number_int_full));
      CHECK(match_exactly<rtriple>(triple_number_int_full));
    }

    SECTION(fmt::format("'triple_number_int_single_1' : \"{}\"\n",
                        triple_number_int_single_1)) {
      CHECK(match_exactly<triple>(triple_number_int_single_1));
      CHECK(match_exactly<rtriple>(triple_number_int_single_1));
    }

    SECTION(fmt::format("'triple_number_int_single_2' : \"{}\"\n",
                        triple_number_int_single_2)) {
      CHECK(match_exactly<triple>(triple_number_int_single_2));
      CHECK(match_exactly<rtriple>(triple_number_int_single_2));
    }

    SECTION(fmt::format("'triple_number_int_single_3' : \"{}\"\n",
                        triple_number_int_single_3)) {
      CHECK(match_exactly<triple>(triple_number_int_single_3));
      CHECK(match_exactly<rtriple>(triple_number_int_single_3));
    }

    SECTION(fmt::format("'triple_number_int_dual_1' : \"{}\"\n",
                        triple_number_int_dual_1)) {
      CHECK(match_exactly<triple>(triple_number_int_dual_1));
      CHECK(match_exactly<rtriple>(triple_number_int_dual_1));
    }

    SECTION(fmt::format("'triple_number_int_dual_2' : \"{}\"\n",
                        triple_number_int_dual_2)) {
      CHECK(match_exactly<triple>(triple_number_int_dual_2));
      CHECK(match_exactly<rtriple>(triple_number_int_dual_2));
    }

    SECTION(fmt::format("'triple_number_int_dual_3' : \"{}\"\n",
                        triple_number_int_dual_3)) {
      CHECK(match_exactly<triple>(triple_number_int_dual_3));
      CHECK(match_exactly<rtriple>(triple_number_int_dual_3));
    }

    SECTION(fmt::format("'triple_number_float_full_1' : \"{}\"\n",
                        triple_number_float_full_1)) {
      CHECK(match_exactly<triple>(triple_number_float_full_1));
      CHECK(match_exactly<rtriple>(triple_number_float_full_1));
    }

    SECTION(fmt::format("'triple_number_float_full_2' : \"{}\"\n",
                        triple_number_float_full_2)) {
      CHECK(match_exactly<triple>(triple_number_float_full_2));
      CHECK(match_exactly<rtriple>(triple_number_float_full_2));
    }

    SECTION(fmt::format("'triple_number_float_full_3' : \"{}\"\n",
                        triple_number_float_full_3)) {
      CHECK(match_exactly<triple>(triple_number_float_full_3));
      CHECK(match_exactly<rtriple>(triple_number_float_full_3));
    }

    SECTION(fmt::format("'triple_number_float_full_4(signed)' : \"{}\"\n",
                        triple_number_float_full_4)) {
      CHECK(match_exactly<rtriple>(triple_number_float_full_4));
    }

    SECTION(fmt::format("'triple_number_float_single_1_1' : \"{}\"\n",
                        triple_number_float_single_1_1)) {
      CHECK(match_exactly<triple>(triple_number_float_single_1_1));
      CHECK(match_exactly<rtriple>(triple_number_float_single_1_1));
    }

    SECTION(fmt::format("'triple_number_float_single_1_2' : \"{}\"\n",
                        triple_number_float_single_1_2)) {
      CHECK(match_exactly<triple>(triple_number_float_single_1_2));
      CHECK(match_exactly<rtriple>(triple_number_float_single_1_2));
    }

    SECTION(fmt::format("'triple_number_float_single_1_3' : \"{}\"\n",
                        triple_number_float_single_1_3)) {
      CHECK(match_exactly<triple>(triple_number_float_single_1_3));
      CHECK(match_exactly<rtriple>(triple_number_float_single_1_3));
    }

    SECTION(fmt::format("'triple_number_float_single_1_4' : \"{}\"\n",
                        triple_number_float_single_1_4)) {
      CHECK(match_exactly<triple>(triple_number_float_single_1_4));
      CHECK(match_exactly<rtriple>(triple_number_float_single_1_4));
    }

    SECTION(fmt::format("'triple_number_float_single_1_5(signed)' : \"{}\"\n",
                        triple_number_float_single_1_5)) {
      CHECK(match_exactly<rtriple>(triple_number_float_single_1_5));
    }

    SECTION(fmt::format("'triple_number_float_single_2_1' : \"{}\"\n",
                        triple_number_float_single_2_1)) {
      CHECK(match_exactly<triple>(triple_number_float_single_2_1));
      CHECK(match_exactly<rtriple>(triple_number_float_single_2_1));
    }

    SECTION(fmt::format("'triple_number_float_single_2_2' : \"{}\"\n",
                        triple_number_float_single_2_2)) {
      CHECK(match_exactly<triple>(triple_number_float_single_2_2));
      CHECK(match_exactly<rtriple>(triple_number_float_single_2_2));
    }

    SECTION(fmt::format("'triple_number_float_single_2_3' : \"{}\"\n",
                        triple_number_float_single_2_3)) {
      CHECK(match_exactly<triple>(triple_number_float_single_2_3));
      CHECK(match_exactly<rtriple>(triple_number_float_single_2_3));
    }

    SECTION(fmt::format("'triple_number_float_single_2_4(signed)' : \"{}\"\n",
                        triple_number_float_single_2_4)) {
      CHECK(match_exactly<rtriple>(triple_number_float_single_2_4));
    }

    SECTION(fmt::format("'triple_number_float_single_2_5' : \"{}\"\n",
                        triple_number_float_single_2_5)) {
      CHECK(match_exactly<triple>(triple_number_float_single_2_5));
      CHECK(match_exactly<rtriple>(triple_number_float_single_2_5));
    }

    SECTION(fmt::format("'triple_number_float_single_2_6(signed)' : \"{}\"\n",
                        triple_number_float_single_2_6)) {
      CHECK(match_exactly<rtriple>(triple_number_float_single_2_6));
    }

    SECTION(fmt::format("'triple_number_float_single_3_1' : \"{}\"\n",
                        triple_number_float_single_3_1)) {
      CHECK(match_exactly<triple>(triple_number_float_single_3_1));
      CHECK(match_exactly<rtriple>(triple_number_float_single_3_1));
    }

    SECTION(fmt::format("'triple_number_float_single_3_2' : \"{}\"\n",
                        triple_number_float_single_3_2)) {
      CHECK(match_exactly<triple>(triple_number_float_single_3_2));
      CHECK(match_exactly<rtriple>(triple_number_float_single_3_2));
    }

    SECTION(fmt::format("'triple_number_float_single_3_3' : \"{}\"\n",
                        triple_number_float_single_3_3)) {
      CHECK(match_exactly<triple>(triple_number_float_single_3_3));
      CHECK(match_exactly<rtriple>(triple_number_float_single_3_3));
    }

    SECTION(fmt::format("'triple_number_float_single_3_4' : \"{}\"\n",
                        triple_number_float_single_3_4)) {
      CHECK(match_exactly<triple>(triple_number_float_single_3_4));
      CHECK(match_exactly<rtriple>(triple_number_float_single_3_4));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_1' : \"{}\"\n",
                        triple_number_float_dual_1_1)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_1_1));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_1_1));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_2' : \"{}\"\n",
                        triple_number_float_dual_1_2)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_1_2));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_1_2));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_3' : \"{}\"\n",
                        triple_number_float_dual_1_3)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_1_3));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_1_3));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_4(signed)' : \"{}\"\n",
                        triple_number_float_dual_1_4)) {
      CHECK(match_exactly<rtriple>(triple_number_float_dual_1_4));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_5(signed)' : \"{}\"\n",
                        triple_number_float_dual_1_5)) {
      CHECK(match_exactly<rtriple>(triple_number_float_dual_1_5));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_1' : \"{}\"\n",
                        triple_number_float_dual_2_1)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_2_1));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_2_1));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_2' : \"{}\"\n",
                        triple_number_float_dual_2_2)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_2_2));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_2_2));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_3' : \"{}\"\n",
                        triple_number_float_dual_2_3)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_2_3));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_2_3));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_4(signed)' : \"{}\"\n",
                        triple_number_float_dual_2_4)) {
      CHECK(match_exactly<rtriple>(triple_number_float_dual_2_4));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_5(signed)' : \"{}\"\n",
                        triple_number_float_dual_2_5)) {
      CHECK(match_exactly<rtriple>(triple_number_float_dual_2_5));
    }

    SECTION(fmt::format("'triple_number_float_dual_3_1' : \"{}\"\n",
                        triple_number_float_dual_3_1)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_3_1));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_3_1));
    }

    SECTION(fmt::format("'triple_number_float_dual_3_2' : \"{}\"\n",
                        triple_number_float_dual_3_2)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_3_2));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_3_2));
    }

    SECTION(fmt::format("'triple_number_float_dual_3_3(signed)' : \"{}\"\n",
                        triple_number_float_dual_3_3)) {
      CHECK(match_exactly<rtriple>(triple_number_float_dual_3_3));
    }

    SECTION(fmt::format("'triple_number_float_dual_3_4(signed)' : \"{}\"\n",
                        triple_number_float_dual_3_4)) {
      CHECK(match_exactly<rtriple>(triple_number_float_dual_3_4));
    }
  }

  SECTION("Values"){

    SECTION(fmt::format("'empty_triple' : \"{}\"\n",
                        empty_triple)) {
      INFO("Should not allow empty triples");
      CHECK(match_exactly<value>(fmt::format("({})",empty_triple)));
    }

    SECTION(fmt::format("'single_number_unsigned_float_1' : \"({})\"\n",
                        single_number_unsigned_float_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",single_number_unsigned_float_1)));
    }
    SECTION(fmt::format("'single_number_inverted_float_1' : \"({})\"\n",
                        single_number_inverted_float_1)) {
      INFO("Should not allow signed values");
      CHECK_THROWS(match_exactly<value>(fmt::format("({})",single_number_inverted_float_1)));
    }
    SECTION(fmt::format("'triple_number_int_single_1' : \"({})\"\n",
                        triple_number_int_single_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_int_single_1)));
    }
    SECTION(fmt::format("'triple_number_int_dual_1' : \"({})\"\n",
                        triple_number_int_dual_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_int_dual_1)));
    }
    SECTION(fmt::format("'triple_number_float_full_1' : \"({})\"\n",
                        triple_number_float_full_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_full_1)));
    }
    SECTION(fmt::format("'triple_number_float_single_1_1' : \"({})\"\n",
                        triple_number_float_single_1_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_1_1)));
    }
    SECTION(fmt::format("'triple_number_float_single_2_1' : \"({})\"\n",
                        triple_number_float_single_2_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_2_1)));
    }
    SECTION(fmt::format("'triple_number_float_single_3_1' : \"({})\"\n",
                        triple_number_float_single_3_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_3_1)));
    }
    SECTION(fmt::format("'triple_number_float_dual_1_1' : \"({})\"\n",
                        triple_number_float_dual_1_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_1_1)));
    }
    SECTION(fmt::format("'triple_number_float_dual_2_1' : \"({})\"\n",
                        triple_number_float_dual_2_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_2_1)));
    }
    SECTION(fmt::format("'triple_number_float_dual_3_1' : \"({})\"\n",
                        triple_number_float_dual_3_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_3_1)));
    }
  }

  SECTION("Signed Values"){

      SECTION(fmt::format("'empty_triple' : \"{}\"\n",
                        empty_triple)) {
      INFO("Should not allow empty triples");
      CHECK(match_exactly<rvalue>(fmt::format("({})",empty_triple)));
    }


    SECTION(fmt::format("'single_number_inverted_float_1' : \"({})\"\n",
                        single_number_inverted_float_1)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",single_number_inverted_float_1)));
    }
    SECTION(fmt::format("'triple_number_float_full_4_3_1' : \"({})\"\n",
                        triple_number_float_full_4)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",triple_number_float_full_4)));
    }
    SECTION(fmt::format("'triple_number_float_single_1_5' : \"({})\"\n",
                        triple_number_float_single_1_5)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",triple_number_float_single_1_5)));
    }
    SECTION(fmt::format("'triple_number_float_single_2_4' : \"({})\"\n",
                        triple_number_float_single_2_4)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",triple_number_float_single_2_4)));
    }
    SECTION(fmt::format("'triple_number_float_single_2_6' : \"({})\"\n",
                        triple_number_float_single_2_6)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",triple_number_float_single_2_6)));
    }
    SECTION(fmt::format("'triple_number_float_dual_1_4_1' : \"({})\"\n",
                        triple_number_float_dual_1_4)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",triple_number_float_dual_1_4)));
    }
    SECTION(fmt::format("'triple_number_float_dual_1_5_1' : \"({})\"\n",
                        triple_number_float_dual_1_5)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",triple_number_float_dual_1_5)));
    }
    SECTION(fmt::format("'triple_number_float_dual_2_4_1' : \"({})\"\n",
                        triple_number_float_dual_2_4)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",triple_number_float_dual_2_4)));
    }
    SECTION(fmt::format("'triple_number_float_dual_2_5_1' : \"({})\"\n",
                        triple_number_float_dual_2_5)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",triple_number_float_dual_2_5)));
    }
    SECTION(fmt::format("'triple_number_float_dual_3_3_1' : \"({})\"\n",
                        triple_number_float_dual_3_3)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",triple_number_float_dual_3_3)));
    }
    SECTION(fmt::format("'triple_number_float_dual_3_4_1' : \"({})\"\n",
                        triple_number_float_dual_3_4)) {
      CHECK(match_exactly<rvalue>(fmt::format("({})",triple_number_float_dual_3_4)));
    }
 
  }

} 
