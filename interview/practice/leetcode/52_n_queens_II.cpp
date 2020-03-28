#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool checkOK(vector< pair< int, int > > queens, int current_n, int pos) {
    for (int i = 0; i < current_n; ++i) {
        if (queens[i].first == -1 || queens[i].second == pos || (abs(queens[i].first - current_n) == abs(queens[i].second - pos) || queens[i].first == current_n)) {
            return false;
        }
    }
    return true;
}

// backtrack
void nQueensBacktrack(vector< vector< pair< int, int > > > &result, vector< pair< int, int > > queens, int current_n) {
    int n = queens.size();
    if (current_n == n) {
        result.push_back(queens);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (checkOK(queens, current_n, i)) {
            queens[current_n] = {current_n, i};
            nQueensBacktrack(result, queens, current_n + 1);
            queens[current_n] = {-1, -1};
        }
    }
}

int totalNQueens(int n) {
    vector< vector< pair< int, int > > > result_pair;
    vector< pair< int, int > > queens(n, {-1, -1});
    nQueensBacktrack(result_pair, queens, 0);
    return result_pair.size();
}

int main() {
    std::cout << totalNQueens(4) << std::endl;
    std::cout << totalNQueens(6) << std::endl;
    return 0;
}
