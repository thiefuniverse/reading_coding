#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

void combinationSum(vector< int > cur_nums, vector< int > &nums, vector< vector< int > > &result, int cur_target, int target, int current_n) {
    if (cur_target == target) {
        result.push_back(cur_nums);
        return;
    }
    if (cur_target > target) {
        return;
    }

    for (int i = current_n; i < nums.size(); ++i) {
        if (current_n > i) {
            return;
        }
        cur_nums.push_back(nums[i]);
        combinationSum(cur_nums, nums, result, cur_target + nums[i], target, i);
        cur_nums.pop_back();
    }
}

vector< vector< int > > combinationSum(vector< int > &nums, int target) {
    vector< vector< int > > result;
    combinationSum({}, nums, result, 0, target, 0);
    return result;
}

int main() {
    vector< int > t{2, 3, 6, 7};
    auto result = combinationSum(t, 7);
    for (auto &rr : result) {
        for (auto &r : rr) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
