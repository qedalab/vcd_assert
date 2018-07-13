#ifndef LIBSDF_ACTIONS_TIMING_HPP
#define LIBSDF_ACTIONS_TIMING_HPP

#include <sdf/actions/base.hpp>

#include <sdf/grammar/timing.hpp>
#include <sdf/types/timing.hpp>

#include <vector>

namespace SDF{
namespace Actions{

using namespace Parse;  

struct BusIndexAction : single_dispatch<
    Grammar::integer, apply<Apply::integer>
>{
  using state = size_t;
};

struct BusRangeAction : single_dispatch<
    Grammar::integer, inner_action<BusIndexAction, Storage::push_back>
>{
  using state = std::vector<size_t>;
};

struct BusRangeStorage  {
  static bool store(Node &n, std::vector<size_t> arr) {
    n.end = arr[0];
    n.start = arr[1];
    return true;
  }
};

/*CCM Assumption 001*/
// struct BasenameStorage { 
//   static bool store(Node &node, HierarchicalIdentifier hi) {
//     node.basename_identifier = std::move(hi.value.back()); 
//     hi.value.pop_back();

//     //without check, hi is initialized as empty string.
//     if(hi.value.size() > 1){
//       node.hierarchical_identifier = std::move(hi);
//     }
//     return true;
//   }
// };

struct NodeAction : multi_dispatch<
    Grammar::identifier, inner_action<
      // IdentifierAction, BasenameStorage /*CCM Assumption 001*/
      IdentifierAction, Storage::member<&Node::basename_identifier> /*CCM Assumption 001*/
    >,
    Grammar::bus_index, inner_action<
      BusIndexAction, Storage::member<&Node::start>
    >,
    Grammar::bus_range, inner_action<
      BusRangeAction, BusRangeStorage
    >
>{
  using state = Node;
};

// //appends the HIERID from port with HIERID from port_instance (minus basename)
// struct PortInstanceHIDStorage {
//   static bool store(Node &node, HierarchicalIdentifier hi) {
//     node.hierarchical_identifier.value.push_back(std::move(s));
//     return true;
//   }
// };

struct PortStorage {
  static bool store(Node &parent, Node child) {
    /*CCM Assumption 001*/  
    // auto phi = &parent.hierarchical_identifier;
    // auto chi = child.hierarchical_identifier;

    parent = std::move(child);

    /* set node type */
    parent.type = NodeType::port;

    /*
      set node hierarchy to the 'port_spec' hierarchy 
      and the extra 'port_instance' hierarchy 
      
    */
    /*CCM Assumption 001*/  
    // if(phi->has_value() && chi.has_value()) {   
    //   auto pv = &phi->value().value;
    //   auto cv = chi.value().value;
    //   pv->insert(
    //     pv->end(),
    //     std::make_move_iterator(cv.begin()),
    //     std::make_move_iterator(cv.end())
    //   );
    // }else if (chi.has_value()){
    //   *phi = std::move(chi);
    // }
    
    return true;
  }
};
struct PortAction : multi_dispatch<
    Grammar::scalar_port, inner_action< NodeAction, PortStorage >,
    Grammar::bus_port, inner_action< NodeAction, PortStorage >
>{
  using state = Node;
};

struct PortInstanceAction : multi_dispatch<
    Grammar::port, inner_action< PortAction, PortStorage >,
    Grammar::hierarchical_identifier, inner_action<
      HierarchicalIdentifierAction, 
      Storage::member<&Node::hierarchical_identifier>
    >
>{
  using state = Node;
};

struct PortEdgeStorage {
  static bool store(Node &parent, EdgeType edge) {
    parent.edge = std::move(edge);
    return true;
  }
};

struct EdgeTypeAction : multi_dispatch<
    Grammar::edge_identifier_01, apply0<Apply::value<EdgeType::posedge>>,
    Grammar::edge_identifier_10, apply0<Apply::value<EdgeType::negedge>>,
    // Grammar::edge_identifier_0z, apply0<Apply::value<EdgeType::posedge>>,
    // Grammar::edge_identifier_z1, apply0<Apply::value<EdgeType::posedge>>,
    // Grammar::edge_identifier_1z, apply0<Apply::value<EdgeType::negedge>>,
    // Grammar::edge_identifier_z0, apply0<Apply::value<EdgeType::posedge>>,
    Grammar::edge_identifier_posedge, apply0<Apply::value<EdgeType::posedge>>,
    Grammar::edge_identifier_negedge, apply0<Apply::value<EdgeType::negedge>>
>{
  using state = EdgeType;
};

struct PortEdgeAction : multi_dispatch<
    Grammar::edge_identifier, inner_action<EdgeTypeAction, PortEdgeStorage>,
    Grammar::port_instance, inner_action_passthrough<PortInstanceAction>
>{
  using state = Node;
};

struct PortSpecAction : multi_dispatch<
    Grammar::port_instance, inner_action_passthrough<PortInstanceAction>,
    Grammar::port_edge, inner_action_passthrough<PortEdgeAction>
>{
  using state = Node;
};


}
}
#endif // LIBSDF_ACTIONS_TIMING_HPP
