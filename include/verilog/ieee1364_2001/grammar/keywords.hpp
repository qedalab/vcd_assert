#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_KEYWORDS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_KEYWORDS_HPP

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct module_keyword : sor<
   TAO_PEGTL_STRING("module"),
   TAO_PEGTL_STRING("macromodule")
> {}; 

// misc
struct endmodule_keyword      : TAO_PEGTL_STRING("endmodule"){};         
struct endprimitive_keyword   : TAO_PEGTL_STRING("endprimitive"){};           
struct inout_keyword          : TAO_PEGTL_STRING("inout"){};             
struct input_keyword          : TAO_PEGTL_STRING("input"){};     
struct integer_keyword        : TAO_PEGTL_STRING("integer"){};               
struct output_keyword         : TAO_PEGTL_STRING("output"){};             
struct parameter_keyword      : TAO_PEGTL_STRING("parameter"){};         
struct primitive_keyword      : TAO_PEGTL_STRING("primitive"){};         
struct real_keyword           : TAO_PEGTL_STRING("real"){};           
struct realtime_keyword       : TAO_PEGTL_STRING("realtime"){};       
struct reg_keyword            : TAO_PEGTL_STRING("reg"){};   
struct signed_keyword         : TAO_PEGTL_STRING("signed"){};             
struct time_keyword           : TAO_PEGTL_STRING("time"){};   

// net types
struct supply0_keyword        : TAO_PEGTL_STRING("supply0"){};
struct supply1_keyword        : TAO_PEGTL_STRING("supply1"){};
struct tri_keyword            : TAO_PEGTL_STRING("tri"){};
struct triand_keyword         : TAO_PEGTL_STRING("triand"){};
struct trior_keyword          : TAO_PEGTL_STRING("trior"){};
struct tri0_keyword           : TAO_PEGTL_STRING("tri0"){};
struct tri1_keyword           : TAO_PEGTL_STRING("tri1"){};
struct wire_keyword           : TAO_PEGTL_STRING("wire"){};
struct wand_keyword           : TAO_PEGTL_STRING("wand"){};
struct wor_keyword            : TAO_PEGTL_STRING("wor"){};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_KEYWORDS_HPP
