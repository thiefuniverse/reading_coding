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
vector< int > spiralOrder(vector< vector< int > > &matrix) {
    if (matrix.empty()) {
        return {};
    }
    vector< int > result;
    int h = matrix.size();
    int w = 0;
    if (h > 0) {
        w = matrix[0].size();
    }

    // bound
    int left = 0, right = w - 1, top = 0, bottom = h - 1;
    //  directions
    vector< pair< int, int > > directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // move
    int dire = 0;
    pair< int, int > sp = {0, 0};

    result.push_back(matrix[sp.first][sp.second]);
    while (true) {
        pair< int, int > nextsp = {sp.first + directions[dire].first, sp.second + directions[dire].second};
        std::cout << "next:" << nextsp.first << " " << nextsp.second << std::endl;
        if (checkOK(nextsp.first, nextsp.second, left, right, top, bottom)) {
            sp = nextsp;
        } else {
            if (result.size() == w * h) {
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
        result.push_back(matrix[sp.first][sp.second]);
    }
    return result;
}
int main() {
    vector< vector< int > > tt{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = spiralOrder(tt);
    for (auto &r : res) {
        std::cout << " " << r;
        std::cout << std::endl;
    }
    return 0;
}
