#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< int > spiralOrder(vector< vector< int > > &matrix) {
    int h = matrix.size();
    int w = 0;
    if (h > 0) {
        w = matrix[0].size();
    }
    vector< vector< int > > direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int l = 0, r = w - 1, t = 0, b = h - 1;
    int x = 0, y = 0;
    int dir_flag = 0;
    int all_size = w * h;
    vector< int > result;
    while (result.size() < all_size) {
        result.push_back(matrix[y][x]);
        y += direction[dir_flag][0];
        x += direction[dir_flag][1];

        if (!(y >= t && y <= b && x >= l && x <= r)) {
            if (dir_flag == 0) {
                ++t;
            } else if (dir_flag == 1) {
                --r;
            } else if (dir_flag == 2) {
                --b;
            } else if (dir_flag == 3) {
                ++l;
            }
            y -= direction[dir_flag][0];
            x -= direction[dir_flag][1];
            ++dir_flag;
            if (dir_flag == 4) {
                dir_flag = 0;
            }
            y += direction[dir_flag][0];
            x += direction[dir_flag][1];
        }
    }
    return result;
}
int main() {
    vector< vector< int > > tt{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    auto res = spiralOrder(tt);
    for (auto &r : res) {
        std::cout << r << " ";
    }
    return 0;
}
