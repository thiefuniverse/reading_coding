#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool validateStackSequences(vector< int > &pushed, vector< int > &popped) {
    if (pushed.size() != popped.size()) {
        return false;
    }
    int l = pushed.size();
    stack< int > s;
    int j = 0;
    for (int i = 0; i < l; ++i) {
        s.push(pushed[i]);
        while (!s.empty() && j < l && s.top() == popped[j]) {
            s.pop();
            ++j;
        }
    }
    return j == l;
}
int main() {

    return 0;
}
