#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< int > countBits(int num) {
    vector< int > dp(num + 1, 0);
    for (int i = 1; i <= num; i++) {
        if ((i & (i - 1)) == 0) {
            dp[i] = 1;
        } else if ((i ^ (i - 1)) == 1) {
            dp[i] = dp[i - 1] + 1;
        } else {
            int carry_bit = (i ^ (i - 1)) + 1;
            int remove_bit = log(carry_bit) / log(2) - 2;
            dp[i] = dp[i - 1] - remove_bit;
        }
    }
    return dp;
}

// fancy...
vector< int > countBits2(int num) {
    vector< int > dp(num + 1, 0);
    for (int i = 1; i <= num; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}

int main() {
    vector< int > tt{2, 5, 0, 1, 10, 30};
    for (auto &t : tt) {
        auto res = countBits2(t);
        for (auto &r : res) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
