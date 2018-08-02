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

// struct BusRangeAction : multi_dispatch<
//     Grammar::integer, inner_action<BusIndexAction, Storage::push_back>
// >{
//   using state = std::vector<size_t>;
// };

struct BusRangeAction : multi_dispatch<
    Grammar::bus_start_index, inner_action<
      BusIndexAction, 
      Storage::member<&Node::start>
    >,
    Grammar::bus_end_index, inner_action<
      BusIndexAction, 
      Storage::member<&Node::end>
    >
>{
  using state = Node;
};

struct BusRangeStorage  {
  static bool store(Node &parent, Node child) {
    parent.start = std::move(child.start);
    parent.end = std::move(child.end);
    return true;
  }
  // static bool store(Node &n, std::vector<size_t> arr) {
  //   n.start = arr[0];
  //   n.end = arr[1];
  //   return true;
  // }
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
    // Grammar::bus_range, inner_action<
    //   BusRangeAction, BusRangeStorage
    // >
>{
  using state = Node;
};

struct PortNodeStorage {
  static bool store(Node &parent, Node child) {
    parent.basename_identifier = std::move(child.basename_identifier);
    if(child.start.has_value()){
      parent.start = std::move(child.start);
    }
    if(child.end.has_value()){
      parent.end = std::move(child.end);
    }

    /* set node type */
    parent.type = NodeType::port;
    

    /*
      set node hierarchy to the 'port_spec' hierarchy 
      and the extra 'port_instance' hierarchy   
    */
    /*CCM Assumption 001*/  
    // auto phi = &parent.hierarchical_identifier;
    // auto chi = child.hierarchical_identifier;
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
    Grammar::scalar_port, inner_action< NodeAction, PortNodeStorage >,
    Grammar::bus_port, inner_action< NodeAction, PortNodeStorage >
>{
  using state = Node;
};

struct PortStorage {
  //Taking care not to overwrite the HierarchicalIdentifier
  static bool store(Node &parent, Node child) {
    parent.type = std::move(child.type);

    if(!parent.edge.has_value()){
      parent.edge = std::move(child.edge);
    }
    
    parent.basename_identifier = std::move(child.basename_identifier);
    
    if(parent.hierarchical_identifier.has_value()){
      if(child.hierarchical_identifier.has_value()){
        auto p_hi = parent.hierarchical_identifier.value();
        auto c_hi = child.hierarchical_identifier.value();
        for(auto && cv : c_hi.value){
          p_hi.value.emplace_back(std::move(cv));
        }
      }
    }else{
      parent.hierarchical_identifier = std::move(child.hierarchical_identifier);
    }


    if(child.start.has_value())
      parent.start = std::move(child.start);
    if(child.end.has_value())
      parent.end = std::move(child.end);
    return true;
  }
};

struct PortInstanceAction : multi_dispatch<
    Grammar::port, inner_action<PortAction,PortStorage>,
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

// struct EdgeTypeAction : multi_dispatch<
//     Grammar::edge_identifier_01, apply0<Apply::rule_value<>>,//value<EdgeType::_01>>,
//     Grammar::edge_identifier_10, apply0<Apply::rule_value<>>,//value<EdgeType::_10>>,
//     Grammar::edge_identifier_0z, apply0<Apply::rule_value<>>,//value<EdgeType::_0z>>,
//     Grammar::edge_identifier_z1, apply0<Apply::rule_value<>>,//value<EdgeType::_z1>>,
//     Grammar::edge_identifier_1z, apply0<Apply::rule_value<>>,//value<EdgeType::_1z>>,
//     Grammar::edge_identifier_z0, apply0<Apply::rule_value<>>,//value<EdgeType::_z0>>,
//     Grammar::edge_identifier_posedge, apply0<Apply::rule_value<>>,//value<EdgeType::posedge>>,
//     Grammar::edge_identifier_negedge, apply0<Apply::rule_value<>>,//value<EdgeType::negedge>>
// >{
//   using state = EdgeType;
// };
struct EdgeTypeAction : all_dispatch<apply0<Apply::rule_value>> {
  using state = EdgeType;
};

struct PortEdgeAction : multi_dispatch<
    Grammar::edge_identifier, inner_action<EdgeTypeAction, PortEdgeStorage>,
    Grammar::port_instance, inner_action<PortInstanceAction, PortStorage>
>{
  using state = Node;
};

struct PortSpecAction : multi_dispatch<
    Grammar::port_edge, inner_action_passthrough<PortEdgeAction>,
    Grammar::port_instance, inner_action_passthrough<PortInstanceAction>
>{
  using state = Node;
};

struct NetStorage {
  static bool store(Node &parent, Node child) {
    parent = std::move(child);
    parent.type = NodeType::net;
    return true;
  }
};

struct NetAction : multi_dispatch<
    Grammar::scalar_net, inner_action< NodeAction, NetStorage>,
    Grammar::bus_net, inner_action< NodeAction, NetStorage>
>{
  using state = Node;
};

struct NodeStorage {
  static bool store(Node &parent, Node child) {
    parent = std::move(child);
    parent.type = NodeType::unspecified;
    return true;
  }
};
struct ScalarNodeAction :  multi_dispatch<
    Grammar::scalar_port, inner_action<PortAction, NodeStorage>,
    Grammar::scalar_net, inner_action<NetAction, NodeStorage>
>{
  using state = Node;
};

}
}
#endif // LIBSDF_ACTIONS_TIMING_HPP
