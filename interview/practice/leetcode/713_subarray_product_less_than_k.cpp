#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector< int > &nums, int k) {
    if (k <= 1) {
        return 0;
    }
    int len = nums.size();
    int res = 0, prod = 1, left = 0;
    for (int i = 0; i < len; i++) {
        prod *= nums[i];
        while (prod >= k)
            prod /= nums[left++];
        res += i - left + 1;
    }
    return res;
}
int main() {
    vector< vector< int > > tt{{1, 2, 3, 4}, {3, 4, 5, 6, 9, 4, 5, 45, 34, 67, 89, 23, 67, 89, 5678, 23, 4, 56, 7123, 567, 345, 24, 234, 234, 23423424}, {2, 4, 6, 1}, {34, 5, 6, 7, 8, 23}};
    for (auto &t : tt) {
        std::cout << numSubarrayProductLessThanK(t, 9) << std::endl;
    }
    return 0;
}
