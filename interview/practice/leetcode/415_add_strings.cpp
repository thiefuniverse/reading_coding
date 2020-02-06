#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string addStrings(string num1, string num2) {
    int flag1 = num1.size() - 1;
    int flag2 = num2.size() - 1;
    int result_len = max(flag1, flag2) + 2;
    string result(result_len, '0');

    bool carry = false;
    int mid_result = 0;
    int result_flag = result_len - 1;
    int f1 = 0, f2 = 0;
    while (flag1 >= 0 || flag2 >= 0) {
        f1 = f2 = 0;
        if (flag1 >= 0) {
            f1 = num1[flag1] - '0';
        }
        if (flag2 >= 0) {
            f2 = num2[flag2] - '0';
        }
        mid_result = f1 + f2 + carry;
        carry = false;
        if (mid_result >= 10) {
            mid_result %= 10;
            carry = true;
        }
        result[result_flag] = mid_result + '0';
        result_flag--;
        flag1--;
        flag2--;
    }
    if (carry) {
        result[result_flag] = carry + '0';
        result_flag--;
    }
    return string(result, result_flag + 1, result_len - result_flag - 1);
}

int main() {
    std::cout << addStrings("34", "25") << std::endl;
    std::cout << addStrings("", "2") << std::endl;
    std::cout << addStrings("0", "50") << std::endl;
    std::cout << addStrings("39", "25") << std::endl;
    std::cout << addStrings("99", "25") << std::endl;
    std::cout << addStrings("0", "0") << std::endl;

    return 0;
}
