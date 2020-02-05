#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int trailingZeroes(int n) {
    int pow_num = 1;
    int result = 0;
    while (true) {
        int cur_pow = pow(5, pow_num);
        int cur_result = n / cur_pow;
        if (cur_result == 0) {
            return result;
        }
        result += cur_result;
        pow_num++;
    }
    return result;
}
int main() {
    std::cout << trailingZeroes(3) << std::endl;
    std::cout << trailingZeroes(5) << std::endl;
    std::cout << trailingZeroes(30) << std::endl;
    std::cout << trailingZeroes(130) << std::endl;
    return 0;
}
