#include "parse/actions/storage/member.hpp"
#include "parse/actions/control.hpp"
#include "parse/actions/storage/push_back.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/apply0.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/actions/apply/string.hpp"
#include "parse/actions/apply/value.hpp"
#include "parse/actions/apply/integer.hpp"

#include <catch2/catch.hpp>

#include <variant>
#include <tao/pegtl/parse.hpp>

#include "./json.hpp"

using namespace Parse;

struct JSONObjectStorage {
  static bool store(JSONObject &parent, JSONObjectKeyPair child) {
    parent[std::move(child.key)] = std::move(child.value);
    return true;
  }
};

struct JSONValuePtrStorage {
  template<class InnerValue>
  static bool store(JSONValuePtr& value_ptr, InnerValue value) {
    if constexpr (std::is_same_v<JSONValuePtr, InnerValue>) {
      value_ptr = std::move(value);
    } else {
      value_ptr = std::make_unique<JSONValue>(std::move(value));
    }

    return true;
  }
};

struct JSONValueAction;

struct JSONBoolAction : multi_dispatch<
    json_grammar::false_, apply0<Apply::value<false>>,
    json_grammar::true_, apply0<Apply::value<true>>
> {
  using state = bool;
};

struct JSONStringAction : single_dispatch<
    json_grammar::string_content, apply<Apply::string>
>{
  using state = JSONString;
};

struct JSONArrayAction : single_dispatch<
    json_grammar::value, inner_action<JSONValueAction, Storage::push_back>
> {
  using state = JSONArray;
};

struct JSONKeyAction : single_dispatch<
    json_grammar::key_content, apply<Apply::string>
> {
  using state = JSONString;
};


struct JSONMemberAction : multi_dispatch<
    json_grammar::value, inner_action<JSONValueAction, Storage::member<&JSONObjectKeyPair::value>>,
    json_grammar::key, inner_action<JSONKeyAction, Storage::member<&JSONObjectKeyPair::key>>
> {
  using state = JSONObjectKeyPair;
};

struct JSONObjectAction : single_dispatch<
    json_grammar::member, inner_action<JSONMemberAction, JSONObjectStorage>
> {
  using state = JSONObject;
};

struct JSONNumberAction : single_dispatch<
    json_grammar::number, apply<Apply::integer>
> {
  using state = JSONNumber;
};

struct JSONValueAction : multi_dispatch<
    json_grammar::array, inner_action<JSONArrayAction, JSONValuePtrStorage>,
    json_grammar::object, inner_action<JSONObjectAction, JSONValuePtrStorage>,
    json_grammar::false_, inner_action<JSONBoolAction, JSONValuePtrStorage>,
    json_grammar::true_, inner_action<JSONBoolAction, JSONValuePtrStorage>,
    json_grammar::number, inner_action<JSONNumberAction, JSONValuePtrStorage>,
    json_grammar::string, inner_action <JSONStringAction, JSONValuePtrStorage>
> {
  using state = JSONValuePtr;
};

TEST_CASE("Parse.CaptureControl") {
  SECTION("JSON") {
    JSONValuePtr json;


    tao::pegtl::memory_input<> input(std::begin(json_example),
                                     std::end(json_example), "json_example");

    bool success = tao::pegtl::parse<json_grammar::text, make_pegtl_template<JSONValueAction>::type,
                                     capture_control>(input, json);

    REQUIRE(success);

    // Make sure that the main object exists
    REQUIRE(bool(json));
    REQUIRE(std::holds_alternative<JSONObject>(*json));
    JSONObject* main_object = &std::get<JSONObject>(*json);

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
