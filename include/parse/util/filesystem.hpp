#ifndef LIBPARSE_UTIL_FILESYSTEM_HPP
#define LIBPARSE_UTIL_FILESYSTEM_HPP

using namespace Parse {

#ifdef __cpp_lib_filesystem
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

} // namespace Parse

#endif // LIBPARSE_UTIL_FILESYSTEM_HPP
