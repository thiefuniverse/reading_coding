#include <functional>
#include <iostream>
#include <memory>

using namespace std;

int main() {
    std::unique_ptr< int > tp(new int(2));
    int m = 4;
    //    function< void(void) > r = [&tc = std::move(tp)]() {
    function< void(void) > r = [&]() {
        auto tc = std::move(tp);
        std::cout << *tc << std::endl;
    };
    r();
    return 0;
}
