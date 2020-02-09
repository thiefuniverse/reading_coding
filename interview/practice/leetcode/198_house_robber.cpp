#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int rob(vector< int > &nums) {
    if (nums.empty()) {
        return 0;
    }
    int len = nums.size();
    if (len == 1) {
        return nums[0];
    }
    if (len == 2) {
        return max(nums[0], nums[1]);
    }
    int before2 = nums[0];
    int before1 = max(nums[0], nums[1]);
    int result = 0;
    for (int i = 3; i <= len; i++) {
        result = max(before2 + nums[i - 1], before1);
        before2 = before1;
        before1 = result;
    }
    return result;
}
int main() {
    vector< vector< int > > tt{{1, 2, 3, 1}, {2, 7, 9, 3, 1}, {}, {3}, {3, 6}};
    for (auto &t : tt) {
        std::cout << rob(t) << std::endl;
    }
    return 0;
}
