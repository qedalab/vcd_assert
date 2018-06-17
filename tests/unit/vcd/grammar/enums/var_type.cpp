#include "vcd/grammar/enums/var_type.hpp"
#include "vcd/types/enums.hpp"

#include "parse/test/match.h"

#include <catch.hpp>

using namespace Parse::Test;
using namespace VCD::Grammar;
using VCD::VarType;

constexpr char event_str[] = "event";
constexpr char integer_str[] = "integer";
constexpr char parameter_str[] = "parameter";
constexpr char real_str[] = "real";
constexpr char realtime_str[] = "realtime";
constexpr char reg_str[] = "reg";
constexpr char supply0_str[] = "supply0";
constexpr char supply1_str[] = "supply1";
constexpr char time_str[] = "time";
constexpr char tri_str[] = "tri";
constexpr char triand_str[] = "triand";
constexpr char trior_str[] = "trior";
constexpr char trireg_str[] = "trireg";
constexpr char tri0_str[] = "tri0";
constexpr char tri1_str[] = "tri1";
constexpr char wand_str[] = "wand";
constexpr char wire_str[] = "wire";
constexpr char wor_str[] = "wor";

TEST_CASE("VCD.Grammar.Enums.VarType", "[VCD][Grammar][Enums][VarType]") {
  SECTION("Individual") {
    CHECK(match_value_exactly<var_event>(event_str, VarType::event));
    CHECK(match_value_exactly<var_integer>(integer_str, VarType::integer));
    CHECK(match_value_exactly<var_parameter>(parameter_str, VarType::parameter));
    CHECK(match_value_exactly<var_real>(real_str, VarType::real));
    CHECK(match_value_exactly<var_realtime>(realtime_str, VarType::realtime));
    CHECK(match_value_exactly<var_reg>(reg_str, VarType::reg));
    CHECK(match_value_exactly<var_supply0>(supply0_str, VarType::supply0));
    CHECK(match_value_exactly<var_supply1>(supply1_str, VarType::supply1));
    CHECK(match_value_exactly<var_time>(time_str, VarType::time));
    CHECK(match_value_exactly<var_tri>(tri_str, VarType::tri));
    CHECK(match_value_exactly<var_triand>(triand_str, VarType::triand));
    CHECK(match_value_exactly<var_trior>(trior_str, VarType::trior));
    CHECK(match_value_exactly<var_trireg>(trireg_str, VarType::trireg));
    CHECK(match_value_exactly<var_tri0>(tri0_str, VarType::tri0));
    CHECK(match_value_exactly<var_tri1>(tri1_str, VarType::tri1));
    CHECK(match_value_exactly<var_wand>(wand_str, VarType::wand));
    CHECK(match_value_exactly<var_wire>(wire_str, VarType::wire));
    CHECK(match_value_exactly<var_wor>(wor_str, VarType::wor));
  }

  SECTION("Together") {
    CHECK(match_value_exactly<var_type>(event_str, VarType::event));
    CHECK(match_value_exactly<var_type>(integer_str, VarType::integer));
    CHECK(match_value_exactly<var_type>(parameter_str, VarType::parameter));
    CHECK(match_value_exactly<var_type>(real_str, VarType::real));
    CHECK(match_value_exactly<var_type>(realtime_str, VarType::realtime));
    CHECK(match_value_exactly<var_type>(reg_str, VarType::reg));
    CHECK(match_value_exactly<var_type>(supply0_str, VarType::supply0));
    CHECK(match_value_exactly<var_type>(supply1_str, VarType::supply1));
    CHECK(match_value_exactly<var_type>(time_str, VarType::time));
    CHECK(match_value_exactly<var_type>(tri_str, VarType::tri));
    CHECK(match_value_exactly<var_type>(triand_str, VarType::triand));
    CHECK(match_value_exactly<var_type>(trior_str, VarType::trior));
    CHECK(match_value_exactly<var_type>(trireg_str, VarType::trireg));
    CHECK(match_value_exactly<var_type>(tri0_str, VarType::tri0));
    CHECK(match_value_exactly<var_type>(tri1_str, VarType::tri1));
    CHECK(match_value_exactly<var_type>(wand_str, VarType::wand));
    CHECK(match_value_exactly<var_type>(wire_str, VarType::wire));
    CHECK(match_value_exactly<var_type>(wor_str, VarType::wor));

    CHECK(var_type::error() != nullptr);
  }
}

