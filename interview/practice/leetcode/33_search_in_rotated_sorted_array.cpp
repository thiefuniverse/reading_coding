#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int search(vector< int > &nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    // find min_flag by binary search
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    // get l and r for binary search
    int min_flag = l;
    if (target == nums[0]) {
        return 0;
    }
    if (target == nums[min_flag]) {
        return min_flag;
    }
    if (min_flag == 0) {
        l = 0;
        r = nums.size() - 1;
    } else {
        if (target <= nums[nums.size() - 1]) {
            l = min_flag;
            r = nums.size() - 1;
        } else {
            l = 0;
            r = min_flag - 1;
        }
    }
    // binary search
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (nums[l] == target) {
        return l;
    }
    return -1;
}

// now, it's idea stolen from leetcode
int search2(vector< int > &nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if ((nums[mid] - nums[nums.size() - 1]) * (target - nums[nums.size() - 1]) > 0) {
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                return mid;
            }
        } else if (target < nums[nums.size() - 1]) {
            l = mid + 1;
        } else if (target > nums[nums.size() - 1]) {
            r = mid - 1;
        } else {
            return nums.size() - 1;
        }
    }
    if (nums[l] == target) {
        return l;
    } else {
        return -1;
    }
}
int main() {
    vector< vector< int > > tt{{6, 7, 8, 1, 4, 5}, {4, 1, 2, 3}, {2}, {4, 2}, {1, 2}, {6, 7}, {5, 1, 3}};
    for (auto &t : tt) {
        std::cout << search2(t, 6) << " " << std::endl;
        std::cout << search2(t, 7) << " " << std::endl;
        std::cout << search2(t, 3) << " " << std::endl;
    }
    return 0;
}
