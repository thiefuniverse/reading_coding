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
    vector< int > dp(prices.size(), 0);
    for (int i = 1; i < prices.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (prices[j] < prices[i]) {
                if (j > 0) {
                    max_profit = max(max_profit, dp[j - 1] + prices[i] - prices[j]);
                } else {
                    max_profit = max(max_profit, dp[0] + prices[i] - prices[j]);
                }
            }
        }
        dp[i] = max_profit;
    }
    return dp[prices.size() - 1];
}

// steal from leetcode, so tricky :)
int maxProfit2(vector< int > &prices) {
    int profit = 0;
    for (int i = 0; i + 1 < prices.size(); i++) {
        if (prices[i + 1] > prices[i]) {
            profit += prices[i + 1] - prices[i];
        }
    }
    return profit;
}

// steal from leetcode, cool :).
int maxProfit3(vector< int > &prices) {
    if (prices.empty()) {
        return 0;
    }
    vector< vector< int > > dp(prices.size() + 1, vector< int >(2, 0));
    dp[0][1] = INT_MIN;
    for (int i = 1; i <= prices.size(); i++) {
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
    }
    return dp[prices.size()][0];
}
int main() {

    vector< vector< int > > tt{{7, 1, 5, 3, 6, 4}, {7, 6, 4, 3, 1}, {}, {3, 4}, {5}};
    for (auto &t : tt) {
        std::cout << maxProfit3(t) << std::endl;
    }
    return 0;
}
