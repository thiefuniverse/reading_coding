#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isLeft(char c) { return c == '{' || c == '[' || c == '('; }
bool isValid(string s) {
    stack<char> st;
    for (auto& c : s) {
        if (st.empty()) {
            st.push(c);
        } else {
            if (isLeft(c)) {
                st.push(c);
            } else {
                auto top = st.top();
                if (top == '(') {
                    if (c == ')') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else if (top == '{') {
                    if (c == '}') {
                        st.pop();
                    } else {
                        return false;
                    }

                } else if (top == '[') {
                    if (c == ']') {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
    }
    return st.empty();
}

int main() {
    std::cout << isValid("()[]{}") << std::endl;
    std::cout << isValid("()[]{}}") << std::endl;
    std::cout << isValid("([]){}") << std::endl;
    std::cout << isValid("([){]}") << std::endl;
    return 0;
}
