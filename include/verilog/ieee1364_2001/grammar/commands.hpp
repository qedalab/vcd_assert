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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_COMMANDS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_COMMANDS_HPP

#include "./base.hpp"
#include "./grammar_hacked.hpp"
#include "./keywords.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

struct name_of_instance;

struct sdf_file : if_must< one<'"'>, file_path_spec, one<'"'>>{};
struct config_file : if_must< one<'"'>, file_path_spec, one<'"'>>{};
struct log_file : if_must< one<'"'>, file_path_spec, one<'"'>>{};
struct mtm_spec : alias<qstring>{};
struct scale_factors : alias<qstring>{};
struct scale_type : alias<qstring>{};

struct sdf_annotate_task : if_must<
  seq<
    one<'$'>, 
    sdf_annotate_keyword
  >,
  opt<separator>,
  if_must<
    one<'('>, 
    opt<separator>,
    sdf_file,
    opt< 
      opt<separator>,
      one<','>,
      opt< opt<separator>, name_of_instance >
      , 
      opt< 
        opt<separator>,
        one<','>, 
        opt< opt<separator>, config_file >,
        opt< 
          opt<separator>,
          one<','>, 
          opt< opt<separator>, log_file >,
          opt< 
            opt<separator>,
            one<','>, 
            opt< opt<separator>, mtm_spec >,
            opt< 
            opt<separator>,
              one<','>, 
              opt< opt<separator>, scale_factors >,
              opt< 
                one<','>, 
                opt< opt<separator>, scale_type >
              > 
            > 
          > 
        > 
      >
    >, 
    opt<separator>,
    one<')'>
  >,
  opt<separator>,
  one<';'> 
> {};

}
}
}

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_COMMANDS_HPP
