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

// struct module_str : sor<
//    TAO_PEGTL_STRING("module"),
//    TAO_PEGTL_STRING("macromodule")
// > {}; 

// misc

struct always_str  : TAO_PEGTL_STRING("always"){};
struct and_str  : TAO_PEGTL_STRING("and"){};
struct assign_str  : TAO_PEGTL_STRING("assign"){};
struct automatic_str  : TAO_PEGTL_STRING("automatic"){};
struct begin_str  : TAO_PEGTL_STRING("begin"){};
struct buf_str  : TAO_PEGTL_STRING("buf"){};
struct bufif0_str  : TAO_PEGTL_STRING("bufif0"){};
struct bufif1_str  : TAO_PEGTL_STRING("bufif1"){};
struct case_str  : TAO_PEGTL_STRING("case"){};
struct casex_str  : TAO_PEGTL_STRING("casex"){};
struct casez_str  : TAO_PEGTL_STRING("casez"){};
struct cell_str  : TAO_PEGTL_STRING("cell"){};
struct cmos_str  : TAO_PEGTL_STRING("cmos"){};
struct config_str  : TAO_PEGTL_STRING("config"){};
struct deassign_str  : TAO_PEGTL_STRING("deassign"){};
struct default_str  : TAO_PEGTL_STRING("default"){};
struct defparam_str  : TAO_PEGTL_STRING("defparam"){};
struct design_str  : TAO_PEGTL_STRING("design"){};
struct disable_str  : TAO_PEGTL_STRING("disable"){};
struct edge_str  : TAO_PEGTL_STRING("edge"){};
struct else_str  : TAO_PEGTL_STRING("else"){};
struct end_str  : TAO_PEGTL_STRING("end"){};
struct endcase_str  : TAO_PEGTL_STRING("endcase"){};
struct endconfig_str  : TAO_PEGTL_STRING("endconfig"){};
struct endfunction_str  : TAO_PEGTL_STRING("endfunction"){};
struct endgenerate_str  : TAO_PEGTL_STRING("endgenerate"){};
struct endmodule_str  : TAO_PEGTL_STRING("endmodule"){};
struct endprimitive_str  : TAO_PEGTL_STRING("endprimitive"){};
struct endspecify_str  : TAO_PEGTL_STRING("endspecify"){};
struct endtable_str  : TAO_PEGTL_STRING("endtable"){};
struct endtask_str  : TAO_PEGTL_STRING("endtask"){};
struct event_str  : TAO_PEGTL_STRING("event"){};
struct for_str  : TAO_PEGTL_STRING("for"){};
struct force_str  : TAO_PEGTL_STRING("force"){};
struct forever_str  : TAO_PEGTL_STRING("forever"){};
struct fork_str  : TAO_PEGTL_STRING("fork"){};
struct function_str  : TAO_PEGTL_STRING("function"){};
struct generate_str  : TAO_PEGTL_STRING("generate"){};
struct genvar_str  : TAO_PEGTL_STRING("genvar"){};
struct highz0_str  : TAO_PEGTL_STRING("highz0"){};
struct highz1_str  : TAO_PEGTL_STRING("highz1"){};
struct if_str  : TAO_PEGTL_STRING("if"){};
struct ifnone_str  : TAO_PEGTL_STRING("ifnone"){};
struct incdir_str  : TAO_PEGTL_STRING("incdir"){};
struct include_str  : TAO_PEGTL_STRING("include"){};
struct initial_str  : TAO_PEGTL_STRING("initial"){};
struct inout_str  : TAO_PEGTL_STRING("inout"){};
struct input_str  : TAO_PEGTL_STRING("input"){};
struct instance_str  : TAO_PEGTL_STRING("instance"){};
struct integer_str  : TAO_PEGTL_STRING("integer"){};
struct join_str  : TAO_PEGTL_STRING("join"){};
struct large_str  : TAO_PEGTL_STRING("large"){};
struct liblist_str  : TAO_PEGTL_STRING("liblist"){};
struct library_str  : TAO_PEGTL_STRING("library"){};
struct localparam_str  : TAO_PEGTL_STRING("localparam"){};
struct macromodule_str  : TAO_PEGTL_STRING("macromodule"){};
struct medium_str  : TAO_PEGTL_STRING("medium"){};
struct module_str  : TAO_PEGTL_STRING("module"){};
struct nand_str  : TAO_PEGTL_STRING("nand"){};
struct negedge_str  : TAO_PEGTL_STRING("negedge"){};
struct nmos_str  : TAO_PEGTL_STRING("nmos"){};
struct nor_str  : TAO_PEGTL_STRING("nor"){};
struct noshowcancelled_str  : TAO_PEGTL_STRING("noshowcancelled"){};
struct not_str  : TAO_PEGTL_STRING("not"){};
struct notif0_str  : TAO_PEGTL_STRING("notif0"){};
struct notif1_str  : TAO_PEGTL_STRING("notif1"){};
struct or_str  : TAO_PEGTL_STRING("or"){};
struct output_str  : TAO_PEGTL_STRING("output"){};
struct parameter_str  : TAO_PEGTL_STRING("parameter"){};
struct pmos_str  : TAO_PEGTL_STRING("pmos"){};
struct posedge_str  : TAO_PEGTL_STRING("posedge"){};
struct primitive_str  : TAO_PEGTL_STRING("primitive"){};
struct pull0_str  : TAO_PEGTL_STRING("pull0"){};
struct pull1_str  : TAO_PEGTL_STRING("pull1"){};
struct pulldown_str  : TAO_PEGTL_STRING("pulldown"){};
struct pullup_str  : TAO_PEGTL_STRING("pullup"){};
struct pulsestyle_onevent_str  : TAO_PEGTL_STRING("pulsestyle_onevent"){};
struct pulsestyle_ondetect_str  : TAO_PEGTL_STRING("pulsestyle_ondetect"){};
struct rcmos_str  : TAO_PEGTL_STRING("rcmos"){};
struct real_str  : TAO_PEGTL_STRING("real"){};
struct realtime_str  : TAO_PEGTL_STRING("realtime"){};
struct reg_str  : TAO_PEGTL_STRING("reg"){};
struct release_str  : TAO_PEGTL_STRING("release"){};
struct repeat_str  : TAO_PEGTL_STRING("repeat"){};
struct rnmos_str  : TAO_PEGTL_STRING("rnmos"){};
struct rpmos_str  : TAO_PEGTL_STRING("rpmos"){};
struct rtran_str  : TAO_PEGTL_STRING("rtran"){};
struct rtranif0_str  : TAO_PEGTL_STRING("rtranif0"){};
struct rtranif1_str  : TAO_PEGTL_STRING("rtranif1"){};
struct scalared_str  : TAO_PEGTL_STRING("scalared"){};
struct showcancelled_str  : TAO_PEGTL_STRING("showcancelled"){};
struct signed_str  : TAO_PEGTL_STRING("signed"){};
struct small_str  : TAO_PEGTL_STRING("small"){};
struct specify_str  : TAO_PEGTL_STRING("specify"){};
struct specparam_str  : TAO_PEGTL_STRING("specparam"){};
struct strong0_str  : TAO_PEGTL_STRING("strong0"){};
struct strong1_str  : TAO_PEGTL_STRING("strong1"){};
struct supply0_str  : TAO_PEGTL_STRING("supply0"){};
struct supply1_str  : TAO_PEGTL_STRING("supply1"){};
struct table_str  : TAO_PEGTL_STRING("table"){};
struct task_str  : TAO_PEGTL_STRING("task"){};
struct time_str  : TAO_PEGTL_STRING("time"){};
struct tran_str  : TAO_PEGTL_STRING("tran"){};
struct tranif0_str  : TAO_PEGTL_STRING("tranif0"){};
struct tranif1_str  : TAO_PEGTL_STRING("tranif1"){};
struct tri_str  : TAO_PEGTL_STRING("tri"){};
struct tri0_str  : TAO_PEGTL_STRING("tri0"){};
struct tri1_str  : TAO_PEGTL_STRING("tri1"){};
struct triand_str  : TAO_PEGTL_STRING("triand"){};
struct trior_str  : TAO_PEGTL_STRING("trior"){};
struct trireg_str  : TAO_PEGTL_STRING("trireg"){};
struct unsigned_str  : TAO_PEGTL_STRING("unsigned"){};
struct use_str  : TAO_PEGTL_STRING("use"){};
struct vectored_str  : TAO_PEGTL_STRING("vectored"){};
struct wait_str  : TAO_PEGTL_STRING("wait"){};
struct wand_str  : TAO_PEGTL_STRING("wand"){};
struct weak0_str  : TAO_PEGTL_STRING("weak0"){};
struct weak1_str  : TAO_PEGTL_STRING("weak1"){};
struct while_str  : TAO_PEGTL_STRING("while"){};
struct wire_str  : TAO_PEGTL_STRING("wire"){};
struct wor_str  : TAO_PEGTL_STRING("wor"){};
struct xnor_str  : TAO_PEGTL_STRING("xnor"){};
struct xor_str  : TAO_PEGTL_STRING("xor"){};



struct module_str         : TAO_PEGTL_STRING("module"){};
struct endmodule_str      : TAO_PEGTL_STRING("endmodule"){};
struct primitive_str      : TAO_PEGTL_STRING("primitive"){};
struct endprimitive_str   : TAO_PEGTL_STRING("endprimitive"){};
struct generate_str       : TAO_PEGTL_STRING("generate"){};
struct endgenerate_str    : TAO_PEGTL_STRING("endgenerate"){};

struct inout_str          : TAO_PEGTL_STRING("inout"){};
struct input_str          : TAO_PEGTL_STRING("input"){};
struct integer_str        : TAO_PEGTL_STRING("integer"){};
struct include_str        : TAO_PEGTL_STRING("include"){};
struct output_str         : TAO_PEGTL_STRING("output"){};

struct defparam_str     : TAO_PEGTL_STRING("defparam"){};
struct localparam_str     : TAO_PEGTL_STRING("localparam"){};
struct parameter_str      : TAO_PEGTL_STRING("parameter"){};
struct specparam_str      : TAO_PEGTL_STRING("specparam"){};

struct real_str           : TAO_PEGTL_STRING("real"){};

struct realtime_str       : TAO_PEGTL_STRING("realtime"){};
struct reg_str            : TAO_PEGTL_STRING("reg"){};
struct trireg_str         : TAO_PEGTL_STRING("trireg"){};

struct signed_str         : TAO_PEGTL_STRING("signed"){};
struct time_str           : TAO_PEGTL_STRING("time"){};

struct begin_str          : TAO_PEGTL_STRING("begin"){};
struct end_str            : TAO_PEGTL_STRING("end"){};
struct fork_str           : TAO_PEGTL_STRING("fork"){};
struct join_str           : TAO_PEGTL_STRING("join"){};
struct assign_str         : TAO_PEGTL_STRING("assign"){};
struct deassign_str       : TAO_PEGTL_STRING("deassign"){};
struct force_str          : TAO_PEGTL_STRING("force"){};
struct release_str        : TAO_PEGTL_STRING("release"){};
struct wait_str           : TAO_PEGTL_STRING("wait"){};
struct while_str          : TAO_PEGTL_STRING("while"){};
struct for_str            : TAO_PEGTL_STRING("for"){};
struct forever_str        : TAO_PEGTL_STRING("forever"){};
struct if_str             : TAO_PEGTL_STRING("if"){};
struct else_str           : TAO_PEGTL_STRING("else"){};
struct disable_str        : TAO_PEGTL_STRING("disable"){};
struct initial_str        : TAO_PEGTL_STRING("initial"){};
struct automatic_str      : TAO_PEGTL_STRING("automatic"){};
struct always_str         : TAO_PEGTL_STRING("always"){};
struct specify_str        : TAO_PEGTL_STRING("specify"){};
struct endspecify_str     : TAO_PEGTL_STRING("endspecify"){};

struct posedge_str        : TAO_PEGTL_STRING("posedge"){};
struct negedge_str        : TAO_PEGTL_STRING("negedge"){};


struct repeat_str         : TAO_PEGTL_STRING("repeat"){};
struct case_str           : TAO_PEGTL_STRING("case"){};
struct casez_str          : TAO_PEGTL_STRING("casez"){};
struct casex_str          : TAO_PEGTL_STRING("casex"){};
struct endcase_str        : TAO_PEGTL_STRING("endcase"){};
struct default_str        : TAO_PEGTL_STRING("default"){};

struct net_str            : TAO_PEGTL_STRING("net"){};
struct event_str          : TAO_PEGTL_STRING("event"){};
struct genvar_str         : TAO_PEGTL_STRING("genvar"){};
struct task_str           : TAO_PEGTL_STRING("task"){};
struct endtask_str        : TAO_PEGTL_STRING("endtask"){};
struct function_str       : TAO_PEGTL_STRING("function"){};
struct endfunction_str    : TAO_PEGTL_STRING("endfunction"){};

struct small_str          : TAO_PEGTL_STRING("small"){}; 
struct medium_str         : TAO_PEGTL_STRING("medium"){}; 
struct large_str          : TAO_PEGTL_STRING("large"){}; 

struct vectored_str       : TAO_PEGTL_STRING("vectored"){}; 
struct scalared_str       : TAO_PEGTL_STRING("scalared"){}; 

struct sdf_annotate_str   : TAO_PEGTL_STRING("sdf_annotate"){}; 

struct cmos_str           : TAO_PEGTL_STRING("cmos"){}          
struct rcmos_str          : TAO_PEGTL_STRING("rcmos"){}          
struct bufif0_str         : TAO_PEGTL_STRING("bufif0"){}            
struct bufif1_str         : TAO_PEGTL_STRING("bufif1"){}            
struct notif0_str         : TAO_PEGTL_STRING("notif0"){}            
struct notif1_str         : TAO_PEGTL_STRING("notif1"){}            
struct nmos_str           : TAO_PEGTL_STRING("nmos"){}          
struct pmos_str           : TAO_PEGTL_STRING("pmos"){}          
struct rnmos_str          : TAO_PEGTL_STRING("rnmos"){}          
struct rpmos_str          : TAO_PEGTL_STRING("rpmos"){}          
struct and_str            : TAO_PEGTL_STRING("and"){}        
struct nand_str           : TAO_PEGTL_STRING("nand"){}          
struct or_str             : TAO_PEGTL_STRING("or"){}        
struct nor_str            : TAO_PEGTL_STRING("nor"){}        
struct xor_str            : TAO_PEGTL_STRING("xor"){}        
struct xnor_str           : TAO_PEGTL_STRING("xnor"){}          
struct buf_str            : TAO_PEGTL_STRING("buf"){}        
struct not_str            : TAO_PEGTL_STRING("not"){}        
struct tranif0_str        : TAO_PEGTL_STRING("tranif0"){}            
struct tranif1_str        : TAO_PEGTL_STRING("tranif1"){}            
struct rtranif1_str       : TAO_PEGTL_STRING("rtranif1"){}              
struct rtranif0_str       : TAO_PEGTL_STRING("rtranif0"){}              
struct tran_str           : TAO_PEGTL_STRING("tran"){}          
struct rtran_str          : TAO_PEGTL_STRING("rtran"){}          

struct supply0_str        : TAO_PEGTL_STRING("supply0"){};
struct strong0_str        : TAO_PEGTL_STRING("strong0"){};
struct pull0_str          : TAO_PEGTL_STRING("pull0"){};
struct weak0_str          : TAO_PEGTL_STRING("weak0"){};
struct supply1_str        : TAO_PEGTL_STRING("supply1"){};
struct strong1_str        : TAO_PEGTL_STRING("strong1"){};
struct pull1_str          : TAO_PEGTL_STRING("pull1"){};
struct weak1_str          : TAO_PEGTL_STRING("weak1"){};
struct highz0_str         : TAO_PEGTL_STRING("highz0"){};
struct highz1_str         : TAO_PEGTL_STRING("highz1"){};

struct tri_str            : TAO_PEGTL_STRING("tri"){};
struct triand_str         : TAO_PEGTL_STRING("triand"){};
struct trior_str          : TAO_PEGTL_STRING("trior"){};
struct tri0_str           : TAO_PEGTL_STRING("tri0"){};
struct tri1_str           : TAO_PEGTL_STRING("tri1"){};
struct wire_str           : TAO_PEGTL_STRING("wire"){};
struct wand_str           : TAO_PEGTL_STRING("wand"){};
struct wor_str            : TAO_PEGTL_STRING("wor"){};

struct keyword_str: sor< 
module_str,
endmodule_str,
primitive_str,
endprimitive_str,
generate_str,
endgenerate_str,
inout_str,
input_str,
integer_str,
include_str,
output_str,
parameter_str,
specparam_str,
defparam_str,
localparam_str,
real_str,
realtime_str,
reg_str,
trireg_str,
signed_str,
time_str,
begin_str,
end_str,
fork_str,
join_str,
assign_str,
deassign_str,
force_str,
release_str,
wait_str,
while_str,
for_str,
forever_str,
if_str,
else_str,
disable_str,
initial_str,
automatic_str,
always_str,
specify_str,
endspecify_str,
posedge_str,
negedge_str,
repeat_str,
case_str,
casez_str,
casex_str,
endcase_str,
default_str,
event_str,
genvar_str,
task_str,
endtask_str,
function_str,
endfunction_str,
small_str,
medium_str,
large_str,
vectored_str,
scalared_str,
sdf_annotate_str,

cmos_str,
rcmos_str,
bufif0_str,
bufif1_str,
notif0_str,
notif1_str,
nmos_str,
pmos_str,
rnmos_str,
rpmos_str,
and_str,
nand_str,
or_str,
nor_str,
xor_str,
xnor_str,
buf_str,
not_str,
tranif0_str,
tranif1_str,
rtranif1_str,
rtranif0_str,
tran_str,
rtran_str,

supply0_str,
strong0_str,
pull0_str,
weak0_str,
supply1_str,
strong1_str,
pull1_str,
weak1_str,
highz0_str,
highz1_str,
tri_str,
triand_str,
trior_str,
tri0_str,
tri1_str,
wire_str,
wand_str,
wor_str
> {};


template< typename Key >
struct key : seq< Key, not_at< character > > {};

struct keyword : key< keyword_str > {};

struct module_keyword : key < module_str > {};
struct endmodule_keyword : key < endmodule_str > {};
struct primitive_keyword : key < primitive_str > {};
struct endprimitive_keyword : key < endprimitive_str > {};
struct generate_keyword : key < generate_str > {};
struct endgenerate_keyword : key < endgenerate_str > {};
struct inout_keyword : key < inout_str > {};
struct input_keyword : key < input_str > {};
struct integer_keyword : key < integer_str > {};
struct include_keyword : key < include_str > {};
struct output_keyword : key < output_str > {};
struct parameter_keyword : key < parameter_str > {};
struct specparam_keyword : key < specparam_str > {};
struct defparam_keyword : key < defparam_str > {};
struct localparam_keyword : key < localparam_str > {};
struct real_keyword : key < real_str > {};
struct realtime_keyword : key < realtime_str > {};
struct reg_keyword : key < reg_str > {};
struct trireg_keyword : key < trireg_str > {};
struct signed_keyword : key < signed_str > {};
struct time_keyword : key < time_str > {};
struct begin_keyword : key < begin_str > {};
struct end_keyword : key < end_str > {};
struct fork_keyword : key < fork_str > {};
struct join_keyword : key < join_str > {};
struct assign_keyword : key < assign_str > {};
struct deassign_keyword : key < deassign_str > {};
struct force_keyword : key < force_str > {};
struct release_keyword : key < release_str > {};
struct wait_keyword : key < wait_str > {};
struct while_keyword : key < while_str > {};
struct for_keyword : key < for_str > {};
struct forever_keyword : key < forever_str > {};
struct if_keyword : key < if_str > {};
struct else_keyword : key < else_str > {};
struct disable_keyword : key < disable_str > {};
struct initial_keyword : key < initial_str > {};
struct automatic_keyword : key < automatic_str > {};
struct always_keyword : key < always_str > {};
struct specify_keyword : key < specify_str > {};
struct endspecify_keyword : key < endspecify_str > {};
struct posedge_keyword : key < posedge_str > {};
struct negedge_keyword : key < negedge_str > {};
struct repeat_keyword : key < repeat_str > {};
struct case_keyword : key < case_str > {};
struct casez_keyword : key < casez_str > {};
struct casex_keyword : key < casex_str > {};
struct endcase_keyword : key < endcase_str > {};
struct default_keyword : key < default_str > {};
struct event_keyword : key < event_str > {};
struct genvar_keyword : key < genvar_str > {};
struct task_keyword : key < task_str > {};
struct endtask_keyword : key < endtask_str > {};
struct function_keyword : key < function_str > {};
struct endfunction_keyword : key < endfunction_str > {};
struct small_keyword : key < small_str > {};
struct medium_keyword : key < medium_str > {};
struct large_keyword : key < large_str > {};
struct vectored_keyword : key < vectored_str > {};
struct scalared_keyword : key < scalared_str > {};
struct sdf_annotate_keyword : key < sdf_annotate_str > {};

struct cmos_keyword : key < cmos_str > {};
struct rcmos_keyword : key < rcmos_str > {};
struct bufif0_keyword : key < bufif0_str > {};
struct bufif1_keyword : key < bufif1_str > {};
struct notif0_keyword : key < notif0_str > {};
struct notif1_keyword : key < notif1_str > {};
struct nmos_keyword : key < nmos_str > {};
struct pmos_keyword : key < pmos_str > {};
struct rnmos_keyword : key < rnmos_str > {};
struct rpmos_keyword : key < rpmos_str > {};
struct and_keyword : key < and_str > {};
struct nand_keyword : key < nand_str > {};
struct or_keyword : key < or_str > {};
struct nor_keyword : key < nor_str > {};
struct xor_keyword : key < xor_str > {};
struct xnor_keyword : key < xnor_str > {};
struct buf_keyword : key < buf_str > {};
struct not_keyword : key < not_str > {};
struct tranif0_keyword : key < tranif0_str > {};
struct tranif1_keyword : key < tranif1_str > {};
struct rtranif1_keyword : key < rtranif1_str > {};
struct rtranif0_keyword : key < rtranif0_str > {};
struct tran_keyword : key < tran_str > {};
struct rtran_keyword : key < rtran_str > {};

struct supply0_keyword : key < supply0_str > {};
struct strong0_keyword : key < strong0_str > {};
struct pull0_keyword : key < pull0_str > {};
struct weak0_keyword : key < weak0_str > {};
struct supply1_keyword : key < supply1_str > {};
struct strong1_keyword : key < strong1_str > {};
struct pull1_keyword : key < pull1_str > {};
struct weak1_keyword : key < weak1_str > {};
struct highz0_keyword : key < highz0_str > {};
struct highz1_keyword : key < highz1_str > {};
struct tri_keyword : key < tri_str > {};
struct triand_keyword : key < triand_str > {};
struct trior_keyword : key < trior_str > {};
struct tri0_keyword : key < tri0_str > {};
struct tri1_keyword : key < tri1_str > {};
struct wire_keyword : key < wire_str > {};
struct wand_keyword : key < wand_str > {};
struct wor_keyword : key < wor_str > {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_KEYWORDS_HPP
