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

vector< vector< int > > levelOrder(TreeNode *root) {
    if (!root) {
        return {};
    }
    queue< TreeNode * > q;
    q.push(root);
    vector< vector< int > > res;
    while (!q.empty()) {
        int size = q.size();
        vector< int > cur;
        for (int i = 0; i < size; i++) {
            auto f = q.front();
            cur.push_back(f->val);
            q.pop();
            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
        }
        res.push_back(cur);
    }
    return res;
}

void levelOrder2_Helper(TreeNode *root, vector< vector< int > > &res, int depth) {
    if (!root) {
        return;
    }
    if (depth == res.size()) {
        res.push_back(vector< int >());
    }
    res[depth].push_back(root->val);
    levelOrder2_Helper(root->left, res, depth + 1);
    levelOrder2_Helper(root->right, res, depth + 1);
}

vector< vector< int > > levelOrder2(TreeNode *root) {
    if (!root) {
        return {};
    }

    vector< vector< int > > res;
    levelOrder2_Helper(root, res, 0);
    return res;
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

    auto res = levelOrder2(&t1);
    for (int i = 0; i < res.size(); i++) {
        for (auto &j : res[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
