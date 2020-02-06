#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
bool checkPerfectNumber(int num) {
    if (num <= 0) {
        return false;
    }
    int result = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            result += i;
        }
    }
    return result == num;
}
// optimize
bool checkPerfectNumber2(int num) {
    if (num <= 1) {
        return false;
    }
    int result = 1;
    int sqrt_num = sqrt(num);
    for (int i = 2; i <= sqrt_num + 1; i++) {
        if (num % i == 0) {
            result += i + num / i;
        }
    }
    return result == num;
}

int main() {

    std::cout << checkPerfectNumber2(28) << std::endl;
    std::cout << checkPerfectNumber2(29) << std::endl;
    std::cout << checkPerfectNumber2(100000000) << std::endl;
    return 0;
}
