#ifndef LIBPARSE_UTIL_FILESYSTEM_HPP
#define LIBPARSE_UTIL_FILESYSTEM_HPP

#ifdef __cpp_lib_filesystem
#include <filesystem>
#else
#include <experimental/filesystem>
#endif

namespace Parse::Util {

#ifdef __cpp_lib_filesystem
namespace fs = std::filesystem;
#else
namespace fs = std::experimental::filesystem;
#endif

} // namespace Parse

#endif // LIBPARSE_UTIL_FILESYSTEM_HPP
