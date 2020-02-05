#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// two pointers move forward, 16ms, 11MB.
int majorityElement(vector< int > &nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }

    std::vector< bool > nums_flag(nums.size(), true);
    int first = 0, next = 1;
    while (next < nums.size()) {
        if (nums[first] != nums[next]) {
            nums_flag[first] = false;
            nums_flag[next] = false;
            while (++first < nums.size()) {
                if (nums_flag[first]) {
                    nums_flag[first] = false;
                    break;
                }
            }
            while (++next < nums.size()) {
                if (nums_flag[next]) {
                    nums_flag[next] = false;
                    break;
                }
            }

        } else {
            nums_flag[next] = true;
            next++;
        }
    }
    return nums[first];
}

// use unordered_map, 20ms, 11.1MB
int majorityElement2(vector< int > &nums) {
    unordered_map< int, int > all;
    for (auto &n : nums) {
        all[n]++;
    }
    int max_n = 0;
    int max_num = 0;
    for (auto &k : all) {
        if (k.second > max_n) {
            max_n = k.second;
            max_num = k.first;
        }
    }
    return max_num;
}

// steal from leetcode
int majorityElement3(vector< int > &nums) {
    int major_ele = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (!count) {
            major_ele = nums[i];
            count++;
        } else {
            if (major_ele == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
    }
    return major_ele;
}
int main() {
    vector< vector< int > > t{{3, 2, 3}, {1}, {2, 2, 1, 1, 1, 2, 2}, {3, 3, 3, 3, 3}, {5, 6, 7, 4, 5, 5, 5}, {10, 9, 9, 9, 10}};
    for (auto &tt : t) {
        std::cout << majorityElement3(tt) << std::endl;
    }

    return 0;
}
