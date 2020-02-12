#include <exception>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template < class T >
class Queue {
public:
    Queue() {}
    ~Queue() {}
    void appendTail(const T &value) {
        stack1.push(value);
    }
    T deleteHead() {
        if (stack2.empty()) {
            // transfer element in stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            if (stack2.empty()) {
                throw new range_error("queue is empty now");
            }
        }
        T head = stack2.top();
        stack2.pop();
        return head;
    }

private:
    stack< T > stack1;
    stack< T > stack2;
};

template < class T >
class Stack {
public:
    Stack() {}
    ~Stack() {}
    void push(const T &value) {
        queue1.push(value);
    }
    T pop() {
        if (queue1.empty()) {
            if (queue2.empty()) {
                throw new range_error("stack is empty now");
            } else {
                while (queue2.size() != 1) {
                    queue1.push(queue2.front());
                    queue2.pop();
                }
                T top = queue2.back();
                queue2.pop();
                return top;
            }

        } else {
            while (queue1.size() != 1) {
                queue2.push(queue1.front());
                queue1.pop();
            }
            T top = queue1.back();
            queue1.pop();
            return top;
        }
    }

private:
    queue< T > queue1;
    queue< T > queue2;
};
int main() {
    Queue< int > q;
    q.appendTail(1);
    q.appendTail(2);
    q.appendTail(3);
    q.appendTail(4);
    q.appendTail(5);
    std::cout << q.deleteHead() << std::endl;
    q.appendTail(6);
    q.appendTail(7);
    std::cout << q.deleteHead() << std::endl;
    q.appendTail(8);
    std::cout << q.deleteHead() << std::endl;
    std::cout << q.deleteHead() << std::endl;
    std::cout << q.deleteHead() << std::endl;
    std::cout << q.deleteHead() << std::endl;
    std::cout << q.deleteHead() << std::endl;
    std::cout << q.deleteHead() << std::endl;
    //    std::cout << q.deleteHead() << std::endl;

    Stack< int > s;
    s.push(1);
    s.push(2);
    std::cout << s.pop() << std::endl;
    s.push(3);
    s.push(4);
    std::cout << s.pop() << std::endl;
    s.push(5);
    s.push(6);
    std::cout << s.pop() << std::endl;
    s.push(7);
    s.push(8);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    return 0;
}
