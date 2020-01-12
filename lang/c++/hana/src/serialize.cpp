// g++ -I/ -I../run/any/include -I ../run/hana/include/ -I /usr/local/Cellar/boost/1.68.0/include serailize.cpp -o se -std=c++14
#include <iostream>
#include "boost/hana.hpp" 
#include <boost/any.hpp>

namespace hana = boost::hana;

struct Person {
    BOOST_HANA_DEFINE_STRUCT(Person,
        (std::string, name),
        (int, age)
    );
};

int main (){
    auto serialize = [](std::ostream& os, auto const& object) {
        hana::for_each(hana::members(object), [&](auto member){
            os << member << std::endl;
        });
    };
    Person thief{"thief", 22};
    serialize(std::cout, thief);
}