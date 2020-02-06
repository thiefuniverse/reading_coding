#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// repeat oprations too much
int climbStairs(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// iterations, heap overflow
int climbStairs2(int n) {
    vector< int > dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// fast, simple
int climbStairs3(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int on_1 = 1;
    int on_2 = 2;
    int result = 0;
    for (int i = 3; i <= n; i++) {
        result = on_1 + on_2;
        on_1 = on_2;
        on_2 = result;
    }
    return result;
}

int main() {
    std::cout << climbStairs3(2) << std::endl;
    std::cout << climbStairs3(3) << std::endl;
    std::cout << climbStairs3(4) << std::endl;
    return 0;
}
