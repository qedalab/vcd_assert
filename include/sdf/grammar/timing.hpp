#ifndef LIBSDF_GRAMMAR_TIMING_HPP 
#define LIBSDF_GRAMMAR_TIMING_HPP 

#include <sdf/grammar/base.hpp>
#include <sdf/grammar/cell.hpp>
#include <sdf/grammar/conditions.hpp>
#include <sdf/grammar/keywords.hpp>
#include <sdf/grammar/numbers.hpp>
#include <sdf/grammar/values.hpp>
#include <tao/pegtl.hpp>

namespace SDF {
namespace Grammar {
// clang-format off

/*
Required forward declartions so that grammar can be kept
in the order defined in the LRM (well reversed order, actually). 
*/
struct port_instance;
struct cell_instance;
struct iopath_def;

/*
  TIMING SPECIFICATIONS
*/

struct bus_net : op_sep_seq< 
  hierarchical_identifier,
  opt<
    op_sep_seq<
      one< '[' >,
      integer,
      one< ':' >,
      integer,
      one< ']' >
    >
  >
>{};

struct scalar_net : op_sep_seq< 
  hierarchical_identifier,
  opt< integer >
>{};

struct net : sor< 
  scalar_net,
  bus_net
>{};


struct net_instance : sor< 
  net,
  must<
    hierarchical_identifier,
    hchar,
    net
  >
>{};

struct net_spec : sor< 
  port_instance,
  net_instance
>{};

struct bus_port : op_sep_seq< 
  hierarchical_identifier,
  opt<
    op_sep_seq<
      one< '[' >,
      integer,
      one< ':' >,
      integer,
      one< ']' >
    >
  >
>{};

struct scalar_port : op_sep_seq< 
    hierarchical_identifier,
    opt< integer >
>{};

struct port : sor< 
  scalar_port,
  bus_port
>{};

struct port_instance : sor< 
  port,
  op_sep_seq< 
    hierarchical_identifier,
    hchar,
    port
  >
>{};

struct edge_identifier : sor<
  TAO_PEGTL_STRING( "posedge" ),
  TAO_PEGTL_STRING( "negedge" ),
  TAO_PEGTL_STRING( "01" ),
  TAO_PEGTL_STRING( "10" ),
  TAO_PEGTL_STRING( "0z" ),
  TAO_PEGTL_STRING( "z1" ),
  TAO_PEGTL_STRING( "1z" ),
  TAO_PEGTL_STRING( "z0" )
> {};

struct port_edge : op_sep_seq< 
  one< '(' >,
  edge_identifier,
  port_instance,
  one< ')' >
>{};


struct port_spec : sor< 
  port_instance,
  port_edge
>{};


struct lbl_def : op_sep_seq< 
  one< '(' >,
  identifier,
  delval_list,
  one< ')' >
>{};

struct lbl_type : op_sep_seq< 
  one< '(' >,
  sor< key_increment, key_absolute >,
  plus< lbl_def >,
  one< ')' >
>{};

struct neg_pair : op_sep_seq< 
  one< '(' >,
  TAO_PEGTL_ISTRING( "negedge" ),
  signed_real_number,
  opt< signed_real_number >,
  one< ')' >,
  one< '(' >,
  TAO_PEGTL_ISTRING( "posedge" ),
  signed_real_number,
  opt< signed_real_number >,
  one< ')' >
>{};

struct pos_pair : op_sep_seq< 
  one< '(' >,
  TAO_PEGTL_STRING( "posedge" ),
  signed_real_number,
  opt< signed_real_number >,
  one< ')' >,
  one< '(' >,
  TAO_PEGTL_ISTRING( "negedge" ),
  signed_real_number,
  opt< signed_real_number >,
  one< ')' >
>{};

struct edge_list : sor< 
  plus< pos_pair >,
  plus< neg_pair >  
>{};

struct waveform_env : block<
  key_waveform,
  port_instance,
  real_number,
  edge_list
>{};

struct slack_env : block< 
  key_slack,
  port_instance,
  rvalue,
  rvalue,
  rvalue,
  rvalue,
  opt< real_number >
>{};

struct departure_env : block< 
  key_departure,
  opt< port_edge >,
  port_instance,
  rvalue,
  rvalue,
  rvalue,
  rvalue
>{};

struct arrival_env : block<
  key_arrival,
  opt< port_edge >,
  port_instance,
  rvalue,
  rvalue,
  rvalue,
  rvalue
>{};

struct tenv_def : sor< 
  arrival_env,
  departure_env,
  slack_env,
  waveform_env
>{};

struct constraint_path : op_sep_seq< 
  one< '(' >,
  port_instance,
  port_instance,
  one< ')' >
>{};

struct name : block<
  key_name,
  opt< qstring >
>{};

struct exception : block<
  key_exception,
  plus< cell_instance >
>{};

struct skew_constraint : block<
  key_skewconstraint,
  port_spec,
  value
>{};

struct diff_constraint : block<
  key_diff,
  constraint_path,
  constraint_path,
  value,
  opt< value >
>{};

struct sum_constraint : block<
  key_sum,
  constraint_path,
  plus< constraint_path >,
  rvalue,
  opt< rvalue >
>{};

struct period_constraint : block<
  key_periodconstraint,
  port_instance, 
  value,
  opt< exception >
>{};

struct path_constraint : block<
  key_pathconstraint,
  opt< name >,
  port_instance,
  plus< port_instance >,
  rvalue,
  rvalue
>{};

struct cns_def : op_sep_seq<
  path_constraint,
  period_constraint,
  sum_constraint,
  diff_constraint,
  skew_constraint
>{};

struct te_def : sor< 
  cns_def,
  tenv_def
>{};

struct ccond : block<
  key_ccond,
  opt< qstring >,
  timing_check_condition
>{};


struct scond : block<
  key_scond,
  opt< qstring >,
  timing_check_condition
>{};

// switched order, for quicker failure
struct port_tchk : sor<
  block<
    key_cond,
    opt< qstring >,
    timing_check_condition,
    port_spec
  > ,
  port_spec
>{};

struct nochange_timing_check : unimplemented<key_nochange>{};
struct disabled_nochange_timing_check : block<
  key_nochange,
  port_tchk,
  port_tchk,
  rvalue,
  rvalue
>{};

struct period_timing_check : unimplemented<key_period>{};
struct disabled_period_timing_check : block<
  key_period,
  port_tchk,
  value
>{};

struct width_timing_check : unimplemented<key_width>{};
struct disabled_width_timing_check : block<
  key_width,
  port_tchk,
  value
>{};

struct bidirectskew_timing_check : unimplemented<key_bidirectskew>{};
struct disabled_bidirectskew_timing_check : block<
  key_bidirectskew,
  port_tchk,
  port_tchk,
  value,
  value
>{};

struct skew_timing_check : unimplemented<key_skew>{};
struct disabled_skew_timing_check : block<
  key_skew,
  port_tchk,
  port_tchk,
  rvalue
>{};

struct recrem_timing_check : unimplemented<key_recrem>{};
struct disabled_recrem_timing_check : block<
  key_recrem,
  port_tchk,
  port_tchk,
  rvalue,
  rvalue,
  if_must< scond, opt<sps>, ccond > 
>{};

struct removal_timing_check : unimplemented<key_removal>{};
struct disabled_removal_timing_check : block<
  key_removal,
  port_tchk,
  port_tchk,
  value
>{};

struct recovery_timing_check : unimplemented<key_recovery>{};
struct disabled_recovery_timing_check : block<
  key_recovery,
  port_tchk,
  port_tchk,
  value
>{};

// struct hold_timing_check : unimplemented<key_hold>{};
struct hold_timing_check : block<
  key_hold,
  port_tchk,
  port_tchk,
  value
>{};

struct setuphold_timing_check : unimplemented<key_setuphold>{};
struct disabled_setuphold_timing_check : sor<
  block<
    key_setuphold,
    port_tchk,
    port_tchk,
    rvalue,
    rvalue 
  >,
  block<
    key_setuphold,
    port_spec,
    port_spec,
    rvalue,
    rvalue,
    opt<scond>,
    opt<ccond> 
  >
>{};

// using hold_port_tchk_1 =  port_tchk;
// using hold_port_tchk_2 =  port_tchk;

struct setup_timing_check : unimplemented<key_setup>{};
struct disabled_setup_timing_check : block<
  key_setup,
  port_tchk,
  port_tchk,
  value
>{};

struct tchk_def : sor< 
  setup_timing_check,
  hold_timing_check,
  setuphold_timing_check,
  recovery_timing_check,
  removal_timing_check,
  recrem_timing_check,
  skew_timing_check,
  bidirectskew_timing_check,
  width_timing_check,
  period_timing_check,
  nochange_timing_check
>{};

struct device_def : block<
  key_device,
  opt< port_instance >,
  delval_list
>{};

struct netdelay_def : block<
  key_netdelay,
  net_spec,
  delval_list
>{};

struct interconnect_def : block<
  key_interconnect,
  port_instance,
  port_instance,
  delval_list
>{};

struct port_def : block<
  key_port,
  port_instance,
  delval_list
>{};

struct retain_def : block<
  key_retain,
  retval_list
>{};

struct iopath_def : block<
  key_iopath,
  port_spec,
  port_instance,
  star< retain_def >,
  delval_list
>{};

struct condelse_def : block<
  key_condelse,
  iopath_def
>{};

struct cond_def : block<
  key_cond,
  opt< qstring >,
  conditional_port_expr,
  iopath_def
>{};

struct del_def : sor< 
  port_def,
  netdelay_def,
  iopath_def,
  interconnect_def,
  device_def,
  condelse_def,
  cond_def
>{};

struct input_output_path : op_sep_seq< 
  port_instance, 
  port_instance
>{};

struct increment_deltype : block<
  key_increment,
  plus< del_def >
>{};

struct absolute_deltype : block<
  key_absolute,
  plus< del_def >
>{};

struct pathpulsepercent_deltype : block<
  key_pathpulsepercent,
  opt< input_output_path >,
  value,
  opt< value >
>{};

struct pathpulse_deltype : block<
  key_pathpulse,
  opt< input_output_path >,
  value,
  opt< value >
>{};

struct deltype : sor< 
  absolute_deltype,
  increment_deltype,
  pathpulse_deltype,
  pathpulsepercent_deltype
>{};

struct te_spec : unimplemented< key_timingenv >{};
// struct te_spec : block<
//     key_timingenv,
//     plus< te_def >
// >{};

struct lbl_spec : unimplemented< key_label >{};
// struct lbl_spec : block<
//     key_label,
//     plus< lbl_type >
// >{};

// struct tc_spec : unimplemented< key_timingcheck >{};
struct tc_spec : block<
    key_timingcheck,
    plus< tchk_def >
>{};

struct del_spec : unimplemented< key_delay >{};

// struct del_spec : block<
//     key_delay,
//     plus< deltype >
// >{};

struct timing_spec : sor<
  del_spec,
  tc_spec,
  lbl_spec,
  te_spec
>{};

// clang-format on
} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_TIMING_HPP 
