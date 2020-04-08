#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int findLUSlength(string a, string b) {
    if (a == b) {
        return -1;
    }
    if (a.size() > b.size()) {
        return a.size();
    } else {
        return b.size();
    }
}

int main() {

    return 0;
}
