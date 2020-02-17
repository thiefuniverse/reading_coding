#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int singleNumber(vector< int > &nums) {
    if (nums.empty()) {
        return 0;
    }
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        res ^= nums[i];
    }
    return res;
}
int main() {
    vector< vector< int > > tt{{2, 2, 1}, {4}, {4, 1, 2, 1, 2}, {5, 6, 7, 7, 6, 5, 9}};
    for (auto &t : tt) {
        std::cout << singleNumber(t) << std::endl;
    }
    return 0;
}
