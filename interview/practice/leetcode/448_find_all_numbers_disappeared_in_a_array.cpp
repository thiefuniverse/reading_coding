#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< int > findDisappearedNumbers(vector< int > &nums) {
    int len = nums.size();
    int val = 0;
    int i = 0;
    while (i < len) {
        val = nums[i];
        if (nums[i] != i + 1) {
            swap(nums[i], nums[val - 1]);
            if (nums[i] == nums[val - 1]) {
                i++;
            }
        } else {
            i++;
        }
    }
    vector< int > result;
    for (int i = 0; i < len; i++) {
        if (nums[i] != i + 1) {
            result.push_back(i + 1);
        }
    }
    return result;
}

// now we steal a cool solution :)

vector< int > findDisappearedNumbers2(vector< int > &nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        int val = abs(nums[i]) - 1;
        nums[val] = nums[val] > 0 ? -nums[val] : nums[val];
    }

    vector< int > result;
    for (int i = 0; i < len; i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }
    return result;
}
int main() {
    vector< vector< int > > tt{{4, 3, 2, 7, 8, 2, 3, 1, 4}, {2, 3, 4, 5, 1, 6, 5, 7}};
    for (auto &t : tt) {
        auto r = findDisappearedNumbers2(t);
        for (auto &m : r) {
            std::cout << m << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
