#include <iostream>
#include <memory>
#include <type_traits>

template < class T, class = void >
struct has_type_name : std::false_type {};

// my void_t in c++11
template < class... Ts >
struct make_void {
    using type = void;
};
template < class... T >
using my2_void_t = typename make_void< T... >::type;

template < class... Ts >
using my_void_t = void;

// template < class... Ts >
// using current_void_t = std::void_t<Ts...>;   // for c++ 17
template < class... Ts >
using current_void_t = my2_void_t< Ts... >;  // for c++ 11

// template < class T >
// struct has_type_name< T, std::void_t< typename T::type > > : std::true_type {};
template < class T >
struct has_type_name< T, current_void_t< decltype(T::type) > > : std::true_type {};

class A {
public:
    //    typedef int type;
    int type;
};

class B {};

template < class T, class = void >
struct is_smart_pointer : std::false_type {};
template < class T >
struct is_smart_pointer< T, current_void_t< decltype(std::declval< T >().operator->()), decltype(std::declval< T >().get()) > > : std::true_type {};

int main() {
    std::cout << has_type_name< A >::value << std::endl;
    std::cout << has_type_name< B >::value << std::endl;

    std::unique_ptr< int > a1;
    std::cout << is_smart_pointer< decltype(a1) >::value << std::endl;
    return 0;
}
