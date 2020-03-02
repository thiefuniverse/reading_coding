#include <functional>
#include <iostream>

class NumGenerator {
public:
    int num_;
    NumGenerator(int num) : num_(num) {
        std::cout << "generator constructed." << std::endl;
    }
    NumGenerator(const NumGenerator &another) {
        std::cout << "copy generator constructed." << std::endl;
        num_ = another.num_;
    }
    // NumGenerator(NumGenerator &&another) {
    //     std::cout << "rvalue generator constructed." << std::endl;
    //     num_ = another.num_;
    // }
    int getNum() {
        return num_;
    }
    ~NumGenerator() {
        std::cout << "destruct now" << std::endl;
    }
};

struct getTwo {
    getTwo() {
        std::cout << "construct gettwo" << std::endl;
    }
    int operator()(NumGenerator b) {
        return b.getNum();
    }
};

int main() {
    std::function< int(NumGenerator) > f(getTwo{});
    NumGenerator gen(8);
    std::cout << f(std::forward< NumGenerator >(gen)) << std::endl;
    std::cout << f(gen) << std::endl;
    return 0;
}
