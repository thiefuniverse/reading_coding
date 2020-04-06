#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

void combinationSum2(vector< int > cur_nums, vector< int > &nums, vector< vector< int > > &result, int cur_target, int target, int index) {
    if (cur_target == target) {
        result.push_back(cur_nums);
        return;
    }
    if (cur_target > target) {
        return;
    }

    for (int i = index; i < nums.size(); ++i) {
        if (i > index && nums[i] == nums[i - 1]) continue;
        if (index > i) {
            continue;
        }
        cur_nums.push_back(nums[i]);
        combinationSum2(cur_nums, nums, result, cur_target + nums[i], target, i + 1);
        cur_nums.pop_back();
    }
}

vector< vector< int > > combinationSum2(vector< int > &nums, int target) {
    vector< vector< int > > result;
    sort(nums.begin(), nums.end());
    combinationSum2({}, nums, result, 0, target, 0);
    return result;
}

int main() {
    vector< int > t{10, 1, 2, 7, 6, 1, 5};
    sort(t.begin(), t.end());
    auto result = combinationSum2(t, 8);
    for (auto &rr : result) {
        for (auto &r : rr) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
