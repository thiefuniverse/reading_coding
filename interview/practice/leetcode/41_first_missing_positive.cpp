#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int firstMissingPositive(vector< int > &nums) {
    int len = nums.size();
    if (len == 0) {
        return 1;
    }
    int i = 0;
    while (i < len) {
        int val = nums[i];
        if (val < len && val > 0) {
            swap(nums[i], nums[val - 1]);
            if (nums[i] == nums[val - 1]) {
                i++;
            }
        } else {
            i++;
        }
    }
    for (int i = 0; i < len; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return len + 1;
}
int main() {
    vector< vector< int > > tt{{0}, {1, 2, 0}, {3, 4, -1, 1}, {7, 8, 9, 11, 12}, {4, 3, 2, 7, 8, 2, 3, 1, 4}, {2, 3, 4, 5, 1, 6, 5, 7}, {10, 2, 5, 10, 9, 1, 1, 4, 3, 7}};
    for (auto &t : tt) {
        std::cout << firstMissingPositive(t) << std::endl;
    }

    return 0;
}
