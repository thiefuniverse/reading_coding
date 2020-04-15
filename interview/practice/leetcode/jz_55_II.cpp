#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    return 0;
}
int isBalancedHelper(TreeNode *root, bool &result) {
    if (!root) {
        return 0;
    }
    int l_len = 0, r_len = 0;
    if (root->left) {
        l_len = isBalancedHelper(root->left, result) + 1;
    }
    if (root->right) {
        r_len = isBalancedHelper(root->right, result) + 1;
    }
    if (abs(l_len - r_len) > 1) {
        result = false;
    }
    return max(l_len, r_len);
}
bool isBalanced(TreeNode *root) {
    if (!root) {
        return true;
    }
    bool result = true;
    isBalancedHelper(root, result);
    return result;
}
