#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int maxDistToClosest(vector< int > &seats) {
    if (seats.empty()) {
        return 0;
    }
    int maxDis = INT_MIN;
    int curDis = 0;
    bool isFirst = true;
    int spStartResult = INT_MIN;

    for (int i = 0; i < seats.size(); i++) {
        if (seats[i]) {
            if (curDis != 0) {
                if (isFirst) {
                    spStartResult = curDis;
                    isFirst = false;
                }
                maxDis = max(maxDis, curDis);
                curDis = 0;
            }
        } else {
            curDis++;
        }
    }
    int spEndResult = INT_MIN;
    if (seats[seats.size() - 1] == 0) {
        spEndResult = curDis;
    }
    if (seats[0] != 0) {
        spStartResult = INT_MIN;
    }
    maxDis = max(maxDis, curDis);
    if (maxDis == 0) {
        return 0;
    }
    int result = 0;
    if (maxDis % 2 == 1) {
        result = maxDis / 2 + 1;
    } else {
        result = maxDis / 2;
    }
    return max({result, spEndResult, spStartResult});
}

// clear solution
int maxDistToClosest2(vector< int > &seats) {
    int res = 0, last = -1, n = seats.size();
    for (int i = 0; i < n; i++) {
        if (seats[i] == 1) {
            res = last < 0 ? i : max(res, (i - last) / 2);
            last = i;
        }
    }
    res = max(res, n - last - 1);
    return res;
}
int main() {
    vector< vector< int > > tt{{1, 0, 0, 0, 1, 0, 1}, {1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 1, 1, 1}, {0, 0, 1, 0, 0, 1}};
    for (auto &t : tt) {
        std::cout << maxDistToClosest(t) << std::endl;
    }
    return 0;
}
