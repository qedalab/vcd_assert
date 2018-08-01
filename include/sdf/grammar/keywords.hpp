// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

#ifndef LIBSDF_GRAMMAR_KEYWORDS_HPP 
#define LIBSDF_GRAMMAR_KEYWORDS_HPP 

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include "./character.hpp"

namespace SDF {
namespace Grammar {
// clang-format off

struct str_absolute :         TAO_PEGTL_ISTRING ("ABSOLUTE") {};
struct str_arrival :          TAO_PEGTL_ISTRING ("ARRIVAL") {};
struct str_bidirectskew :     TAO_PEGTL_ISTRING ("BIDIRECTSKEW") {};
struct str_ccond :            TAO_PEGTL_ISTRING ("CCOND") {};
struct str_cell :             TAO_PEGTL_ISTRING ("CELL") {};
struct str_cell_type :        TAO_PEGTL_ISTRING ("CELLTYPE") {};
struct str_cond :             TAO_PEGTL_ISTRING ("COND") {};
struct str_condelse :         TAO_PEGTL_ISTRING ("CONDELSE") {};
struct str_date :             TAO_PEGTL_ISTRING ("DATE") {};
struct str_delay :            TAO_PEGTL_ISTRING ("DELAY") {};
struct str_delayfile :        TAO_PEGTL_ISTRING ("DELAYFILE") {};
struct str_departure :        TAO_PEGTL_ISTRING ("DEPARTURE") {};
struct str_design :           TAO_PEGTL_ISTRING ("DESIGN") {};
struct str_device :           TAO_PEGTL_ISTRING ("DEVICE") {};
struct str_diff :             TAO_PEGTL_ISTRING ("DIFF") {};
struct str_divider :          TAO_PEGTL_ISTRING ("DIVIDER") {};
struct str_exception :        TAO_PEGTL_ISTRING ("EXCEPTION") {};
struct str_hold :             TAO_PEGTL_ISTRING ("HOLD") {};
struct str_increment :        TAO_PEGTL_ISTRING ("INCREMENT") {};
struct str_instance :         TAO_PEGTL_ISTRING ("INSTANCE") {};
struct str_interconnect :     TAO_PEGTL_ISTRING ("INTERCONNECT") {};
struct str_iopath :           TAO_PEGTL_ISTRING ("IOPATH") {};
struct str_label :            TAO_PEGTL_ISTRING ("LABEL") {};
struct str_name :             TAO_PEGTL_ISTRING ("NAME") {};
struct str_netdelay :         TAO_PEGTL_ISTRING ("NETDELAY") {};
struct str_nochange :         TAO_PEGTL_ISTRING ("NOCHANGE") {};
struct str_pathconstraint :   TAO_PEGTL_ISTRING ("PATHCONSTRAINT") {};
struct str_pathpulse :        TAO_PEGTL_ISTRING ("PATHPULSE") {};
struct str_pathpulsepercent : TAO_PEGTL_ISTRING ("PATHPULSEPERCENT") {};
struct str_period :           TAO_PEGTL_ISTRING ("PERIOD") {};
struct str_periodconstraint : TAO_PEGTL_ISTRING ("PERIODCONSTRAINT") {};
struct str_port :             TAO_PEGTL_ISTRING ("PORT") {};
struct str_process :          TAO_PEGTL_ISTRING ("PROCESS") {};
struct str_program :          TAO_PEGTL_ISTRING ("PROGRAM") {};
struct str_recovery :         TAO_PEGTL_ISTRING ("RECOVERY") {};
struct str_recrem :           TAO_PEGTL_ISTRING ("RECREM") {};
struct str_removal :          TAO_PEGTL_ISTRING ("REMOVAL") {};
struct str_retain :           TAO_PEGTL_ISTRING ("RETAIN") {};
struct str_scond :            TAO_PEGTL_ISTRING ("SCOND") {};
struct str_sdfversion :       TAO_PEGTL_ISTRING ("SDFVERSION") {};
struct str_setup :            TAO_PEGTL_ISTRING ("SETUP") {};
struct str_setuphold :        TAO_PEGTL_ISTRING ("SETUPHOLD") {};
struct str_skew :             TAO_PEGTL_ISTRING ("SKEW") {};
struct str_skewconstraint :   TAO_PEGTL_ISTRING ("SKEWCONSTRAINT") {};
struct str_slack :            TAO_PEGTL_ISTRING ("SLACK") {};
struct str_sum :              TAO_PEGTL_ISTRING ("SUM") {};
struct str_temperature :      TAO_PEGTL_ISTRING ("TEMPERATURE") {};
struct str_timescale :        TAO_PEGTL_ISTRING ("TIMESCALE") {};
struct str_timingcheck :      TAO_PEGTL_ISTRING ("TIMINGCHECK") {};
struct str_timingenv :        TAO_PEGTL_ISTRING ("TIMINGENV") {};
struct str_vendor :           TAO_PEGTL_ISTRING ("VENDOR") {};
struct str_version :          TAO_PEGTL_ISTRING ("VERSION") {};
struct str_voltage :          TAO_PEGTL_ISTRING ("VOLTAGE") {};
struct str_waveform :         TAO_PEGTL_ISTRING ("WAVEFORM") {};
struct str_width :            TAO_PEGTL_ISTRING ("WIDTH") {};

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
  str_cell_type,
  str_cell,
  str_ccond,
  str_bidirectskew,
  str_arrival,
  str_absolute
> {};

template< typename Key >
struct key : seq< Key, not_at< character > > {};

struct key_absolute : key< str_absolute > {};
struct key_arrival : key< str_arrival > {};
struct key_bidirectskew : key< str_bidirectskew > {};
struct key_ccond : key< str_ccond > {};
struct key_cell : key< str_cell > {};
struct key_cell_type : key< str_cell_type > {};
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
