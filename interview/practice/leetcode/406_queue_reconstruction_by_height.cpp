#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    if (people.empty()) {
        return {};
    }
    int num = people.size();
    vector<vector<int>> res(num, vector<int>(2, -1));
    sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    });

    vector<int> big_record(num);
    for (int i = 0; i < num; i++) {
        big_record[i] = i;
    }
    for (int i = 0; i < num; i++) {
        auto new_person = people[i];
        int big_counter = new_person[1];
        int index = 0;
        for (int j = 0; j < num; j++) {
            if (big_record[j] == big_counter && res[j][0] == -1) {
                index = j;
            }
        }
        res[index] = new_person;
        for (int j = index + 1; j < num; j++) {
            big_record[j]--;
        }
    }
    return res;
}

vector<vector<int>> reconstructQueue2(vector<vector<int>> &people) {
    vector<vector<int>> res;
    sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        } else {
            return a[0] > b[0];
        }
    });
    for (auto s : people) {
        res.insert(res.begin() + s[1], s);
    }
    return res;
}

int main() {
    vector<vector<int>> tt{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> tt2{{9, 0}, {7, 0}, {1, 9}, {3, 0}, {2, 7}, {5, 3}, {6, 0}, {3, 4}, {6, 2}, {5, 2}};
    auto res = reconstructQueue2(tt2);
    for (auto &r : res) {
        for (auto &ri : r) {
            std::cout << ri << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
