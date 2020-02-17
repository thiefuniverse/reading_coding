
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< int > sumZero(int n) {
    vector< int > result;
    if (n % 2 != 0) {
        result.push_back(0);
    }
    int m = n / 2;
    for (int i = 1; i <= m; i++) {
        result.push_back(-i);
        result.push_back(i);
    }
    return result;
}

int main() {

    return 0;
}
