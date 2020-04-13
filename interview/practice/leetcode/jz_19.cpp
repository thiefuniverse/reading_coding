#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    int sl = s.size();
    int pl = p.size();
    vector< vector< bool > > dp(s.size() + 1, vector< bool >(p.size() + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= sl; ++i) {
        for (int j = 1; j <= pl; ++j) {
            // not *
            if (p[j - 1] != '*') {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            } else {
                std::cout << "*i: " << i << " j:" << j << std::endl;
                if (i - 1 >= 0 && j - 2 >= 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j - 3 >= 0) {
                    dp[i][j] = dp[i][j] || dp[i][j - 3];
                }
            }
        }
    }
    return dp[sl][pl];
}
int main() {
    //    std::cout << isMatch("aab", ".ab*") << std::endl;
    std::cout << isMatch("aa", "a*") << std::endl;

    return 0;
}
