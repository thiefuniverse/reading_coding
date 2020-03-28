#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int findPoisonedDuration(vector< int > &timeSeries, int duration) {
    if (timeSeries.empty()) {
        return 0;
    }
    int len = timeSeries.size();
    int result = 0;
    for (int i = 1; i < len; ++i) {
        int interval = timeSeries[i] - timeSeries[i - 1];
        if (interval >= duration) {
            result += duration;
        } else {
            result += interval;
        }
    }
    result += duration;
    return result;
}

int main() {
    vector< vector< int > > tt{{1, 4}, {1, 2}};
    for (auto &t : tt) {
        std::cout << findPoisonedDuration(t, 2) << std::endl;
    }
    return 0;
}
