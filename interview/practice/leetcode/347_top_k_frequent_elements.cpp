#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// bucket sort
vector< int > topKFrequent(vector< int > &nums, int k) {
    int len = nums.size();
    vector< vector< int > > buckets(len);
    unordered_map< int, int > store;
    for (auto &i : nums) {
        store[i]++;
    }
    for (auto &key : store) {
        buckets[key.second - 1].push_back(key.first);
    }
    vector< int > result;
    int flag = 0;
    for (int j = len - 1; j >= 0; j--) {
        for (auto &r : buckets[j]) {
            flag++;
            result.push_back(r);
            if (flag == k) {
                return result;
            }
        }
    }
    return result;
}

// use max heap
vector< int > topKFrequent2(vector< int > &nums, int k) {
    unordered_map< int, int > store;
    unordered_map< int, bool > store_key;

    unordered_map< int, vector< int > > freq2val;
    for (auto &i : nums) {
        store[i]++;
    }
    for (auto &key : store) {
        freq2val[key.second].push_back(key.first);
        store_key[key.second] = true;
    }
    priority_queue< int > max_k;
    for (auto &key : store_key) {
        max_k.push(key.first);
    }
    vector< int > result;
    while (!max_k.empty()) {
        auto freq = max_k.top();
        max_k.pop();
        for (auto &val : freq2val[freq]) {
            result.push_back(val);
            if (result.size() == k) {
                return result;
            }
        }
    }
    return result;
}
int main() {
    vector< vector< int > > tt{{3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6}, {5, 3, 1, 1, 1, 3, 5, 73, 1}, {1, 1, 1, 2, 2, 3}, {1}};
    for (auto &t : tt) {
        auto res = topKFrequent2(t, 10);
        for (auto &r : res) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
