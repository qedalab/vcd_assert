#ifndef LIBSDF_TYPES_VARIANT_H_
#define LIBSDF_TYPES_VARIANT_H_

// #include <type_traits>

namespace SDF {
namespace Types {
namespace Extra {

// template <typename T, typename... Args>
// struct is_one_of : std::disjunction<std::is_same<std::decay_t<T>, Args>...> {};

// template <typename... Args>
// struct visit_only_for {
//   // delete templated call operator
//   template <typename T>
//   std::enable_if_t<!is_one_of<T, Args...>{}> operator()(T &&) const = delete;
// };

// template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
// template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;


// std::visit([](auto&& arg) {
//     static_assert(is_one_of<decltype(arg), 
//                             int, long, double, std::string>{}, "Non matching type.");

//     using T = std::decay_t<decltype(arg)>;

//     if constexpr (std::is_same_v<T, int>){
//       std::cout << "int with value " << arg << '\n';
//     }
//     else if constexpr (std::is_same_v<T, double>){
//       std::cout << "double with value " << arg << '\n';
//     }
//     else{
//       std::cout << "default with value " << arg << '\n';
//     } 
//   }, v);

// std::variant<int, long, double, std::string> v = "asdf";



} // namespace Extra
} // namespace Types
} // namespace SDF

#endif //LIBSDF_TYPES_VARIANT_H_