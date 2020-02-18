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
TreeNode *getDepthAndParent(TreeNode *root, int x, int cur_depth, int &depth) {
    if (!root) {
        return nullptr;
    }
    if (root->val == x) {
        depth = 0;
        return nullptr;
    }
    TreeNode *l = nullptr, *r = nullptr;
    if (root->left) {
        if (root->left->val == x) {
            depth = cur_depth + 1;
            return root;
        }
        l = getDepthAndParent(root->left, x, cur_depth + 1, depth);
    }
    if (root->right) {
        if (root->right->val == x) {
            depth = cur_depth + 1;
            return root;
        }
        r = getDepthAndParent(root->right, x, cur_depth + 1, depth);
    }
    if (l) {
        return l;
    }
    if (r) {
        return r;
    }
    return nullptr;
}

bool isCousins(TreeNode *root, int x, int y) {
    if (!root) {
        return false;
    }
    int d1 = 0, d2 = 0;
    auto xp = getDepthAndParent(root, x, 0, d1);
    auto yp = getDepthAndParent(root, y, 0, d2);
    if (xp != yp && d1 == d2) {
        return true;
    }
    return false;
}

// version 2: iteration :)
bool isCousins2(TreeNode *root, int x, int y) {
    if (!root) {
        return false;
    }
    queue< pair< TreeNode *, int > > s;
    s.push(make_pair(root, 0));
    int parent = -1;
    while (!s.empty()) {
        int size = s.size();
        for (int i = 0; i < size; i++) {
            auto f = s.front();
            if (f.first->val == x || f.first->val == y) {
                if (parent != -1) {
                    if (parent == f.second) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    parent = f.second;
                }
            }
            s.pop();
            if (f.first->left) {
                s.push(make_pair(f.first->left, f.first->val));
            }
            if (f.first->right) {
                s.push(make_pair(f.first->right, f.first->val));
            }
        }
        if (parent != -1) {
            return false;
        }
    }
    return false;
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

    std::cout << isCousins2(&t1, 3, 9) << std::endl;
    //    std::cout << isCousins2(&t1, 6, 7) << std::endl;
    return 0;
}
