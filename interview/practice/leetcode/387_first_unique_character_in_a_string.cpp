#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map< char, int > all;
    for (int i = 0; i < s.size(); i++) {
        all[s[i]]++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (all[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}
int firstUniqChar2(string s) {
    int char_count[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        char_count[s[i]]++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (char_count[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}
int firstUniqChar3(string s) {
    short char_count[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        char_count[s[i] - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (char_count[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}
int main() {
    cout << firstUniqChar2("leetcode") << std::endl;
    cout << firstUniqChar2("loveleetcode") << std::endl;
    cout << firstUniqChar2(" t ") << std::endl;
}
