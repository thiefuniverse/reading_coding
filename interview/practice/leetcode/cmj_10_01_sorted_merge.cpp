#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
void merge(vector< int > &A, int m, vector< int > &B, int n) {
    if (n == 0) {
        return;
    }
    int endA = m - 1, endB = n - 1;
    for (int i = m + n - 1; i >= 0; --i) {
        if (endB < 0) {
            A[i] = A[endA];
            --endA;
        } else if (endA < 0) {
            A[i] = B[endB];
            --endB;
        } else {
            if (A[endA] > B[endB]) {
                A[i] = A[endA];
                --endA;
            } else {
                A[i] = B[endB];
                --endB;
            }
        }
    }
}
int main() {
    vector< vector< int > > tt{{1, 2, 3, 0, 0, 0}, {2, 5, 6}};
    merge(tt[0], 3, tt[1], 3);
    for (auto &t : tt[0]) {
        std::cout << t << " ";
        std::cout << std::endl;
    }

    return 0;
}
