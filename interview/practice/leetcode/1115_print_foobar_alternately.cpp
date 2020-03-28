#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class FooBar {
private:
    int n;

    mutex print_mutex;
    condition_variable cv;
    int flag = 0;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function< void() > printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock< mutex > lock(print_mutex);
            cv.wait(lock, [&]() { return flag == 0; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            flag = 1;
            cv.notify_one();
        }
    }

    void bar(function< void() > printBar) {

        for (int i = 0; i < n; i++) {
            unique_lock< mutex > lock(print_mutex);
            cv.wait(lock, [&]() { return flag == 1; });

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            flag = 0;
            cv.notify_one();
        }
    }
};
void printFoo() {
    std::cout << "foo";
}
void printBar() {
    std::cout << "bar" << std::endl;
}
int main() {
    FooBar fb(4);
    thread t1(&FooBar::foo, &fb, &printFoo);
    thread t2(&FooBar::bar, &fb, &printBar);

    t2.join();
    t1.join();
    return 0;
}
