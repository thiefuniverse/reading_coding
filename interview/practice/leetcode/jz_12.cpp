#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool existHelper(vector< vector< char > > &board, vector< vector< bool > > &visited, int h, int w, int cur_y, int cur_x, const string &word, int cur_pos, int dir) {
    if (cur_pos == word.size()) {
        return true;
    }
    if (cur_x < 0 || cur_x >= w || cur_y < 0 || cur_y >= h || visited[cur_y][cur_x]) {
        return false;
    }
    if (word[cur_pos] == board[cur_y][cur_x]) {
        ++cur_pos;
        visited[cur_y][cur_x] = true;
        // 1 ->
        if (dir != 1) {
            // <-
            if (existHelper(board, visited, h, w, cur_y - 1, cur_x, word, cur_pos, 2)) {
                return true;
            }
        }
        // 2 <-
        if (dir != 2) {
            // ->
            if (existHelper(board, visited, h, w, cur_y + 1, cur_x, word, cur_pos, 1)) {
                return true;
            }
        }
        // 3 ^
        if (dir != 3) {
            // v
            if (existHelper(board, visited, h, w, cur_y, cur_x + 1, word, cur_pos, 4)) {
                return true;
            }
        }
        // 1 ->
        if (dir != 4) {
            // <-
            if (existHelper(board, visited, h, w, cur_y, cur_x - 1, word, cur_pos, 3)) {
                return true;
            }
        }
        visited[cur_y][cur_x] = false;
    }
    return false;
}

bool exist(vector< vector< char > > &board, string word) {
    int h = board.size();
    int w = 0;
    if (h > 0) {
        w = board[0].size();
    }
    vector< vector< bool > > visited(h, vector< bool >(w, false));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (board[i][j] == word[0]) {
                if (existHelper(board, visited, h, w, i, j, word, 0, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {

    vector< vector< char > > tt{{'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'b'}};
    std::cout << exist(tt, "aaaaaaaaaaaaaaaaaaaa") << std::endl;
    return 0;
}
