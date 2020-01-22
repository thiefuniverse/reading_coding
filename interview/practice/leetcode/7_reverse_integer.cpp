#include <iostream>
int reverse(long x) {
    long result = 0;
    bool is_negtive = false;
    if (x < 0) {
        is_negtive = true;
        x = -x;
    }
    while (x > 0) {
        long temp = x % 10;
        x = x / 10;
        result = 10 * result + temp;
    }
    if (result > INT_MAX) {
        return 0;
    }
    if (is_negtive) {
        result = -result;
    }
    return result;
}
int main() {
    std::cout << "result: " << reverse(123) << std::endl;
    std::cout << "result: " << reverse(120) << std::endl;
    std::cout << "result: " << reverse(0) << std::endl;
    std::cout << "result: " << reverse(-123) << std::endl;
    std::cout << "result: " << reverse(1534236469) << std::endl;
    std::cout << "result: " << reverse(-2147483648) << std::endl;
    std::cout << "int max: " << INT_MAX << std::endl;
    return 0;
}
