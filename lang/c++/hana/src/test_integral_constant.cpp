#include <iostream>
#include <type_traits>

template <class T, T v>
struct integral_constant {
    static constexpr T value = v;
    typedef T value_type;
    typedef integral_constant type;
    constexpr operator value_type() const noexcept { return value;}
    constexpr value_type operator()() const noexcept { return value;}
};

template <typename N>
using succ = integral_constant<int, N::value  + 1>;
using one = integral_constant<int, 1>;
using two = succ<one>;
using three = succ<two>;

// get object which has value type attribute
template <typename N>
auto succ2(N) {
    return integral_constant<int, N::value + 1>{};
}

// using type entity for plus
template <typename X, typename Y>
struct plus {
    using type = integral_constant< decltype(X::value + Y::value), X::value + Y::value>;
};

// using value objecft for plus
template <typename V, V v, typename U, U u>
constexpr auto operator+(integral_constant<V,v>, integral_constant<U,u>) {
    return integral_constant<decltype(v + u), v+u>{};
}
template <int i>
constexpr integral_constant<int, i> int_c{};

int main (){
    // using type entity
    typedef std::integral_constant<int, 2> two_t;
    typedef std::integral_constant<int, 4> four_t;

    static_assert(two_t::value * 2 == four_t::value, "2 * 2 != 4");
    std::cout<< "two_t::value  : "<<two_t()<<std::endl;
    std::cout<< "four_t::value  : "<<four_t()<<std::endl;

    // using object which has value attribute
    auto one = integral_constant<int, 1>{};
    constexpr int one_constexpr = decltype(one)::value;
    std::cout<< "one const: "<<one_constexpr<<std::endl;
    auto two = succ2(one);
    std::cout<< "two value:"<<two::value<<std::endl;
    auto three = succ2(two);
    std::cout<< "three value:"<<three::value<<std::endl;

// plus implementation
    // type computation
    using three_v1 = plus<integral_constant<int, 1>, integral_constant<int, 2>>::type;
    std::cout<<"three v1 value:"<<three_v1::value<<std::endl;
    
    // value object
    auto three_v2 = integral_constant<int, 1>{} + integral_constant<int, 2>{};
    std::cout<<"three v2 value:"<<decltype(three_v2)::value<<std::endl;

    
    
}