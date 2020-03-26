#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int getSum(int a, int b) {
    return b == 0 ? a : getSum(( unsigned int )(a ^ b), ( unsigned int )(a & b) << 1);
}
int main() {

    std::cout << getSum(-1, 8) << std::endl;
    return 0;
}
