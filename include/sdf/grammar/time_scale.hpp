#ifndef LIBSDF_GRAMMAR_TIME_SCALE_HPP
#define LIBSDF_GRAMMAR_TIME_SCALE_HPP

#include "./block.hpp"
#include "./keywords.hpp"
#include "../types/time_scale.hpp"

namespace SDF::Grammar {

// clang-format off
struct timescale_number_1 : sor<
    TAO_PEGTL_ISTRING( "1.0" ),
    TAO_PEGTL_ISTRING( "1" )
> {
  static constexpr auto value = TimeScaleNumber::_1;
};

struct timescale_number_10 : sor<
    TAO_PEGTL_ISTRING( "10.0" ),
    TAO_PEGTL_ISTRING( "10" )
> {
  static constexpr auto value = TimeScaleNumber::_10;
};

struct timescale_number_100 : sor<
    TAO_PEGTL_ISTRING( "100.0" ),
    TAO_PEGTL_ISTRING( "100" )
> {
  static constexpr auto value = TimeScaleNumber::_100;
};

struct timescale_number : sor< 
    timescale_number_100,
    timescale_number_10,
    timescale_number_1
> {};

struct timescale_unit_fs : TAO_PEGTL_ISTRING("fs") {
  static constexpr auto value = TimeScaleUnit::fs;
};

struct timescale_unit_ps : TAO_PEGTL_ISTRING("ps") {
  static constexpr auto value = TimeScaleUnit::ps;
};

struct timescale_unit_ns : TAO_PEGTL_ISTRING("ns") {
  static constexpr auto value = TimeScaleUnit::ns;
};

struct timescale_unit_us : TAO_PEGTL_ISTRING("us") {
  static constexpr auto value = TimeScaleUnit::us;
};

struct timescale_unit_ms : TAO_PEGTL_ISTRING("ms") {
  static constexpr auto value = TimeScaleUnit::ms;
};

struct timescale_unit_s : TAO_PEGTL_ISTRING("s") {
  static constexpr auto value = TimeScaleUnit::s;
};

struct timescale_unit : sor< 
    timescale_unit_fs,
    timescale_unit_ps,
    timescale_unit_ns,
    timescale_unit_us,
    timescale_unit_ms,
    timescale_unit_s
> {};

struct timescale : block< 
  key_timescale,
  timescale_number,
  timescale_unit
> {};
// clang-format on

} // namespace SDF::Grammar

#endif // LIBSDF_GRAMMAR_TIME_SCALE_HPP
