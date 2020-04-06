#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

// slowly
void combinationSum4(vector< int > cur_nums, vector< int > &nums, vector< vector< int > > &result, int cur_target, int target, int index) {
    if (cur_target == target) {
        result.push_back(cur_nums);
        return;
    }
    if (cur_target > target) {
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        cur_nums.push_back(nums[i]);
        combinationSum4(cur_nums, nums, result, cur_target + nums[i], target, i);
        cur_nums.pop_back();
    }
}

int combinationSum4(vector< int > &nums, int target) {
    vector< vector< int > > result;
    sort(nums.begin(), nums.end());
    combinationSum4({}, nums, result, 0, target, 0);
    return result.size();
}
// fast now :)
int combinationSum42(vector< int > &nums, int target) {
    if (target == 0) {
        return 0;
    }
    vector< int > dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= target; ++i) {
        for (auto &num : nums) {
            if (i + num <= target) {
                dp[i + num] += dp[i];
            }
        }
    }
    return dp[target];
}

int main() {
    vector< int > t{3, 33, 333};
    int result = combinationSum42(t, 10000);
    std::cout << "result " << result << std::endl;
    return 0;
}
