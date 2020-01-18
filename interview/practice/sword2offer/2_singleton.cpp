#include <iostream>

class S {
public:
    static S &getInstance() {
        static S instance;
        return instance;
    }

private:
    S() {}

public:
    S(S const &) = delete;
    void operator=(S const &) = delete;
};

int main() {
    auto &s1 = S::getInstance();
    auto &s2 = S::getInstance();
    std::cout << "s1: " << &s1 << std::endl;
    std::cout << "s2: " << &s2 << std::endl;
    return 0;
}
