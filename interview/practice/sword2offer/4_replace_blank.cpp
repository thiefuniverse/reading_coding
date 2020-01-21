#include <iostream>
#include <string>
#include <vector>
using namespace std;

void replaceBlank(char str[], int len) {
    int all_spaces = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            all_spaces++;
        }
    }
    int target_index = len + all_spaces * 2 - 1;
    int current_space_num = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            // str here is original string. we can change it to another new string.
            str[target_index--] = '0';
            str[target_index--] = '2';
            str[target_index--] = '%';
        } else {

            str[target_index--] = str[i];
        }
    }
}

void mergeTwoOrderArray(vector< int > &a, vector< int > &b) {
    int a_size = a.size(), b_size = b.size();
    a.resize(a_size + b_size);
    int a_index = a_size - 1;
    int b_index = b_size - 1;
    int all_index = a_size + b_size - 1;
    while (a_index >= 0 || b_index >= 0) {
        if (a_index < 0) {
            a[all_index--] = b[b_index];
            b_index--;
        }
        if (b_index < 0) {
            a[all_index--] = a[a_index];
            a_index--;
        }
        if (a_index >= 0 && b_index >= 0) {
            if (a[a_index] > b[b_index]) {
                a[all_index--] = a[a_index];
                a_index--;
            } else {
                a[all_index--] = b[b_index];
                b_index--;
            }
        }
    }
    for (auto &aa : a) {
        std::cout << aa << " ";
    }
    std::cout << std::endl;
}
int main() {
    char test1[20] = "we are thief.";
    replaceBlank(test1, 13);
    std::cout << test1 << std::endl;

    char test2[20] = "we are   ";
    replaceBlank(test2, 9);
    std::cout << test2 << std::endl;

    char test3[20] = "   we ";
    replaceBlank(test3, 6);
    std::cout << test3 << std::endl;

    char test4[20] = "universe";
    replaceBlank(test4, 8);
    std::cout << test4 << std::endl;

    // test merge array
    vector< int > a1{1, 3, 5, 6, 7};
    vector< int > a2{2, 3, 6, 8, 10};
    vector< int > a3;
    vector< int > a4{3, 6, 8, 10};

    mergeTwoOrderArray(a1, a2);
    mergeTwoOrderArray(a3, a4);
    return 0;
}
