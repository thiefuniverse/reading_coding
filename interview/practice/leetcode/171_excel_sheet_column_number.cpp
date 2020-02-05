#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int titleToNumber(string s) {
    int result = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        result *= 26;
        result += (*it - 'A' + 1);
    }
    return result;
}

int main() {
    std::cout << titleToNumber("A") << std::endl;
    std::cout << titleToNumber("AA") << std::endl;
    std::cout << titleToNumber("AB") << std::endl;
    std::cout << titleToNumber("ZY") << std::endl;
    return 0;
}
