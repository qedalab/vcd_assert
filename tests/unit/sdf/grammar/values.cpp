#include "values.hpp"

using namespace Parse::Test;
using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;

TEST_CASE("SDF.Grammar.Values") {

  SECTION("triple values") {

    SECTION(fmt::format("'empty_triple' : {}\n",
                        empty_triple)) {
      CHECK(match_exactly<triple>(empty_triple));
      CHECK(match_exactly<rtriple>(empty_triple));
    }

    SECTION(fmt::format("'triple_number_int_full' : {}\n",
                        triple_number_int_full)) {
      CHECK(match_exactly<triple>(triple_number_int_full));
      CHECK(match_exactly<rtriple>(triple_number_int_full));
    }

    SECTION(fmt::format("'triple_number_int_single_1' : {}\n",
                        triple_number_int_single_1)) {
      CHECK(match_exactly<triple>(triple_number_int_single_1));
      CHECK(match_exactly<rtriple>(triple_number_int_single_1));
    }

    SECTION(fmt::format("'triple_number_int_single_2' : {}\n",
                        triple_number_int_single_2)) {
      CHECK(match_exactly<triple>(triple_number_int_single_2));
      CHECK(match_exactly<rtriple>(triple_number_int_single_2));
    }

    SECTION(fmt::format("'triple_number_int_single_3' : {}\n",
                        triple_number_int_single_3)) {
      CHECK(match_exactly<triple>(triple_number_int_single_3));
      CHECK(match_exactly<rtriple>(triple_number_int_single_3));
    }

    SECTION(fmt::format("'triple_number_int_dual_1' : {}\n",
                        triple_number_int_dual_1)) {
      CHECK(match_exactly<triple>(triple_number_int_dual_1));
      CHECK(match_exactly<rtriple>(triple_number_int_dual_1));
    }

    SECTION(fmt::format("'triple_number_int_dual_2' : {}\n",
                        triple_number_int_dual_2)) {
      CHECK(match_exactly<triple>(triple_number_int_dual_2));
      CHECK(match_exactly<rtriple>(triple_number_int_dual_2));
    }

    SECTION(fmt::format("'triple_number_int_dual_3' : {}\n",
                        triple_number_int_dual_3)) {
      CHECK(match_exactly<triple>(triple_number_int_dual_3));
      CHECK(match_exactly<rtriple>(triple_number_int_dual_3));
    }

    SECTION(fmt::format("'triple_number_float_full_1' : {}\n",
                        triple_number_float_full_1)) {
      CHECK(match_exactly<triple>(triple_number_float_full_1));
      CHECK(match_exactly<rtriple>(triple_number_float_full_1));
    }

    SECTION(fmt::format("'triple_number_float_full_2' : {}\n",
                        triple_number_float_full_2)) {
      CHECK(match_exactly<triple>(triple_number_float_full_2));
      CHECK(match_exactly<rtriple>(triple_number_float_full_2));
    }

    SECTION(fmt::format("'triple_number_float_full_3' : {}\n",
                        triple_number_float_full_3)) {
      CHECK(match_exactly<triple>(triple_number_float_full_3));
      CHECK(match_exactly<rtriple>(triple_number_float_full_3));
    }

    SECTION(fmt::format("'triple_number_float_full_4' : {}\n",
                        triple_number_float_full_4)) {
      CHECK(match_exactly<triple>(triple_number_float_full_4));
      CHECK(match_exactly<rtriple>(triple_number_float_full_4));
    }

    SECTION(fmt::format("'triple_number_float_single_1_1' : {}\n",
                        triple_number_float_single_1_1)) {
      CHECK(match_exactly<triple>(triple_number_float_single_1_1));
      CHECK(match_exactly<rtriple>(triple_number_float_single_1_1));
    }

    SECTION(fmt::format("'triple_number_float_single_1_2' : {}\n",
                        triple_number_float_single_1_2)) {
      CHECK(match_exactly<triple>(triple_number_float_single_1_2));
      CHECK(match_exactly<rtriple>(triple_number_float_single_1_2));
    }

    SECTION(fmt::format("'triple_number_float_single_1_3' : {}\n",
                        triple_number_float_single_1_3)) {
      CHECK(match_exactly<triple>(triple_number_float_single_1_3));
      CHECK(match_exactly<rtriple>(triple_number_float_single_1_3));
    }

    SECTION(fmt::format("'triple_number_float_single_1_4' : {}\n",
                        triple_number_float_single_1_4)) {
      CHECK(match_exactly<triple>(triple_number_float_single_1_4));
      CHECK(match_exactly<rtriple>(triple_number_float_single_1_4));
    }

    SECTION(fmt::format("'triple_number_float_single_2_1' : {}\n",
                        triple_number_float_single_2_1)) {
      CHECK(match_exactly<triple>(triple_number_float_single_2_1));
      CHECK(match_exactly<rtriple>(triple_number_float_single_2_1));
    }

    SECTION(fmt::format("'triple_number_float_single_2_2' : {}\n",
                        triple_number_float_single_2_2)) {
      CHECK(match_exactly<triple>(triple_number_float_single_2_2));
      CHECK(match_exactly<rtriple>(triple_number_float_single_2_2));
    }

    SECTION(fmt::format("'triple_number_float_single_2_3' : {}\n",
                        triple_number_float_single_2_3)) {
      CHECK(match_exactly<triple>(triple_number_float_single_2_3));
      CHECK(match_exactly<rtriple>(triple_number_float_single_2_3));
    }

    SECTION(fmt::format("'triple_number_float_single_3_1' : {}\n",
                        triple_number_float_single_3_1)) {
      CHECK(match_exactly<triple>(triple_number_float_single_3_1));
      CHECK(match_exactly<rtriple>(triple_number_float_single_3_1));
    }

    SECTION(fmt::format("'triple_number_float_single_3_2' : {}\n",
                        triple_number_float_single_3_2)) {
      CHECK(match_exactly<triple>(triple_number_float_single_3_2));
      CHECK(match_exactly<rtriple>(triple_number_float_single_3_2));
    }

    SECTION(fmt::format("'triple_number_float_single_3_3' : {}\n",
                        triple_number_float_single_3_3)) {
      CHECK(match_exactly<triple>(triple_number_float_single_3_3));
      CHECK(match_exactly<rtriple>(triple_number_float_single_3_3));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_1' : {}\n",
                        triple_number_float_dual_1_1)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_1_1));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_1_1));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_2' : {}\n",
                        triple_number_float_dual_1_2)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_1_2));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_1_2));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_3' : {}\n",
                        triple_number_float_dual_1_3)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_1_3));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_1_3));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_1' : {}\n",
                        triple_number_float_dual_2_1)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_2_1));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_2_1));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_2' : {}\n",
                        triple_number_float_dual_2_2)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_2_2));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_2_2));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_3' : {}\n",
                        triple_number_float_dual_2_3)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_2_3));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_2_3));
    }

    SECTION(fmt::format("'triple_number_float_dual_3_1' : {}\n",
                        triple_number_float_dual_3_1)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_3_1));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_3_1));
    }

    SECTION(fmt::format("'triple_number_float_dual_3_2' : {}\n",
                        triple_number_float_dual_3_2)) {
      CHECK(match_exactly<triple>(triple_number_float_dual_3_2));
      CHECK(match_exactly<rtriple>(triple_number_float_dual_3_2));
    }
  }

  SECTION("values") {

    SECTION(fmt::format("'empty_triple' : ({})\n",
                        empty_triple)) {
      CHECK(match_exactly<value>(fmt::format("({})",empty_triple)));
    }

    SECTION(fmt::format("'triple_number_int_full' : ({})\n",
                        triple_number_int_full)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_int_full)));
    }

    SECTION(fmt::format("'triple_number_int_single_1' : ({})\n",
                        triple_number_int_single_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_int_single_1)));
    }

    SECTION(fmt::format("'triple_number_int_single_2' : ({})\n",
                        triple_number_int_single_2)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_int_single_2)));
    }

    SECTION(fmt::format("'triple_number_int_single_3' : ({})\n",
                        triple_number_int_single_3)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_int_single_3)));
    }

    SECTION(fmt::format("'triple_number_int_dual_1' : ({})\n",
                        triple_number_int_dual_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_int_dual_1)));
    }

    SECTION(fmt::format("'triple_number_int_dual_2' : ({})\n",
                        triple_number_int_dual_2)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_int_dual_2)));
    }

    SECTION(fmt::format("'triple_number_int_dual_3' : ({})\n",
                        triple_number_int_dual_3)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_int_dual_3)));
    }

    SECTION(fmt::format("'triple_number_float_full_1' : ({})\n",
                        triple_number_float_full_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_full_1)));
    }

    SECTION(fmt::format("'triple_number_float_full_2' : ({})\n",
                        triple_number_float_full_2)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_full_2)));
    }

    SECTION(fmt::format("'triple_number_float_full_3' : ({})\n",
                        triple_number_float_full_3)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_full_3)));
    }

    SECTION(fmt::format("'triple_number_float_full_4' : ({})\n",
                        triple_number_float_full_4)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_full_4)));
    }

    SECTION(fmt::format("'triple_number_float_single_1_1' : ({})\n",
                        triple_number_float_single_1_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_1_1)));
    }

    SECTION(fmt::format("'triple_number_float_single_1_2' : ({})\n",
                        triple_number_float_single_1_2)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_1_2)));
    }

    SECTION(fmt::format("'triple_number_float_single_1_3' : ({})\n",
                        triple_number_float_single_1_3)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_1_3)));
    }

    SECTION(fmt::format("'triple_number_float_single_1_4' : ({})\n",
                        triple_number_float_single_1_4)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_1_4)));
    }

    SECTION(fmt::format("'triple_number_float_single_2_1' : ({})\n",
                        triple_number_float_single_2_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_2_1)));
    }

    SECTION(fmt::format("'triple_number_float_single_2_2' : ({})\n",
                        triple_number_float_single_2_2)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_2_2)));
    }

    SECTION(fmt::format("'triple_number_float_single_2_3' : ({})\n",
                        triple_number_float_single_2_3)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_2_3)));
    }

    SECTION(fmt::format("'triple_number_float_single_3_1' : ({})\n",
                        triple_number_float_single_3_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_3_1)));
    }

    SECTION(fmt::format("'triple_number_float_single_3_2' : ({})\n",
                        triple_number_float_single_3_2)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_3_2)));
    }

    SECTION(fmt::format("'triple_number_float_single_3_3' : ({})\n",
                        triple_number_float_single_3_3)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_single_3_3)));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_1' : ({})\n",
                        triple_number_float_dual_1_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_1_1)));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_2' : ({})\n",
                        triple_number_float_dual_1_2)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_1_2)));
    }

    SECTION(fmt::format("'triple_number_float_dual_1_3' : ({})\n",
                        triple_number_float_dual_1_3)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_1_3)));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_1' : ({})\n",
                        triple_number_float_dual_2_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_2_1)));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_2' : ({})\n",
                        triple_number_float_dual_2_2)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_2_2)));
    }

    SECTION(fmt::format("'triple_number_float_dual_2_3' : ({})\n",
                        triple_number_float_dual_2_3)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_2_3)));
    }

    SECTION(fmt::format("'triple_number_float_dual_3_1' : ({})\n",
                        triple_number_float_dual_3_1)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_3_1)));
    }

    SECTION(fmt::format("'triple_number_float_dual_3_2' : ({})\n",
                        triple_number_float_dual_3_2)) {
      CHECK(match_exactly<value>(fmt::format("({})",triple_number_float_dual_3_2)));
    }
  }
}
