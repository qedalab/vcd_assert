
#ifndef LIBSDF_GRAMMAR_HEADER_HPP 
#define LIBSDF_GRAMMAR_HEADER_HPP 

#include <sdf/grammar/base.hpp>

#include <sdf/grammar/keywords.hpp>
#include <sdf/grammar/values.hpp>

#include "./time_scale.hpp"

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

