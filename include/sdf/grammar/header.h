
#ifndef LIBSDF_GRAMMAR_HEADER_H
#define LIBSDF_GRAMMAR_HEADER_H

#include "parse/grammar/base.h"
#include "base.h"
#include "keywords.h"
#include "values.h"

namespace SDF {
namespace Grammar {

// clang-format off

struct sdf_version : block< 
  key_sdfversion,
  qstring
>{};

struct design_name : block< 
  key_design,
  qstring
>{};

struct date : block< 
  key_date,
  qstring
>{};

struct vendor : block< 
  key_vendor,
  qstring
>{};

struct program_name : block< 
  key_program,
  qstring
>{};

struct program_version : block< 
  key_version,
  qstring
>{};

struct hierarchy_divider : block< 
  key_divider,
  hchar
>{};

struct voltage : block< 
  key_voltage,
  sor< rtriple, signed_real_number>
>{};

struct process : block< 
  key_process,
  qstring    
>{};

struct temperature : block<
  key_temperature,
  sor< rtriple, signed_real_number>
>{};


struct timescale_number : sor< 
    TAO_PEGTL_ISTRING( "100.0" ),
    TAO_PEGTL_ISTRING( "10.0" ),
    TAO_PEGTL_ISTRING( "1.0" ),
    TAO_PEGTL_ISTRING( "100" ),
    TAO_PEGTL_ISTRING( "10" ),
    TAO_PEGTL_ISTRING( "1" )
>{};

struct timescale_unit : sor< 
    TAO_PEGTL_ISTRING( "fs" ),
    TAO_PEGTL_ISTRING( "ps" ),
    TAO_PEGTL_ISTRING( "ns" ),
    TAO_PEGTL_ISTRING( "us" ),
    TAO_PEGTL_ISTRING( "ms" ),
    TAO_PEGTL_ISTRING( "s" )
>{};

struct time_scale : block< 
  key_timescale,
  timescale_number,
  timescale_unit
>{};


struct sdf_header : op_sep_seq< //make ws_ignored_seq
  must<sdf_version>,
  opt<design_name>,
  opt<date>,
  opt<vendor>,
  opt<program_name>,
  opt<program_version>,
  opt<hierarchy_divider>,
  opt<voltage>,
  opt<process>,
  opt<temperature>,
  opt<time_scale>
>{};

// clang-format on
} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_HEADER_H

