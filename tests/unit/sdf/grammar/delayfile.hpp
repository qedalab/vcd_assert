#ifndef LIBSDF_TEST_SDF_DELAYFILE_H
#define LIBSDF_TEST_SDF_DELAYFILE_H

#include "./base.hpp"
#include <sdf/grammar/delayfile.h>

namespace Test {
namespace SDF {
namespace Grammar {

using namespace Parse::Test;
using namespace SDF::Grammar;

constexpr auto sdf_delayfile_ex1_1_str = R"####(
(DELAYFILE
    (SDFVERSION "4.0")
    (DESIGN "system")
    (DATE "Saturday September 30 08:30:33 PST 1990")
    (VENDOR "Yosemite Semiconductor")
    (PROGRAM "delay_calc")
    (VERSION "1.5")
    (DIVIDER /)
    (VOLTAGE 5.5:5.0:4.5)
    (PROCESS "worst")
    (TEMPERATURE 55:85:125)
    (TIMESCALE 1ns)
    (CELL 
        (CELLTYPE "XOR2")
        (INSTANCE top.x1)
    )
)
)####";

constexpr auto sdf_delayfile_ex3_1_str = R"####(
(DELAYFILE
    (SDFVERSION "4.0")
    (TIMESCALE 1ns)
    (CELL 
        (CELLTYPE "XOR2")
        (INSTANCE top.x1)
        (DELAY ()())
        (DELAY ()())
        (DELAY ()())
    )
)
)####";

constexpr auto sdf_delayfile_ex3_2_str = R"####(
(DELAYFILE
    (SDFVERSION "4.0")
    (TIMESCALE 1ns)
    (CELL 
        (CELLTYPE "XOR2")
        (INSTANCE top.x1)
        (DELAY (asdf)())
    )
)
)####";

constexpr auto sdf_delayfile_ex3_3_str = R"####(
(DELAYFILE
    (SDFVERSION "4.0")
    (TIMESCALE 1ns)
    (CELL 
        (CELLTYPE "XOR2")
        (INSTANCE top.x1)
        (DELAY
            (INCREMENT
                (COND i1   )
            )
        )
    )
)
)####";

constexpr auto sdf_delayfile_ex3_4_str = R"####(
(DELAYFILE
    (SDFVERSION "4.0")
    (TIMESCALE 1ns)
    (CELL 
        (CELLTYPE "XOR2")
        (INSTANCE top.x1)
        (DELAY ("\("))
    )
)
)####";
constexpr auto sdf_delayfile_ex3_5_str = R"####(
(DELAYFILE
    (SDFVERSION "4.0")
    (TIMESCALE 1ns)
    (CELL 
        (CELLTYPE "XOR2")
        (INSTANCE top.x1)
        (DELAY ("\)"))
    )
)
)####";
constexpr auto sdf_delayfile_ex3_6_str = R"####(
(DELAYFILE
    (SDFVERSION "4.0")
    (DESIGN "Test")
    (TIMESCALE 1ns)
    (CELL 
        (CELLTYPE "XOR2")
        (INSTANCE top.x1)
        (DELAY ("\)"))
        (DELAY
            (INCREMENT
                (COND i1 (IOPATH i2 o1 (2:2:2) (2:2:2) ) )
            )
            (INCREMENT
                (COND i2 (IOPATH i1 o1 (2:2:2) (2:2:2) ) )
            )
            (INCREMENT
                (COND ~i1 (IOPATH i2 o1 (3:3:3) (3:3:3) ) )
            )
            (INCREMENT
                (COND ~i2 (IOPATH i1 o1 (3:3:3) (3:3:3) ) )
            )
        )
    )
)
)####";

} // namespace Grammar
} // namespace SDF
} // namespace Test

#endif // LIBSDF_TEST_SDF_DELAYFILE_H
