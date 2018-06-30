#include "parse/control/scoped.h"

#include <catch2/catch.hpp>
#include <tao/pegtl/contrib/json.hpp>

#include <variant>
#include <tao/pegtl/parse.hpp>

#include "./json.hpp"

using namespace Parse;

template<class Rule>
struct JSONActions : tao::pegtl::nothing<Rule> {};

template<>
struct JSONActions<json_grammar::string_content> {
    using state = JSONString;
    template<class Rule> using action = JSONActions<Rule>;

    template<class Input>
    static void apply(const Input& in, state& string)
    {
        // Do I need to escape the string: Yes
        // Am I going to for this test case: No
        string = in.string();
    }
};

template<>
struct JSONActions<json_grammar::key_content> :
        public JSONActions<json_grammar::string_content> {};

template<>
struct JSONActions<json_grammar::number> {
    using state = JSONNumber;
    template<class Rule> using action = JSONActions<Rule>;

    template<class Input>
    static void apply(const Input& in, state& number)
    {
        number = std::stod(in.string());
    }
};

template<>
struct JSONActions<json_grammar::array_content> {
    using state = JSONArray;
    template<class Rule> using action = JSONActions<Rule>;

    static void apply0(state&) {};

};

template<>
struct JSONActions<JSONArray> {
    static void success(JSONArray& array, JSONValuePtr value) {
        array.push_back(std::move(value));
    }
};

template<>
struct JSONActions<json_grammar::value> {
    using state = JSONValuePtr;
    template<class Rule> using action = JSONActions<Rule>;

    static void apply0(state&) {};

    template<class InnerValue>
    static void success(state& value_ptr, InnerValue value) {
        if constexpr (std::is_same_v<JSONValuePtr, InnerValue>) {
            value_ptr = std::move(value);
        } else {
            value_ptr = std::make_unique<JSONValue>(std::move(value));
        }
    }
};

template<>
struct JSONActions<JSONValuePtr> {
    template<class InnerValue>
    static void success(JSONValuePtr& value_ptr, InnerValue value) {
        if constexpr (std::is_same_v<JSONValuePtr, InnerValue>) {
            value_ptr = std::move(value);
        } else {
            value_ptr = std::make_unique<JSONValue>(std::move(value));
        }
    }
};

template<>
struct JSONActions<json_grammar::true_> {
    using state = JSONBool;
    template<class Rule> using action = JSONActions<Rule>;

    static void apply0(state& value) {
        value = true;
    }
};

template<>
struct JSONActions<json_grammar::false_> {
    using state = JSONBool;
    template<class Rule> using action = JSONActions<Rule>;

    static void apply0(state& value) {
        value = false;
    }
};

template<>
struct JSONActions<json_grammar::object_content> {
    using state = JSONObject;
    template<class Rule> using action = JSONActions<Rule>;

    static void apply0(state& value) {}
};

template<>
struct JSONActions<JSONObject> {
    static void success(JSONObject& object, JSONObjectKeyPair key_pair) {
        // Should I check that the key doesn't exist: Yes
        // Am I going to: No
        object[key_pair.key] = std::move(key_pair.value);
    }
};

template<>
struct JSONActions<json_grammar::member> {
    using state = JSONObjectKeyPair;
    template<class Rule> using action = JSONActions<Rule>;

    static void apply0(state& value) {}
};

template<>
struct JSONActions<JSONObjectKeyPair> {
    static void success(JSONObjectKeyPair& key_pair, JSONString&& key) {
        key_pair.key = std::move(key);
    }

    static void success(JSONObjectKeyPair& key_pair, JSONValuePtr&& value) {
        key_pair.value = std::move(value);
    }
};

struct StructWithMembers {
    using state = bool;
    template<class Rule> using action = tao::pegtl::nothing<Rule>;
};

struct StructWithoutMembers {
};

TEST_CASE("Parse.ScopedControl") {
    SECTION("member_state_t")        REQUIRE(Internal::is_detected<member_state_t, StructWithMembers>);
        REQUIRE(!Internal::is_detected<member_state_t, StructWithoutMembers>);        REQUIRE(Internal::is_detected<member_state_t, StructWithMembers>);
        REQUIRE(!Internal::is_detected<member_state_t, StructWithoutMembers>); {
    }

    SECTION("member_action_t") {
        REQUIRE(Internal::is_detected<member_action_t, StructWithMembers, void>);
        REQUIRE(!Internal::is_detected<member_action_t, StructWithoutMembers, void>);
    }

    SECTION("JSON") {
        JSONValuePtr json;

        tao::pegtl::memory_input<> input(std::begin(json_example),
                                         std::end(json_example), "json_example");

        bool success = tao::pegtl::parse<json_grammar::text, JSONActions,
                scoped_control>(input, json);

        REQUIRE(success);

        // Make sure that the main object exists
        REQUIRE(bool(json));
        REQUIRE(std::holds_alternative<JSONObject>(*json));
        JSONObject* main_object = &std::get<JSONObject>(*json);

        // Ensure that there are not excessive keys in the object
        REQUIRE(main_object->size() == 3);

        // Check that name == "John        REQUIRE(std::holds_alternative<JSONObject>(*json));"
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
