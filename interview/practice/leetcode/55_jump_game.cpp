#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool canJump(vector< int > &nums) {
    int maxFar = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (i <= maxFar) {
            maxFar = max(maxFar, i + nums[i]);
        }
    }
    return maxFar >= len - 1;
}
int main() {
    vector< vector< int > > tt{{2, 3, 1, 1, 4}, {3, 2, 1, 0, 4}, {1, 0, 1, 2, 1, 4}, {1, 0, 1, 2, 1, 4}, {7, 8, 9}};
    for (auto &t : tt) {
        std::cout << canJump(t) << std::endl;
    }

    return 0;
}
