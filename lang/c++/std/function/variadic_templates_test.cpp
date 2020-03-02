#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template < class... T >
void f(T... args) {
    std::cout << sizeof...(args) << std::endl;
}

template < typename T >
void print(T t) {
    std::cout << t << std::endl;
}

template < typename F, typename... T >
void print(F f, T... args) {
    std::cout << f << std::endl;
    print(args...);
}

int main() {
    f();
    f(1);
    f(1, 2, 3);

    print(1, 2, 3);
    print(4, 5);
    return 0;
}
