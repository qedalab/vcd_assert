#include "values.hpp"

using namespace Parse::Test;
using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;

// clang-format off
static constexpr std::array<std::string_view, 4> exponent_str = {
  "e1",
  "e-1",
  "e100",
  "e-100",
};

constexpr auto unsigned_int_number = "1234";
constexpr auto signed_int_number = "+1234";

static constexpr std::array<std::string_view, 9> single_number_unsigned = {
  "1.1234",
  "1.1234e1",
  "1.1234e-1",
  "123.1234",
  "123.1234e1",
  "123.1234e-1",
  ".1234",
  ".1234e1",
  ".1234e-1",
};

static constexpr std::array<std::string_view, 9> single_number_inverted = {
  "-1.1234",
  "-1.1234e1",
  "-1.1234e-1",
  "-123.1234",
  "-123.1234e1",
  "-123.1234e-1",
  "-.1234",
  "-.1234e1",
  "-.1234e-1",
};

static constexpr auto empty_triple = " :: ";

static constexpr std::array<std::string_view, 7> triple_number_int = {
  "1:1:1",
  "1::",
  ":1:",
  "::1",
  "1:1:",
  "1::1",
  ":1:1"
};

static constexpr std::array<std::string_view, 10> triple_number_float_signed = {
  // Full
  "1.111123:-1.332:1.2e123",

  // Single
  "-1.4e-2::",
  ":-1.123e-6:",
  ":-.123e-6:",
  "-1.7:-1.8:",

  // Double
  "1.9::-1.10",
  "-1.9::-1.10",
  "-1.7:1.8:",
  ":-.11e11:1.12e-1",
  ":-.11e11:-1.12e-1"
};

static constexpr std::array<std::string_view, 23> triple_number_float = {
  // Full
  "1.1:1.3:1.2",
  "1.1e1:1.3:1.2",
  "1.1e1:1.3e22:1.2e-13",

  // Single
  "1.4::",
  "1.4e12::",
  "1.4e-2::",
  ".4e-2::",
  ":1.123:",
  ":1.123e6:",
  ":1.123e-6:",
  ":.123e-6:",
  "::1.633",
  "::1.6e123",
  "::.6e123",
  "::1.6e123",

  // Dual
  "1.7:1.8:",
  "1.7e1:1.8e-1:",
  ".7e1:.8e-1:",
  ".9::.10",
  "1.9::1.10",
  "1.9e0::1.10e12",
  ":.11e11:1.12",
  ":.11e11:1.12e-1",
};
// clang-format on

TEST_CASE("SDF.Grammar.Values", "[SDF][Grammar][Values]")
{
  SECTION("Single numbers")
  {
    SECTION("Unsigned")
    {
      for (auto sv : single_number_unsigned) {
        SECTION(std::string(sv))
        {
          CHECK(match_exactly<signed_real_number>(sv));
          CHECK(match_exactly<real_number>(sv));
        }
      }
    }

    SECTION("Inverted")
    {
      for (auto sv : single_number_inverted) {
        SECTION(std::string(sv))
        {
          CHECK(match_exactly<signed_real_number>(sv));
          CHECK_THROWS(match_exactly<real_number>(sv));
        }
      }
    }
  }

  SECTION("Triple Numbers")
  {

    // SECTION(fmt::format("'empty_triple' : \"{}\"\n",
    //                     empty_triple)) {
    //   INFO("Should not allow empty triples");
    //   CHECK_FALSE(match_exactly<triple>(empty_triple));
    //   CHECK_FALSE(match_exactly<rtriple>(empty_triple));
    // }

    SECTION("Int")
    {
      for (auto sv : triple_number_int) {
        SECTION(std::string(sv))
        {
          CHECK(match_exactly<triple>(sv));
          CHECK(match_exactly<rtriple>(sv));
        }
      }
    }

    SECTION("Float")
    {
      for (std::string_view sv : triple_number_float) {
        SECTION(std::string(sv))
        {
          INFO(std::string(sv));
          CHECK(match_exactly<triple>(sv));
          CHECK(match_exactly<rtriple>(sv));
        }
      }
    }

    SECTION("Float signed")
    {
      for (auto sv : triple_number_int) {
        SECTION(std::string(sv)) { CHECK(match_exactly<rtriple>(sv)); }
      }
    }
  }

  SECTION("Values")
  {
    SECTION(fmt::format("'empty_triple' : \"{}\"\n", empty_triple))
    {
      INFO("Should not allow empty triples");
      CHECK(match_exactly<value>(fmt::format("({})", empty_triple)));
    }

    SECTION("Single unsigned")
    {
      for (auto sv : single_number_unsigned) {
        SECTION(std::string(sv))
        {
          CHECK(match_exactly<rvalue>(fmt::format("({})", sv)));
        }
      }
    }

    SECTION("Single signed")
    {
      for (auto sv : single_number_inverted) {
        INFO("Should not allow signed values");
        SECTION(std::string(sv))
        {
          CHECK_THROWS(match_exactly<value>(fmt::format("({})", sv)));
          CHECK(match_exactly<rvalue>(fmt::format("({})", sv)));
        }
      }
    }

    SECTION("Triple int")
    {
      for (auto sv : triple_number_int) {
        SECTION(std::string(sv))
        {
          CHECK(match_exactly<rvalue>(fmt::format("({})", sv)));
        }
      }
    }

    SECTION("Triple unsigned")
    {
      for (auto sv : triple_number_float) {
        SECTION(std::string(sv))
        {
          CHECK(match_exactly<rvalue>(fmt::format("({})", sv)));
          CHECK(match_exactly<value>(fmt::format("({})", sv)));
        }
      }
    }

    SECTION("Triple signed")
    {
      for (auto sv : triple_number_float_signed) {
        SECTION(std::string(sv))
        {
          CHECK(match_exactly<rvalue>(fmt::format("({})", sv)));
          CHECK_THROWS(match_exactly<value>(fmt::format("({})", sv)));
        }
      }
    }
  }
}
