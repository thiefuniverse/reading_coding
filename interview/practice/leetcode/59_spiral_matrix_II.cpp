#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool checkOK(int x, int y, int l, int r, int t, int b) {
    if (x >= t && x <= b && y >= l && y <= r) {
        return true;
    } else {
        return false;
    }
}
vector< vector< int > > generateMatrix(int n) {
    if (n == 0) {
        return {};
    }
    vector< vector< int > > result(n, vector< int >(n));
    // bound
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    //  directions
    vector< pair< int, int > > directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // move
    int dire = 0;
    pair< int, int > sp = {0, 0};
    int counter = 1;
    result[sp.first][sp.second] = counter;
    while (true) {
        pair< int, int > nextsp = {sp.first + directions[dire].first, sp.second + directions[dire].second};
        if (checkOK(nextsp.first, nextsp.second, left, right, top, bottom)) {
            sp = nextsp;
        } else {
            if (counter == n * n) {
                break;
            }
            // change bound
            if (dire == 0) {
                ++top;
            } else if (dire == 1) {
                --right;
            } else if (dire == 2) {
                --bottom;
            } else {
                ++left;
            }
            // change direction
            ++dire;
            if (dire == 4) {
                dire = 0;
            }
            continue;
        }
        result[sp.first][sp.second] = ++counter;
    }
    return result;
}
int main() {
    auto res = generateMatrix(6);
    for (auto &r : res) {
        for (auto &rr : r) {

            std::cout << " " << rr;
        }
        std::cout << std::endl;
    }
    return 0;
}
