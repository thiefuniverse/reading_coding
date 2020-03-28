#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class ZeroEvenOdd {
private:
    int n;
    mutex print_mutex;
    condition_variable cv;
    int counter = 1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function< void(int) > printNumber) {
        while (counter <= 2 * n) {
            unique_lock< mutex > lock(print_mutex);
            cv.wait(lock, [&]() { return counter % 2 == 1; });
            if (counter <= 2 * n) printNumber(0);
            ++counter;
            cv.notify_all();
        }
    }

    void even(function< void(int) > printNumber) {
        while (counter <= 2 * n) {
            unique_lock< mutex > lock(print_mutex);
            cv.wait(lock, [&]() { return (counter > 0 && counter % 4 == 0); });
            if (counter <= 2 * n) printNumber(counter / 2);
            ++counter;
            cv.notify_all();
        }
    }
    void odd(function< void(int) > printNumber) {
        while (counter <= 2 * n) {
            unique_lock< mutex > lock(print_mutex);
            cv.wait(lock, [&]() { return (counter > 0 && counter % 4 == 2); });
            if (counter <= 2 * n) printNumber(counter / 2);
            ++counter;
            cv.notify_all();
        }
    }
};
void printNumber(int n) {
    std::cout << n;
}
int main() {
    ZeroEvenOdd fb(35);
    thread t1(&ZeroEvenOdd::zero, &fb, &printNumber);
    thread t2(&ZeroEvenOdd::even, &fb, &printNumber);
    thread t3(&ZeroEvenOdd::odd, &fb, &printNumber);

    t2.join();
    t1.join();
    t3.join();
    return 0;
}
