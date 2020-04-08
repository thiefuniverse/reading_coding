#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int numDistinct(string s, string t) {
    int m = t.size();
    int n = s.size();
    vector< vector< int > > dp(m + 1, vector< int >(n + 1, 0));
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

// optimize memory
int numDistinct2(string s, string t) {
    int m = t.size();
    int n = s.size();
    vector< int > dp(n + 1, 1);
    for (int i = 1; i <= m; ++i) {
        auto last = dp[0];
        dp[0] = 0;
        for (int j = 1; j <= n; ++j) {
            int olddp = dp[j];
            if (t[i - 1] == s[j - 1]) {
                dp[j] = last + dp[j - 1];
            } else {
                dp[j] = dp[j - 1];
            }
            last = olddp;
        }
    }
    return dp[n];
}
int main() {

    std::cout << numDistinct2("rabbbit", "rabbit") << std::endl;
    std::cout << numDistinct2("babgbag", "bag") << std::endl;

    return 0;
}
