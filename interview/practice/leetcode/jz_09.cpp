#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class CQueue {
private:
    stack< int > s1, s2;

public:
    CQueue() {}

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        if (!s2.empty()) {
            int result = s2.top();
            s2.pop();
            return result;
        } else {
            if (s1.empty()) {
                throw "stack is empty";
                return -1;
            } else {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                int result = s2.top();
                s2.pop();
                return result;
            }
        }
    }
};
int main() {

    return 0;
}
