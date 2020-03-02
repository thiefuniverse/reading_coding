#include <iostream>

template < typename T >
float getNumber() {
    return 3;
}
template < typename T >
class A;

template < typename T >
class A {
    template < typename Type >
    float getNumber() {
        return static_cast< Type >(2.5);
    }

public:
    template < typename NumType >
    A(NumType f) : a_(&A< T >::getNumber< NumType >){};
    float (A< T >::*a_)();
};

class NumGenerator {
public:
    int num_;
    NumGenerator(int num) : num_(num) {
        std::cout << "generator constructed." << std::endl;
    }
    NumGenerator(NumGenerator &another) {
        std::cout << "copy generator constructed." << std::endl;
        num_ = another.num_;
    }
    NumGenerator(NumGenerator &&another) {
        std::cout << "rvalue generator constructed." << std::endl;
        num_ = another.num_;
    }

    operator int() const {
        return num_;
    }
    int getNum() {
        return num_;
    }
    ~NumGenerator() {
        std::cout << "destruct now" << std::endl;
    }
};

void printNum(NumGenerator n) {
    std::cout << n.getNum() << std::endl;
}
template < typename... T >
void print(T &&... a) {
    printNum(std::forward< T >(a)...);
}
void printNumRF(NumGenerator n) {
    std::cout << n.getNum() << std::endl;
}

// test std::forward
void helper(int &t) {
    std::cout << "use left reference" << std::endl;
    std::cout << t << std::endl;
}
void helper(int &&t) {
    std::cout << "use right reference" << std::endl;
    std::cout << t << std::endl;
}

template < typename T >
void printLR(T &&t) {
    helper(std::forward< T >(t));
}
int main() {
    A< void > a1(9);
    A< void > a2(8.5);
    std::cout << (a2.*(a1.a_))() << std::endl;
    std::cout << (a1.*(a2.a_))() << std::endl;
    //    print(2);
    int a = 3;
    //   print(a);
    NumGenerator b(4);
    print(b);
    print(std::move(b));
    printNumRF(std::move(b));

    int r = 60;
    printLR(r);
    printLR(61);
    return 0;
}
