#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

void permute(vector< int > &nums, vector< vector< int > > &result, int current_n) {
    if (current_n == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = current_n; i < nums.size(); ++i) {
        swap(nums[current_n], nums[i]);
        permute(nums, result, current_n + 1);
        swap(nums[current_n], nums[i]);
    }
}
vector< vector< int > > permute(vector< int > &nums) {
    vector< vector< int > > result;
    permute(nums, result, 0);
    return result;
}

void permute2(vector< int > cur_nums, vector< bool > &used, vector< int > &nums, vector< vector< int > > &result, int current_n) {
    if (cur_nums.size() == nums.size()) {
        result.push_back(cur_nums);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            cur_nums.push_back(nums[i]);
            used[i] = true;
            permute2(cur_nums, used, nums, result, current_n + 1);
            used[i] = false;
            cur_nums.pop_back();
        }
    }
}
vector< vector< int > > permute2(vector< int > &nums) {
    vector< vector< int > > result;
    vector< bool > used(nums.size(), false);
    permute2({}, used, nums, result, 0);

    return result;
}
int main() {
    vector< int > t{1, 2, 3, 4};
    auto result = permute2(t);
    for (auto &rr : result) {
        for (auto &r : rr) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
