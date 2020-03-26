#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int missingNumber(vector< int > &nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return (n + 1) * n / 2 - sum;
}

int missingNumber2(vector< int > &nums) {
    int result = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
        result ^= nums[i];
        result ^= i;
    }
    return result;
}

int main() {
    vector< int > test{9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << missingNumber2(test) << std::endl;
    return 0;
}
