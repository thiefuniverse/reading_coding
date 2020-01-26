#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector< int > &nums, int val) {
    int flag = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[flag] = nums[i];
            flag++;
        }
    }
    nums.resize(flag);
    return nums.size();
}
// slower.
int removeElement2(vector< int > &nums, int val) {
    int flag = 0;
    int s = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[flag] = nums[i];
            flag++;
        } else {
            s--;
        }
    }
    return s;
}

int main() {
    vector< vector< int > > t{{}, {3, 2, 2, 3}, {0, 1, 2, 2, 3, 0, 4, 2}};
    for (auto &tt : t) {
        cout << "after remove len:" << removeElement2(tt, 2) << std::endl;

        for (auto &e : tt) {
            cout << " " << e;
        }
        std::cout << std::endl;
    }
    return 0;
}
