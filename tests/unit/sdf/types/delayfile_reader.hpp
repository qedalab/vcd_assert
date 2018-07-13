#ifndef TEST_SDF_TYPES_DELAYFILE_READER_HPP
#define TEST_SDF_TYPES_DELAYFILE_READER_HPP

#include <sdf/types/delayfile.hpp>
#include <sdf/types/delayfile_reader.hpp>

#include "./delayfile.hpp"
#include "./cell.hpp"

#include <catch2/catch.hpp>

// using namespace SDF;

namespace SDF::Test{
void read_in_test_delayfile_w_reader(SDF::DelayFileReader &reader, SDF::DelayFileView &test);
}



#endif // TEST_SDF_TYPES_DELAYFILE_READER_HPP
