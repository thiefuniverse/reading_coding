#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
    if (!left && !right) {
        return true;
    }
    if ((!left && right) || (left && !right)) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    } else {
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
}
bool isSymmetric(TreeNode *root) {
    if (!root) {
        return true;
    }
    return isSymmetricHelper(root->left, root->right);
}
int main() {

    return 0;
}
