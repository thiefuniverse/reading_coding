#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
bool checkStraightLine(vector< vector< int > > &coordinates) {
    if (coordinates.size() <= 1) {
        return false;
    }
    auto one_point = coordinates[0];
    auto two_point = coordinates[1];
    bool isHorizon = false;
    float ratio = 0;
    if (one_point[1] == two_point[1]) {
        isHorizon = true;
    } else {
        ratio = (one_point[0] - two_point[0]) / (one_point[1] - two_point[1]);
    }

    for (int i = 2; i < coordinates.size(); ++i) {
        if (isHorizon) {
            if (coordinates[i][1] != one_point[1]) {
                return false;
            }
        } else {
            if (coordinates[i][1] == one_point[1]) {
                return false;
            }
            if ((coordinates[i][0] - one_point[0]) / (coordinates[i][1] - one_point[1]) != ratio) {
                return false;
            }
        }
    }
    return true;
}
bool checkStraightLine2(vector< vector< int > > &coordinates) {
    if (coordinates.size() <= 1) {
        return false;
    }
    auto m = coordinates[0][0] - coordinates[1][0];
    auto n = coordinates[0][1] - coordinates[1][1];
    for (int i = 2; i < coordinates.size(); ++i) {
        int x = coordinates[i][0] - coordinates[0][0];
        int y = coordinates[i][1] - coordinates[0][1];
        if (x * n != y * m) {
            return false;
        }
    }
    return true;
}
int main() {

    return 0;
}
