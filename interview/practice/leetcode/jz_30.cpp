#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    return 0;
}
class MinStack {
private:
    stack< int > s1, s2;
    int min_element;

public:
    /** initialize your data structure here. */
    MinStack() : min_element(INT_MAX) {}

    void push(int x) {
        s1.push(x);
        if (s2.empty()) {
            s2.push(x);
        } else {
            if (x <= s2.top()) {
                s2.push(x);
            }
        }
    }

    void pop() {
        if (s1.top() <= s2.top()) {
            s2.pop();
        }
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int min() {
        return s2.top();
    }
};
