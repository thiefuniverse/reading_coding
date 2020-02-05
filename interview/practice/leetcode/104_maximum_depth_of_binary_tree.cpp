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
int maxDepthImpl(TreeNode *root, int depth) {
    if (root) {
        depth += 1;
        return max(depth, max(maxDepthImpl(root->left, depth), maxDepthImpl(root->right, depth)));
    } else {
        return depth;
    }
}
int maxDepth(TreeNode *root) {
    return maxDepthImpl(root, 0);
}

// iteration
int maxDepth2(TreeNode *root) {
    if (!root) {
        return 0;
    }
    deque< pair< TreeNode *, int > > all_nodes;
    all_nodes.push_back(make_pair(root, 1));
    int result_depth = 0;
    while (!all_nodes.empty()) {
        auto cur_root = all_nodes.front();
        all_nodes.pop_front();
        auto cur_node = cur_root.first;
        int depth = cur_root.second;
        if (!cur_node->left && !cur_node->right) {
            result_depth = max(result_depth, depth);
            continue;
        }
        depth++;
        if (cur_node->left) {
            all_nodes.push_back(make_pair(cur_node->left, depth));
        }
        if (cur_node->right) {
            all_nodes.push_back(make_pair(cur_node->right, depth));
        }
    }
    return result_depth;
}

// steal from leetcode
int maxDepth3(TreeNode *root) {
    if (!root) {
        return 0;
    }
    return max(maxDepth3(root->left), maxDepth3(root->right)) + 1;
}

int main() {
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(1);
    TreeNode t5(2);
    TreeNode t6(3);
    //    t1.left = &t2;
    //    t1.right = &t3;
    t4.left = &t5;
    t4.right = &t6;

    t2.left = &t4;
    t3.right = &t2;

    std::cout << maxDepth3(&t1) << std::endl;
    std::cout << maxDepth3(&t4) << std::endl;
    std::cout << maxDepth3(&t2) << std::endl;
    std::cout << maxDepth3(&t3) << std::endl;
    std::cout << maxDepth3(nullptr) << std::endl;
    return 0;
}
