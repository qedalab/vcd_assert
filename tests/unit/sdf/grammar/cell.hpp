#ifndef LIBSDF_TEST_SDF_CELL_H
#define LIBSDF_TEST_SDF_CELL_H

#include "base.hpp"
#include <sdf/grammar/cell.hpp>

namespace Test {
namespace SDF {
namespace Grammar {

using namespace Parse::Test;
using namespace SDF::Grammar;

constexpr auto sdf_cell_ex1_str =
R"((CELL 
  (CELLTYPE "CDS_GEN_FD_P_SD_RB_SB_NO")
  (INSTANCE top.ff1)
)
)";

constexpr auto sdf_cell_ex2_str =
R"((CELL 
    (CELLTYPE "DFF")
    (INSTANCE *)
    (TIMINGCHECK 
        (HOLD D (COND D_ENABLE (posedge CP)) (1:1:1))
        (HOLD E (posedge CP) (1:1:1))
        (HOLD F (COND ~F_ENABLE (negedge CP)) (1:1:1))
    )
  )
)";

}
}
}

#endif //LIBSDF_TEST_SDF_CELL_H