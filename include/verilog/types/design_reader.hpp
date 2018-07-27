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
  
  /// Introduces a new instance, and links it with a <NetType> definition  
  /// \param NetType instance definition's type
  /// \param instance_name instance identifier.
  /// \param definition_name <NetType> definition identifier
  /// \return index instance is stored at if successful, throws otherwise.
  /// \exception Throws if definition is not found. (missing import statement)
  std::size_t instance(NetType type, std::string instance_name, std::string definition_name);

  /// Add a command to be applied at a specific definition scope
  /// \param command command to add
  /// \param definition identifier
  std::size_t command(Command command, std::string definition_name);

  /// Releases the design file that was read in.
  /// Essentially finalizing the data within the design file.
  /// \returns Owning pointer to the Design
  /// \exception Throws if all there is still net in the stack.
  std::unique_ptr<Design> release();
};

}

#endif // LIBVERILOG_TYPES_DESIGN_READER_HPP
