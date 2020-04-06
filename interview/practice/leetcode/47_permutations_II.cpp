
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

void permuteUnique(vector< int > cur_nums, vector< bool > &used, vector< int > &nums, vector< vector< int > > &result, int current_n) {
    if (cur_nums.size() == nums.size()) {
        result.push_back(cur_nums);
        return;
    }

    set< int > visited;
    for (int i = 0; i < nums.size(); ++i) {
        if (visited.find(nums[i]) != visited.end()) {
            continue;
        }
        if (!used[i]) {
            cur_nums.push_back(nums[i]);
            used[i] = true;
            visited.insert(nums[i]);
            permuteUnique(cur_nums, used, nums, result, current_n + 1);
            used[i] = false;
            cur_nums.pop_back();
        }
    }
}
vector< vector< int > > permuteUnique(vector< int > &nums) {
    vector< vector< int > > result;
    vector< bool > used(nums.size(), false);
    permuteUnique({}, used, nums, result, 0);

    return result;
}
int main() {
    vector< int > t{1, 1, 2};
    auto result = permuteUnique(t);
    for (auto &rr : result) {
        for (auto &r : rr) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
