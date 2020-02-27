#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void sortColors(vector< int > &nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int &i : nums) {
        if (i == 0) {
            count0++;
        } else if (i == 1) {
            count1++;
        } else {
            count2++;
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        if (count0 > 0) {

            nums[i] = 0;
            count0--;
        } else if (count1 > 0) {
            nums[i] = 1;
            count1--;
        } else {
            nums[i] = 2;
            count2--;
        }
    }
}

void sortColors2(vector< int > &nums) {
    int len = nums.size();
    int start1 = -1, start2 = -1, left = 0;
    int right = len - 1;
    int last1 = -1;
    for (int i = 0; i <= right; i++) {
        if (nums[i] == 0) {
            swap(nums[left], nums[i]);
            left++;
        } else if (nums[i] == 2) {
            swap(nums[i], nums[right]);
            i--;
            right--;
        }
    }
}
int main() {
    vector< vector< int > > tt{{2, 0, 2, 1, 1, 0}, {2, 0}, {2, 1, 0, 0}, {0, 2}, {1, 2}, {1, 2, 2, 1, 2}, {2, 1, 2}};
    for (auto &t : tt) {
        sortColors2(t);
        for (auto &m : t) {
            std::cout << m << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
