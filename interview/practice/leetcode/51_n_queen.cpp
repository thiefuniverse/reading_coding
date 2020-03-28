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
bool nQueens(vector< vector< pair< int, int > > > &result, vector< pair< int, int > > queens, int n, int current_n, int pos) {
    if (checkOK(queens, current_n, pos)) {
        queens[current_n] = {current_n, pos};
        if (current_n == n - 1) {
            result.push_back(queens);
            return true;
        }
        for (int i = current_n + 1; i < n; ++i) {
            bool get_one = false;
            for (int j = 0; j < n; ++j) {
                if (nQueens(result, queens, n, i, j)) {
                    get_one = true;
                }
            }
            if (!get_one) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}
vector< vector< string > > solveNQueens(int n) {
    vector< vector< string > > result;
    vector< vector< pair< int, int > > > result_pair;
    vector< pair< int, int > > queens(n, {-1, -1});
    for (int i = 0; i < n; ++i) {
        nQueens(result_pair, queens, n, 0, i);
    }
    std::cout << result_pair.size() << std::endl;
    for (auto &queen_result : result_pair) {
        vector< string > one_result(n, string(n, '.'));
        for (int j = 0; j < n; ++j) {
            one_result[queen_result[j].first][queen_result[j].second] = 'Q';
        }
        result.push_back(one_result);
    }
    return result;
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

vector< vector< string > > solveNQueens2(int n) {
    vector< vector< string > > result;
    vector< vector< pair< int, int > > > result_pair;
    vector< pair< int, int > > queens(n, {-1, -1});
    nQueensBacktrack(result_pair, queens, 0);
    std::cout << result_pair.size() << std::endl;
    for (auto &queen_result : result_pair) {
        vector< string > one_result(n, string(n, '.'));
        for (int j = 0; j < n; ++j) {
            one_result[queen_result[j].first][queen_result[j].second] = 'Q';
        }
        result.push_back(one_result);
    }
    return result;
}

int main() {
    auto res = solveNQueens2(4);
    for (auto &queen_result : res) {
        for (auto &r : queen_result) {
            std::cout << r << std::endl;
        }
        std::cout << "---------" << std::endl;
    }
    return 0;
}
