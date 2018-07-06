#ifndef TEST_SDF_TYPES_TIMING_HPP
#define TEST_SDF_TYPES_TIMING_HPP

#include <sdf/types/base.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/timing.hpp>

namespace SDF::Test {

// static const NodeType node_type_test_1{
//   "test"
// };

// static const NodeType node_type_test_2{
//   "test",
//   HierarchicalIdentifier{
//     HChar::slash,
//     {"root","design"}
//   }
// };

// static const NodeType node_type_test_3{
//   "test",
//   HierarchicalIdentifier{
//     HChar::dot,
//     {"root","design"}
//   },
//   2
// };

static const Node port_1{
  NodeType::port,
  "CP"
};

static const Node port_2{
  NodeType::port,
  "D"
};

static const Node port_3{
  NodeType::port,
  "E"
};

static const Node port_4{
  NodeType::port,
  "F"
};

static const Node node_1{ 
  NodeType::port,
  "D_ENABLE"
};

static const Node node_2{ 
  NodeType::port,
  "E_ENABLE"
};

static const Node node_3{ 
  NodeType::port,
  "F_ENABLE"
};

static const Node node_complex_1{ 
  NodeType::port,
  port_1.basename_identifier,
  HierarchicalIdentifier{
    HChar::slash,
    {"root"}
  }
};


static const Node node_complex_2{ 
  NodeType::port,
  "D_ENABLE",
  HierarchicalIdentifier{ 
    HChar::slash,
    {"root","scope"}
  }
  
};

static const Node node_complex_3{ 
  NodeType::port,
  port_3.basename_identifier,
  HierarchicalIdentifier{ 
    HChar::dot,
    {"root","scope"}
  }
};

static const Node node_complex_4{ 
  NodeType::port,
  port_4.basename_identifier,
  HierarchicalIdentifier{ 
    HChar::slash,
    {"root","scope","counter"}
  },
  4
};

// void read_in_test_timing(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_timing(SDF::DelayFile &header, SDF::Cell &scope, TestCell &test);

} // SDF::Test

#endif // TEST_SDF_TYPES_TIMING_HPP
