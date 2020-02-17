#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// O(n) time, O(n) space.
vector< int > productExceptSelf(vector< int > &nums) {
    int len = nums.size();
    if (len <= 1) {
        return {};
    }
    vector< int > left(len), right(len);
    int left_pro = 1, right_pro = 1;
    for (int i = 0; i < len; i++) {
        left_pro = left_pro * nums[i];
        left[i] = left_pro;
        right_pro = right_pro * nums[len - i - 1];
        right[len - i - 1] = right_pro;
    }
    vector< int > result(len);
    result[0] = right[1];
    result[len - 1] = left[len - 2];
    for (int i = 1; i < len - 1; i++) {
        result[i] = left[i - 1] * right[i + 1];
    }
    return result;
}

// well :)
vector< int > productExceptSelf2(vector< int > &nums) {
    int len = nums.size();
    if (len <= 1) {
        return {};
    }
    vector< int > result(len);
    int left_pro = 1, right_pro = 1;
    for (int i = 0; i < len; i++) {
        left_pro = left_pro * nums[i];
        result[i] = left_pro;
    }
    for (int i = len - 1; i >= 1; i--) {
        result[i] = right_pro * result[i - 1];
        right_pro = right_pro * nums[i];
    }
    result[0] = right_pro;
    return result;
}

int main() {
    vector< vector< int > > tt{{1, 2, 3, 4}, {3, 4, 5, 6, 0}, {2, 4, 6, -1}, {34, 0, 0, 5, 6, 7, 8, 23}};
    for (auto &t : tt) {
        auto res = productExceptSelf2(t);
        for (auto &r : res) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
