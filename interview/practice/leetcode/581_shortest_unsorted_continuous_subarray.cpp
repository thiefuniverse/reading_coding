#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
        return 0;
    }
    int l = 1, r = 1;
    int i = 1;
    // get first pair for  nums[i-1] > nums[i], l = i-1, r = i
    while (i < len) {
        if (nums[i] >= nums[i - 1]) {
            i++;
        } else {
            l = i - 1;
            r = i;
            break;
        }
    }
    if (i == len) {
        return 0;
    }
    int max_num = max(nums[l], nums[r]), min_num = min(nums[l], nums[r]);

    // adjust l and r.   <-----l      r----->
    while (i < len) {
        if (nums[i] < max_num) {
            r = i;
            min_num = min(min_num, nums[i]);
            while (l >= 1) {
                if (nums[l - 1] > min_num) {
                    l--;
                } else {
                    break;
                }
            }
        } else {
            max_num = max(max_num, nums[i]);
        }
        i++;
    }
    return (r - l) + 1;
}

int main() {
    vector<vector<int> > tt{{6, 7, 8, 1, 4, 8},      {4, 1, 2, 3},   {2}, {4, 2}, {1, 2},
                            {2, 6, 4, 8, 10, 9, 15}, {2, 3, 3, 2, 4}};
    for (auto& t : tt) {
        std::cout << findUnsortedSubarray(t) << std::endl;
    }

    return 0;
}
