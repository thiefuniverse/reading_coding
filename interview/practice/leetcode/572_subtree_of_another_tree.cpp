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

bool isSubtreeHelper(TreeNode *s, TreeNode *t) {
    if (!s && !t) {
        return true;
    }
    if ((!s && t) || (s && !t)) {
        return false;
    }
    if (s->val == t->val) {
        return isSubtreeHelper(s->left, t->left) && isSubtreeHelper(s->right, t->right);
    } else {
        return false;
    }
}
bool isSubtree(TreeNode *s, TreeNode *t) {
    if (s == t || t == nullptr) {
        return true;
    }
    if (!s) {
        return false;
    }
    bool result = false;
    if (s->val == t->val) {
        result = isSubtreeHelper(s->left, t->left) && isSubtreeHelper(s->right, t->right);
    }
    if (!result) {
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
}
bool isSubtree2(TreeNode *s, TreeNode *t) {
    if (s == t || t == nullptr) {
        return true;
    }
    if (!s) {
        return false;
    }
    stack< TreeNode * > s1;
    s1.push(s);
    while (!s1.empty()) {
        auto t1 = s1.top();
        s1.pop();
        // std::cout << "now " << std::endl;
        if (t1->val == t->val) {
            // compare subtree
            stack< TreeNode * > m1, m2;
            m1.push(t1);
            m2.push(t);
            bool result = true;
            while (!m1.empty() && !m2.empty()) {
                auto n1 = m1.top();
                auto n2 = m2.top();
                // std::cout << "n1: " << n1->val << std::endl;
                // std::cout << "n2: " << n2->val << std::endl;
                if (n1->val != n2->val) {
                    result = false;
                    break;
                }
                m1.pop();
                m2.pop();
                if ((n1->left && !n2->left) || (!n1->left && n2->left)) {
                    result = false;
                    break;
                } else if (n1->left && n2->left) {
                    m1.push(n1->left);
                    m2.push(n2->left);
                }
                if ((n1->right && !n2->right) || (!n1->right && n2->right)) {
                    result = false;
                    break;
                } else if (n1->right && n2->right) {
                    m1.push(n1->right);
                    m2.push(n2->right);
                }
            }
            if (result) {
                return result;
            }
        }
        if (t1->left) s1.push(t1->left);
        if (t1->right) s1.push(t1->right);
    }
    return false;
}

int main() {
    TreeNode t1(10);
    TreeNode t2(6);
    TreeNode t3(12);
    TreeNode t4(4);
    TreeNode t5(8);
    TreeNode t6(12);
    TreeNode t7(12);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    //    t3.right = &t7;

    std::cout << isSubtree(&t1, &t2) << std::endl;
    std::cout << isSubtree2(&t1, &t2) << std::endl;
    std::cout << isSubtree(&t1, &t4) << std::endl;
    std::cout << isSubtree2(&t1, &t4) << std::endl;
    std::cout << isSubtree(&t1, &t3) << std::endl;
    std::cout << isSubtree2(&t1, &t3) << std::endl;
    std::cout << isSubtree(&t3, &t1) << std::endl;
    std::cout << isSubtree2(&t3, &t6) << std::endl;
    return 0;
}
