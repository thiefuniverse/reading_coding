#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    return 0;
}
// v1
bool isCommonAncestor(TreeNode *root, TreeNode *p) {
    if (!root || !p) {
        return false;
    }
    if (root->val == p->val) {
        return true;
    }
    return isCommonAncestor(root->left, p) || isCommonAncestor(root->right, p);
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || !p || !q) {
        return nullptr;
    }
    queue< TreeNode * > que;
    q.push(root);
    TreeNode *result = nullptr;
    while (!que.empty()) {
        auto f = q.front();
        que.pop();
        if (isCommonAncestor(f, p) && isCommonAncestor(f, q)) {
            result = f
        }
        if (f->left) {
            que.push(f->left);
        }
        if (f->right) {
            que.push(f->right);
        }
    }
    return result;
}

//v2

TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root == p || root == q) {
        return root;
    }
    TreeNode *left = lowestCommonAncestor2(root->left, p);
    TreeNode *right = lowestCommonAncestor2(root->right, p);
    if (left && right) {
        return root;
    }
    if (left != nullptr) {
        return left;
    } else {
        return right;
    }
}
