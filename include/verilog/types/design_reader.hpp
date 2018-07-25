#ifndef LIBVERILOG_TYPES_DESIGN_READER_HPP
#define LIBVERILOG_TYPES_DESIGN_READER_HPP

#include "enums.hpp"
#include "design.hpp"

#include <optional>
#include <memory>
#include <vector>
#include <fmt/format.h>

// #include <pegtl/input/>

namespace Verilog {


template<class InputType>
using InputHandles = std::unordered_map<std::string, InputType>; //source

// template<class InputType>
// class InputHandles{
//   // std::vector<std::filesystem::path>;
//   // std::vector<std::string> sources_;
//   std::unordered_map<std::string, InputType> inputs_; //source
// };
/// Verilog design reader class
/// This class populates and returns a populated Verilog::Design
// template<class InputType>
class DesignReader {
  std::unique_ptr<Design> design_;       /// Pointer to Verilog Design
  std::vector<std::size_t> net_stack_;   /// Stack of current nets

  // InputHandles<InputType> inputs_;
  // std::vector<tao::pegtl::file_input> files_;
  // std::unordered_map<std::string, std::size_t> file_lookup_; 

public:
  /// DesignReader constructor
  DesignReader();
  // void merge(std::unique_ptr<DesignReader> other);
  void merge(DesignReader other);

  std::size_t module(std::string module_name, std::string file_path);
  
  /// Introduces a new instance, and links it with a <NetType> defintion  
  /// \param NetType instance defintion's type
  /// \param instance identifier.
  /// \param <NetType> defintion identifier
  /// \return index instance is stored at if successful, throws otherwise.
  /// \exception Throws if definition is not found. (missing import statement)
  std::size_t instance(NetType type, std::string instance_name, std::string defintion_name);

  /// Introduce a new net
  void net(NetType type, std::string name, std::string net_definition);

  /// Introduce a new net
  void net(NetDataView net);

  /// Exits current net
  void upnet();

  /// Adds a variable to the net
  void var(VarType type, std::size_t size, std::string identifier_code,
           std::string reference);

  /// Adds a variable to the net
  /// \param VariableView view of variable to add
  void var(VariableView variable);

  // /// Set design time scale
  // /// \param number The time scale number
  // /// \param unit The time unit number
  // /// \exception Throws if and only if time scale is already set
  // void timescale(TimeScaleNumber number, TimeScaleUnit unit);

  // /// Set design time scale
  // /// \param timescale The time scale
  // /// \exception Throws if and only if time scale is already set
  // void timescale(TimeScaleView time_scale);

  // /// Set the design time scale, overwriting if already set
  // /// \param number The time scale number
  // /// \param unit The time unit number
  // void overwrite_timescale(TimeScaleNumber number, TimeScaleUnit unit) noexcept;

  // /// True if the current design contains a time scale
  // /// \returns Wether the current design contains a time scale
  // bool has_timescale() const noexcept;

  /// Releases the design file that was read in.
  /// Essentially finalizaing the data within the design file.
  /// \returns Owning pointer to the Design
  /// \exception Throws if all there is still net in the stack.
  std::unique_ptr<Design> release();
};

}

#endif // LIBVERILOG_TYPES_DESIGN_READER_HPP
