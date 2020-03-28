#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// can't pass, two slow
double myPow(double x, int n) {
    if (x == 0) {
        return 0;
    }
    double onex = x;
    long long nl = n;
    if (n < 0) {
        onex = 1 / onex;
        nl = -nl;
    }
    double result = 1;
    while (nl > 0) {
        result = result * onex;
        --nl;
    }
    return result;
}

// recursion
double myPowHelper(double x, long n) {
    if (n == 0) {
        return 1;
    }
    double half = myPowHelper(x, n / 2);
    if (n % 2) {
        return half * half * x;
    } else {
        return half * half;
    }
}
double myPow2(double x, int n) {
    if (x == 0) {
        return 0;
    }
    double onex = x;
    long nl = n;
    if (n < 0) {
        onex = 1 / onex;
        nl = -nl;
    }
    return myPowHelper(onex, nl);
}

double myPow3(double x, int n) {
    if (x == 0) {
        return 0;
    }
    double onex = x;
    long nl = n;
    double result = 1;
    if (n < 0) {
        onex = 1 / onex;
        nl = -nl;
    }
    double current_product = onex;
    for (int i = nl; i; i /= 2) {
        if (i % 2 == 1) {
            result *= current_product;
        }
        current_product *= current_product;
    }
    return result;
}

int main() {
    std::cout << myPow(2, 10) << std::endl;
    std::cout << myPow2(1, INT_MAX) << std::endl;
    std::cout << myPow3(2, 3) << std::endl;
    return 0;
}
