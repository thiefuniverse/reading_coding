#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// multiset can be used as min heap or max heap
class MinStack2 {
public:
    /** initialize your data structure here. */
    MinStack2() {}

    void push(int x) {
        stack_.push(x);
        min_stack_.insert(x);
    }

    void pop() {
        auto front = stack_.top();
        auto it = min_stack_.find(front);
        if (it != min_stack_.end()) {
            min_stack_.erase(it);
        }
        stack_.pop();
    }

    int top() {
        return stack_.top();
    }

    int getMin() {
        if (min_stack_.empty()) {
            throw "stack empty, no min";
            return 0;
        }
        return *min_stack_.begin();
    }

private:
    stack< int > stack_;
    multiset< int > min_stack_;
};
// steal from leetcode history submission.
class MinStack {
private:
    stack< int > allS, minS;

public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        allS.push(x);
        if (minS.empty()) {
            minS.push(x);
        } else if (x <= minS.top()) {
            minS.push(x);
        }
    }

    void pop() {
        if (allS.top() == getMin()) {
            minS.pop();
        }
        allS.pop();
    }

    int top() {
        if (allS.empty())
            return INT_MIN;
        else
            return allS.top();
    }

    int getMin() {
        if (minS.empty())
            return INT_MIN;
        else
            return minS.top();
    }
};

int main() {
    MinStack *obj = new MinStack();
    obj->push(5);
    std::cout << obj->getMin() << std::endl;
    obj->push(3);
    std::cout << obj->getMin() << std::endl;
    obj->push(1);
    std::cout << obj->getMin() << std::endl;
    obj->push(9);
    std::cout << obj->getMin() << std::endl;

    return 0;
}
