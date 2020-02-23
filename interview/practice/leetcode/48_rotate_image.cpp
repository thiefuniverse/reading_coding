#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
void rotate(vector< vector< int > > &matrix) {
    int n = matrix.size();
    int xIndex = n / 2 - 1;
    int yIndex = n / 2 - 1;
    if (n % 2) {
        xIndex++;
    }
    for (int x = 0; x <= xIndex; x++) {
        for (int y = 0; y <= yIndex; y++) {
            int newX = x, newY = y;
            int newVal = matrix[x][y];
            int oldX = 0, oldY = 0, oldVal = 0;
            for (int k = 0; k < 4; k++) {
                oldY = n - newX - 1;
                oldX = newY;
                oldVal = matrix[oldX][oldY];
                matrix[oldX][oldY] = newVal;
                newVal = oldVal;
                newY = oldY;
                newX = oldX;
            }
        }
    }
}

// reverse and swap symmetry
void rotate2(vector< vector< int > > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix.size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
int main() {
    vector< vector< int > > tt{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (auto &k1 : tt) {
        for (auto &k2 : k1) {
            std::cout << k2 << " ";
        }
        std::cout << std::endl;
    }
    rotate2(tt);
    for (auto &k1 : tt) {
        for (auto &k2 : k1) {
            std::cout << k2 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
