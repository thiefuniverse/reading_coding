#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isUnique(string astr) {
    sort(astr.begin(), astr.end());
    for (int i = 1; i < astr.size(); ++i) {
        if (astr[i] == astr[i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {

    std::cout << isUnique("") << std::endl;
    std::cout << isUnique("leetcode") << std::endl;
    std::cout << isUnique("abc") << std::endl;
    return 0;
}
