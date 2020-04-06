#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

void findSubsequences(vector< int > cur_nums, vector< int > nums, vector< vector< int > > &result, int current_n) {
    if (cur_nums.size() >= 2) {
        result.push_back(cur_nums);
    }

    set< int > visited;
    for (int i = current_n; i < nums.size(); ++i) {
        if (visited.find(nums[i]) != visited.end()) {
            continue;
        }
        if (!cur_nums.empty() && nums[i] < cur_nums[cur_nums.size() - 1]) {
            continue;
        }
        visited.insert(nums[i]);
        cur_nums.push_back(nums[i]);
        findSubsequences(cur_nums, nums, result, i + 1);
        cur_nums.pop_back();
    }
}
vector< vector< int > > findSubsequences(vector< int > &nums) {
    vector< vector< int > > result;
    findSubsequences({}, nums, result, 0);
    return result;
}

int main() {
    vector< int > t{4, 6, 7, 7, 6, 7};
    auto result = findSubsequences(t);
    for (auto &rr : result) {
        for (auto &r : rr) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
