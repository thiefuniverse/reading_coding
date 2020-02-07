#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int maxProfit(vector< int > &prices) {
    int cur_min = INT_MAX, max_profit = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] > cur_min) {
            max_profit = max(max_profit, prices[i] - cur_min);
        }
        cur_min = min(cur_min, prices[i]);
    }
    return max_profit;
}
int main() {

    vector< vector< int > > tt{{7, 1, 5, 3, 6, 4}, {7, 6, 4, 3, 1}, {}, {3, 4}, {5}};
    for (auto &t : tt) {
        std::cout << maxProfit(t) << std::endl;
    }
    return 0;
}
