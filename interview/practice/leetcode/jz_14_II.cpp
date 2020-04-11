#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int cuttingRope(int n) {
    if (n <= 1) {
        return 1;
    }
    vector< int > dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], max((i - j) * j, j * dp[i - j]));
            dp[i] %= 1000000007;
        }
    }
    return dp[n];
}
int main() {

    std::cout << cuttingRope(10) << std::endl;
    return 0;
}
