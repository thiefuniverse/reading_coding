#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int distinctSubseqII(string S) {
    if (S.empty()) {
        return 0;
    }
    int len = S.size();
    unordered_map< char, int > record;
    vector< int > dp(len + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= len; ++i) {
        int duplicate = 0;
        if (record.find(S[i - 1]) != record.end()) {
            duplicate = dp[record[S[i - 1]] - 1];
        }
        dp[i] = 2 * dp[i - 1] - duplicate;
        record[S[i - 1]] = i;
    }
    return (dp[len] - 1) % 1000000007;
}
int main() {
    std::cout << distinctSubseqII("abc") << std::endl;
    std::cout << distinctSubseqII("aba") << std::endl;
    std::cout << distinctSubseqII("aaa") << std::endl;

    return 0;
}
