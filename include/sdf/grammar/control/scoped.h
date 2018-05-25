#include "parse/control/scoped.h"

#include <catch.hpp>
#include <tao/pegtl/contrib/json.hpp>

#include <tao/pegtl/parse.hpp>
#include <variant>

namespace JSON {
namespace Grammar {
namespace Control {

using namespace Parse;
using namespace Internal;

namespace json_grammer = tao::pegtl::json;

struct JSONNull {};
struct JSONValue;

using JSONValuePtr = std::unique_ptr<JSONValue>;

using JSONString = std::string;
using JSONNumber = double;
using JSONBool = bool;
using JSONArray = std::vector<JSONValuePtr>;
using JSONObject = std::map<JSONString, JSONValuePtr>;

// I require this object for keeping the state of key
struct JSONObjectKeyPair {
  JSONValuePtr value;
  JSONString key;
};

template <class Rule>
struct JSONActions : tao::pegtl::nothing<Rule> {};

using JSONValueVariant = std::variant<JSONNull, JSONString, JSONNumber,
                                      JSONArray, JSONObject, JSONBool>;

struct JSONValue : public JSONValueVariant {
  using JSONValueVariant::JSONValueVariant;
};

template <>
struct JSONActions<json_grammer::string_content> {
  using state = JSONString;
  template <class Rule>
  using action = JSONActions<Rule>;

  template <class Input>
  static void apply(const Input &in, state &string) {
    // Do I need to escape the string: Yes
    // Am I going to for this test case: No
    string = in.string();
  }
};

template <>
struct JSONActions<json_grammer::key_content>
    : public JSONActions<json_grammer::string_content> {};

template <>
struct JSONActions<json_grammer::number> {
  using state = JSONNumber;
  template <class Rule>
  using action = JSONActions<Rule>;

  template <class Input>
  static void apply(const Input &in, state &number) {
    number = std::stod(in.string());
  }
};

template <>
struct JSONActions<json_grammer::array_content> {
  using state = JSONArray;
  template <class Rule>
  using action = JSONActions<Rule>;

  static void apply0(state &){};
};

template <>
struct JSONActions<JSONArray> {
  static void success(JSONArray &array, JSONValuePtr value) {
    array.push_back(std::move(value));
  }
};

template <>
struct JSONActions<json_grammer::value> {
  using state = JSONValuePtr;
  template <class Rule>
  using action = JSONActions<Rule>;

  static void apply0(state &){};

  template <class InnerValue>
  static void success(state &value_ptr, InnerValue value) {
    if constexpr (std::is_same_v<JSONValuePtr, InnerValue>) {
      value_ptr = std::move(value);
    } else {
      value_ptr = std::make_unique<JSONValue>(std::move(value));
    }
  }
};

template <>
struct JSONActions<JSONValuePtr> {
  template <class InnerValue>
  static void success(JSONValuePtr &value_ptr, InnerValue value) {
    if constexpr (std::is_same_v<JSONValuePtr, InnerValue>) {
      value_ptr = std::move(value);
    } else {
      value_ptr = std::make_unique<JSONValue>(std::move(value));
    }
  }
};

template <>
struct JSONActions<json_grammer::true_> {
  using state = JSONBool;
  template <class Rule>
  using action = JSONActions<Rule>;

  static void apply0(state &value) { value = true; }
};

template <>
struct JSONActions<json_grammer::false_> {
  using state = JSONBool;
  template <class Rule>
  using action = JSONActions<Rule>;

  static void apply0(state &value) { value = false; }
};

template <>
struct JSONActions<json_grammer::object_content> {
  using state = JSONObject;
  template <class Rule>
  using action = JSONActions<Rule>;

  static void apply0(state &value) {}
};

template <>
struct JSONActions<JSONObject> {
  static void success(JSONObject &object, JSONObjectKeyPair key_pair) {
    // Should I check that the key doesn't exist: Yes
    // Am I going to: No
    object[key_pair.key] = std::move(key_pair.value);
  }
};

template <>
struct JSONActions<json_grammer::member> {
  using state = JSONObjectKeyPair;
  template <class Rule>
  using action = JSONActions<Rule>;

  static void apply0(state &value) {}
};

template <>
struct JSONActions<JSONObjectKeyPair> {
  static void success(JSONObjectKeyPair &key_pair, JSONString &&key) {
    key_pair.key = std::move(key);
  }

  static void success(JSONObjectKeyPair &key_pair, JSONValuePtr &&value) {
    key_pair.value = std::move(value);
  }
};

struct StructWithMembers {
  using state = bool;
  template <class Rule>
  using action = tao::pegtl::nothing<Rule>;
};

struct StructWithoutMembers {};

} // namespace Control
} // namespace Grammar
} // namespace JSON
