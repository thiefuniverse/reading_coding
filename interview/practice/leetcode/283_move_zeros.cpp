#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
void moveZeroes(vector< int > &nums) {
    int forward = 0;
    for (int next = 0; next < nums.size(); next++) {
        if (nums[next] != 0) {
            swap(nums[forward], nums[next]);
            forward++;
        }
    }
}
int main() {
    vector< vector< int > > t{{0, 1, 0, 3, 12}, {1, 0}, {3, 0, 0}, {0, 0, 1, 0}};
    for (auto &tt : t) {
        moveZeroes(tt);
        for (auto &ii : tt) {
            std::cout << ii << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
