#ifndef LIBSDF_TEST_SDF_CELL_H
#define LIBSDF_TEST_SDF_CELL_H

#include "./base.hpp"
#include <sdf/grammar/cell.h>

namespace Test {
namespace SDF {
namespace Grammar {

using namespace Parse::Test;
using namespace SDF::Grammar;

// constexpr auto empty_cell_str    = R"((CELL  ))"; 
// constexpr auto minimal_cell_str  = R"((CELLTYPE "String" ))"; 
// constexpr auto cell_type_str     = R"((INSTANCE (CELL) ))"; 
// constexpr auto cell_instance_str = R"((CELL (CELL) ))"; 

//   (CELL
//         (CELLTYPE "system")
//         (INSTANCE )
//         (DELAY
//             (ABSOLUTE
//                 (INTERCONNECT P1/z     P1/z B1/C1/i     (.145::.145) (.125::.125))
//                 (INTERCONNECT P1/z     P1/z B1/C2/i2    (.135::.135) (.130::.130))
//                 (INTERCONNECT B1/C1/z  B1/C1/z B1/C2/i1 (.095::.095) (.095::.095))
//                 (INTERCONNECT B1/C2/z  B1/C2/z B2/C1/i  (.145::.145) (.125::.125))
//                 (INTERCONNECT B2/C1/z  B2/C1/z B2/C2/i1 (.075::.075) (.075::.075))
//                 (INTERCONNECT B2/C2/z  B2/C2/z P2/i     (.055::.055) (.075::.075))
//                 (INTERCONNECT B2/C2/z  B2/C2/z D1/i     (.255::.255) (.275::.275))
//                 (INTERCONNECT D1/z     D1/z B2/C2/i2    (.155::.155) (.175::.175))
//                 (INTERCONNECT D1/z     D1/z P3/i        (.155::.155) (.130::.130))
//             )
//         )
//     )

// decltype(auto) constexpr sdf_header_str_ex_arr = 
//   std::array{
// R"(((SDFVERSION "4.0")
//     (DESIGN "system")
//   };


}
}
}

#endif //LIBSDF_TEST_SDF_CELL_H