#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int maxProduct(vector< int > &nums) {
    if (nums.empty()) {
        return 0;
    }
    int imax = nums[0], imin = nums[0];
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(imax, imin);
        }
        imax = max(nums[i], imax * nums[i]);
        imin = min(nums[i], imin * nums[i]);
        result = max(imax, result);
    }
    return result;
}

// dp
int maxProduct2(vector< int > &nums) {
    if (nums.empty()) {
        return 0;
    }
    int imax = nums[0], imin = nums[0];
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int cur_imax = max({nums[i], imax * nums[i], imin * nums[i]});
        int cur_imin = min({nums[i], imin * nums[i], imax * nums[i]});
        imax = cur_imax;
        imin = cur_imin;
        result = max({imax, result, imin});
    }
    return result;
}

int main() {
    vector< vector< int > > tt{{2, 3, -2, 4}, {-2, 0, -1}, {-2}, {}, {3, -1, 5}, {2, 3, -2, 4, -3, 0, 5, -3, 6, -2, -90}};
    for (auto &t : tt) {
        std::cout << maxProduct(t) << std::endl;
        std::cout << maxProduct2(t) << std::endl;
    }
    return 0;
}
