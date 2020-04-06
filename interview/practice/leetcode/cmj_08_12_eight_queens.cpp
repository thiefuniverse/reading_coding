#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
bool check(const vector< int > &pos) {
    int tx = 0, ty = 0;
    if (pos.size() >= 2) {
        ty = pos.size() - 1;
        tx = pos[pos.size() - 1];
    } else {
        return true;
    }
    for (int i = 0; i < pos.size() - 1; ++i) {
        if (abs(tx - pos[i]) == abs(ty - i) || tx == pos[i] || ty == i) {
            return false;
        }
    }
    return true;
}
void solveNQueens(vector< string > &oneSol, vector< int > &pos, vector< vector< string > > &result, int n) {
    if (oneSol.size() == n) {
        if (check(pos)) {
            result.push_back(oneSol);
            return;
        } else {
            return;
        }
    } else {
        if (!check(pos)) {
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        string tmp(n, '.');
        tmp[i] = 'Q';
        oneSol.push_back(tmp);
        pos.push_back(i);
        solveNQueens(oneSol, pos, result, n);
        oneSol.pop_back();
        pos.pop_back();
    }
}
vector< vector< string > > solveNQueens(int n) {
    vector< string > oneSol;
    vector< int > pos;
    vector< vector< string > > result;
    solveNQueens(oneSol, pos, result, n);
    return result;
}

int main() {
    auto res = solveNQueens(4);
    for (auto &queen_result : res) {
        for (auto &r : queen_result) {
            std::cout << r << std::endl;
        }
        std::cout << "---------" << std::endl;
    }

    return 0;
}
