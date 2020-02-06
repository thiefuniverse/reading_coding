#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string reverseStr(string s, int k) {
    int counter = 1;
    while (counter * 2 * k < s.size()) {
        int start = (counter - 1) * 2 * k;
        int end = (counter - 1) * 2 * k + k - 1;
        int mid = (start + end) / 2;
        for (int i = start; i <= mid; i++) {
            swap(s[i], s[start + end - i]);
        }
        counter++;
    }
    int start = (counter - 1) * 2 * k;
    int end = s.size();
    int reverse_end = 0;
    if (end - start < k) {
        reverse_end = end - 1;
    } else {
        reverse_end = start - 1 + k;
    }
    int mid = (start + reverse_end) / 2;
    for (int i = start; i <= mid; i++) {
        swap(s[i], s[start + reverse_end - i]);
    }
    return s;
}

// use reverse ([start, last))
string reverseStr2(string s, int k) {
    int counter = 1;
    while (counter * 2 * k < s.size()) {
        reverse(s.begin() + (counter - 1) * 2 * k, s.begin() + (counter - 1) * 2 * k + k);
        counter++;
    }
    if (s.size() - (counter - 1) * 2 * k >= k) {
        reverse(s.begin() + counter * 2 * k - 2 * k, s.begin() + counter * 2 * k - k);
    } else {
        reverse(s.begin() + counter * 2 * k - 2 * k, s.end());
    }
    return s;
}
int main() {
    std::cout << reverseStr2("", 3) << std::endl;
    std::cout << reverseStr2("thief", 3) << std::endl;
    std::cout << reverseStr2("thief", 2) << std::endl;
    std::cout << reverseStr2("thiefuniverse", 2) << std::endl;
    std::cout << reverseStr2("abcd", 2) << std::endl;
    std::cout << reverseStr2("thief", 5) << std::endl;
    return 0;
}
