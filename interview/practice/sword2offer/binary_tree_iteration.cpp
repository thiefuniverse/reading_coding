#include <iostream>
#include <queue>
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
// 中序
void midBT(TreeNode *root) {
    if (!root) {
        return;
    }
    midBT(root->left);
    std::cout << root->val << " ";
    midBT(root->right);
}
// 后序
void backBT(TreeNode *root) {
    if (!root) {
        return;
    }
    backBT(root->left);
    backBT(root->right);
    std::cout << root->val << " ";
}

// iteration
// 先序
void frontIBT(TreeNode *root) {
    if (!root) {
        return;
    }
    stack< TreeNode * > s;
    s.push(root);
    while (!s.empty()) {
        auto cur = s.top();
        s.pop();
        // handle node
        std::cout << cur->val << " ";
        if (cur->right) {
            s.push(cur->right);
        }
        if (cur->left) {
            s.push(cur->left);
        }
    }
}

// 中序
void midIBT(TreeNode *root) {
    if (!root) {
        return;
    }
    stack< TreeNode * > s;
    s.push(root);
    TreeNode *p = root;
    while (!s.empty()) {
        while (p != nullptr && !s.empty()) {
            auto cur = s.top();
            if (cur->left)
                s.push(cur->left);
            else {
                break;
            }
        }
        // handle node
        auto cur = s.top();
        std::cout << cur->val << " ";
        s.pop();
        p = cur->right;
        if (p) {
            s.push(p);
        }
    }
}
// 后序
void backIBT(TreeNode *root) {
    if (!root) {
        return;
    }
    stack< TreeNode * > s;
    s.push(root);
    TreeNode *pre = nullptr;
    while (!s.empty()) {
        auto cur = s.top();
        if ((!cur->left && !cur->right) || (pre && (cur->left == pre || cur->right == pre))) {
            // handle node
            s.pop();
            pre = cur;
            std::cout << cur->val << " ";
        } else {
            if (cur->right) {
                s.push(cur->right);
            }
            if (cur->left) {
                s.push(cur->left);
            }
        }
    }
}

//宽度优先
void widthIBT(TreeNode *root) {
    if (!root) {
        return;
    }
    queue< TreeNode * > q;
    q.push(root);

    while (!q.empty()) {
        auto t = q.front();
        std::cout << t->val << " ";

        q.pop();
        if (t->left) {
            q.push(t->left);
        }
        if (t->right) {
            q.push(t->right);
        }
    }
}

// 二叉搜索树
//最大堆

//最小堆

//红黑树

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
    frontIBT(&t1);
    std::cout << std::endl;

    midBT(&t1);
    std::cout << std::endl;
    midIBT(&t1);
    std::cout << std::endl;

    backBT(&t1);
    std::cout << std::endl;
    backIBT(&t1);
    std::cout << std::endl;

    widthIBT(&t1);
    std::cout << std::endl;
    return 0;
}
