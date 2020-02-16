#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int maximumProduct(vector< int > &nums) {
    if (nums.size() < 3) {
        return 0;
    }
    int min_down_2[2] = {INT_MAX, INT_MAX};
    int max_down_2[2] = {INT_MAX, INT_MAX};
    int min_3[3] = {INT_MIN, INT_MIN, INT_MIN};
    int max_3[3] = {INT_MIN, INT_MIN, INT_MIN};
    int pos_counter = 0, neg_counter = 0;
    int zero_counter = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            pos_counter++;
            if (nums[i] >= max_3[0]) {
                max_3[2] = max_3[1];
                max_3[1] = max_3[0];
                max_3[0] = nums[i];
            } else if (nums[i] >= max_3[1]) {
                max_3[2] = max_3[1];
                max_3[1] = nums[i];
            } else if (nums[i] > max_3[2]) {
                max_3[2] = nums[i];
            }

            if (nums[i] <= max_down_2[0]) {
                max_down_2[1] = max_down_2[0];
                max_down_2[0] = nums[i];
            } else if (nums[i] < max_down_2[1]) {
                max_down_2[1] = nums[i];
            }
        } else if (nums[i] == 0) {
            zero_counter++;
        } else {
            neg_counter++;
            if (nums[i] >= min_3[0]) {
                min_3[2] = min_3[1];
                min_3[1] = min_3[0];
                min_3[0] = nums[i];
            } else if (nums[i] >= min_3[1]) {
                min_3[2] = min_3[1];
                min_3[1] = nums[i];
            } else if (nums[i] > min_3[2]) {
                min_3[2] = nums[i];
            }

            if (nums[i] <= min_down_2[0]) {
                min_down_2[1] = min_down_2[0];
                min_down_2[0] = nums[i];
            } else if (nums[i] < min_down_2[1]) {
                min_down_2[1] = nums[i];
            }
        }
    }
    vector< int > result(4, INT_MIN);
    if (pos_counter >= 3) {
        result[0] = max_3[0] * max_3[1] * max_3[2];
    }
    if (pos_counter >= 2 && neg_counter >= 1) {
        result[1] = max_down_2[0] * max_down_2[1] * min_3[0];
    }
    if (pos_counter >= 1 && neg_counter >= 2) {
        result[2] = max_3[0] * min_down_2[0] * min_down_2[1];
    }
    if (neg_counter >= 3) {
        result[3] = min_3[0] * min_3[1] * min_3[2];
    }
    auto me = max_element(result.begin(), result.end());
    if (*me == INT_MIN) {
        return 0;
    } else {
        return *me;
    }
}

// hummmm.... :), very cool....
int maximumProduct2(vector< int > &nums) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for (int n : nums) {
        if (n > max1) {
            max3 = max2;
            max2 = max1;
            max1 = n;
        } else if (n > max2) {
            max3 = max2;
            max2 = n;
        } else if (n > max3) {
            max3 = n;
        }

        if (n < min1) {
            min2 = min1;
            min1 = n;
        } else if (n < min2) {
            min2 = n;
        }
    }
    std::cout << "ma1:" << max1 << std::endl;
    std::cout << "ma2:" << max2 << std::endl;
    std::cout << "ma3:" << max3 << std::endl;
    std::cout << "mi1:" << min1 << std::endl;
    std::cout << "mi2:" << min2 << std::endl;

    return max(max1 * max2 * max3, max1 * min1 * min2);
}
int main() {
    vector< vector< int > > tt{{3, -1, 6, 7, 5}, {1, 2, 3}, {1, 2, 3, 4}, {2, 4, -5, -6, 9, 0, 2, -40}, {-1, -2, -3, -4}};
    for (auto &t : tt) {
        std::cout << maximumProduct(t) << std::endl;
        std::cout << maximumProduct2(t) << std::endl;
    }
    return 0;
}
