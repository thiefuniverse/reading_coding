#include <deque>
#include <iostream>
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

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr) {
        return t2;
    }
    if (t2 == nullptr) {
        return t1;
    }
    if (t1 && t2) {
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
    }
    return t1;
}
TreeNode *mergeTrees2(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr) {
        return t2;
    }
    if (t2 == nullptr) {
        return t1;
    }
    stack< TreeNode * > s1, s2;
    s1.push(t1);
    s2.push(t2);
    while (!s1.empty() && !s2.empty()) {
        auto m1 = s1.top();
        auto m2 = s2.top();
        s1.pop();
        s2.pop();
        m1->val += m2->val;
        if (m2->left && !m1->left) {
            m1->left = m2->left;
        } else if (m2->left && m1->left) {
            s1.push(m1->left);
            s2.push(m2->left);
        }
        if (m2->right && !m1->right) {
            m1->right = m2->right;
        } else if (m2->right && m1->right) {
            s1.push(m1->right);
            s2.push(m2->right);
        }
    }
    return t1;
}

int main() {
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(1);
    TreeNode t5(2);
    TreeNode t6(3);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t4.left = &t5;
    t4.right = &t6;

    mergeTrees(nullptr, nullptr);
    mergeTrees(&t1, &t4);
    return 0;
}
