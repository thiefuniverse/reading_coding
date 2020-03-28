#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector< vector< int > > insert(vector< vector< int > > &intervals, vector< int > &newinterval) {
    intervals.push_back(newinterval);
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

vector< vector< int > > insert2(vector< vector< int > > &intervals, vector< int > &newinterval) {
    vector< vector< int > > result;
    vector< int > mergeInterval = newinterval;
    bool mergeDone = false;
    for (int i = 0; i < intervals.size(); ++i) {
        if (intervals[i][1] < mergeInterval[0]) {
            result.push_back(intervals[i]);
        } else if (intervals[i][0] <= mergeInterval[0] && intervals[i][1] <= mergeInterval[1]) {
            mergeInterval = {intervals[i][0], mergeInterval[1]};
        } else if (intervals[i][0] > mergeInterval[0] && intervals[i][1] <= mergeInterval[1]) {
            continue;
        } else if (intervals[i][0] > mergeInterval[0] && intervals[i][1] > mergeInterval[1] && intervals[i][0] <= mergeInterval[1]) {
            mergeInterval = {mergeInterval[0], intervals[i][1]};
        } else if (intervals[i][0] > mergeInterval[1]) {
            if (!mergeDone) {
                result.push_back(mergeInterval);
                mergeDone = true;
            }
            result.push_back(intervals[i]);
        } else if (intervals[i][0] <= mergeInterval[0] && intervals[i][1] >= mergeInterval[1]) {
            mergeDone = true;
            result.push_back(intervals[i]);
        }
    }
    if (!mergeDone) {
        result.push_back(mergeInterval);
    }
    return result;
}

int main() {
    vector< vector< int > > tt{{1, 2}, {3, 5}, {8, 10}, {12, 16}};
    vector< vector< int > > tt1{{2, 13}, {2, 6}, {1, 6}, {8, 10}, {15, 18}};
    vector< int > newInterval{4, 8};
    auto res = insert2(tt, newInterval);
    for (auto &m : res) {
        for (auto &n : m) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
