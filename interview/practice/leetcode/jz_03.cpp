#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int findRepeatNumber(vector< int > &nums) {
    if (nums.empty()) {
        return -1;
    }
    int flag = 0;
    while (flag < nums.size()) {
        while (nums[flag] != flag) {
            if (nums[flag] == nums[nums[flag]]) {
                return nums[flag];
            }
            swap(nums[flag], nums[nums[flag]]);
        }
        ++flag;
    }
    return nums[flag];
}
int findRepeatNumber2(vector< int > &nums) {
    unordered_set< int > result;
    for (int i = 0; i < nums.size(); ++i) {
        if (result.find(nums[i]) != result.end()) {
            return nums[i];
        } else {
            result.insert(nums[i]);
        }
    }
    return -1;
}

int main() {
    vector< vector< int > > tt{{2, 3, 1, 0, 2, 5, 3}, {3, 4, 2, 4, 5, 6, 7, 1}, {5, 5, 7, 8, 9, 1, 1, 1, 1, 1, 1}, {1, 2, 3, 4, 5, 6, 6, 6}, {1, 2, 4, 3, 5, 4}};
    for (auto &t : tt) {
        std::cout << findRepeatNumber2(t) << std::endl;
    }
    return 0;
}
