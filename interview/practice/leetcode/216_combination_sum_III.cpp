#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

void combine(vector< int > &cur_nums, vector< bool > &used, vector< int > &nums, vector< vector< int > > &result, int target, int k, int cur_target, int current_n) {
    if (cur_target == target && cur_nums.size() == k) {
        result.push_back(cur_nums);
        return;
    }
    if (cur_nums.size() > k || cur_target > target) {
        return;
    }
    for (int i = current_n; i < nums.size(); ++i) {
        if (used[i]) {
            continue;
        }
        cur_nums.push_back(nums[i]);
        used[i] = true;
        combine(cur_nums, used, nums, result, target, k, cur_target + nums[i], i + 1);
        used[i] = false;
        cur_nums.pop_back();
    }
}

vector< vector< int > > combinationSum3(int k, int n) {
    vector< vector< int > > result;
    vector< int > nums(9, 0);
    for (int i = 1; i <= 9; ++i) {
        nums[i - 1] = i;
    }
    vector< bool > used(n, false);
    vector< int > cur_nums;
    combine(cur_nums, used, nums, result, n, k, 0, 0);
    return result;
}
int main() {
    vector< int > t{2, 3, 6, 7};
    auto result = combinationSum3(3, 9);
    for (auto &rr : result) {
        for (auto &r : rr) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
