#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool findNumberIn2DArray(vector< vector< int > > &matrix, int target) {
    int h = matrix.size();
    if (h == 0) {
        return false;
    }
    int w = matrix[0].size();
    int i = 0, j = w - 1;
    while (i >= 0 && i <= h - 1 && j >= 0 && j <= w - 1) {
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] > target) {
            --j;
        } else if (matrix[i][j] < target) {
            ++i;
        }
    }
    return false;
}
int main() {

    return 0;
}
