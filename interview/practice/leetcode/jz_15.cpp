#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int hammingWeight(uint32_t n) {
    bitset< 32 > result(n);
    return result.count();
}
int main() {

    std::cout << hammingWeight(9) << std::endl;
    return 0;
}
