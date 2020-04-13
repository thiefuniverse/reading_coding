#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    return 0;
}
vector< int > exchange(vector< int > &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        while (l < r && nums[l] % 2) {
            ++l;
        }
        while (l < r && nums[r] % 2 == 0) {
            --r;
        }
        swap(nums[l], nums[r]);
        ++l;
        --r;
    }
    return nums;
}
