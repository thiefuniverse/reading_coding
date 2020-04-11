#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int minArray(vector< int > &numbers) {
    int len = numbers.size();
    int l = 0, r = len - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (numbers[mid] == numbers[r]) {
            --r;
        } else if (numbers[mid] > numbers[r]) {
            l = mid + 1;
        } else if (numbers[mid] < numbers[r]) {
            r = mid;
        }
    }
    return numbers[l];
}
int main() {

    return 0;
}
