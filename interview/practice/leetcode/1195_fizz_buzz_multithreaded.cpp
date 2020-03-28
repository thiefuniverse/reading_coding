#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class FizzBuzz {
private:
    int n;
    mutex print_mutex;
    // int current_n;
    int current_n;
    condition_variable cv;
    bool over;

public:
    FizzBuzz(int n) {
        this->n = n;
        current_n = 1;
        over = false;
    }

    // printFizz() outputs "fizz".
    void fizz(function< void() > printFizz) {
        while (current_n <= n) {
            unique_lock< mutex > lock(print_mutex);
            cv.wait(lock, [&, this] { return over || (current_n % 3 == 0 && current_n % 15 != 0); });
            if (!over) printFizz();
            if (current_n == n) {
                over = true;
                cv.notify_all();
                return;
            }
            ++current_n;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function< void() > printBuzz) {
        while (current_n <= n) {
            unique_lock< mutex > lock(print_mutex);
            cv.wait(lock, [&, this] { return over || (this->current_n % 5 == 0 && this->current_n % 15 != 0); });
            if (!over) printBuzz();
            if (current_n == n) {
                over = true;
                cv.notify_all();
                return;
            }
            ++current_n;
            // std::cout << "cur buzz: " << current_n << std::endl;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function< void() > printFizzBuzz) {
        while (current_n <= n) {
            unique_lock< mutex > lock(print_mutex);
            cv.wait(lock, [&, this] { return over || this->current_n % 15 == 0; });
            if (!over) printFizzBuzz();
            if (current_n == n) {
                over = true;
                cv.notify_all();
                return;
            }
            ++current_n;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function< void(int) > printNumber) {
        while (current_n <= n) {
            unique_lock< mutex > lock(print_mutex);
            cv.wait(lock, [&, this] { return over || (current_n % 3 != 0 && current_n % 5 != 0 && current_n % 15 != 0); });
            if (!over) printNumber(current_n);
            if (current_n == n) {
                over = true;
                cv.notify_all();
                return;
            }
            ++current_n;
            cv.notify_all();
        }
    }
};
void printFizz() {
    std::cout << "fizz" << std::endl;
}
void printBuzz() {
    std::cout << "buzz" << std::endl;
}
void printFizzBuzz() {
    std::cout << "fizzbuzz" << std::endl;
}
void printNumber(int number) {
    std::cout << number << std::endl;
}
int main() {
    FizzBuzz fb(15);
    thread t1(&FizzBuzz::buzz, &fb, &printBuzz);
    thread t2(&FizzBuzz::fizz, &fb, &printFizz);
    thread t3(&FizzBuzz::fizzbuzz, &fb, &printFizzBuzz);
    thread t4(&FizzBuzz::number, &fb, &printNumber);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
