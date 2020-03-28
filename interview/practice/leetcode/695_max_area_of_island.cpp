#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
void bfs(int i, int j, vector< vector< int > > &grid, vector< vector< bool > > &isvalid, int &result) {
    int w = grid.size();
    int h = 0;
    if (w > 0) {
        h = grid[0].size();
    }

    queue< pair< int, int > > q;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        ++result;
        isvalid[cur.first][cur.second] = true;
        if (cur.first + 1 < w && !isvalid[cur.first + 1][cur.second] && grid[cur.first + 1][cur.second] == 1) {
            q.push(make_pair(cur.first + 1, cur.second));
            isvalid[cur.first + 1][cur.second] = true;
        }
        if (cur.second + 1 < h && !isvalid[cur.first][cur.second + 1] && grid[cur.first][cur.second + 1] == 1) {
            q.push(make_pair(cur.first, cur.second + 1));
            isvalid[cur.first][cur.second + 1] = true;
        }
        if (cur.first - 1 >= 0 && !isvalid[cur.first - 1][cur.second] && grid[cur.first - 1][cur.second] == 1) {
            q.push(make_pair(cur.first - 1, cur.second));
            isvalid[cur.first - 1][cur.second] = true;
        }
        if (cur.second - 1 >= 0 && !isvalid[cur.first][cur.second - 1] && grid[cur.first][cur.second - 1] == 1) {
            q.push(make_pair(cur.first, cur.second - 1));
            isvalid[cur.first][cur.second - 1] = true;
        }
    }
}

int maxAreaOfIsland(vector< vector< int > > &grid) {
    if (grid.empty()) {
        return 0;
    }
    int w = grid.size();
    int h = 0;
    if (w > 0) {
        h = grid[0].size();
    } else {
        return 0;
    }
    int count = 0;
    int max_result = 0;
    vector< vector< bool > > isvalid(w, vector< bool >(h, false));
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            if (!isvalid[i][j] && grid[i][j] == 1) {
                int result = 0;
                bfs(i, j, grid, isvalid, result);
                max_result = max(max_result, result);
                ++count;
            }
        }
    }
    return max_result;
}

void dfs(int i, int j, vector< vector< int > > &grid, vector< vector< bool > > &isvalid, int &result) {
    int w = grid.size();
    int h = 0;
    if (w > 0) {
        h = grid[0].size();
    }
    if (i < 0 || i >= w || j < 0 || j >= h) {
        return;
    }
    if (!isvalid[i][j] && grid[i][j] == 1) {
        isvalid[i][j] = true;
        ++result;
        dfs(i - 1, j, grid, isvalid, result);
        dfs(i, j - 1, grid, isvalid, result);
        dfs(i + 1, j, grid, isvalid, result);
        dfs(i, j + 1, grid, isvalid, result);
    }
}

int maxAreaOfIsland2(vector< vector< int > > &grid) {
    if (grid.empty()) {
        return 0;
    }
    int w = grid.size();
    int h = 0;
    if (w > 0) {
        h = grid[0].size();
    } else {
        return 0;
    }
    int count = 0;
    int max_result = 0;
    vector< vector< bool > > isvalid(w, vector< bool >(h, false));
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            if (!isvalid[i][j] && grid[i][j] == 1) {
                int result = 0;
                dfs(i, j, grid, isvalid, result);
                max_result = max(max_result, result);
                ++count;
            }
        }
    }
    return max_result;
}

int main() {
    vector< vector< char > > tt{
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };                                           //, "11010", "11000", "00000"};
    vector< vector< char > > tt4{{'1'}, {'1'}};  //, "11010", "11000", "00000"};
    vector< vector< char > > tt2{
        {
            '1',
            '1',
            '1',
        },
        {
            '0',
            '1',
            '0',
        },
        {
            '1',
            '1',
            '1',
        },
    };
    vector< vector< int > > tt3 = {
        {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0}, {1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1}, {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    std::cout << maxAreaOfIsland2(tt3) << std::endl;
    return 0;
}
