#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector< int > printNumbers(int n) {
    int powN = pow(10, n);
    vector< int > result(powN - 1, 0);
    for (int i = 1; i < powN; ++i) {
        result[i - 1] = i;
    }
    return result;
}
int main() {

    return 0;
}
