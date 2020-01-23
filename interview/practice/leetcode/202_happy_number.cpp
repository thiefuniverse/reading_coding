#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool isHappy1(int n) {
    unordered_map< int, int > query_map{{0, 0}, {1, 1}, {2, 4}, {3, 9}, {4, 16}, {5, 25}, {6, 36}, {7, 49}, {8, 64}, {9, 81}};
    unordered_map< int, bool > history_map;
    int sum = n;
    int new_sum = 0;
    while (true) {
        if (sum == 1) {
            return true;
        }
        new_sum = 0;
        while (sum > 0) {
            new_sum += query_map[sum % 10];
            sum /= 10;
        }
        sum = new_sum;
        if (history_map.find(sum) != history_map.end()) {
            return false;
        }
        history_map[sum] = true;
    }
    return false;
}

// floyd cycle detection algorithm
int squareSum(int n) {
    vector< int > query_map{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    int res = 0;
    while (n > 0) {
        res += query_map[n % 10];
        n /= 10;
    }
    return res;
}

bool isHappy2(int n) {
    int slow = n, fast = n;
    do {
        slow = squareSum(slow);
        fast = squareSum(fast);
        fast = squareSum(fast);
    } while (slow != fast);
    return slow == 1 ? true : false;
}

int main() {
    std::cout << "ishappy : " << isHappy2(19);
    std::cout << "ishappy : " << isHappy2(1);
    std::cout << "ishappy : " << isHappy2(0);
    return 0;
}
