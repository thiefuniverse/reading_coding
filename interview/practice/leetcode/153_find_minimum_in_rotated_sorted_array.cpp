#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int findMin(vector< int > &arr) {
    if (arr.empty()) {
        throw new range_error("empty array");
        return 0;
    }
    if (arr.size() == 1 || arr[0] < arr[arr.size() - 1]) {
        return arr[0];
    }
    int i = 0, j = arr.size() - 1;
    int mid = (i + j) / 2;
    while (mid + 1 <= j) {
        if (arr[mid] > arr[mid + 1]) {
            return arr[mid + 1];
        }
        if (arr[mid] >= arr[arr.size() - 1]) {
            i = mid;
        } else {
            j = mid;
        }
        mid = (i + j) / 2;
    }
}

// simplify it :)
int findMin2(vector< int > &arr) {
    int len = arr.size();
    if (len == 0) {
        throw new range_error("empty array");
        return 0;
    }
    int l = 0, r = len - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] > arr[r]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return arr[l];
}
int main() {
    vector< vector< int > > tt{{6, 7, 8, 1, 4, 5}, {4, 1, 2, 3}, {2}, {4, 2}, {1, 2}};
    for (auto &t : tt) {
        std::cout << findMin2(t) << std::endl;
    }

    return 0;
}
