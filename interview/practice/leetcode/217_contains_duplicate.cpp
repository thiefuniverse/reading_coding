#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector< int > &nums) {
    unordered_set< int > all_map;
    for (auto &n : nums) {
        if (all_map.find(n) != all_map.end()) {
            return true;
        } else {
            all_map.insert(n);
        }
    }
    return false;
}

// use count for unordered_set
bool containsDuplicate2(vector< int > &nums) {
    unordered_set< int > all_map;
    for (auto &n : nums) {
        if (all_map.count(n)) {
            return true;
        } else {
            all_map.insert(n);
        }
    }
    return false;
}
// :(, you can't believe that sorting will be faster.
bool containsDuplicate3(vector< int > &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i + 1 < nums.size(); i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    vector< vector< int > > t1{{1}, {1, 1}, {1, 2, 3, 1}, {1, 2, 3, 4}, {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}};
    for (auto t : t1) {
        std::cout << containsDuplicate3(t) << std::endl;
    }

    return 0;
}
