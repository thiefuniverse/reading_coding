#include <deque>
#include <iostream>
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

TreeNode *invertTree(TreeNode *root) {
    if (!root) {
        return nullptr;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// now we want a iteration version :)
TreeNode *invertTree2(TreeNode *root) {
    if (!root) {
        return nullptr;
    }
    stack< TreeNode * > s;
    s.push(root);
    while (!s.empty()) {
        auto top = s.top();
        s.pop();
        swap(top->left, top->right);
        if (top->left) {
            s.push(top->left);
        }
        if (top->right) {
            s.push(top->right);
        }
    }
    return root;
}

int main() {
    TreeNode t1(10);
    TreeNode t2(6);
    TreeNode t3(14);
    TreeNode t4(4);
    TreeNode t5(8);
    TreeNode t6(12);
    TreeNode t7(16);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;

    frontBT(&t1);
    std::cout << std::endl;
    TreeNode *new_t1 = invertTree2(&t1);
    frontBT(new_t1);
    std::cout << std::endl;

    return 0;
}
