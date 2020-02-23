#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void subsets(vector< int > &nums, vector< int > &sub, vector< vector< int > > &result, int k) {
    result.push_back(sub);
    for (int i = k; i < nums.size(); i++) {
        sub.push_back(nums[i]);
        subsets(nums, sub, result, i + 1);
        sub.pop_back();
    }
}
vector< vector< int > > subsets(vector< int > &nums) {
    vector< vector< int > > result;
    vector< int > sub;
    int k = 0;
    subsets(nums, sub, result, k);
    return result;
}

// version 2

vector< vector< int > > subsets2(vector< int > &nums) {
    vector< vector< int > > result{{}};
    for (auto &num : nums) {
        int n = result.size();
        for (int i = 0; i < n; i++) {
            result.push_back(result[i]);
            result.back().push_back(num);
        }
    }
    return result;
}

// version3
vector< vector< int > > subsets3(vector< int > &nums) {
    int len = nums.size(), p = 1 << len;
    vector< vector< int > > result(p);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < len; j++) {
            if ((i >> j) & 1) {
                result[i].push_back(nums[j]);
            }
        }
    }
    return result;
}
// version 4
vector< vector< int > > subsets4(vector< int > &nums) {
    int len = nums.size(), p = 1 << len;
    vector< vector< int > > result(p);
    for (int i = 0; i < len; i++) {
        for (int step = 1 << i, start = 0; start < p; start += 2 * step) {
            for (int j = start; j < start + step; j++) {
                result[j].push_back(nums[i]);
            }
        }
    }
    return result;
}

int main() {

    vector< vector< int > > tt{{1, 2, 3}, {4, 5, 6, 7, 8}};
    for (auto &t : tt) {
        auto res = subsets4(t);
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
