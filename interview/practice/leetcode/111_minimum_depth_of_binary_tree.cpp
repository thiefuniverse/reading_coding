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
int minDepth(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int l = 0, r = 0;
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    int min_result = INT_MAX;
    if (root->left) {
        l = 1 + minDepth(root->left);
        min_result = min(min_result, l);
    }
    if (root->right) {
        r = 1 + minDepth(root->right);
        min_result = min(min_result, r);
    }
    return min_result;
}

// version 2: recusion
int minDepth2(TreeNode *root) {
    if (!root) {
        return 0;
    }
    if (!root->left) {
        return 1 + minDepth(root->right);
    }
    if (!root->right) {
        return 1 + minDepth(root->left);
    }
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// version 3: bfs
int minDepth3(TreeNode *root) {
    if (!root) {
        return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    int cur_depth = 0;
    while (!q.empty()) {
        auto size = q.size();
        cur_depth++;
        for (int i = 0; i < size; i++) {
            auto f = q.front();
            q.pop();
            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
            if (f->left == nullptr && f->right == nullptr) {
                return cur_depth;
            }
        }
    }
    return cur_depth;
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
    // t2.right = &t5;
    t3.left = &t6;
    // t3.right = &t7;

    std::cout << minDepth3(&t1) << std::endl;
    return 0;
}
