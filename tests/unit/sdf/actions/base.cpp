#include <sdf/grammar/base.hpp>
#include <sdf/actions/base.hpp>

// using namespace Parse::Test;
using namespace SDF;
using namespace SDF::Grammar;


#include <catch2/catch.hpp>

// constexpr auto four_state_vcd_example_header_str =
//     "$date June 26, 1989 10:05:41\n"
//     "$end\n"
//     "$version VERILOG-SIMULATOR 1.0a\n"
//     "$end\n"
//     "$timescale 1 ns\n"
//     "$end\n"
//     "$scope module top $end\n"
//     "$scope module m1 $end\n" // Error here?
//     "$var trireg 1 *@ net1 $end\n"
//     "$var trireg 1 *# net2 $end\n"
//     "$var trireg 1 *$ net3 $end\n"
//     "$upscope $end\n"
//     "$scope task t1 $end\n"
//     "$var reg 32 (k accumulator[31:0] $end\n"
//     "$var integer 32 {2 index $end\n"
//     "$upscope $end\n"
//     "$upscope $end\n"
//     "$enddefinitions $end\n";

// static Test::TestHeader vcd_4_state_example_header {
//     TimeScale {TimeNumber::_1, TimeUnit::ns},
//     "June 26, 1989 10:05:41",
//     "VERILOG-SIMULATOR 1.0a",
//     Test::TestScope {
//         ScopeType::module,
//         "top",
//         {
//             Test::TestScope {
//                 ScopeType::module,
//                 "m1",
//                 {
//                     // No modules in m1
//                 },
//                 {
//                     {VarType::trireg, 1, "*@", "net1"},
//                     {VarType::trireg, 1, "*#", "net2"},
//                     {VarType::trireg, 1, "*$", "net3"}
//                 }
//             },
//             Test::TestScope {
//                 ScopeType::task,
//                 "t1",
//                 {
//                     // modules in t1
//                 },
//                 {
//                     {VarType::reg, 32, "(k", "accumulator[31:0]"},
//                     {VarType::integer, 32, "{2", "index"}
//                 }
//             }
//         },
//         {
//             // No variables in top
//         }
//     }
// };

// static Test::TestHeader vcd_4_state_example_header {
//     TimeScale {TimeNumber::_1, TimeUnit::ns},
//     Date{"June 26, 1989 10:05:41"},
//     Progam{"VERILOG-SIMULATOR 1.0a"},
//     Cell{
//       TimingCheck{}
//     },
//     Cell{
//       TimingDelay{}
//     },
//       Test::TestScope {
//         ScopeType::module,
//         "top",
//         {
//             Test::TestScope {
//                 ScopeType::module,
//                 "m1",
//                 {
//                     // No modules in m1
//                 },
//                 {
//                     {VarType::trireg, 1, "*@", "net1"},
//                     {VarType::trireg, 1, "*#", "net2"},
//                     {VarType::trireg, 1, "*$", "net3"}
//                 }
//             },
//             Test::TestScope {
//                 ScopeType::task,
//                 "t1",
//                 {
//                     // modules in t1
//                 },
//                 {
//                     {VarType::reg, 32, "(k", "accumulator[31:0]"},
//                     {VarType::integer, 32, "{2", "index"}
//                 }
//             }
//         },
//         {
//             // No variables in top
//         }
//     }
// };

// TEST_CASE("SDF.Actions.Base", "[SDF][Actions][Base]") {

//   std::string result;
//   require_parse<Grammar::qstring, Actions::QStringAction>(
//       qstring_example_1_str, result);

//   auto header_p = reader.release();
//   REQUIRE(header_p.operator bool());
//   auto &header = *header_p.get();
//   Test::catch_test_header(header, vcd_4_state_example_header);
// }


// TEST_CASE("SDF.Actions") {
//   SECTION("Delayfile") {
//     JSONValuePtr json;


//     tao::pegtl::memory_input<> input(std::begin(json_example),
//                                      std::end(json_example), "json_example");

//     bool success = tao::pegtl::parse<json_grammar::text, make_pegtl_template<JSONValueAction>::type,
//                                      capture_control>(input, json);

//     REQUIRE(success);

//     // Make sure that the main object exists
//     REQUIRE(bool(json));
//     REQUIRE(std::holds_alternative<JSONObject>(*json));
//     JSONObject* main_object = &std::get<JSONObject>(*json);

//     // Ensure that there are not excessive keys in the object
//     REQUIRE(main_object->size() == 3);

//     // Check that name == "John
//     main_object->at("name");
//     JSONValuePtr& name_value = main_object->at("name");
//     REQUIRE(bool(name_value));
//     REQUIRE(std::holds_alternative<JSONString>(*name_value));
//     REQUIRE(std::get<JSONString>(*name_value) == "John");

//     // Check that age == 30
//     JSONValuePtr& age_value = main_object->at("age");
//     REQUIRE(std::holds_alternative<JSONNumber>(*age_value));
//     REQUIRE(std::get<JSONNumber>(*age_value) == Approx(30));

//     // Check that cars == ["Ford", "BMW", "Fiat"]
//     JSONValuePtr& cars_value = main_object->at("cars");
//     REQUIRE(std::holds_alternative<JSONArray>(*cars_value));
//     JSONArray& cars_array = std::get<JSONArray>(*cars_value);

//     REQUIRE(cars_array.size() == 3);
//     REQUIRE(std::holds_alternative<JSONString>(*cars_array[0]));
//     REQUIRE(std::get<JSONString>(*cars_array[0]) == "Ford");
//     REQUIRE(std::holds_alternative<JSONString>(*cars_array[1]));
//     REQUIRE(std::get<JSONString>(*cars_array[1]) == "BMW");
//     REQUIRE(std::holds_alternative<JSONString>(*cars_array[2]));
//     REQUIRE(std::get<JSONString>(*cars_array[2]) == "Fiat");
//   }
// }
