#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) {
        return 0;
    }
    int n = grid[0].size();
    if (n == 0) {
        return 0;
    }
    for (int i = 1; i < n; i++) {
        grid[0][i] += grid[0][i - 1];
    }
    for (int i = 1; i < m; i++) {
        grid[i][0] += grid[i - 1][0];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[m - 1][n - 1];
}
int minPathSum2(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) {
        return 0;
    }
    int n = grid[0].size();
    if (n == 0) {
        return 0;
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                dp[j] += grid[i][j];
            } else {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
    }
    return dp[n - 1];
}

int main() {
    vector<vector<int>> g{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    std::cout << minPathSum2(g) << std::endl;
    return 0;
}
