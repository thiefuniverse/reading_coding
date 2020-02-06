#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }
    int m1 = (( float )log(n) / ( float )log(3));
    return pow(3, m1) == n;
}
int main() {

    std::cout << isPowerOfThree(243) << std::endl;
    std::cout << isPowerOfThree(1) << std::endl;
    std::cout << isPowerOfThree(1594332) << std::endl;
    std::cout << isPowerOfThree(9) << std::endl;
    std::cout << isPowerOfThree(5) << std::endl;
    std::cout << isPowerOfThree(27) << std::endl;
    return 0;
}
