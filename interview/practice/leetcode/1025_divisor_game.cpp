
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool divisorGame(int N) {
    return (!(N % 2));
}
int main() {

    std::cout << divisorGame(999) << std::endl;
    std::cout << divisorGame(456) << std::endl;
    return 0;
}
