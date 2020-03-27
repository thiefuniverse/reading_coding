#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< vector< int > > generate(int numRows) {
    if (numRows <= 0) {
        return {};
    }
    vector< vector< int > > result;
    for (int i = 1; i <= numRows; ++i) {
        result.push_back(vector< int >(i, 0));
    }
    // get init line
    result[0][0] = 1;
    for (int i = 1; i < numRows; ++i) {
        for (int j = 0; j <= i; ++j) {
            int left = j - 1 >= 0 ? result[i - 1][j - 1] : 0;
            int right = j <= i - 1 ? result[i - 1][j] : 0;
            result[i][j] = left + right;
        }
    }
    return result;
}
int main() {
    auto res = generate(5);
    for (auto &rr : res) {
        for (auto &r : rr) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
