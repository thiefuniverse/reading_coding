#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< int > findErrorNums(vector< int > &nums) {
    vector< short > all(nums.size(), 0);
    for (auto &num : nums) {
        ++all[num - 1];
    }
    int dup_num = -1;
    int miss_num = -1;
    for (int i = 0; i < all.size(); ++i) {
        if (all[i] == 0) {
            miss_num = i + 1;
        }
        if (all[i] == 2) {
            dup_num = i + 1;
        }
    }
    return {dup_num, miss_num};
}
int main() {
    vector< int > test{1, 2, 2, 4};
    auto res = findErrorNums(test);
    for (auto &r : res) {
        std::cout << r << std::endl;
    }

    return 0;
}
