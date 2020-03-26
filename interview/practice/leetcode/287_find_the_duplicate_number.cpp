#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int findDuplicate(vector< int > &nums) {
    int fast = 0, slow = 0;
    if (nums.empty()) {
        return -1;
    }
    slow = nums[0];
    fast = nums[nums[0]];

    int flag = 0;
    while (fast != slow) {
        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];
    }
    fast = 0;
    while (fast != slow) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int findDuplicate2(vector< int > &nums) {
    if (nums.size() <= 1) {
        return -1;
    }
    int n = nums.size() - 1;
    int left = 0, right = n;
    int dup = (left + right) / 2;
    while (left < right) {
        int count = count_if(nums.begin(), nums.end(), [&](int num) { return num <= dup; });
        //        std::cout << "cur dup: " << dup << " count: " << count << std::endl;
        if (count <= dup) {
            left = dup + 1;
            dup = (left + right) / 2;
        } else {
            right = dup;
            dup = (left + right) / 2;
        }
    }
    return dup;
}

int main() {
    vector< vector< int > > tt{{1, 3, 4, 2, 2}, {3, 1, 3, 4, 2}, {4, 5, 3, 4, 1, 4}, {2, 5, 9, 6, 9, 3, 8, 9, 7, 1}};
    for (auto &t : tt) {
        std::cout << findDuplicate2(t) << std::endl;
    }
    return 0;
}
