#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void reverseString(vector< char > &s) {
    int len = s.size();
    if (len == 0) {
        return;
    }
    for (int left = 0, right = len - 1; left < right; left++, right--) {
        swap(s[left], s[right]);
    }
}

int main() {
    vector< vector< char > > t{{'t', 'h', 'i', 'e', 'f'}, {'u', 'n', 'i', 'v', 'e', 'r', 's', 'e'}, {'t'}};
    for (auto &tt : t) {
        reverseString(tt);
        for (auto &c : tt) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    return 0;
}
