#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< string > fizzBuzz(int n) {
    vector< string > result(n);
    for (int i = 1; i <= n; ++i) {
        if (i % 15 == 0) {
            result[i - 1] = "FizzBuzz";
        } else if (i % 3 == 0) {
            result[i - 1] = "Fizz";
        } else if (i % 5 == 0) {
            result[i - 1] = "Buzz";
        } else {
            result[i - 1] = std::to_string(i);
        }
    }
    return result;
}
int main() {
    auto res = fizzBuzz(15);
    for (auto &r : res) {
        std::cout << r << std::endl;
    }
    return 0;
}
