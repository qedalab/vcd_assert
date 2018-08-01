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

#ifndef LIBSDF_ACTIONS_CELL_HPP
#define LIBSDF_ACTIONS_CELL_HPP

#include <sdf/actions/base.hpp>

#include <sdf/actions/timing_spec.hpp>

#include <sdf/types/cell.hpp>
#include <sdf/grammar/cell.hpp>

namespace SDF{
namespace Actions{

using namespace Parse;  


/*always returns star if got to this point*/
struct StarStorage {
  static bool store(Star & /*unused*/, bool found) {
    if(found){
      return true;
    }else{
      return false;
    }
  }
};


struct StarAction : single_dispatch<
  Grammar::one<'*'>, apply0<Apply::value<true>>
> {
  using state = bool;
};

struct StarCellInstanceAction : single_dispatch<
  Grammar::one<'*'>, inner_action<StarAction, StarStorage>
> {
  using state = Star;
};


struct CellInstanceAction : multi_dispatch<
  Grammar::one<'*'>, inner_action_passthrough< StarCellInstanceAction >,
  Grammar::hierarchical_identifier, inner_action_passthrough< HierarchicalIdentifierAction >
> {
  using state = CellInstance;
};


struct CellAction : multi_dispatch<
  Grammar::cell_type, inner_action<
    QStringAction,
    Storage::member<&Cell::cell_type>
  >,
  Grammar::cell_instance, inner_action<
    CellInstanceAction,
    Storage::member<&Cell::cell_instance>
  >,
  Grammar::timing_spec, inner_action<
    TimingSpecArrayAction,
    Storage::member<&Cell::timing_specs>
  >
> {
  using state = Cell;
};


struct CellArrayAction : single_dispatch<
  Grammar::cell, inner_action<
    CellAction,
    Storage::push_back
  >
> {
  using state = std::vector<Cell>;
};


}
}

#endif // LIBSDF_ACTIONS_CELL_HPP
