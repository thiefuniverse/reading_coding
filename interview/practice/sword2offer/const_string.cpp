#include <iostream>
#include <string>

// const char* in C++ are all same.
int main() {
    char s1[] = "hello thief";
    char s2[] = "hello thief";
    char *c_s1 = "hello thief";
    char *c_s2 = "hello thief";

    if (s1 == s2) {
        std::cout << "same: s1: " << s1 << " s2: " << s2 << std::endl;
    } else {
        std::cout << "not same: s1: " << s1 << " s2: " << s2 << std::endl;
    }
    if (c_s1 == c_s2) {
        std::cout << "same: c_s1: " << c_s1 << " c_s2: " << c_s2 << std::endl;
    } else {
        std::cout << "not c_same: c_s1: " << c_s1 << " c_s2: " << c_s2 << std::endl;
    }

    return 0;
}
