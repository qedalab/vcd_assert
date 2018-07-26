
#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_COMMANDS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_COMMANDS_HPP


#include "./base.hpp"
#include "./grammar_hacked.hpp"
#include "./keywords.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

struct name_of_instance;

struct sdf_file : if_must< one<'"'>, file_path_spec, one<'"'>>{};
struct config_file : if_must< one<'"'>, file_path_spec, one<'"'>>{};
struct log_file : if_must< one<'"'>, file_path_spec, one<'"'>>{};
struct mtm_spec : alias<qstring>{};
struct scale_factors : alias<qstring>{};
struct scale_type : alias<qstring>{};

struct sdf_annotate_task : if_must<
  seq<
    one<'$'>, 
    sdf_annotate_keyword
  >,
  opt<separator>,
  if_must<
    one<'('>, 
    opt<separator>,
    sdf_file,
    opt< 
      opt<separator>,
      one<','>,
      opt< opt<separator>, name_of_instance >
      , 
      opt< 
        opt<separator>,
        one<','>, 
        opt< opt<separator>, config_file >,
        opt< 
          opt<separator>,
          one<','>, 
          opt< opt<separator>, log_file >,
          opt< 
            opt<separator>,
            one<','>, 
            opt< opt<separator>, mtm_spec >,
            opt< 
            opt<separator>,
              one<','>, 
              opt< opt<separator>, scale_factors >,
              opt< 
                one<','>, 
                opt< opt<separator>, scale_type >
              > 
            > 
          > 
        > 
      >
    >, 
    opt<separator>,
    one<')'>
  >,
  opt<separator>,
  one<';'> 
> {};

}
}
}

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_COMMANDS_HPP
