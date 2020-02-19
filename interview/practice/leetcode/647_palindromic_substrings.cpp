#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int countSubstrings(string s) {
    int len = s.size();
    int result = 0;
    for (int i = 0; i < len; i++) {
        int j = 0;
        while (j <= i && i + j < len) {
            if (s[i - j] == s[i + j]) {
                result++;
            } else {
                break;
            }
            j++;
        }
    }
    for (int i = 0; i + 1 < len; i++) {
        int j = 0;
        while (j <= i && i + 1 + j < len) {
            if (s[i - j] == s[i + 1 + j]) {
                result++;
            } else {
                break;
            }
            j++;
        }
    }
    return result;
}

// version 2: optimize code
int countSubstrings(string s) {
    int len = s.size();
    int result = 0;
    for (int i = 0; i < len; i++) {
        int j = 0;
        // for a, bab, cbabc
        while (j <= i && i + j < len) {
            if (s[i - j] == s[i + j]) {
                result++;
            } else {
                break;
            }
            j++;
        }
        // for  ab, aabb, caabbc
        while (i + 1 < len && j <= i && i + 1 + j < len) {
            if (s[i - j] == s[i + 1 + j]) {
                result++;
            } else {
                break;
            }
            j++;
        }
    }
    return result;
}

int main() {
    std::cout << countSubstrings("abc") << std::endl;
    std::cout << countSubstrings("aaa") << std::endl;

    return 0;
}
