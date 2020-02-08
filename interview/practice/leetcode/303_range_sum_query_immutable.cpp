#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector< int > &nums) {
        nums_ = nums;
    }

    int sumRange(int i, int j) {
        if (cache_results_.find(i) != cache_results_.end()) {

            if (cache_results_[i].find(j) != cache_results_[i].end()) {
                return cache_results_[i][j];
            }
        }
        int result = 0;
        for (int m = i; m <= j; m++) {
            result += nums_[m];
        }
        cache_results_[i][j] = result;
        return result;
    }

private:
    // this cache will increase unlimitedly. :(, bad.
    unordered_map< int, unordered_map< int, int > > cache_results_;
    vector< int > nums_;
};

class NumArray2 {
public:
    NumArray2(vector< int > &nums) {
        nums_ = nums;
        cache_results_ = vector< vector< int > >(nums.size(), vector< int >(nums.size(), INT_MIN));
    }

    int sumRange(int i, int j) {
        int result = 0;
        if (cache_results_[i][j] != INT_MIN) {
            return cache_results_[i][j];
        }
        for (int m = i; m <= j; m++) {
            result += nums_[m];
        }
        cache_results_[i][j] = result;
        return result;
    }

private:
    vector< vector< int > > cache_results_;
    vector< int > nums_;
};

// fast, quickly.
class NumArray3 {
public:
    NumArray3(vector< int > &nums) {
        nums_ = nums;
        sums_ = nums;
        for (int i = 1; i < nums.size(); i++) {
            sums_[i] = sums_[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (j == i) {
            return nums_[i];
        }
        return sums_[j] - sums_[i] + nums_[i];
    }

private:
    vector< int > sums_, nums_;
};

int main() {

    vector< int > tt{-2, 0, 3, -5, 2, -1};
    NumArray3 n(tt);
    std::cout << n.sumRange(0, 2) << std::endl;
    std::cout << n.sumRange(2, 5) << std::endl;
    std::cout << n.sumRange(0, 5) << std::endl;
    return 0;
}
