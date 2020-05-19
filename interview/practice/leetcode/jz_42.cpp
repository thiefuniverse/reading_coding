#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int maxSubArray(vector< int > &nums) {
    int result = INT_MIN, max_result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (max_result < 0) {
            max_result = nums[i];
        } else {
            max_result += nums[i];
        }
        result = max(result, max_result);
    }
    return result;
}

int main() {

    return 0;
}
