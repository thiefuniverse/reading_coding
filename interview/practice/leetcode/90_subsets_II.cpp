#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void subsets(vector< int > &nums, vector< int > &sub, vector< vector< int > > &result, int k) {
    result.push_back(sub);
    for (int i = k; i < nums.size(); i++) {
        if (i > k && nums[i] == nums[i - 1]) {
            continue;
        }
        sub.push_back(nums[i]);
        subsets(nums, sub, result, i + 1);
        sub.pop_back();
    }
}
vector< vector< int > > subsetsWithDup(vector< int > &nums) {
    vector< vector< int > > result;
    vector< int > sub;
    int k = 0;
    sort(nums.begin(), nums.end());
    subsets(nums, sub, result, k);
    return result;
}
// version 2
vector< vector< int > > subsetsWithDup2(vector< int > &nums) {
    vector< vector< int > > result{{}};
    sort(nums.begin(), nums.end());
    int lastN = 0;
    for (int j = 0; j < nums.size(); j++) {
        int n = result.size();
        if (j == 0 || nums[j] != nums[j - 1]) {
            lastN = 0;
        }
        for (int i = lastN; i < n; i++) {
            result.push_back(result[i]);
            result.back().push_back(nums[j]);
        }
        lastN = n;
    }
    return result;
}

int main() {

    vector< vector< int > > tt{{1, 2, 2}, {4, 5, 6, 7, 8}};
    for (auto &t : tt) {
        auto res = subsetsWithDup2(t);
        for (auto &k1 : res) {
            for (auto &k2 : k1) {
                std::cout << k2 << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "one case: " << std::endl;
    }
    return 0;
}
