#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector< int > &cost) {
    int len = cost.size();
    if (len < 2) {
        return 0;
    }
    vector< vector< int > > min_cost(len + 1, vector< int >(2, 0));
    min_cost[1][1] = cost[0];
    for (int i = 2; i <= len; i++) {
        min_cost[i][1] = min(min_cost[i - 1][1] + cost[i - 1], min_cost[i - 2][1] + cost[i - 1]);
        min_cost[i][0] = min(min_cost[i - 1][1], min_cost[i - 2][1] + cost[i - 2]);
    }
    return min(min_cost[len][0], min_cost[len][1]);
}

// steal from leetcode
int minCostClimbingStairs2(vector< int > &cost) {
    if (cost.size() < 2) {
        return 0;
    }
    int len = cost.size();
    vector< int > dp(len + 1, 0);
    dp[1] = cost[0];
    dp[2] = cost[1];
    for (int i = 3; i <= len; i++) {
        dp[i] = cost[i - 1] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[len], dp[len - 1]);
}

int main() {
    vector< vector< int > > tt{{10, 15, 20}, {1, 100, 1, 1, 1, 100, 1, 1, 100, 1}};
    for (auto &t : tt) {
        std::cout << minCostClimbingStairs(t) << std::endl;
        std::cout << minCostClimbingStairs2(t) << std::endl;
    }
    return 0;
}
