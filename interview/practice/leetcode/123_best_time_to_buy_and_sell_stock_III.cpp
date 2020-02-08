#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// my solution
int maxProfit(vector< int > &prices) {
    if (prices.empty()) {
        return 0;
    }
    int cur_min = prices[0], max_profit = 0;
    vector< vector< int > > dp(prices.size(), vector< int >(2, 0));
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        for (int j = 0; j < i; j++) {
            if (prices[j] < prices[i]) {
                dp[i][0] = max(dp[i][0], prices[i] - prices[j]);
                if (j > 0) {
                    dp[i][1] = max(dp[i][1], dp[j - 1][0] + prices[i] - prices[j]);
                } else {
                    dp[i][1] = max(dp[i][1], prices[i] - prices[j]);
                }
            }
        }
    }
    return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
}

// steal from leetcode
int maxProfit2(vector< int > &prices) {
    int m = 2;
    int n = prices.size();
    if (n <= 1 || m == 0) {
        return 0;
    }
    std::vector< std::vector< int > > dp(2, std::vector< int >(m + 1, 0)), prev;
    for (int k = 0; k <= m; ++k) {
        dp[0][k] = 0;
        dp[1][k] = INT_MIN;
    }
    for (int i = 0; i < n; ++i) {
        for (int k = 1; k <= m; ++k) {
            dp[0][k] = max(dp[1][k] + prices[i], dp[0][k]);
            dp[1][k] = max(dp[0][k - 1] - prices[i], dp[1][k]);
        }
    }
    return dp[0][m];
}

int maxProfit3(vector< int > &prices) {
    int oneB = INT_MIN, oneS = INT_MIN, twoB = INT_MIN, twoS = 0;
    for (int &p : prices) {
        oneB = max(oneB, -p);
        oneS = max(oneS, oneB + p);
        twoB = max(twoB, oneS - p);
        twoS = max(twoS, twoB + p);
    }
    return max(oneS, twoS);
}
int main() {

    vector< vector< int > > tt{{3, 3, 5, 0, 0, 3, 1, 4}, {1, 2, 3, 4, 5}, {7, 1, 5, 3, 6, 4}, {7, 6, 4, 3, 1}, {}, {3, 4}, {5}, {6, 1, 3, 2, 4, 7}};
    for (auto &t : tt) {
        std::cout << maxProfit3(t) << std::endl;
    }
    return 0;
}
