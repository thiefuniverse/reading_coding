#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
bool judgePrime(int m) {
    int half_m = m / 2;
    for (int i = 2; i <= half_m; i++) {
        if (m % i == 0) {
            return false;
        }
    }
    return true;
}
int countPrimes(int n) {
    int result = 0;
    for (int i = 2; i < n; i++) {
        if (i > 7 && (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0)) {
            continue;
        }
        if (judgePrime(i)) {

            result++;
        }
    }
    return result;
}

int countPrimes2(int n) {
    if (n <= 2) {
        return 0;
    }
    vector< bool > s(n, false);
    int result = 1;
    float n_sqrt = sqrt(n);
    for (int i = 3; i < n; i += 2) {
        if (!s[i]) {
            result++;
            if (i > n_sqrt) continue;

            for (int m = i * i; m < n; m += i) {
                s[m] = true;
            }
        }
    }
    return result;
}

int main() {
    std::cout << countPrimes(10) << std::endl;
    std::cout << countPrimes(0) << std::endl;
    std::cout << countPrimes(1) << std::endl;
    std::cout << countPrimes(2) << std::endl;
    std::cout << countPrimes(3) << std::endl;
    std::cout << countPrimes(100) << std::endl;
    std::cout << countPrimes2(2000000) << std::endl;
    return 0;
}
