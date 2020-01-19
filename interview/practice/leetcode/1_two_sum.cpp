#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

vector< int > twoSum1(vector< int > &nums, int target) {
    map< int, vector< int > > nums_map;
    for (int i = 0; i < nums.size(); i++) {
        if (nums_map.find(nums[i]) != nums_map.end()) {
            nums_map[nums[i]].push_back(i);
        } else {
            nums_map[nums[i]] = std::vector< int >{i};
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums_map.find(target - nums[i]) != nums_map.end()) {
            //            cout << i << " " << nums[i] << std::endl;
            if (target == 2 * nums[i]) {
                if (nums_map[nums[i]].size() >= 2) {
                    return vector< int >{nums_map[nums[i]][0], nums_map[nums[i]][1]};
                }
            } else {
                int one_index = nums_map[target - nums[i]][0];
                int another_index = nums_map[nums[i]][0];
                return one_index > another_index ? vector< int >{another_index, one_index} : vector< int >{one_index, another_index};
            }
        }
    }
    return {0, 0};
}

vector< int > twoSum2(vector< int > &nums, int target) {
    unordered_map< int, int > nums_map;
    unordered_map< int, int > nums_double_map;
    int n_size = nums.size();
    for (int i = 0; i < n_size; i++) {
        if (nums_map.find(nums[i]) != nums_map.end()) {
            nums_double_map[nums[i]] = i;
        } else {
            nums_map[nums[i]] = i;
        }
    }
    for (int i = 0; i < n_size; i++) {
        if (nums_map.find(target - nums[i]) != nums_map.end()) {
            //            cout << i << " " << nums[i] << std::endl;
            int one_index = 0;
            int another_index = 0;
            if (target == 2 * nums[i]) {
                one_index = nums_map[target - nums[i]];
                if (nums_double_map.find(nums[i]) != nums_double_map.end()) {
                    another_index = nums_double_map[nums[i]];
                } else {
                    continue;
                }
            } else {
                one_index = nums_map[target - nums[i]];
                another_index = nums_map[nums[i]];
            }
            return one_index > another_index ? vector< int >{another_index, one_index} : vector< int >{one_index, another_index};
        }
    }
    return {0, 0};
}
vector< int > twoSum3(vector< int > &nums, int target) {
    unordered_map< int, pair< int, int > > nums_map;
    int n_size = nums.size();
    for (int i = 0; i < n_size; i++) {
        if (nums_map.find(nums[i]) != nums_map.end()) {
            nums_map[nums[i]].second = i;
        } else {
            nums_map[nums[i]] = make_pair(i, INT_MAX);
        }
    }
    for (int i = 0; i < n_size; i++) {
        if (nums_map.find(target - nums[i]) != nums_map.end()) {
            //            cout << i << " " << nums[i] << std::endl;
            int one_index = 0;
            int another_index = 0;
            if (target == 2 * nums[i]) {
                one_index = nums_map[target - nums[i]].first;
                another_index = nums_map[nums[i]].second;
                if (another_index == INT_MAX) {
                    continue;
                }
            } else {
                one_index = nums_map[target - nums[i]].first;
                another_index = nums_map[nums[i]].first;
            }
            return one_index > another_index ? vector< int >{another_index, one_index} : vector< int >{one_index, another_index};
        }
    }
    return {0, 0};
}

// twoSum2 is better: 8ms, 10.4MB

// twoSum4 is best. :) steal from others. 4ms, 10.1MB.
vector< int > twoSum4(vector< int > &nums, int target) {
    unordered_map< int, int > nums_map;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = nums_map.find(target - nums[i]);
        if (it != nums_map.end()) {
            return vector< int >{nums_map[target - nums[i]], i};
        }
        nums_map[nums[i]] = i;
    }
    return {0, 0};
}

int main() {
    // vector< int > t1 = {2, 7, 11, 15};
    vector< int > t1 = {3, 2, 4};
    // vector< int > target_list = {1, 9, 13, 18, 22, 27, 30, 13};
    vector< int > target_list = {6};
    for (int i = 0; i < target_list.size(); i++) {
        auto rs = twoSum4(t1, target_list[i]);
        std::cout << "target: " << target_list[i] << ": " << rs[0] << " " << rs[1] << std::endl;
    }
    return 0;
}
