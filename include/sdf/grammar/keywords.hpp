#ifndef LIBSDF_GRAMMAR_KEYWORDS_HPP 
#define LIBSDF_GRAMMAR_KEYWORDS_HPP 

#include <sdf/grammar/base.hpp>

namespace SDF {
namespace Grammar {
// clang-format off

struct str_absolute :         TAO_PEGTL_ISTRING ("absolute") {};
struct str_arrival :          TAO_PEGTL_ISTRING ("arrival") {};
struct str_bidirectskew :     TAO_PEGTL_ISTRING ("bidirectskew") {};
struct str_ccond :            TAO_PEGTL_ISTRING ("ccond") {};
struct str_cell :             TAO_PEGTL_ISTRING ("cell") {};
struct str_celltype :         TAO_PEGTL_ISTRING ("celltype") {};
struct str_cond :             TAO_PEGTL_ISTRING ("cond") {};
struct str_condelse :         TAO_PEGTL_ISTRING ("condelse") {};
struct str_date :             TAO_PEGTL_ISTRING ("date") {};
struct str_delay :            TAO_PEGTL_ISTRING ("delay") {};
struct str_delayfile :        TAO_PEGTL_ISTRING ("delayfile") {};
struct str_departure :        TAO_PEGTL_ISTRING ("departure") {};
struct str_design :           TAO_PEGTL_ISTRING ("design") {};
struct str_device :           TAO_PEGTL_ISTRING ("device") {};
struct str_diff :             TAO_PEGTL_ISTRING ("diff") {};
struct str_divider :          TAO_PEGTL_ISTRING ("divider") {};
struct str_exception :        TAO_PEGTL_ISTRING ("exception") {};
struct str_hold :             TAO_PEGTL_ISTRING ("hold") {};
struct str_increment :        TAO_PEGTL_ISTRING ("increment") {};
struct str_instance :         TAO_PEGTL_ISTRING ("instance") {};
struct str_interconnect :     TAO_PEGTL_ISTRING ("interconnect") {};
struct str_iopath :           TAO_PEGTL_ISTRING ("iopath") {};
struct str_label :            TAO_PEGTL_ISTRING ("label") {};
struct str_name :             TAO_PEGTL_ISTRING ("name") {};
struct str_netdelay :         TAO_PEGTL_ISTRING ("netdelay") {};
struct str_nochange :         TAO_PEGTL_ISTRING ("nochange") {};
struct str_pathconstraint :   TAO_PEGTL_ISTRING ("pathconstraint") {};
struct str_pathpulse :        TAO_PEGTL_ISTRING ("pathpulse") {};
struct str_pathpulsepercent : TAO_PEGTL_ISTRING ("pathpulsepercent") {};
struct str_period :           TAO_PEGTL_ISTRING ("period") {};
struct str_periodconstraint : TAO_PEGTL_ISTRING ("periodconstraint") {};
struct str_port :             TAO_PEGTL_ISTRING ("port") {};
struct str_process :          TAO_PEGTL_ISTRING ("process") {};
struct str_program :          TAO_PEGTL_ISTRING ("program") {};
struct str_recovery :         TAO_PEGTL_ISTRING ("recovery") {};
struct str_recrem :           TAO_PEGTL_ISTRING ("recrem") {};
struct str_removal :          TAO_PEGTL_ISTRING ("removal") {};
struct str_retain :           TAO_PEGTL_ISTRING ("retain") {};
struct str_scond :            TAO_PEGTL_ISTRING ("scond") {};
struct str_sdfversion :       TAO_PEGTL_ISTRING ("sdfversion") {};
struct str_setup :            TAO_PEGTL_ISTRING ("setup") {};
struct str_setuphold :        TAO_PEGTL_ISTRING ("setuphold") {};
struct str_skew :             TAO_PEGTL_ISTRING ("skew") {};
struct str_skewconstraint :   TAO_PEGTL_ISTRING ("skewconstraint") {};
struct str_slack :            TAO_PEGTL_ISTRING ("slack") {};
struct str_sum :              TAO_PEGTL_ISTRING ("sum") {};
struct str_temperature :      TAO_PEGTL_ISTRING ("temperature") {};
struct str_timescale :        TAO_PEGTL_ISTRING ("timescale") {};
struct str_timingcheck :      TAO_PEGTL_ISTRING ("timingcheck") {};
struct str_timingenv :        TAO_PEGTL_ISTRING ("timingenv") {};
struct str_vendor :           TAO_PEGTL_ISTRING ("vendor") {};
struct str_version :          TAO_PEGTL_ISTRING ("version") {};
struct str_voltage :          TAO_PEGTL_ISTRING ("voltage") {};
struct str_waveform :         TAO_PEGTL_ISTRING ("waveform") {};
struct str_width :            TAO_PEGTL_ISTRING ("width") {};

/* test keyword not to included in list*/
struct str_test_keyword :     TAO_PEGTL_ISTRING ("test_keyword") {};


// Note that the following list is sorted DECENDING to have for 
// example 'pathpulsepercent' precede 'pathpulse' in order to 
// prevent matching only a subset of a keyword by mistake.

// TODO : consider moving the keywords likely to occur more often
//          to the start of the list, for optimization purposes. 


struct str_keyword : sor< 
  str_width,
  str_waveform,
  str_voltage,
  str_version,
  str_vendor,
  str_timingenv,
  str_timingcheck,
  str_timescale,
  str_temperature,
  str_sum,
  str_slack,
  str_skewconstraint,
  str_skew,
  str_setuphold,
  str_setup,
  str_sdfversion,
  str_scond,
  str_retain,
  str_removal,
  str_recrem,
  str_recovery,
  str_program,
  str_process,
  str_port,
  str_periodconstraint,
  str_period,
  str_pathpulsepercent,
  str_pathpulse,
  str_pathconstraint,
  str_nochange,
  str_netdelay,
  str_name,
  str_label,
  str_iopath,
  str_interconnect,
  str_instance,
  str_increment,
  str_hold,
  str_exception,
  str_divider,
  str_diff,
  str_device,
  str_design,
  str_departure,
  str_delayfile,
  str_delay,
  str_date,
  str_condelse,
  str_cond,
  str_celltype,
  str_cell,
  str_ccond,
  str_bidirectskew,
  str_arrival,
  str_absolute
> {};

template< typename Key >
struct key : seq< Key, not_at< identifier > > {};


struct key_absolute : key< str_absolute > {};
struct key_arrival : key< str_arrival > {};
struct key_bidirectskew : key< str_bidirectskew > {};
struct key_ccond : key< str_ccond > {};
struct key_cell : key< str_cell > {};
struct key_celltype : key< str_celltype > {};
struct key_cond : key< str_cond > {};
struct key_condelse : key< str_condelse > {};
struct key_date : key< str_date > {};
struct key_delay : key< str_delay > {};
struct key_delayfile : key< str_delayfile > {};
struct key_departure : key< str_departure > {};
struct key_design : key< str_design > {};
struct key_device : key< str_device > {};
struct key_diff : key< str_diff > {};
struct key_divider : key< str_divider > {};
struct key_exception : key< str_exception > {};
struct key_hold : key< str_hold > {};
struct key_increment : key< str_increment > {};
struct key_instance : key< str_instance > {};
struct key_interconnect : key< str_interconnect > {};
struct key_iopath : key< str_iopath > {};
struct key_label : key< str_label > {};
struct key_name : key< str_name > {};
struct key_netdelay : key< str_netdelay > {};
struct key_nochange : key< str_nochange > {};
struct key_pathconstraint : key< str_pathconstraint > {};
struct key_pathpulse : key< str_pathpulse > {};
struct key_pathpulsepercent : key< str_pathpulsepercent > {};
struct key_period : key< str_period > {};
struct key_periodconstraint : key< str_periodconstraint > {};
struct key_port : key< str_port > {};
struct key_process : key< str_process > {};
struct key_program : key< str_program > {};
struct key_recovery : key< str_recovery > {};
struct key_recrem : key< str_recrem > {};
struct key_removal : key< str_removal > {};
struct key_retain : key< str_retain > {};
struct key_scond : key< str_scond > {};
struct key_sdfversion : key< str_sdfversion > {};
struct key_setup : key< str_setup > {};
struct key_setuphold : key< str_setuphold > {};
struct key_skew : key< str_skew > {};
struct key_skewconstraint : key< str_skewconstraint > {};
struct key_slack : key< str_slack > {};
struct key_sum : key< str_sum > {};
struct key_temperature : key< str_temperature > {};
struct key_timescale : key< str_timescale > {};
struct key_timingcheck : key< str_timingcheck > {};
struct key_timingenv : key< str_timingenv > {};
struct key_vendor : key< str_vendor > {};
struct key_version : key< str_version > {};
struct key_voltage : key< str_voltage > {};
struct key_waveform : key< str_waveform > {};
struct key_width : key< str_width > {};


/* test keyword not to included in list*/
struct key_test_keyword : key< str_test_keyword > {};

struct keyword : key< str_keyword > {};

// clang-format on

} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_KEYWORDS_HPP 