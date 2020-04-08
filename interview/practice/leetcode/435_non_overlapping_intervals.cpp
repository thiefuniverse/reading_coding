#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int eraseOverlapIntervals(vector< vector< int > > &intervals) {
    if (intervals.empty()) {
        return {};
    }
    // sort
    std::sort(intervals.begin(), intervals.end(), [](vector< int > &a, vector< int > &b) { return a[1] < b[1]; });

    vector< int > last_area = intervals[0];
    int result = 0;
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < last_area[1]) {
            ++result;
        } else {
            last_area = intervals[i];
        }
    }
    return result;
}

int main() {
    vector< vector< int > > tt{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector< vector< int > > tt1{{2, 13}, {2, 6}, {1, 6}, {8, 10}, {15, 18}};
    vector< vector< int > > tt2(4, vector< int >{4, 5});
    std::cout << eraseOverlapIntervals(tt) << std::endl;
    std::cout << eraseOverlapIntervals(tt2) << std::endl;
    return 0;
}
