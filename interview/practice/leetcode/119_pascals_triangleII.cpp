#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< int > generate(int numRows) {
    vector< int > result(numRows + 1);
    // get init line
    result[0] = 1;
    for (int i = 1; i < numRows + 1; ++i) {
        int oldLeft = -1;
        for (int j = 0; j <= i; ++j) {
            int left = j - 1 >= 0 ? oldLeft : 0;
            int right = j <= i - 1 ? result[j] : 0;
            oldLeft = result[j];
            result[j] = left + right;
        }
    }
    return result;
}
int main() {
    auto res = generate(3);
    for (auto &rr : res) {
        std::cout << rr << " ";
    }
    return 0;
}
