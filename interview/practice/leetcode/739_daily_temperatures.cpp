#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    if (T.empty()) {
        return {};
    }
    vector<int> result(T.size(), 0);
    stack<int> s;
    s.push(0);
    for (int i = 1; i < T.size(); i++) {
        if (T[i] > T[i - 1]) {
            while (!s.empty()) {
                auto t = s.top();
                if (T[t] < T[i]) {
                    result[t] = i - t;
                    s.pop();
                } else {
                    break;
                }
            }
        }
        s.push(i);
    }
    while (!s.empty()) {
        auto t = s.top();
        result[t] = 0;
        s.pop();
    }
    return result;
}
int main() {
    vector<vector<int> > tt{{6, 7, 8, 1, 4, 8},      {4, 1, 2, 3},   {2}, {4, 2}, {1, 2},
                            {2, 6, 4, 8, 10, 9, 15}, {2, 3, 3, 2, 4}};
    for (auto& t : tt) {
        auto r = dailyTemperatures(t);
        for (auto& rr : r) {
            std::cout << rr << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
