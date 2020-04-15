#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    return 0;
}

void kthLargestHelper(TreeNode *root, int k, int &cur_k, int &result) {
    if (!root) {
        return;
    }
    kthLargestHelper(root->right, k, cur_k);
    ++cur_k;
    if (cur_k == k) {
        result = root->val;
        return;
    }
    kthLargestHelper(root->left, k, cur_k);
}
int kthLargest(TreeNode *root, int k) {
    int result = 0;
    return kthLargestHelper(root, k, 0, result);
}
