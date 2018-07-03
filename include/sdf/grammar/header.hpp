
#ifndef LIBSDF_GRAMMAR_HEADER_HPP 
#define LIBSDF_GRAMMAR_HEADER_HPP 

#include <sdf/grammar/base.hpp>

#include <sdf/grammar/keywords.hpp>
#include <sdf/grammar/values.hpp>

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


struct timescale_number_1 : sor<
    TAO_PEGTL_ISTRING( "1.0" ),
    TAO_PEGTL_ISTRING( "1" )
>{};

struct timescale_number_10 : sor<
    TAO_PEGTL_ISTRING( "10.0" ),
    TAO_PEGTL_ISTRING( "10" )
>{};

struct timescale_number_100 : sor<
    TAO_PEGTL_ISTRING( "100.0" ),
    TAO_PEGTL_ISTRING( "100" )
>{};

struct timescale_number : sor< 
    timescale_number_100,
    timescale_number_10,
    timescale_number_1
>{};

struct timescale_unit_fs : TAO_PEGTL_ISTRING("fs") {};
struct timescale_unit_ps : TAO_PEGTL_ISTRING("ps") {};
struct timescale_unit_ns : TAO_PEGTL_ISTRING("ns") {};
struct timescale_unit_us : TAO_PEGTL_ISTRING("us") {};
struct timescale_unit_ms : TAO_PEGTL_ISTRING("ms") {};
struct timescale_unit_s : TAO_PEGTL_ISTRING("s") {};

struct timescale_unit : sor< 
    timescale_unit_fs,
    timescale_unit_ps,
    timescale_unit_ns,
    timescale_unit_us,
    timescale_unit_ms,
    timescale_unit_s
>{};

struct timescale : block< 
  key_timescale,
  timescale_number,
  timescale_unit
>{};


struct sdf_header : op_sep_seq< 
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
  opt<timescale>
>{};

// clang-format on
} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_HEADER_HPP 

