#ifndef PARSE_JSON_HPP
#define PARSE_JSON_HPP

#include <map>
#include <memory>
#include <string>
#include <variant>
#include <vector>

#include <tao/pegtl/contrib/json.hpp>

constexpr char json_example[] =
    "{\n"
    "  \"name\":\"John\",\n"
    "  \"age\":30,\n"
    "  \"cars\":[ \"Ford\", \"BMW\", \"Fiat\" ]\n"
    "}";

namespace json_grammar = tao::pegtl::json;

struct JSONValue;
using JSONValuePtr = std::unique_ptr<JSONValue>;
struct JSONNull {};

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

using JSONValueVariant = std::variant<JSONNull, JSONString, JSONNumber, JSONArray,
                                      JSONObject, JSONBool>;

struct JSONValue : public JSONValueVariant
{
  using JSONValueVariant::JSONValueVariant;
};

#endif //PARSE_JSON_HPP
