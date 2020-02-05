#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// dp
int maxSubArray(const vector< int > &nums) {
    if (nums.empty()) {
        return 0;
    }
    vector< int > record_flag(nums.size());
    int max_sub = nums[0], running_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (running_sum > 0) {
            running_sum += nums[i];
        } else {
            running_sum = nums[i];
        }
        max_sub = max(running_sum, max_sub);
    }
    return max_sub;
}

// 分治
int crossSubArray(const vector< int > &nums, int left, int mid, int right) {
    int lm = 0, tmpl = 0;
    for (int i = mid - 1; i >= left; i--) {
        tmpl += nums[i];
        lm = max(tmpl, lm);
    }
    int rm = 0, tmpr = 0;
    for (int i = mid; i <= right; i++) {
        tmpr += nums[i];
        rm = max(tmpr, rm);
    }
    return lm + rm;
}
int maxSubArray2(const vector< int > &nums, int left, int right) {
    if (nums.empty() || left > right) {
        return 0;
    }
    if (left == right) {
        return nums[left];
    }
    if (left + 1 == right) {
        return max(nums[left], nums[right]);
    }
    int mid = (left + right) / 2;
    int leftMax = maxSubArray2(nums, left, mid);
    int rightMax = maxSubArray2(nums, mid, right);
    // get cross max sum
    int crossMax = crossSubArray(nums, left, mid, right);
    return max(leftMax, max(rightMax, crossMax));
}
int main() {
    vector< vector< int > > t{{-2, 1, -3, 4, -1, 2, 1, -5, 4}, {}, {-3}, {-3, 5}, {-1, 2, 6, -9, 10, -1, 3}};
    for (auto &tt : t) {
        std::cout << "t: " << maxSubArray(tt) << std::endl;
        std::cout << "t: " << maxSubArray2(tt, 0, tt.size() - 1) << std::endl;
    }

    return 0;
}
