#ifndef LIBSDF_TEST_SDF_KEYWORDS_H
#define LIBSDF_TEST_SDF_KEYWORDS_H


#include "base.hpp"
#include <sdf/grammar/keywords.hpp>


namespace Test {
namespace SDF {
namespace Grammar {

using namespace Parse::Test;
using namespace SDF::Grammar;

constexpr auto k_absolute_str_l         = R"(absolute)";
constexpr auto k_arrival_str_l          = R"(arrival)";
constexpr auto k_bidirectskew_str_l     = R"(bidirectskew)";
constexpr auto k_ccond_str_l            = R"(ccond)";
constexpr auto k_cell_str_l             = R"(cell)";
constexpr auto k_celltype_str_l         = R"(celltype)";
constexpr auto k_cond_str_l             = R"(cond)";
constexpr auto k_condelse_str_l         = R"(condelse)";
constexpr auto k_date_str_l             = R"(date)";
constexpr auto k_delay_str_l            = R"(delay)";
constexpr auto k_delayfile_str_l        = R"(delayfile)";
constexpr auto k_departure_str_l        = R"(departure)";
constexpr auto k_design_str_l           = R"(design)";
constexpr auto k_device_str_l           = R"(device)";
constexpr auto k_diff_str_l             = R"(diff)";
constexpr auto k_divider_str_l          = R"(divider)";
constexpr auto k_exception_str_l        = R"(exception)";
constexpr auto k_hold_str_l             = R"(hold)";
constexpr auto k_increment_str_l        = R"(increment)";
constexpr auto k_instance_str_l         = R"(instance)";
constexpr auto k_interconnect_str_l     = R"(interconnect)";
constexpr auto k_iopath_str_l           = R"(iopath)";
constexpr auto k_label_str_l            = R"(label)";
constexpr auto k_name_str_l             = R"(name)";
constexpr auto k_netdelay_str_l         = R"(netdelay)";
constexpr auto k_nochange_str_l         = R"(nochange)";
constexpr auto k_pathconstraint_str_l   = R"(pathconstraint)";
constexpr auto k_pathpulse_str_l        = R"(pathpulse)";
constexpr auto k_pathpulsepercent_str_l = R"(pathpulsepercent)";
constexpr auto k_period_str_l           = R"(period)";
constexpr auto k_periodconstraint_str_l = R"(periodconstraint)";
constexpr auto k_port_str_l             = R"(port)";
constexpr auto k_process_str_l          = R"(process)";
constexpr auto k_program_str_l          = R"(program)";
constexpr auto k_recovery_str_l         = R"(recovery)";
constexpr auto k_recrem_str_l           = R"(recrem)";
constexpr auto k_removal_str_l          = R"(removal)";
constexpr auto k_retain_str_l           = R"(retain)";
constexpr auto k_scond_str_l            = R"(scond)";
constexpr auto k_sdfversion_str_l       = R"(sdfversion)";
constexpr auto k_setup_str_l            = R"(setup)";
constexpr auto k_setuphold_str_l        = R"(setuphold)";
constexpr auto k_skew_str_l             = R"(skew)";
constexpr auto k_skewconstraint_str_l   = R"(skewconstraint)";
constexpr auto k_slack_str_l            = R"(slack)";
constexpr auto k_sum_str_l              = R"(sum)";
constexpr auto k_temperature_str_l      = R"(temperature)";
constexpr auto k_timescale_str_l        = R"(timescale)";
constexpr auto k_timingcheck_str_l      = R"(timingcheck)";
constexpr auto k_timingenv_str_l        = R"(timingenv)";
constexpr auto k_vendor_str_l           = R"(vendor)";
constexpr auto k_version_str_l          = R"(version)";
constexpr auto k_voltage_str_l          = R"(voltage)";
constexpr auto k_waveform_str_l         = R"(waveform)";
constexpr auto k_width_str_l            = R"(width)";

constexpr auto k_absolute_str_c         = R"(Absolute)";
// constexpr auto k_arrival_str_c          = R"(Arrival)";
// constexpr auto k_bidirectskew_str_c     = R"(Bidirectskew)";
// constexpr auto k_ccond_str_c            = R"(Ccond)";
// constexpr auto k_cell_str_c             = R"(Cell)";
// constexpr auto k_celltype_str_c         = R"(Celltype)";
// constexpr auto k_cond_str_c             = R"(Cond)";
// constexpr auto k_condelse_str_c         = R"(Condelse)";
// constexpr auto k_date_str_c             = R"(Date)";
// constexpr auto k_delay_str_c            = R"(Delay)";
// constexpr auto k_delayfile_str_c        = R"(Delayfile)";
// constexpr auto k_departure_str_c        = R"(Departure)";
// constexpr auto k_design_str_c           = R"(Design)";
// constexpr auto k_device_str_c           = R"(Device)";
// constexpr auto k_diff_str_c             = R"(Diff)";
// constexpr auto k_divider_str_c          = R"(Divider)";
// constexpr auto k_exception_str_c        = R"(Exception)";
// constexpr auto k_hold_str_c             = R"(Hold)";
// constexpr auto k_increment_str_c        = R"(Increment)";
// constexpr auto k_instance_str_c         = R"(Instance)";
// constexpr auto k_interconnect_str_c     = R"(Interconnect)";
// constexpr auto k_iopath_str_c           = R"(Iopath)";
// constexpr auto k_label_str_c            = R"(Label)";
// constexpr auto k_name_str_c             = R"(Name)";
// constexpr auto k_netdelay_str_c         = R"(Netdelay)";
// constexpr auto k_nochange_str_c         = R"(Nochange)";
// constexpr auto k_pathconstraint_str_c   = R"(Pathconstraint)";
// constexpr auto k_pathpulse_str_c        = R"(Pathpulse)";
// constexpr auto k_pathpulsepercent_str_c = R"(Pathpulsepercent)";
// constexpr auto k_period_str_c           = R"(Period)";
// constexpr auto k_periodconstraint_str_c = R"(Periodconstraint)";
// constexpr auto k_port_str_c             = R"(Port)";
// constexpr auto k_process_str_c          = R"(Process)";
// constexpr auto k_program_str_c          = R"(Program)";
// constexpr auto k_recovery_str_c         = R"(Recovery)";
// constexpr auto k_recrem_str_c           = R"(Recrem)";
// constexpr auto k_removal_str_c          = R"(Removal)";
// constexpr auto k_retain_str_c           = R"(Retain)";
// constexpr auto k_scond_str_c            = R"(Scond)";
// constexpr auto k_sdfversion_str_c       = R"(Sdfversion)";
// constexpr auto k_setup_str_c            = R"(Setup)";
// constexpr auto k_setuphold_str_c        = R"(Setuphold)";
// constexpr auto k_skew_str_c             = R"(Skew)";
// constexpr auto k_skewconstraint_str_c   = R"(Skewconstraint)";
// constexpr auto k_slack_str_c            = R"(Slack)";
// constexpr auto k_sum_str_c              = R"(Sum)";
// constexpr auto k_temperature_str_c      = R"(Temperature)";
// constexpr auto k_timescale_str_c        = R"(Timescale)";
// constexpr auto k_timingcheck_str_c      = R"(Timingcheck)";
// constexpr auto k_timingenv_str_c        = R"(Timingenv)";
// constexpr auto k_vendor_str_c           = R"(Vendor)";
// constexpr auto k_version_str_c          = R"(Version)";
// constexpr auto k_voltage_str_c          = R"(Voltage)";
// constexpr auto k_waveform_str_c         = R"(Waveform)";
// constexpr auto k_width_str_c            = R"(Width)";

constexpr auto k_absolute_str_u         = R"(ABSOLUTE)";
// constexpr auto k_arrival_str_u          = R"(ARRIVAL)";
// constexpr auto k_bidirectskew_str_u     = R"(BIDIRECTSKEW)";
// constexpr auto k_ccond_str_u            = R"(CCOND)";
// constexpr auto k_cell_str_u             = R"(CELL)";
// constexpr auto k_celltype_str_u         = R"(CELLTYPE)";
// constexpr auto k_cond_str_u             = R"(COND)";
// constexpr auto k_condelse_str_u         = R"(CONDELSE)";
// constexpr auto k_date_str_u             = R"(DATE)";
// constexpr auto k_delay_str_u            = R"(DELAY)";
// constexpr auto k_delayfile_str_u        = R"(DELAYFILE)";
// constexpr auto k_departure_str_u        = R"(DEPARTURE)";
// constexpr auto k_design_str_u           = R"(DESIGN)";
// constexpr auto k_device_str_u           = R"(DEVICE)";
// constexpr auto k_diff_str_u             = R"(DIFF)";
// constexpr auto k_divider_str_u          = R"(DIVIDER)";
// constexpr auto k_exception_str_u        = R"(EXCEPTION)";
// constexpr auto k_hold_str_u             = R"(HOLD)";
// constexpr auto k_increment_str_u        = R"(INCREMENT)";
// constexpr auto k_instance_str_u         = R"(INSTANCE)";
// constexpr auto k_interconnect_str_u     = R"(INTERCONNECT)";
// constexpr auto k_iopath_str_u           = R"(IOPATH)";
// constexpr auto k_label_str_u            = R"(LABEL)";
// constexpr auto k_name_str_u             = R"(NAME)";
// constexpr auto k_netdelay_str_u         = R"(NETDELAY)";
// constexpr auto k_nochange_str_u         = R"(NOCHANGE)";
// constexpr auto k_pathconstraint_str_u   = R"(PATHCONSTRAINT)";
// constexpr auto k_pathpulse_str_u        = R"(PATHPULSE)";
// constexpr auto k_pathpulsepercent_str_u = R"(PATHPULSEPERCENT)";
// constexpr auto k_period_str_u           = R"(PERIOD)";
// constexpr auto k_periodconstraint_str_u = R"(PERIODCONSTRAINT)";
// constexpr auto k_port_str_u             = R"(PORT)";
// constexpr auto k_process_str_u          = R"(PROCESS)";
// constexpr auto k_program_str_u          = R"(PROGRAM)";
// constexpr auto k_recovery_str_u         = R"(RECOVERY)";
// constexpr auto k_recrem_str_u           = R"(RECREM)";
// constexpr auto k_removal_str_u          = R"(REMOVAL)";
// constexpr auto k_retain_str_u           = R"(RETAIN)";
// constexpr auto k_scond_str_u            = R"(SCOND)";
// constexpr auto k_sdfversion_str_u       = R"(SDFVERSION)";
// constexpr auto k_setup_str_u            = R"(SETUP)";
// constexpr auto k_setuphold_str_u        = R"(SETUPHOLD)";
// constexpr auto k_skew_str_u             = R"(SKEW)";
// constexpr auto k_skewconstraint_str_u   = R"(SKEWCONSTRAINT)";
// constexpr auto k_slack_str_u            = R"(SLACK)";
// constexpr auto k_sum_str_u              = R"(SUM)";
// constexpr auto k_temperature_str_u      = R"(TEMPERATURE)";
// constexpr auto k_timescale_str_u        = R"(TIMESCALE)";
// constexpr auto k_timingcheck_str_u      = R"(TIMINGCHECK)";
// constexpr auto k_timingenv_str_u        = R"(TIMINGENV)";
// constexpr auto k_vendor_str_u           = R"(VENDOR)";
// constexpr auto k_version_str_u          = R"(VERSION)";
// constexpr auto k_voltage_str_u          = R"(VOLTAGE)";
// constexpr auto k_waveform_str_u         = R"(WAVEFORM)";
// constexpr auto k_width_str_u            = R"(WIDTH)";




auto constexpr sdf_keywords = 
  std::array{
    k_absolute_str_l,          k_absolute_str_c,         k_absolute_str_u,
    k_arrival_str_l,          // k_arrival_str_c,          k_arrival_str_u,
    k_bidirectskew_str_l,     // k_bidirectskew_str_c,     k_bidirectskew_str_u,
    k_ccond_str_l,            // k_ccond_str_c,            k_ccond_str_u,
    k_cell_str_l,             // k_cell_str_c,             k_cell_str_u,
    k_celltype_str_l,         // k_celltype_str_c,         k_celltype_str_u,
    k_cond_str_l,             // k_cond_str_c,             k_cond_str_u,
    k_condelse_str_l,         // k_condelse_str_c,         k_condelse_str_u,
    k_date_str_l,             // k_date_str_c,             k_date_str_u,
    k_delay_str_l,            // k_delay_str_c,            k_delay_str_u,
    k_delayfile_str_l,        // k_delayfile_str_c,        k_delayfile_str_u,
    k_departure_str_l,        // k_departure_str_c,        k_departure_str_u,
    k_design_str_l,           // k_design_str_c,           k_design_str_u,
    k_device_str_l,           // k_device_str_c,           k_device_str_u,
    k_diff_str_l,             // k_diff_str_c,             k_diff_str_u,
    k_divider_str_l,          // k_divider_str_c,          k_divider_str_u,
    k_exception_str_l,        // k_exception_str_c,        k_exception_str_u,
    k_hold_str_l,             // k_hold_str_c,             k_hold_str_u,
    k_increment_str_l,        // k_increment_str_c,        k_increment_str_u,
    k_instance_str_l,         // k_instance_str_c,         k_instance_str_u,
    k_interconnect_str_l,     // k_interconnect_str_c,     k_interconnect_str_u,
    k_iopath_str_l,           // k_iopath_str_c,           k_iopath_str_u,
    k_label_str_l,            // k_label_str_c,            k_label_str_u,
    k_name_str_l,             // k_name_str_c,             k_name_str_u,
    k_netdelay_str_l,         // k_netdelay_str_c,         k_netdelay_str_u,
    k_nochange_str_l,         // k_nochange_str_c,         k_nochange_str_u,
    k_pathconstraint_str_l,   // k_pathconstraint_str_c,   k_pathconstraint_str_u,
    k_pathpulse_str_l,        // k_pathpulse_str_c,        k_pathpulse_str_u,
    k_pathpulsepercent_str_l, // k_pathpulsepercent_str_c, k_pathpulsepercent_str_u,
    k_period_str_l,           // k_period_str_c,           k_period_str_u,
    k_periodconstraint_str_l, // k_periodconstraint_str_c, k_periodconstraint_str_u,
    k_port_str_l,             // k_port_str_c,             k_port_str_u,
    k_process_str_l,          // k_process_str_c,          k_process_str_u,
    k_program_str_l,          // k_program_str_c,          k_program_str_u,
    k_recovery_str_l,         // k_recovery_str_c,         k_recovery_str_u,
    k_recrem_str_l,           // k_recrem_str_c,           k_recrem_str_u,
    k_removal_str_l,          // k_removal_str_c,          k_removal_str_u,
    k_retain_str_l,           // k_retain_str_c,           k_retain_str_u,
    k_scond_str_l,            // k_scond_str_c,            k_scond_str_u,
    k_sdfversion_str_l,       // k_sdfversion_str_c,       k_sdfversion_str_u,
    k_setup_str_l,            // k_setup_str_c,            k_setup_str_u,
    k_setuphold_str_l,        // k_setuphold_str_c,        k_setuphold_str_u,
    k_skew_str_l,             // k_skew_str_c,             k_skew_str_u,
    k_skewconstraint_str_l,   // k_skewconstraint_str_c,   k_skewconstraint_str_u,
    k_slack_str_l,            // k_slack_str_c,            k_slack_str_u,
    k_sum_str_l,              // k_sum_str_c,              k_sum_str_u,
    k_temperature_str_l,      // k_temperature_str_c,      k_temperature_str_u,
    k_timescale_str_l,        // k_timescale_str_c,        k_timescale_str_u,
    k_timingcheck_str_l,      // k_timingcheck_str_c,      k_timingcheck_str_u,
    k_timingenv_str_l,        // k_timingenv_str_c,        k_timingenv_str_u,
    k_vendor_str_l,           // k_vendor_str_c,           k_vendor_str_u,
    k_version_str_l,          // k_version_str_c,          k_version_str_u,
    k_voltage_str_l,          // k_voltage_str_c,          k_voltage_str_u,
    k_waveform_str_l,         // k_waveform_str_c,         k_waveform_str_u,
    k_width_str_l            // k_width_str_c,            k_width_str_u
  };

constexpr auto k_test_keyword            = R"(test_keyword)";


}
}
}

#endif //LIBSDF_TEST_SDF_KEYWORDS_H