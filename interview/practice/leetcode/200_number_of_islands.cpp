#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
void dfs(int i, int j, vector< vector< char > > &grid, vector< vector< bool > > &isvalid) {
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
        isvalid[cur.first][cur.second] = true;
        if (cur.first + 1 < w && !isvalid[cur.first + 1][cur.second] && grid[cur.first + 1][cur.second] == '1') {
            q.push(make_pair(cur.first + 1, cur.second));
            isvalid[cur.first + 1][cur.second] = true;
        }
        if (cur.second + 1 < h && !isvalid[cur.first][cur.second + 1] && grid[cur.first][cur.second + 1] == '1') {
            q.push(make_pair(cur.first, cur.second + 1));
            isvalid[cur.first][cur.second + 1] = true;
        }
        if (cur.first - 1 >= 0 && !isvalid[cur.first - 1][cur.second] && grid[cur.first - 1][cur.second] == '1') {
            q.push(make_pair(cur.first - 1, cur.second));
            isvalid[cur.first - 1][cur.second] = true;
        }
        if (cur.second - 1 >= 0 && !isvalid[cur.first][cur.second - 1] && grid[cur.first][cur.second - 1] == '1') {
            q.push(make_pair(cur.first, cur.second - 1));
            isvalid[cur.first][cur.second - 1] = true;
        }
    }
}

int numIslands(vector< vector< char > > &grid) {
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
    vector< vector< bool > > isvalid(w, vector< bool >(h, false));
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            if (!isvalid[i][j] && grid[i][j] == '1') {
                std::cout << "i:" << i << std::endl;
                std::cout << "j:" << j << std::endl;

                dfs(i, j, grid, isvalid);
                ++count;
            }
        }
    }
    return count;
}

int main() {
    vector< vector< char > > tt{
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };  //, "11010", "11000", "00000"};
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
    vector< vector< char > > tt3 = {{'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1'},
                                    {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0'},
                                    {'1', '0', '1', '1', '1', '0', '0', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                                    {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                                    {'1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                                    {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1'},
                                    {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '1', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1'},
                                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                                    {'0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1'},
                                    {'1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '0'},
                                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0'},
                                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}};
    std::cout << numIslands(tt3) << std::endl;

    return 0;
}
