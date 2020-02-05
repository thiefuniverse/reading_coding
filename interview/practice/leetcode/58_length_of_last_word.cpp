#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// from start
int lengthOfLastWord(string s) {
    int result_len = 0, len = 0;
    for (auto &c : s) {
        if (c == ' ') {
            if (len != 0) {
                result_len = len;
                len = 0;
            }
        } else {
            len++;
        }
    }
    if (len != 0) {
        result_len = len;
    }
    return result_len;
}
// from last
int lengthOfLastWord2(string s) {
    int result_len = 0, len = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            if (len != 0) {
                result_len = len;
                break;
            }
        } else {
            len++;
        }
    }
    if (len != 0) {
        result_len = len;
    }
    return result_len;
}
int main() {
    vector< string > t{"hello world", "   hello wor", "   ", "hello   ", "   hell    ", "w o r l  d "};
    for (auto &tt : t) {
        std::cout << lengthOfLastWord2(tt) << std::endl;
    }
    return 0;
}
