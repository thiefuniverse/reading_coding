#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    int a0 = 0, a1 = 1;
    int a2 = 0;
    for (int i = 2; i <= n; ++i) {
        a2 = a1 + a0;
        a2 %= 1000000007;
        a0 = a1;
        a1 = a2;
    }
    return a2;
}
int main() {

    return 0;
}
