#ifndef LIBSDF_TEST_SDF_GRAMMAR_H
#define LIBSDF_TEST_SDF_GRAMMAR_H

#include "./base.hpp"
#include "./delayfile.hpp"
#include <sdf/grammar/grammar.h>

namespace Test {
namespace SDF {
namespace Grammar {

using namespace Parse::Test;
using namespace SDF::Grammar;

// extern char _binary_sdf_example_1_sdf_start;
// extern char _binary_sdf_example_1_sdf_end;

constexpr auto sdf_example_1_sdf_str = (
#include "../rc/sdf_example_1_sdf.raw"
);
constexpr auto sdf_example_2_sdf_str = (
#include "../rc/sdf_example_2_sdf.raw"
);
constexpr auto sdf_example_3_sdf_str = (
#include "../rc/sdf_example_3_sdf.raw"
);
constexpr auto sdf_example_4_sdf_str = (
#include "../rc/sdf_example_4_sdf.raw"
);

}
}
}

#endif //LIBSDF_TEST_SDF_GRAMMAR_H