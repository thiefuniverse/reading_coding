#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
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

// iteration
void flatten(TreeNode *root) {
    if (!root) {
        return;
    }
    TreeNode *head = root;
    TreeNode *l = nullptr;
    TreeNode *r = nullptr;
    while (root) {
        r = root->right;
        if (root->left) {
            l = root->left;
            root->right = l;
            while (l->right) {
                l = l->right;
            }
            l->right = r;
        }
        root->left = nullptr;
        root = root->right;
    }
}

TreeNode *pre = nullptr;
void flatten2(TreeNode *root) {
    if (!root) {
        return;
    }
    flatten2(root->right);
    flatten2(root->left);
    root->right = pre;
    root->left = nullptr;
    pre = root;
}
int main() {
    TreeNode t1(10);
    TreeNode t2(6);
    TreeNode t3(7);
    TreeNode t4(3);
    TreeNode t5(2);
    TreeNode t6(9);
    TreeNode t7(1);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;

    flatten2(&t1);
    frontBT(&t1);
    return 0;
}
