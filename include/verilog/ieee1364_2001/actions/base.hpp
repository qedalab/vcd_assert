#ifndef LIBVERILOG_IEEE1364_2001_ACTIONS_BASE_HPP
#define LIBVERILOG_IEEE1364_2001_ACTIONS_BASE_HPP

#include "../../types/base.hpp"
#include "../grammar/base.hpp"

#include "parse/actions/apply/float.hpp"
#include "parse/actions/apply/integer.hpp"
#include "parse/actions/apply/rule_value.hpp"
#include "parse/actions/apply/string.hpp"
#include "parse/actions/apply/value.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/apply0.hpp"
#include "parse/actions/command/inner_action.hpp"
// #include "parse/actions/command/pegtl_action.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/actions/storage/function.hpp"
#include "parse/actions/storage/member.hpp"
#include "parse/actions/storage/push_back.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/actions/control.hpp"

#include "parse/actions/make_pegtl_template.hpp"
#include <tao/pegtl/memory_input.hpp>


using namespace Parse;

namespace Verilog {
namespace IEEE1364_2001 {


// struct HCharAction : all_dispatch<apply0<Apply::rule_value>> {
//   using state = HChar;
// };

// struct IdentifierAction : single_dispatch<
//     Grammar::identifier, apply<Apply::string>
// > {
//   using state = std::string;
// };

// struct IdentifierArrayAction : single_dispatch<
//     Grammar::identifier, inner_action<
//       IdentifierAction, 
//       Storage::push_back
//     >
// > {
//   using state = std::vector<std::string>;
// };

// struct PathIdentifierStorage{
//   static bool store(HierarchicalIdentifier &hi, std::string s) {
//      hi.value.push_back(std::move(s));
//      return true;
//    }
//  };

struct QStringAction : single_dispatch<
    Grammar::qstring_content, apply<Apply::string>
> {
  using state = std::string;
};

struct HCharAction : all_dispatch<apply0<Apply::rule_value>> {
  using state = HChar;
};

struct IdentifierAction : single_dispatch<
    Grammar::identifier, apply<Apply::string>
> {
  using state = std::string;
};

struct IdentifierArrayAction : single_dispatch<
    Grammar::identifier, inner_action<
      IdentifierAction, 
      Storage::push_back
    >
> {
  using state = std::vector<std::string>;
};

struct HierarchicalIdentifierStorage{
  static bool store(HierarchicalIdentifier &hi, std::string s) {
    hi.value.push_back(std::move(s));
    return true;
   }
 };

struct HierarchicalIdentifierAction : multi_dispatch<
    Grammar::hchar, inner_action<
      HCharAction, 
      Storage::member<&HierarchicalIdentifier::sep>
    >,
    Grammar::identifier, inner_action<
      IdentifierAction, 
      HierarchicalIdentifierStorage
    >
> {
  using state = HierarchicalIdentifier;
};

struct PathIdentifierAction : single_dispatch<
    Grammar::path_identifier, apply<Apply::string>
> {
  using state = std::string;
};

struct FilePathAction : multi_dispatch<
    Grammar::path_separator, inner_action<
      HCharAction, 
      // PathSeparatorAction, 
      Storage::member<&HierarchicalIdentifier::sep>
    >,
    Grammar::path_identifier, inner_action<
      PathIdentifierAction, 
      HierarchicalIdentifierStorage
    >
> {
  using state = HierarchicalIdentifier;
};

struct FilePathSpecAction : single_dispatch<
    Grammar::file_path, apply<Apply::string>
> {
  using state = std::string;
};



}
}

#endif // LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
