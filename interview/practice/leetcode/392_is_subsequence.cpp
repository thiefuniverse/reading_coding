#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// my original solution
bool isSubsequence(string s, string t) {
    if (s.empty()) {
        return true;
    }
    int flag = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == s[flag]) {
            flag++;
            if (flag == s.size()) {
                return true;
            }
        }
    }
    return false;
}

// steal from leetcode, cool code :)
bool isSubsequence2(string s, string t) {
    vector< vector< int > > all_chars(26);
    for (int i = 0; i < t.size(); i++) {
        all_chars[t[i] - 'a'].push_back(i);
    }

    int index = -1;
    for (int j = 0; j < s.size(); j++) {
        auto &char_vector = all_chars[s[j] - 'a'];
        auto it = upper_bound(char_vector.begin(), char_vector.end(), index);
        if (it == char_vector.end()) {
            return false;
        }
        index = *it;
    }
    return true;
}
int main() {
    std::cout << isSubsequence2("abc", "ahbgdc") << std::endl;
    std::cout << isSubsequence2("axc", "ahbgdc") << std::endl;
    std::cout << isSubsequence2("", "ahbgdc") << std::endl;
    std::cout << isSubsequence2("thief", "") << std::endl;
    return 0;
}
