#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
bool isUgly(int num) {
    if (num <= 1) {
        return false;
    }
    while (num > 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else if (num % 3 == 0) {
            num /= 3;
        } else if (num % 5 == 0) {
            num /= 5;
        } else if (num > 1) {
            return false;
        }
    }
    return true;
}
int main() {
    std::cout << isUgly(6) << std::endl;
    std::cout << isUgly(1) << std::endl;
    std::cout << isUgly(8) << std::endl;
    std::cout << isUgly(14) << std::endl;

    return 0;
}
