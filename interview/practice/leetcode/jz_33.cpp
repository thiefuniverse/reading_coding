#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool verifyPostorderHelper(vector< int > &postorder, int left, int right) {
    if (left >= right) {
        return true;
    }
    int cur_root = postorder[right];
    int mid = 0;
    for (int i = left; i < right; ++i) {
        if (postorder[i] > cur_root) {
            mid = i;
            break;
        }
    }
    for (int j = mid; j < right; ++j) {
        if (postorder[j] < cur_root) {
            return false;
        }
    }
    return verifyPostorderHelper(postorder, left, mid - 1) && verifyPostorderHelper(postorder, mid, right - 1);
}
bool verifyPostorder(vector< int > &postorder) {
    int len = postorder.size();
    if (len == 0) {
        return true;
    }
    return verifyPostorderHelper(postorder, 0, len - 1);
}
int main() {

    return 0;
}
