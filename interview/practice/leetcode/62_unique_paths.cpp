#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int uniquePaths(int m, int n) {
    if (m * n == 0) {
        return 0;
    }
    vector< vector< int > > dp(m, vector< int >(n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

// version2
int uniquePaths2(int m, int n) {
    if (m * n == 0) {
        return 0;
    }
    vector< int > dp(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[n - 1];
}

int main() {

    std::cout << uniquePaths(3, 2) << std::endl;
    std::cout << uniquePaths2(3, 2) << std::endl;
    std::cout << uniquePaths(7, 9) << std::endl;
    std::cout << uniquePaths2(7, 9) << std::endl;
    return 0;
}
