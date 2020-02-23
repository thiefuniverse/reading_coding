#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int fib(int N) {
    if (N == 0) {
        return 0;
    }
    if (N == 1) {
        return 1;
    }
    int a1 = 0, a2 = 1;
    int a3 = 0;
    for (int i = 2; i <= N; i++) {
        a3 = a2 + a1;
        a1 = a2;
        a2 = a3;
    }
    return a3;
}
int main() {
    std::cout << fib(4) << std::endl;
    return 0;
}
