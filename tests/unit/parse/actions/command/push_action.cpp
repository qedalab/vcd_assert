#include "parse/actions/command/push_action.hpp"

#include "parse/actions/apply/string.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/control.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/actions/storage/member.hpp"
#include "parse/grammar/base.h"

#include <catch2/catch.hpp>
#include <tao/pegtl/parse.hpp>
#include <tao/pegtl/string_input.hpp>

#include <cstring>
#include <string>
#include <string_view>

using namespace Parse;
using namespace Parse::Grammar;

// Matches C++ raw string literal as an example of using push to handle context
// sensitive grammars.

struct RawStringLiteral {
  std::string delimiter;
  std::string raw_characters;
};

struct delimiter_end {
  template <tao::pegtl::apply_mode A, tao::pegtl::rewind_mode M,
            template <typename...> class Action,
            template <typename...> class Control, typename Input>
  static bool match(Input &in, const std::string & /*unused*/,
                    const RawStringLiteral &rsl) {
    if (in.size() >= rsl.delimiter.size()) {
      if (std::memcmp(in.current(), rsl.delimiter.data(),
                      rsl.delimiter.size()) == 0) {
        in.bump(rsl.delimiter.size());
        return true;
      }
    }

    return false;
  }

  template <tao::pegtl::apply_mode A, tao::pegtl::rewind_mode M,
            template <typename...> class Action,
            template <typename...> class Control, typename Input>
  static bool match(Input &in, const RawStringLiteral &rsl) {
    if (in.size() >= rsl.delimiter.size()) {
      if (std::memcmp(in.current(), rsl.delimiter.data(),
                      rsl.delimiter.size()) == 0) {
        in.bump(rsl.delimiter.size());
        return true;
      }
    }

    return false;
  }
};

// clang-format off
struct delimiter_char :
  tao::pegtl::not_one<' ', '/','(',')',' ','\t', '\f', '\n', '\r'> {};

struct delimiter :
  tao::pegtl::rep_max<16, delimiter_char> {};

struct raw_string_close :
seq<
  one<')'>,
  delimiter_end,
  one<'"'>
> {};

struct raw_characters :
  until<at<raw_string_close>> {};

struct raw_string :
seq<
  string<'R', '"'>,
  delimiter,
  one<'('>,
  must<raw_characters>,
  must<raw_string_close>
> {};

struct DelimiterAction : single_dispatch <
  delimiter, apply<Apply::string>
                         >
{
  using state = std::string;
};

struct RawCharactersAction : single_dispatch <
  raw_characters, apply<Apply::string>
> {
  using state = std::string;
};

struct RawStringAction : multi_dispatch<
  delimiter, inner_action<DelimiterAction,
                          Storage::member<&RawStringLiteral::delimiter>>,
  raw_characters, push_action<RawCharactersAction,
                              Storage::member<&RawStringLiteral::raw_characters>>
> {};

// clang-format on

TEST_CASE("Parse.Actions.Command.PushAction", "[Actions][Command]") {
  struct RawLiteralMatch {
    std::string_view input;
    std::string_view delimtier;
    std::string_view raw_characters;
  };

  std::vector<RawLiteralMatch> data{
      {R"outer(R"(raw_chars)")outer", "", R"(raw_chars)"},
      {R"outer(R"2(asdf)2")outer", "2", "asdf"},
      {R"outer(R"d({R"(still_raw)"})d")outer", "d",
       R"outer({R"(still_raw)"})outer"}};

  for (auto &[input_str, delimiter, raw_chars] : data) {
    SECTION("Parse: " + std::string(input_str)) {
      RawStringLiteral rsl;

      tao::pegtl::memory_input<> input(std::begin(input_str),
                                       std::end(input_str), "push_action");

      bool success =
          tao::pegtl::parse<raw_string,
                            make_pegtl_template<RawStringAction>::type,
                            capture_control>(input, rsl);

      REQUIRE(success);
      CHECK(delimiter == rsl.delimiter);
      CHECK(raw_chars == rsl.raw_characters);
    }
  }
}
