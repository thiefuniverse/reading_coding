#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int rob(vector< int > &nums) {
    if (nums.empty()) {
        return 0;
    }
    int len = nums.size();
    if (len == 1) {
        return nums[0];
    }
    if (len == 2) {
        return max(nums[0], nums[1]);
    }
    vector< vector< int > > dp(len + 1, vector< int >(2, 0));
    dp[1][0] = 0;
    dp[1][1] = nums[0];
    dp[2][0] = nums[1];
    dp[2][1] = nums[0];

    for (int i = 3; i <= len - 1; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 2][0] + nums[i - 1]});
        dp[i][1] = max({dp[i - 1][1], dp[i - 2][1] + nums[i - 1]});
    }
    dp[len][0] = max(dp[len - 1][0], dp[len - 2][0] + nums[len - 1]);
    dp[len][1] = max(dp[len - 1][1], dp[len - 2][1]);
    return max(dp[len][0], dp[len][1]);
}

// use range
int rob_helper(vector< int > &nums, int start, int end) {
    if (start > end) {
        return 0;
    }
    int len = end - start + 1;
    if (len == 1) {
        return nums[start];
    }
    if (len == 2) {
        return max(nums[start], nums[start + 1]);
    }
    int before2 = nums[start];
    int before1 = max(nums[start], nums[start + 1]);
    int result = 0;
    for (int i = start + 3; i <= end + 1; i++) {
        result = max(before2 + nums[i - 1], before1);
        before2 = before1;
        before1 = result;
    }
    return result;
}

int rob2(vector< int > &nums) {
    int len = nums.size();
    if (nums.size() == 0) {
        return 0;
    }
    if (len == 1) {
        return nums[0];
    }
    if (len == 2) {
        return max(nums[0], nums[1]);
    }
    return max(rob_helper(nums, 0, len - 2), rob_helper(nums, 1, len - 1));
}

int main() {
    vector< vector< int > > tt{{2, 3, 2}, {2, 7, 9, 3, 1}, {1, 2, 3, 1}, {}, {3}, {3, 6}, {1, 3, 1, 3, 100}};
    for (auto &t : tt) {
        std::cout << rob(t) << std::endl;
        std::cout << rob2(t) << std::endl;
    }
    return 0;
}
