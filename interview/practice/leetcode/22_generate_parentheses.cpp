
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
void stringstatic(string &s, int &l, int &r) {
    l = 0;
    r = 0;
    for (auto &c : s) {
        if (c == '(') {
            l++;
        } else {
            r++;
        }
    }
}
vector<string> generateParenthesis(int n) {
    if (n == 0) {
        return {};
    }
    vector<string> result;
    result.push_back("");
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int len = result.size();
        for (int j = 0; j < len; j++) {
            string cur = result[j];
            string cur2 = result[j];
            stringstatic(cur, l, r);
            // can put (
            cur += '(';
            if (i == n - 1) {
                string tmp(n - r, ')');
                cur += tmp;
            }
            result[j] = cur;

            // can put )
            int m = l - r;
            for (int k = 0; k < m; k++) {
                string tmp(k + 1, ')');
                if (i == n - 1) {
                    string tmp2(n - r - k - 1, ')');
                    result.push_back(cur2 + tmp + '(' + tmp2);
                } else {
                    result.push_back(cur2 + tmp + '(');
                }
            }
        }
    }
    return result;
}

// version 2: recursion
void generateHelper(vector<string> &result, string cur, int open, int close, int n) {
    if (open == n && close == n) {
        result.push_back(cur);
    }
    if (open < n && open >= close) {
        generateHelper(result, cur + '(', open + 1, close, n);
    }
    if (close < n && open >= close) {
        generateHelper(result, cur + ')', open, close + 1, n);
    }
}
vector<string> generateParenthesis2(int n) {
    vector<string> result;
    generateHelper(result, "", 0, 0, n);
    return result;
}

int main() {
    auto tt = generateParenthesis2(3);
    for (auto &t : tt) {
        std::cout << t << std::endl;
    }
    return 0;
}
