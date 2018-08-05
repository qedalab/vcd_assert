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


template< typename Key >
struct key : seq< Key, not_at< character > > {};

/* LANGUAGE */

struct always_str                 : TAO_PEGTL_STRING("always"){};
struct always_keyword             : key <always_str> {};
struct and_str                    : TAO_PEGTL_STRING("and"){};
struct and_keyword                : key <and_str> {};
struct assign_str                 : TAO_PEGTL_STRING("assign"){};
struct assign_keyword             : key <assign_str> {};
struct automatic_str              : TAO_PEGTL_STRING("automatic"){};
struct automatic_keyword          : key <automatic_str> {};
struct begin_str                  : TAO_PEGTL_STRING("begin"){};
struct begin_keyword              : key <begin_str> {};
struct buf_str                    : TAO_PEGTL_STRING("buf"){};
struct buf_keyword                : key <buf_str> {};
struct bufif0_str                 : TAO_PEGTL_STRING("bufif0"){};
struct bufif0_keyword             : key <bufif0_str> {};
struct bufif1_str                 : TAO_PEGTL_STRING("bufif1"){};
struct bufif1_keyword             : key <bufif1_str> {};
struct case_str                   : TAO_PEGTL_STRING("case"){};
struct case_keyword               : key <case_str> {};
struct casex_str                  : TAO_PEGTL_STRING("casex"){};
struct casex_keyword              : key <casex_str> {};
struct casez_str                  : TAO_PEGTL_STRING("casez"){};
struct casez_keyword              : key <casez_str> {};
struct cell_str                   : TAO_PEGTL_STRING("cell"){};
struct cell_keyword               : key <cell_str> {};
struct cmos_str                   : TAO_PEGTL_STRING("cmos"){};
struct cmos_keyword               : key <cmos_str> {};
struct config_str                 : TAO_PEGTL_STRING("config"){};
struct config_keyword             : key <config_str> {};
struct deassign_str               : TAO_PEGTL_STRING("deassign"){};
struct deassign_keyword           : key <deassign_str> {};
struct default_str                : TAO_PEGTL_STRING("default"){};
struct default_keyword            : key <default_str> {};
struct defparam_str               : TAO_PEGTL_STRING("defparam"){};
struct defparam_keyword           : key <defparam_str> {};
struct design_str                 : TAO_PEGTL_STRING("design"){};
struct design_keyword             : key <design_str> {};
struct disable_str                : TAO_PEGTL_STRING("disable"){};
struct disable_keyword            : key <disable_str> {};
struct edge_str                   : TAO_PEGTL_STRING("edge"){};
struct edge_keyword               : key <edge_str> {};
struct else_str                   : TAO_PEGTL_STRING("else"){};
struct else_keyword               : key <else_str> {};
struct end_str                    : TAO_PEGTL_STRING("end"){};
struct end_keyword                : key <end_str> {};
struct endcase_str                : TAO_PEGTL_STRING("endcase"){};
struct endcase_keyword            : key <endcase_str> {};
struct endconfig_str              : TAO_PEGTL_STRING("endconfig"){};
struct endconfig_keyword          : key <endconfig_str> {};
struct endfunction_str            : TAO_PEGTL_STRING("endfunction"){};
struct endfunction_keyword        : key <endfunction_str> {};
struct endgenerate_str            : TAO_PEGTL_STRING("endgenerate"){};
struct endgenerate_keyword        : key <endgenerate_str> {};
struct endmodule_str              : TAO_PEGTL_STRING("endmodule"){};
struct endmodule_keyword          : key <endmodule_str> {};
struct endprimitive_str           : TAO_PEGTL_STRING("endprimitive"){};
struct endprimitive_keyword       : key <endprimitive_str> {};
struct endspecify_str             : TAO_PEGTL_STRING("endspecify"){};
struct endspecify_keyword         : key <endspecify_str> {};
struct endtable_str               : TAO_PEGTL_STRING("endtable"){};
struct endtable_keyword           : key <endtable_str> {};
struct endtask_str                : TAO_PEGTL_STRING("endtask"){};
struct endtask_keyword            : key <endtask_str> {};
struct event_str                  : TAO_PEGTL_STRING("event"){};
struct event_keyword              : key <event_str> {};
struct for_str                    : TAO_PEGTL_STRING("for"){};
struct for_keyword                : key <for_str> {};
struct force_str                  : TAO_PEGTL_STRING("force"){};
struct force_keyword              : key <force_str> {};
struct forever_str                : TAO_PEGTL_STRING("forever"){};
struct forever_keyword            : key <forever_str> {};
struct fork_str                   : TAO_PEGTL_STRING("fork"){};
struct fork_keyword               : key <fork_str> {};
struct function_str               : TAO_PEGTL_STRING("function"){};
struct function_keyword           : key <function_str> {};
struct generate_str               : TAO_PEGTL_STRING("generate"){};
struct generate_keyword           : key <generate_str> {};
struct genvar_str                 : TAO_PEGTL_STRING("genvar"){};
struct genvar_keyword             : key <genvar_str> {};
struct highz0_str                 : TAO_PEGTL_STRING("highz0"){};
struct highz0_keyword             : key <highz0_str> {};
struct highz1_str                 : TAO_PEGTL_STRING("highz1"){};
struct highz1_keyword             : key <highz1_str> {};
struct if_str                     : TAO_PEGTL_STRING("if"){};
struct if_keyword                 : key <if_str> {};
struct ifnone_str                 : TAO_PEGTL_STRING("ifnone"){};
struct ifnone_keyword             : key <ifnone_str> {};
struct incdir_str                 : TAO_PEGTL_STRING("incdir"){};
struct incdir_keyword             : key <incdir_str> {};
struct include_str                : TAO_PEGTL_STRING("include"){};
struct include_keyword            : key <include_str> {};
struct initial_str                : TAO_PEGTL_STRING("initial"){};
struct initial_keyword            : key <initial_str> {};
struct inout_str                  : TAO_PEGTL_STRING("inout"){};
struct inout_keyword              : key <inout_str> {};
struct input_str                  : TAO_PEGTL_STRING("input"){};
struct input_keyword              : key <input_str> {};
struct instance_str               : TAO_PEGTL_STRING("instance"){};
struct instance_keyword           : key <instance_str> {};
struct integer_str                : TAO_PEGTL_STRING("integer"){};
struct integer_keyword            : key <integer_str> {};
struct join_str                   : TAO_PEGTL_STRING("join"){};
struct join_keyword               : key <join_str> {};
struct large_str                  : TAO_PEGTL_STRING("large"){};
struct large_keyword              : key <large_str> {};
struct liblist_str                : TAO_PEGTL_STRING("liblist"){};
struct liblist_keyword            : key <liblist_str> {};
struct library_str                : TAO_PEGTL_STRING("library"){};
struct library_keyword            : key <library_str> {};
struct localparam_str             : TAO_PEGTL_STRING("localparam"){};
struct localparam_keyword         : key <localparam_str> {};
struct macromodule_str            : TAO_PEGTL_STRING("macromodule"){};
struct macromodule_keyword        : key <macromodule_str> {};
struct medium_str                 : TAO_PEGTL_STRING("medium"){};
struct medium_keyword             : key <medium_str> {};
struct module_str                 : TAO_PEGTL_STRING("module"){};
struct module_keyword             : sor<macromodule_keyword, key <module_str> > {}; //<<<<< DIFFERENT 
struct nand_str                   : TAO_PEGTL_STRING("nand"){};
struct nand_keyword               : key <nand_str> {};
struct negedge_str                : TAO_PEGTL_STRING("negedge"){}; 
struct negedge_keyword            : key <negedge_str> {};
struct nmos_str                   : TAO_PEGTL_STRING("nmos"){};
struct nmos_keyword               : key <nmos_str> {};
struct nor_str                    : TAO_PEGTL_STRING("nor"){};
struct nor_keyword                : key <nor_str> {};
struct noshowcancelled_str        : TAO_PEGTL_STRING("noshowcancelled"){};
struct noshowcancelled_keyword    : key <noshowcancelled_str> {};
struct not_str                    : TAO_PEGTL_STRING("not"){};
struct not_keyword                : key <not_str> {};
struct notif0_str                 : TAO_PEGTL_STRING("notif0"){};
struct notif0_keyword             : key <notif0_str> {};
struct notif1_str                 : TAO_PEGTL_STRING("notif1"){};
struct notif1_keyword             : key <notif1_str> {};
struct or_str                     : TAO_PEGTL_STRING("or"){};
struct or_keyword                 : key <or_str> {};
struct output_str                 : TAO_PEGTL_STRING("output"){};
struct output_keyword             : key <output_str> {};
struct parameter_str              : TAO_PEGTL_STRING("parameter"){};
struct parameter_keyword          : key <parameter_str> {};
struct pmos_str                   : TAO_PEGTL_STRING("pmos"){};
struct pmos_keyword               : key <pmos_str> {};
struct posedge_str                : TAO_PEGTL_STRING("posedge"){};
struct posedge_keyword            : key <posedge_str> {};
struct primitive_str              : TAO_PEGTL_STRING("primitive"){};
struct primitive_keyword          : key <primitive_str> {};
struct pull0_str                  : TAO_PEGTL_STRING("pull0"){};
struct pull0_keyword              : key <pull0_str> {};
struct pull1_str                  : TAO_PEGTL_STRING("pull1"){};
struct pull1_keyword              : key <pull1_str> {};
struct pulldown_str               : TAO_PEGTL_STRING("pulldown"){};
struct pulldown_keyword           : key <pulldown_str> {};
struct pullup_str                 : TAO_PEGTL_STRING("pullup"){};
struct pullup_keyword             : key <pullup_str> {};
struct pulsestyle_onevent_str     : TAO_PEGTL_STRING("pulsestyle_onevent"){};
struct pulsestyle_onevent_keyword : key <pulsestyle_onevent_str> {};
struct pulsestyle_ondetect_str    : TAO_PEGTL_STRING("pulsestyle_ondetect"){};
struct pulsestyle_ondetect_keyword: key <pulsestyle_ondetect_str> {};
struct rcmos_str                  : TAO_PEGTL_STRING("rcmos"){};
struct rcmos_keyword              : key <rcmos_str> {};
struct real_str                   : TAO_PEGTL_STRING("real"){};
struct real_keyword               : key <real_str> {};
struct realtime_str               : TAO_PEGTL_STRING("realtime"){};
struct realtime_keyword           : key <realtime_str> {};
struct reg_str                    : TAO_PEGTL_STRING("reg"){};
struct reg_keyword                : key <reg_str> {};
struct release_str                : TAO_PEGTL_STRING("release"){};
struct release_keyword            : key <release_str> {};
struct repeat_str                 : TAO_PEGTL_STRING("repeat"){};
struct repeat_keyword             : key <repeat_str> {};
struct rnmos_str                  : TAO_PEGTL_STRING("rnmos"){};
struct rnmos_keyword              : key <rnmos_str> {};
struct rpmos_str                  : TAO_PEGTL_STRING("rpmos"){};
struct rpmos_keyword              : key <rpmos_str> {};
struct rtran_str                  : TAO_PEGTL_STRING("rtran"){};
struct rtran_keyword              : key <rtran_str> {};
struct rtranif0_str               : TAO_PEGTL_STRING("rtranif0"){};
struct rtranif0_keyword           : key <rtranif0_str> {};
struct rtranif1_str               : TAO_PEGTL_STRING("rtranif1"){};
struct rtranif1_keyword           : key <rtranif1_str> {};
struct scalared_str               : TAO_PEGTL_STRING("scalared"){};
struct scalared_keyword           : key <scalared_str> {};
struct showcancelled_str          : TAO_PEGTL_STRING("showcancelled"){};
struct showcancelled_keyword      : key <showcancelled_str> {};
struct signed_str                 : TAO_PEGTL_STRING("signed"){};
struct signed_keyword             : key <signed_str> {};
struct small_str                  : TAO_PEGTL_STRING("small"){};
struct small_keyword              : key <small_str> {};
struct specify_str                : TAO_PEGTL_STRING("specify"){};
struct specify_keyword            : key <specify_str> {};
struct specparam_str              : TAO_PEGTL_STRING("specparam"){};
struct specparam_keyword          : key <specparam_str> {};
struct strong0_str                : TAO_PEGTL_STRING("strong0"){};
struct strong0_keyword            : key <strong0_str> {};
struct strong1_str                : TAO_PEGTL_STRING("strong1"){};
struct strong1_keyword            : key <strong1_str> {};
struct supply0_str                : TAO_PEGTL_STRING("supply0"){};
struct supply0_keyword            : key <supply0_str> {};
struct supply1_str                : TAO_PEGTL_STRING("supply1"){};
struct supply1_keyword            : key <supply1_str> {};
struct table_str                  : TAO_PEGTL_STRING("table"){};
struct table_keyword              : key <table_str> {};
struct task_str                   : TAO_PEGTL_STRING("task"){};
struct task_keyword               : key <task_str> {};
struct time_str                   : TAO_PEGTL_STRING("time"){};
struct time_keyword               : key <time_str> {};
struct tran_str                   : TAO_PEGTL_STRING("tran"){};
struct tran_keyword               : key <tran_str> {};
struct tranif0_str                : TAO_PEGTL_STRING("tranif0"){};
struct tranif0_keyword            : key <tranif0_str> {};
struct tranif1_str                : TAO_PEGTL_STRING("tranif1"){};
struct tranif1_keyword            : key <tranif1_str> {};
struct tri_str                    : TAO_PEGTL_STRING("tri"){};
struct tri_keyword                : key <tri_str> {};
struct tri0_str                   : TAO_PEGTL_STRING("tri0"){};
struct tri0_keyword               : key <tri0_str> {};
struct tri1_str                   : TAO_PEGTL_STRING("tri1"){};
struct tri1_keyword               : key <tri1_str> {};
struct triand_str                 : TAO_PEGTL_STRING("triand"){};
struct triand_keyword             : key <triand_str> {};
struct trior_str                  : TAO_PEGTL_STRING("trior"){};
struct trior_keyword              : key <trior_str> {};
struct trireg_str                 : TAO_PEGTL_STRING("trireg"){};
struct trireg_keyword             : key <trireg_str> {};
struct unsigned_str               : TAO_PEGTL_STRING("unsigned"){};
struct unsigned_keyword           : key <unsigned_str> {};
struct use_str                    : TAO_PEGTL_STRING("use"){};
struct use_keyword                : key <use_str> {};
struct vectored_str               : TAO_PEGTL_STRING("vectored"){};
struct vectored_keyword           : key <vectored_str> {};
struct wait_str                   : TAO_PEGTL_STRING("wait"){};
struct wait_keyword               : key <wait_str> {};
struct wand_str                   : TAO_PEGTL_STRING("wand"){};
struct wand_keyword               : key <wand_str> {};
struct weak0_str                  : TAO_PEGTL_STRING("weak0"){};
struct weak0_keyword              : key <weak0_str> {};
struct weak1_str                  : TAO_PEGTL_STRING("weak1"){};
struct weak1_keyword              : key <weak1_str> {};
struct while_str                  : TAO_PEGTL_STRING("while"){};
struct while_keyword              : key <while_str> {};
struct wire_str                   : TAO_PEGTL_STRING("wire"){};
struct wire_keyword               : key <wire_str> {};
struct wor_str                    : TAO_PEGTL_STRING("wor"){};
struct wor_keyword                : key <wor_str> {};
struct xnor_str                   : TAO_PEGTL_STRING("xnor"){};
struct xnor_keyword               : key <xnor_str> {};
struct xor_str                    : TAO_PEGTL_STRING("xor"){};
struct xor_keyword                : key <xor_str> {};

/* SYSTEM */

/* Display tasks [17.1]*/
struct display_str                : TAO_PEGTL_STRING("display"){};
struct display_keyword            : key <display_str> {};
struct displayb_str               : TAO_PEGTL_STRING("displayb"){};
struct displayb_keyword           : key <displayb_str> {};
struct displayh_str               : TAO_PEGTL_STRING("displayh"){};
struct displayh_keyword           : key <displayh_str> {};
struct displayo_str               : TAO_PEGTL_STRING("displayo"){};
struct displayo_keyword           : key <displayo_str> {};
struct monitor_str                : TAO_PEGTL_STRING("monitor"){};
struct monitor_keyword            : key <monitor_str> {};
struct monitorb_str               : TAO_PEGTL_STRING("monitorb"){};
struct monitorb_keyword           : key <monitorb_str> {};
struct monitorh_str               : TAO_PEGTL_STRING("monitorh"){};
struct monitorh_keyword           : key <monitorh_str> {};
struct monitoro_str               : TAO_PEGTL_STRING("monitoro"){};
struct monitoro_keyword           : key <monitoro_str> {};
struct monitoroff_str             : TAO_PEGTL_STRING("monitoroff "){};
struct monitoroff_keyword         : key <monitoroff_str> {};
struct strobe_str                 : TAO_PEGTL_STRING("strobe"){};
struct strobe_keyword             : key <strobe_str> {};
struct strobeb_str                : TAO_PEGTL_STRING("strobeb"){};
struct strobeb_keyword            : key <strobeb_str> {};
struct strobeh_str                : TAO_PEGTL_STRING("strobeh"){};
struct strobeh_keyword            : key <strobeh_str> {};
struct strobeo_str                : TAO_PEGTL_STRING("strobeo"){};
struct strobeo_keyword            : key <strobeo_str> {};
struct write_str                  : TAO_PEGTL_STRING("write"){};
struct write_keyword              : key <write_str> {};
struct writeb_str                 : TAO_PEGTL_STRING("writeb"){};
struct writeb_keyword             : key <writeb_str> {};
struct writeh_str                 : TAO_PEGTL_STRING("writeh"){};
struct writeh_keyword             : key <writeh_str> {};
struct writeo_str                 : TAO_PEGTL_STRING("writeo"){};
struct writeo_keyword             : key <writeo_str> {};
struct monitoron_str              : TAO_PEGTL_STRING("monitoron"){};
struct monitoron_keyword          : key <monitoron_str> {};
/* File I/O tasks [17.2]*/
struct fclose_str                 : TAO_PEGTL_STRING("fclose"){};
struct fclose_keyword             : key <fclose_str> {};
struct fdisplay_str               : TAO_PEGTL_STRING("fdisplay"){};
struct fdisplay_keyword           : key <fdisplay_str> {};
struct fdisplayb_str              : TAO_PEGTL_STRING("fdisplayb"){};
struct fdisplayb_keyword          : key <fdisplayb_str> {};
struct fdisplayh_str              : TAO_PEGTL_STRING("fdisplayh"){};
struct fdisplayh_keyword          : key <fdisplayh_str> {};
struct fdisplayo_str              : TAO_PEGTL_STRING("fdisplayo"){};
struct fdisplayo_keyword          : key <fdisplayo_str> {};
struct fgetc_str                  : TAO_PEGTL_STRING("fgetc"){};
struct fgetc_keyword              : key <fgetc_str> {};
struct fflush_str                 : TAO_PEGTL_STRING("fflush"){};
struct fflush_keyword             : key <fflush_str> {};
struct fgets_str                  : TAO_PEGTL_STRING("fgets"){};
struct fgets_keyword              : key <fgets_str> {};
struct fmonitor_str               : TAO_PEGTL_STRING("fmonitor"){};
struct fmonitor_keyword           : key <fmonitor_str> {};
struct fmonitorb_str              : TAO_PEGTL_STRING("fmonitorb"){};
struct fmonitorb_keyword          : key <fmonitorb_str> {};
struct fmonitorh_str              : TAO_PEGTL_STRING("fmonitorh"){};
struct fmonitorh_keyword          : key <fmonitorh_str> {};
struct fmonitoro_str              : TAO_PEGTL_STRING("fmonitoro"){};
struct fmonitoro_keyword          : key <fmonitoro_str> {};
struct readmemb_str               : TAO_PEGTL_STRING("readmemb"){};
struct readmemb_keyword           : key <readmemb_str> {};
struct swrite_str                 : TAO_PEGTL_STRING("swrite"){};
struct swrite_keyword             : key <swrite_str> {};
struct swriteo_str                : TAO_PEGTL_STRING("swriteo"){};
struct swriteo_keyword            : key <swriteo_str> {};
struct sformat_str                : TAO_PEGTL_STRING("sformat"){};
struct sformat_keyword            : key <sformat_str> {};
struct fscanf_str                 : TAO_PEGTL_STRING("fscanf"){};
struct fscanf_keyword             : key <fscanf_str> {};
struct fread_str                  : TAO_PEGTL_STRING("fread"){};
struct fread_keyword              : key <fread_str> {};
struct fseek_str                  : TAO_PEGTL_STRING("fseek"){};
struct fseek_keyword              : key <fseek_str> {};
struct fopen_str                  : TAO_PEGTL_STRING("fopen"){};
struct fopen_keyword              : key <fopen_str> {};
struct fstrobe_str                : TAO_PEGTL_STRING("fstrobe"){};
struct fstrobe_keyword            : key <fstrobe_str> {};
struct fstrobeb_str               : TAO_PEGTL_STRING("fstrobeb"){};
struct fstrobeb_keyword           : key <fstrobeb_str> {};
struct fstrobeh_str               : TAO_PEGTL_STRING("fstrobeh"){};
struct fstrobeh_keyword           : key <fstrobeh_str> {};
struct fstrobeo_str               : TAO_PEGTL_STRING("fstrobeo"){};
struct fstrobeo_keyword           : key <fstrobeo_str> {};
struct ungetc_str                 : TAO_PEGTL_STRING("ungetc"){};
struct ungetc_keyword             : key <ungetc_str> {};
struct ferror_str                 : TAO_PEGTL_STRING("ferror"){};
struct ferror_keyword             : key <ferror_str> {};
struct rewind_str                 : TAO_PEGTL_STRING("rewind"){};
struct rewind_keyword             : key <rewind_str> {};
struct fwrite_str                 : TAO_PEGTL_STRING("fwrite"){};
struct fwrite_keyword             : key <fwrite_str> {};
struct fwriteb_str                : TAO_PEGTL_STRING("fwriteb"){};
struct fwriteb_keyword            : key <fwriteb_str> {};
struct fwriteh_str                : TAO_PEGTL_STRING("fwriteh"){};
struct fwriteh_keyword            : key <fwriteh_str> {};
struct fwriteo_str                : TAO_PEGTL_STRING("fwriteo"){};
struct fwriteo_keyword            : key <fwriteo_str> {};
struct readmemh_str               : TAO_PEGTL_STRING("readmemh"){};
struct readmemh_keyword           : key <readmemh_str> {};
struct swriteb_str                : TAO_PEGTL_STRING("swriteb"){};
struct swriteb_keyword            : key <swriteb_str> {};
struct swriteh_str                : TAO_PEGTL_STRING("swriteh"){};
struct swriteh_keyword            : key <swriteh_str> {};
struct sdf_annotate_str           : TAO_PEGTL_STRING("sdf_annotate"){};
struct sdf_annotate_keyword       : key <sdf_annotate_str> {};
struct sscanf_str                 : TAO_PEGTL_STRING("sscanf"){};
struct sscanf_keyword             : key <sscanf_str> {};
struct ftell_str                  : TAO_PEGTL_STRING("ftell"){};
struct ftell_keyword              : key <ftell_str> {};
/* Timescale tasks [17.3]*/
struct printtimescale_str         : TAO_PEGTL_STRING("printtimescale "){};
struct printtimescale_keyword     : key <printtimescale_str> {};
struct timeformat_str             : TAO_PEGTL_STRING("timeformat"){};
struct timeformat_keyword         : key <timeformat_str> {};
/* Simulation control tasks [17.4]*/
struct finish_str                 : TAO_PEGTL_STRING("finish"){};
struct finish_keyword             : key <finish_str> {};
struct stop_str                   : TAO_PEGTL_STRING("stop"){};
struct stop_keyword               : key <stop_str> {};
/* PLA modeling tasks [17.5]*/
struct async_and_array_str        : TAO_PEGTL_STRING("async$and$array"){};
struct async_and_array_keyword    : key <async_and_array_str> {};
struct async_nand_array_str       : TAO_PEGTL_STRING("async$nand$array"){};
struct async_nand_array_keyword   : key <async_nand_array_str> {};
struct async_or_array_str         : TAO_PEGTL_STRING("async$or$array"){};
struct async_or_array_keyword     : key <async_or_array_str> {};
struct async_nor_array_str        : TAO_PEGTL_STRING("async$nor$array"){};
struct async_nor_array_keyword    : key <async_nor_array_str> {};
struct sync_and_array_str         : TAO_PEGTL_STRING("sync$and$array"){};
struct sync_and_array_keyword     : key <sync_and_array_str> {};
struct sync_nand_array_str        : TAO_PEGTL_STRING("sync$nand$array"){};
struct sync_nand_array_keyword    : key <sync_nand_array_str> {};
struct sync_or_array_str          : TAO_PEGTL_STRING("sync$or$array"){};
struct sync_or_array_keyword      : key <sync_or_array_str> {};
struct sync_nor_array_str         : TAO_PEGTL_STRING("sync$nor$array"){};
struct sync_nor_array_keyword     : key <sync_nor_array_str> {};
struct async_and_plane_str        : TAO_PEGTL_STRING("async$and$plane"){};
struct async_and_plane_keyword    : key <async_and_plane_str> {};
struct async_nand_plane_str       : TAO_PEGTL_STRING("async$nand$plane"){};
struct async_nand_plane_keyword   : key <async_nand_plane_str> {};
struct async_or_plane_str         : TAO_PEGTL_STRING("async$or$plane"){};
struct async_or_plane_keyword     : key <async_or_plane_str> {};
struct async_nor_plane_str        : TAO_PEGTL_STRING("async$nor$plane"){};
struct async_nor_plane_keyword    : key <async_nor_plane_str> {};
struct sync_and_plane_str         : TAO_PEGTL_STRING("sync$and$plane"){};
struct sync_and_plane_keyword     : key <sync_and_plane_str> {};
struct sync_nand_plane_str        : TAO_PEGTL_STRING("sync$nand$plane"){};
struct sync_nand_plane_keyword    : key <sync_nand_plane_str> {};
struct sync_or_plane_str          : TAO_PEGTL_STRING("sync$or$plane"){};
struct sync_or_plane_keyword      : key <sync_or_plane_str> {};
struct sync_nor_plane_str         : TAO_PEGTL_STRING("sync$nor$plane"){};
struct sync_nor_plane_keyword     : key <sync_nor_plane_str> {};
/* Stochastic analysis tasks [17.6]*/
struct q_initialize_str           : TAO_PEGTL_STRING("q_initialize"){};
struct q_initialize_keyword       : key <q_initialize_str> {};
struct q_remove_str               : TAO_PEGTL_STRING("q_remove"){};
struct q_remove_keyword           : key <q_remove_str> {};
struct q_exam_str                 : TAO_PEGTL_STRING("q_exam"){};
struct q_exam_keyword             : key <q_exam_str> {};
struct q_add_str                  : TAO_PEGTL_STRING("q_add"){};
struct q_add_keyword              : key <q_add_str> {};
struct q_full_str                 : TAO_PEGTL_STRING("q_full"){};
struct q_full_keyword             : key <q_full_str> {};
/* Simulation time functions [17.7]*/
// struct realtime_str               : TAO_PEGTL_STRING("realtime"){}; // DUP
// struct realtime_keyword           : key <realtime_str> {}; // DUP
// struct time_str                   : TAO_PEGTL_STRING("time"){}; // DUP
// struct time_keyword               : key <time_str> {}; // DUP
struct stime_str                  : TAO_PEGTL_STRING("stime"){};
struct stime_keyword              : key <stime_str> {};
/* Conversion functions [17.8]*/
struct bitstoreal_str             : TAO_PEGTL_STRING("bitstoreal"){};
struct bitstoreal_keyword         : key <bitstoreal_str> {};
struct itor_str                   : TAO_PEGTL_STRING("itor"){};
struct itor_keyword               : key <itor_str> {};
// struct signed_str                 : TAO_PEGTL_STRING("signed"){}; //DUP
// struct signed_keyword             : key <signed_str> {}; //DUP
struct realtobits_str             : TAO_PEGTL_STRING("realtobits"){};
struct realtobits_keyword         : key <realtobits_str> {};
struct rtoi_str                   : TAO_PEGTL_STRING("rtoi"){};
struct rtoi_keyword               : key <rtoi_str> {};
// struct unsigned_str               : TAO_PEGTL_STRING("unsigned"){}; //DUP
// struct unsigned_keyword           : key <unsigned_str> {}; //DUP
/* Probabilistic distribution functions  [17.9]*/ 
struct dist_chi_square_str        : TAO_PEGTL_STRING("dist_chi_square"){};
struct dist_chi_square_keyword    : key <dist_chi_square_str> {};
struct dist_exponential_str       : TAO_PEGTL_STRING("dist_exponential"){};
struct dist_exponential_keyword   : key <dist_exponential_str> {};
struct dist_poisson_str           : TAO_PEGTL_STRING("dist_poisson"){};
struct dist_poisson_keyword       : key <dist_poisson_str> {};
struct dist_uniform_str           : TAO_PEGTL_STRING("dist_uniform"){};
struct dist_uniform_keyword       : key <dist_uniform_str> {};
struct dist_erlang_str            : TAO_PEGTL_STRING("dist_erlang"){};
struct dist_erlang_keyword        : key <dist_erlang_str> {};
struct dist_normal_str            : TAO_PEGTL_STRING("dist_normal"){};
struct dist_normal_keyword        : key <dist_normal_str> {};
struct dist_t_str                 : TAO_PEGTL_STRING("dist_t"){};
struct dist_t_keyword             : key <dist_t_str> {};
struct random_str                 : TAO_PEGTL_STRING("random"){};
struct random_keyword             : key <random_str> {};
/* Command line input  /17.10]*/
struct test_plusargs_str          : TAO_PEGTL_STRING("test$plusargs"){};
struct test_plusargs_keyword      : key <test_plusargs_str> {};
struct value_plusargs_str         : TAO_PEGTL_STRING("value$plusargs"){};
struct value_plusargs_keyword     : key <value_plusargs_str> {};


struct keyword_str: sor< 
always_str,
and_str,
assign_str,
automatic_str,
begin_str,
buf_str,
bufif0_str,
bufif1_str,
case_str,
casex_str,
casez_str,
cell_str,
cmos_str,
config_str,
deassign_str,
default_str,
defparam_str,
design_str,
disable_str,
edge_str,
else_str,
end_str,
endcase_str,
endconfig_str,
endfunction_str,
endgenerate_str,
endmodule_str,
endprimitive_str,
endspecify_str,
endtable_str,
endtask_str,
event_str,
for_str,
force_str,
forever_str,
fork_str,
function_str,
generate_str,
genvar_str,
highz0_str,
highz1_str,
if_str,
ifnone_str,
incdir_str,
include_str,
initial_str,
inout_str,
input_str,
instance_str,
integer_str,
join_str,
large_str,
liblist_str,
library_str,
localparam_str,
macromodule_str,
medium_str,
module_str,
nand_str,
negedge_str,
nmos_str,
nor_str,
noshowcancelled_str,
not_str,
notif0_str,
notif1_str,
or_str,
output_str,
parameter_str,
pmos_str,
posedge_str,
primitive_str,
pull0_str,
pull1_str,
pulldown_str,
pullup_str,
pulsestyle_onevent_str,
pulsestyle_ondetect_str,
rcmos_str,
real_str,
realtime_str,
reg_str,
release_str,
repeat_str,
rnmos_str,
rpmos_str,
rtran_str,
rtranif0_str,
rtranif1_str,
scalared_str,
showcancelled_str,
signed_str,
small_str,
specify_str,
specparam_str,
strong0_str,
strong1_str,
supply0_str,
supply1_str,
table_str,
task_str,
time_str,
tran_str,
tranif0_str,
tranif1_str,
tri_str,
tri0_str,
tri1_str,
triand_str,
trior_str,
trireg_str,
unsigned_str,
use_str,
vectored_str,
wait_str,
wand_str,
weak0_str,
weak1_str,
while_str,
wire_str,
wor_str,
xnor_str,
xor_str,
display_str,
displayb_str,
displayh_str,
displayo_str,
monitor_str,
monitorb_str,
monitorh_str,
monitoro_str,
monitoroff_str,
strobe_str,
strobeb_str,
strobeh_str,
strobeo_str,
write_str,
writeb_str,
writeh_str,
writeo_str,
monitoron_str,
fclose_str,
fdisplay_str,
fdisplayb_str,
fdisplayh_str,
fdisplayo_str,
fgetc_str,
fflush_str,
fgets_str,
fmonitor_str,
fmonitorb_str,
fmonitorh_str,
fmonitoro_str,
readmemb_str,
swrite_str,
swriteo_str,
sformat_str,
fscanf_str,
fread_str,
fseek_str,
fopen_str,
fstrobe_str,
fstrobeb_str,
fstrobeh_str,
fstrobeo_str,
ungetc_str,
ferror_str,
rewind_str,
fwrite_str,
fwriteb_str,
fwriteh_str,
fwriteo_str,
readmemh_str,
swriteb_str,
swriteh_str,
sdf_annotate_str,
sscanf_str,
ftell_str,
printtimescale_str,
timeformat_str,
finish_str,
stop_str,
async_and_array_str,
async_nand_array_str,
async_or_array_str,
async_nor_array_str,
sync_and_array_str,
sync_nand_array_str,
sync_or_array_str,
sync_nor_array_str,
async_and_plane_str,
async_nand_plane_str,
async_or_plane_str,
async_nor_plane_str,
sync_and_plane_str,
sync_nand_plane_str,
sync_or_plane_str,
sync_nor_plane_str,
q_initialize_str,
q_remove_str,
q_exam_str,
q_add_str,
q_full_str,
stime_str,
bitstoreal_str,
itor_str,
realtobits_str,
rtoi_str,
dist_chi_square_str,
dist_exponential_str,
dist_poisson_str,
dist_uniform_str,
dist_erlang_str,
dist_normal_str,
dist_t_str,
random_str,
test_plusargs_str,
value_plusargs_str
> {};

struct keyword : key< keyword_str > {};
// struct keyword : key< TAO_PEGTL_STRING("test") > {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_KEYWORDS_HPP
