#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector< vector< int > > dp(m + 1, vector< int >(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = word1[i - 1] + dp[i - 1][0];
    }
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = word2[j - 1] + dp[0][j - 1];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j] + word1[i - 1], dp[i][j - 1] + word2[j - 1]});
            }
        }
    }
    return dp[m][n];
}
int main() {
    std::cout << minDistance("delete", "leet") << std::endl;
    std::cout << minDistance("intention", "execution") << std::endl;
    std::cout << minDistance("sea", "eat") << std::endl;

    return 0;
}
