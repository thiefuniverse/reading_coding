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

bool pathSumHelper(TreeNode *root, int current_sum, int sum) {
    if (!root) {
        return false;
    }
    current_sum += root->val;
    if (root->left == nullptr && root->right == nullptr && current_sum == sum) {
        return true;
    }
    auto l = pathSumHelper(root->left, current_sum, sum);
    if (l) {
        return l;
    }
    auto r = pathSumHelper(root->right, current_sum, sum);
    if (r) {
        return r;
    }
    return false;
}

bool hasPathSum(TreeNode *root, int sum) {
    if (!root) {
        return 0;
    }
    return pathSumHelper(root, 0, sum);
}

// version2 : iteration
bool hasPathSum2(TreeNode *root, int sum) {
    if (!root) {
        return 0;
    }
    stack<pair<TreeNode *, int>> s;
    s.push(make_pair(root, 0));
    while (!s.empty()) {
        auto t = s.top();
        s.pop();

        int cur_sum = t.first->val + t.second;
        if (t.first->left == nullptr && t.first->right == nullptr && cur_sum == sum) {
            return true;
        }
        if (t.first->left) {
            s.push(make_pair(t.first->left, cur_sum));
        }
        if (t.first->right) {
            s.push(make_pair(t.first->right, cur_sum));
        }
    }
    return false;
}

int main() {
    TreeNode t1(10);
    TreeNode t2(5);
    TreeNode t3(-3);
    TreeNode t4(3);
    TreeNode t5(2);
    TreeNode t6(11);
    TreeNode t7(3);
    TreeNode t8(-2);
    TreeNode t9(1);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t4.left = &t7;
    t4.right = &t8;
    t5.right = &t9;

    std::cout << hasPathSum2(&t1, 21) << std::endl;

    return 0;
}
