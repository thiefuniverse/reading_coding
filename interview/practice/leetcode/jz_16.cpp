#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

double myPowHelper(double x, long n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2) {
        return x * myPowHelper(x, n - 1);
    }

    double xx = myPowHelper(x, n / 2);
    return xx * xx;
}

double myPow(double x, int n) {
    if (x == 0.0 || x == 1.0) {
        return x;
    }
    long rn = n;
    if (rn < 0) {
        rn = -rn;
        x = 1 / x;
    }
    return myPowHelper(x, rn);
}
int main() {

    return 0;
}
