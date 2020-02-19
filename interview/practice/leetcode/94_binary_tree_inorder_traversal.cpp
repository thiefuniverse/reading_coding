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

// recursion
void inorderTraversalHelper(TreeNode *root, vector<int> &result) {
    if (!root) {
        return;
    }
    if (root->left) {
        inorderTraversalHelper(root->left, result);
    }
    result.push_back(root->val);
    if (root->right) {
        inorderTraversalHelper(root->right, result);
    }
}
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    inorderTraversalHelper(root, result);
    return result;
}

// iteration
vector<int> inorderTraversal2(TreeNode *root) {
    if (!root) {
        return {};
    }
    vector<int> result;
    stack<TreeNode *> s;
    s.push(root);
    TreeNode *p = root;
    while (!s.empty()) {
        auto t = s.top();
        if (t->left != nullptr && p != nullptr) {
            s.push(t->left);
        } else {
            // handle data
            result.push_back(t->val);
            s.pop();
            p = t->right;
            if (p) {
                s.push(p);
            }
        }
    }
    return result;
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
    //    t1.right = &t3;
    t2.right = &t4;
    // t2.right = &t5;
    t3.left = &t6;
    // t3.right = &t7;

    auto res = inorderTraversal2(&t1);
    for (int i = 0; i < res.size(); i++) {
        for (auto &j : res) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
