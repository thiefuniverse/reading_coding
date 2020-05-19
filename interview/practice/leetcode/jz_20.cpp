#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
bool judgeP(string s) {
    bool result = false, point = false;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        if (s[i] == '+' || s[i] == '-') {
            if (i != 0) {
                return false;
            }
        } else if (s[i] == '.') {
            if (point) {
                return false;
            }
            point = true;
        } else if (s[i] < '0' || s[i] > '9') {
            return false;
        } else {
            result = true;
        }
    }
    return result;
}

bool judgeS(string s) {
    bool result = false;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        if (s[i] == '+' || s[i] == '-') {
            if (i != 0) {
                return false;
            }
        } else if (s[i] < '0' || s[i] > '9') {
            return false;
        } else {
            result = true;
        }
    }
    return result;
}

bool isNumber(string s) {
    if (s.empty()) {
        return false;
    }

    int i = s.find_first_not_of(' ');
    if (i == string::npos) {
        return false;
    }
    int j = s.find_last_not_of(' ');
    s = s.substr(i, j - i + 1);

    int e = s.find('e');
    if (e == string::npos) {
        return judgeP(s);
    } else {
        return judgeP(s.substr(0, e)) && judgeS(s.substr(e + 1));
    }
}

int main() {
    std::cout << isNumber("+4.567") << std::endl;
    std::cout << isNumber("+0004.567") << std::endl;
    return 0;
}
