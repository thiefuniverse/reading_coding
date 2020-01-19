#include <iostream>
#include <vector>

bool FindNumber(const std::vector< std::vector< int > > &ar, const int target_num) {
    int n = ar.size();
    int x_flag = n - 1, y_flag = 0;
    while (x_flag >= 0 && y_flag < n) {
        if (ar[y_flag][x_flag] == target_num) {
            return true;
        }
        if (ar[y_flag][x_flag] > target_num) {
            x_flag--;
        } else {
            y_flag++;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    std::vector< std::vector< int > > t1 = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    std::vector< int > needFind = {0, 10, 6, 14, 5, 6, 7, 999, 14, 15, 9, 11, 4, 2, 1};
    for (int i = 0; i < needFind.size(); i++) {
        std::cout << "find " << needFind[i] << " " << FindNumber(t1, needFind[i]) << std::endl;
    }
    return 0;
}
