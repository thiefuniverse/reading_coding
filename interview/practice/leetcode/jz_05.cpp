#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string replaceSpace(string s) {
    int count = 0;
    for (auto &c : s) {
        if (c == ' ') {
            ++count;
        }
    }
    string result(s.size() + count * 2, ' ');
    int result_index = result.size() - 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ' ') {
            result[result_index] = '0';
            --result_index;
            result[result_index] = '2';
            --result_index;
            result[result_index] = '%';
            --result_index;
        } else {
            result[result_index] = s[i];
            --result_index;
        }
    }
    return result;
}
int main() {
    std::cout << replaceSpace("We are happy.") << std::endl;

    return 0;
}
