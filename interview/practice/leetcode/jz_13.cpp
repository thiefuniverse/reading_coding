#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int getNumSum(int n) {
    int result = 0;
    while (n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

//广度优先遍历
int movingCount(int m, int n, int k) {
    if (m * n == 0) {
        return 0;
    }
    int count = 0;
    vector< vector< bool > > visited(m, vector< bool >(n, false));
    queue< pair< int, int > > q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        if (getNumSum(front.first) + getNumSum(front.second) <= k) {
            ++count;
            if (front.first + 1 < m && !visited[front.first + 1][front.second]) {
                q.push(make_pair(front.first + 1, front.second));
                visited[front.first + 1][front.second] = true;
            }
            if (front.second + 1 < n && !visited[front.first][front.second + 1]) {
                q.push(make_pair(front.first, front.second + 1));
                visited[front.first][front.second + 1] = true;
            }
            // std::cout << "i:" << front.first << " j:" << front.second << std::endl;
        }
    }
    return count;
}
// dp
int movingCount2(int m, int n, int k) {
    if (m * n == 0) {
        return 0;
    }
    int count = 0;
    vector< vector< bool > > visited(m, vector< bool >(n, false));
    visited[0][0] = 1;
    ++count;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == 0 && j == 0) || (getNumSum(i) + getNumSum(j) > k)) {
                continue;
            }
            if (i - 1 >= 0) visited[i][j] = visited[i][j] | visited[i - 1][j];
            if (j - 1 >= 0) visited[i][j] = visited[i][j] | visited[i][j - 1];
            count += visited[i][j];
        }
    }
    return count;
}

int main() {
    std::cout << movingCount2(16, 8, 4) << std::endl;
    std::cout << movingCount2(36, 11, 15) << std::endl;

    return 0;
}
