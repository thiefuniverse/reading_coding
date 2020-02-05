#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int hammingWeight(uint32_t n) {
    int result = 0;
    while (n) {
        if (n % 2) {
            result++;
        }
        n /= 2;
    }
    return result;
}

int hammingWeight2(uint32_t n) {
    bitset< sizeof(uint32_t) * 8 > m(n);
    return m.count();
}
int main() {
    std::cout << hammingWeight2(11) << std::endl;
    std::cout << hammingWeight2(pow(2, 16) - 1) << std::endl;
    std::cout << hammingWeight2(pow(2, 31) - 1) << std::endl;
    std::cout << hammingWeight2(pow(2, 32) - 1) << std::endl;
    return 0;
}
