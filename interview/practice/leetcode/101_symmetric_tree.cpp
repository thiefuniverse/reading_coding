#include <deque>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursion
// 先序
void frontBT(TreeNode *root) {
    if (!root) {
        return;
    }
    std::cout << root->val << " ";
    frontBT(root->left);
    frontBT(root->right);
}
bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
    if (!left && !right) {
        return true;
    }
    if (left && !right) {
        return false;
    }
    if (!left && right) {
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

// verison 2: iteration
bool isSymmetric2(TreeNode *root) {
    if (!root) {
        return true;
    }
    stack< pair< TreeNode *, TreeNode * > > s;
    s.push(make_pair(root->left, root->right));
    while (!s.empty()) {
        auto t = s.top();
        s.pop();

        if ((t.first && !t.second) || (!t.first && t.second)) {
            return false;
        }
        if (t.first && t.second) {
            if (t.first->val != t.second->val) {
                return false;
            } else {
                s.push(make_pair(t.first->left, t.second->right));
                s.push(make_pair(t.first->right, t.second->left));
            }
        }
    }
    return true;
}

int main() {
    TreeNode t1(10);
    TreeNode t2(6);
    TreeNode t3(6);
    TreeNode t4(4);
    TreeNode t5(8);
    TreeNode t6(8);
    TreeNode t7(4);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;

    std::cout << isSymmetric(&t1) << std::endl;
    std::cout << isSymmetric2(&t1) << std::endl;
    std::cout << isSymmetric(&t2) << std::endl;
    std::cout << isSymmetric2(&t2) << std::endl;
    return 0;
}
