#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector< vector< int > > merge(vector< vector< int > > &intervals) {
    if (intervals.empty()) {
        return {};
    }
    // sort
    std::sort(intervals.begin(), intervals.end(), [](vector< int > &a, vector< int > &b) { return a[0] < b[0]; });

    vector< vector< int > > result;
    vector< int > last_area = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] > last_area[1]) {
            result.push_back(last_area);
            last_area = intervals[i];
        } else {
            if (intervals[i][1] > last_area[1]) {
                last_area = {min(intervals[i][0], last_area[0]), intervals[i][1]};
            }
        }
    }
    result.push_back(last_area);
    return result;
}

int main() {
    vector< vector< int > > tt{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector< vector< int > > tt1{{2, 13}, {2, 6}, {1, 6}, {8, 10}, {15, 18}};
    vector< vector< int > > tt2(10000, vector< int >{4, 5});
    auto res = merge(tt2);
    std::cout << "-----" << std::endl;
    for (auto &m : res) {
        for (auto &n : m) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
