// g++ -I/ -I../run/any/include -I ../run/hana/include/ -I /usr/local/Cellar/boost/1.68.0/include any_switch.cpp -o as -std=c++14
#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include "boost/hana.hpp" 
#include <boost/any.hpp>

namespace hana = boost::hana;
template <typename T>
auto case_ = [](auto f) {
    return hana::make_pair(hana::type_c<T>, f);
};

struct default_t;
auto default_ = case_<default_t>;


template <typename Any, typename Default>
auto process(Any&, std::type_index const&, Default& default_) {
    return default_();
}

template <typename Any, typename Default, typename Case, typename ...Rest>
auto process(Any& a, std::type_index const& t, Default& default_, Case& case_, Rest& ...rest) {
    using T = typename decltype(+hana::first(case_))::type;
    return t == typeid(T) ? hana::second(case_) (*boost::unsafe_any_cast<T>(&a)) : process(a, t, default_, rest...);
}

template <typename Any>
auto switch_(Any& a) {
    return [&a] (auto ...cases_){
        auto cases = hana::make_tuple(cases_...);
        auto default_ = hana::find_if(cases, [](auto const& c) {
            return hana::first(c) == hana::type_c<default_t>;
        });

        static_assert( default_ != hana::nothing, " \
                switch is missing a default_ case.");
        auto rest = hana::filter(cases, [](auto const& c) {
            return hana::first(c) != hana::type_c<default_t>;
        });
        return hana::unpack(rest, [&](auto& ...rest) {
            return process(a, a.type(), hana::second(*default_), rest...);
        });
    };
}



int main (){
    boost::any x ='x';

    switch_(x)(
        case_<char>([](auto i){
            std::cout<< "this is a char:"<< i <<std::endl;
        }),
        case_<int>([](auto j) {
            std::cout<< "this is a int:"<<j<<std::endl;
        }),
        default_([]() {
            std::cout<< "this is default"<<std::endl;
        })
    );
    boost::any y = 0;
    int d;
    std::cin>> d;
    y = d;
    switch_(y)(
        case_<char>([](auto i){
            std::cout<< "this is a char:"<< i <<std::endl;
        }),
        case_<int>([](auto j) {
            std::cout<< "this is a int:"<<j<<std::endl;
        }),
        default_([]() {
            std::cout<< "this is default"<<std::endl;
        })
    );
}