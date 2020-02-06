#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// no easy really :)
int addDigits(int num) {
    return 1 + (num - 1) % 9;
}
int main() {

    std::cout << addDigits(1) << std::endl;
    std::cout << addDigits(99) << std::endl;
    return 0;
}
