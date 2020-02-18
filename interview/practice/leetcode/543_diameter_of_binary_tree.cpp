#include <deque>
#include <iostream>
#include <map>
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

// slowly now. :(
int DepthBinaryTree(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int l_len = 0, r_len = 0;
    if (root->left) {
        l_len = 1 + DepthBinaryTree(root->left);
    }
    if (root->right) {
        r_len = 1 + DepthBinaryTree(root->right);
    }
    return max(l_len, r_len);
}

int diameterOfBinaryTree(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int left_len = 0, right_len = 0;
    if (root->left) {
        left_len = 1 + DepthBinaryTree(root->left);
    }
    if (root->right) {
        right_len = 1 + DepthBinaryTree(root->right);
    }
    return max({left_len + right_len, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
}

// add a record
int DepthBinaryTree2(TreeNode *root, map< TreeNode *, int > &depth_record) {
    if (!root) {
        return 0;
    }
    int l_len = 0, r_len = 0;
    if (depth_record.find(root) != depth_record.end()) {
        return depth_record[root];
    }
    if (root->left) {
        l_len = 1 + DepthBinaryTree2(root->left, depth_record);
    }
    if (root->right) {
        r_len = 1 + DepthBinaryTree2(root->right, depth_record);
    }
    int depth = max(l_len, r_len);
    depth_record[root] = depth;
    return depth;
}

int diameterOfBinaryTree2_Helper(TreeNode *root, map< TreeNode *, int > &depth_record) {
    if (!root) {
        return 0;
    }
    int left_len = 0, right_len = 0;
    if (root->left) {
        left_len = 1 + DepthBinaryTree2(root->left, depth_record);
    }
    if (root->right) {
        right_len = 1 + DepthBinaryTree2(root->right, depth_record);
    }
    return max({left_len + right_len, diameterOfBinaryTree2_Helper(root->left, depth_record), diameterOfBinaryTree2_Helper(root->right, depth_record)});
}

int diameterOfBinaryTree2(TreeNode *root) {
    map< TreeNode *, int > depth_record;
    return diameterOfBinaryTree2_Helper(root, depth_record);
}

// version 3
int diameterOfBinaryTree3_Helper(TreeNode *root, int &max_result) {
    if (!root) {
        return 0;
    }
    int left_len = 0, right_len = 0;
    if (root->left) {
        left_len = 1 + diameterOfBinaryTree3_Helper(root->left, max_result);
    }
    if (root->right) {
        right_len = 1 + diameterOfBinaryTree3_Helper(root->right, max_result);
    }
    max_result = max(left_len + right_len, max_result);
    return max(right_len, left_len);
}

int diameterOfBinaryTree3(TreeNode *root) {
    int max_result = 0;
    diameterOfBinaryTree3_Helper(root, max_result);
    return max_result;
}

//version 4: iteration
int diameterOfBinaryTree4(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int max_result = 0;
    stack< TreeNode * > s;
    map< TreeNode *, pair< int, int > > record;
    record[nullptr] = make_pair(0, 0);
    TreeNode *pre = nullptr;
    s.push(root);
    // get depth of each node
    // 中序遍历二叉树,并记录深度左右分叉和的最大值
    while (!s.empty()) {
        auto t = s.top();
        if (t->left == nullptr && t->right == nullptr) {
            pre = t;
            record[t] = make_pair(0, 0);
            s.pop();
        } else if (pre && pre == t->left) {
            // access it
            record[t].first = 1 + max(record[pre].first, record[pre].second);
            max_result = max(record[t].first, max_result);
            pre = t;
            s.pop();
        } else if (pre && pre == t->right) {
            // access it
            if (t->left) {
                record[t].first = 1 + max(record[t->left].first, record[t->left].second);
            } else {
                record[t].first = 0;
            }
            record[t].second = 1 + max(record[pre].first, record[pre].second);
            max_result = max(record[t].first + record[t].second, max_result);
            pre = t;
            s.pop();
        } else {
            if (t->right) s.push(t->right);
            if (t->left) s.push(t->left);
        }
    }
    return max_result;
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
    t6.right = &t7;

    std::cout << diameterOfBinaryTree2(&t1) << std::endl;
    std::cout << diameterOfBinaryTree3(&t1) << std::endl;
    std::cout << diameterOfBinaryTree4(&t1) << std::endl;
    return 0;
}
