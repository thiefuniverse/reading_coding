#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Foo {
private:
    mutex print_mutex;
    condition_variable cv;
    int flag = 0;

public:
    Foo() {}

    void first(function< void() > printFirst) {
        unique_lock< mutex > lock(print_mutex);
        cv.wait(lock, [&]() { return flag == 0; });
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++flag;
        cv.notify_all();
    }

    void second(function< void() > printSecond) {
        unique_lock< mutex > lock(print_mutex);
        cv.wait(lock, [&]() { return flag == 1; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++flag;
        cv.notify_all();
    }

    void third(function< void() > printThird) {
        unique_lock< mutex > lock(print_mutex);
        cv.wait(lock, [&]() { return flag == 2; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        flag = 0;
        cv.notify_all();
    }
};
void printFirst() {
    std::cout << "one" << std::endl;
}
void printSecond() {
    std::cout << "two" << std::endl;
}
void printThird() {
    std::cout << "three" << std::endl;
}
int main() {
    Foo fb;
    thread t1(&Foo::first, &fb, &printFirst);
    thread t2(&Foo::second, &fb, &printSecond);
    thread t3(&Foo::third, &fb, &printThird);

    t3.join();
    t2.join();
    t1.join();
    return 0;
}
