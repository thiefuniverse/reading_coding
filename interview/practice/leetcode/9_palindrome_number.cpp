#include <iostream>
bool isPalindrome1(long x) {
    long result = 0;
    bool is_negtive = false;
    if (x < 0 || x % 10 == 0) {
        return false;
    }
    long original = x;
    while (x > 0) {
        long temp = x % 10;
        x = x / 10;
        result = 10 * result + temp;
    }
    if (result > INT_MAX || result < INT_MIN) {
        return false;
    }
    if (is_negtive) {
        result = -result;
    }
    return result == original;
}

bool isPalindrome2(long x) {
    long result = 0;
    if (x < 0) {
        return false;
    }
    long original = x;
    while (x) {
        result *= 10;
        result += x % 10;
        x /= 10;
    }
    return result == original;
}
int main() {
    std::cout << "result: " << isPalindrome2(121) << std::endl;
    std::cout << "result: " << isPalindrome2(-121) << std::endl;
    std::cout << "result: " << isPalindrome2(10) << std::endl;
    std::cout << "result: " << isPalindrome2(1345431) << std::endl;
    return 0;
}
