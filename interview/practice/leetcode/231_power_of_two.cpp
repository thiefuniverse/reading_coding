#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
bool isPowerOfTwo(int n) {
    if (n < 0) {
        return false;
    }
    for (int i = 0; i < 31; i++) {
        if (n == 2 << i || n == 1) {
            return true;
        }
    }
    return false;
}

// steal from network
bool isPowerOfTwo2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    std::cout << isPowerOfTwo2(1) << std::endl;
    std::cout << isPowerOfTwo2(2) << std::endl;
    std::cout << isPowerOfTwo2(3) << std::endl;
    std::cout << isPowerOfTwo2(64) << std::endl;
    std::cout << isPowerOfTwo2(190) << std::endl;
    std::cout << isPowerOfTwo2(-2147483648) << std::endl;
    return 0;
}
