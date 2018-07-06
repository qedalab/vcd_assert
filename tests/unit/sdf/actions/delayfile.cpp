#include <sdf/grammar/base.hpp>
#include <sdf/actions/base.hpp>
#include <sdf/types/delayfile.hpp>

// using namespace Parse::Test;
using namespace SDF;
using namespace SDF::Grammar;


#include <catch2/catch.hpp>


TEST_CASE("SDF.Actions.Base", "[SDF][Actions][Base]") {

  std::string result;
  require_parse<Grammar::qstring, Actions::QStringAction>(
      qstring_example_1_str, result);

  auto header_p = reader.release();
  REQUIRE(header_p.operator bool());
  auto &header = *header_p.get();
  Test::catch_test_header(header, vcd_4_state_example_header);
}


TEST_CASE("SDF.Actions") {
  SECTION("Delayfile") {
    
    using Parse::Test::require_parse;
    
    DelayFileReader dfr;

    require_parse<Grammar::delayfile, Actions::HeaderAction>(
        basic_example_delayfile, dfr);

    auto header_p = reader.release();
    REQUIRE(header_p.operator bool());
    Test::catch_test_header(*header_p, vcd_4_state_example_header);
    // // Make sure that the main object exists
    // REQUIRE(bool(json));
    // REQUIRE(std::holds_alternative<JSONObject>(*json));
    // JSONObject* main_object = &std::get<JSONObject>(*json);

    // Ensure that there are not excessive keys in the object
    REQUIRE(main_object->size() == 3);

    // Check that name == "John
    main_object->at("name");
    JSONValuePtr& name_value = main_object->at("name");
    REQUIRE(bool(name_value));
    REQUIRE(std::holds_alternative<JSONString>(*name_value));
    REQUIRE(std::get<JSONString>(*name_value) == "John");

    // Check that age == 30
    JSONValuePtr& age_value = main_object->at("age");
    REQUIRE(std::holds_alternative<JSONNumber>(*age_value));
    REQUIRE(std::get<JSONNumber>(*age_value) == Approx(30));

    // Check that cars == ["Ford", "BMW", "Fiat"]
    JSONValuePtr& cars_value = main_object->at("cars");
    
    REQUIRE(std::holds_alternative<JSONArray>(*cars_value));
    
    JSONArray& cars_array = std::get<JSONArray>(*cars_value);
    
    REQUIRE(cars_array.size() == 3);
    REQUIRE(std::holds_alternative<JSONString>(*cars_array[0]));
    REQUIRE(std::get<JSONString>(*cars_array[0]) == "Ford");
    REQUIRE(std::holds_alternative<JSONString>(*cars_array[1]));
    REQUIRE(std::get<JSONString>(*cars_array[1]) == "BMW");
    REQUIRE(std::holds_alternative<JSONString>(*cars_array[2]));
    REQUIRE(std::get<JSONString>(*cars_array[2]) == "Fiat");
  }
}
