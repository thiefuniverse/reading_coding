#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
void bfs(int i, int j, vector< vector< char > > &grid, vector< vector< bool > > &isvalid) {
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

int numIslands1(vector< vector< char > > &grid) {
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

                bfs(i, j, grid, isvalid);
                ++count;
            }
        }
    }
    return count;
}

void dfs(int i, int j, vector< vector< char > > &grid, vector< vector< bool > > &isvalid) {
    int w = grid.size();
    int h = 0;
    if (w > 0) {
        h = grid[0].size();
    }
    if (i < 0 || i >= w || j < 0 || j >= h) {
        return;
    }
    if (!isvalid[i][j] && grid[i][j] == '1') {
        isvalid[i][j] = true;
        dfs(i - 1, j, grid, isvalid);
        dfs(i, j - 1, grid, isvalid);
        dfs(i + 1, j, grid, isvalid);
        dfs(i, j + 1, grid, isvalid);
    }
}

int numIslands2(vector< vector< char > > &grid) {
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

// union set
int getParent(vector< int > &uni, int x) {
    if (x < 0) {
        return 0;
    }
    while (x != -1 && uni[x] != x) {
        x = uni[x];
    }
    return x;
}
void join(vector< int > &uni, int x, int y) {
    uni[getParent(uni, x)] = getParent(uni, y);
}

int numIslands3(vector< vector< char > > &grid) {
    if (grid.empty()) {
        return 0;
    }
    int h = grid.size();
    int w = 0;
    if (h > 0) {
        w = grid[0].size();
    } else {
        return 0;
    }
    vector< int > unionSet(w * h, -1);
    int count = 0;
    array< int, 4 > xs{-1, 0, 1, 0};
    array< int, 4 > ys{0, -1, 0, 1};

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cout << "i:" << i << std::endl;
            std::cout << "j:" << j << std::endl;
            if (grid[i][j] == '1') {
                int current = i * w + j;
                std::cout << "current:" << current << std::endl;
                unionSet[current] = current;
                ++count;
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int current = i * w + j;
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                for (int m = 0; m < 4; ++m) {
                    if (i + xs[m] >= 0 && j + ys[m] >= 0 && i + xs[m] < h && j + ys[m] < w && grid[i + xs[m]][j + ys[m]] == '1') {
                        int other_index = (i + xs[m]) * w + j + ys[m];
                        int other_parent = getParent(unionSet, other_index);
                        int current_parent = getParent(unionSet, current);
                        if (other_parent != current_parent) {
                            unionSet[current_parent] = other_parent;
                            --count;
                        }
                    }
                }
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
    std::cout << numIslands3(tt3) << std::endl;
    return 0;
}
