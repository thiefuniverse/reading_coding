#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int uniquePathsWithObstacles(vector< vector< int > > &obstacleGrid) {
    int m = obstacleGrid.size();
    if (m == 0) {
        return 0;
    }
    int n = obstacleGrid[0].size();
    if (n == 0) {
        return 0;
    }
    vector< vector< int > > dp(m, vector< int >(n, 0));
    int current_paths = 1;
    for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] == 1) {
            current_paths = 0;
        } else {
            dp[0][i] = current_paths;
        }
    }
    current_paths = 1;
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1) {
            current_paths = 0;
        } else {
            dp[i][0] = current_paths;
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (obstacleGrid[i - 1][j] == 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (obstacleGrid[i][j - 1] == 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    vector< vector< int > > tt{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector< vector< int > > tt2{{0, 0}};
    std::cout << uniquePathsWithObstacles(tt2) << std::endl;
    return 0;
}
