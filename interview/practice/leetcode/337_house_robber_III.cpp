#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void rob_helper(TreeNode *node, map< TreeNode *, vector< int > > &dp) {
    if (!node) {
        return;
    }
    dp[node] = vector< int >(2, 0);
    auto l = node->left, r = node->right;
    if (!l && !r) {
        dp[node][1] = node->val;
        return;
    }
    rob_helper(l, dp);
    rob_helper(r, dp);
    dp[node][0] = max({dp[l][1] + dp[r][1], dp[l][0] + dp[r][0], dp[l][0] + dp[r][1], dp[l][1] + dp[r][0]});
    dp[node][1] = dp[l][0] + dp[r][0] + node->val;
}
// maybe it's slowly. :(
// ...hummmm. really slowly.
int rob(TreeNode *root) {
    if (!root) {
        return 0;
    }
    map< TreeNode *, vector< int > > dp;
    dp[nullptr] = vector< int >(2, 0);
    rob_helper(root, dp);
    return max(dp[root][0], dp[root][1]);
}

// hmmmmmm :) now we know that almost all dp memory can be O(1)......
pair< int, int > rob_helper2(TreeNode *node) {
    if (!node) {
        return {0, 0};
    }
    if (!node->left && !node->right) {
        return {0, node->val};
    }
    auto l = node->left, r = node->right;
    auto l_val = rob_helper2(l);
    auto r_val = rob_helper2(r);
    auto max_l_r = max(l_val.first, l_val.second) + max(r_val.first, r_val.second);
    return {max_l_r, node->val + l_val.first + r_val.first};
}

int rob2(TreeNode *root) {
    if (!root) {
        return 0;
    }
    auto result = rob_helper2(root);
    return max(result.first, result.second);
}

int main() {
    TreeNode l1(3);
    l1.left = new TreeNode(2);
    l1.left->right = new TreeNode(3);
    l1.right = new TreeNode(3);
    l1.right->right = new TreeNode(1);

    std::cout << rob(&l1) << std::endl;
    std::cout << rob2(&l1) << std::endl;
    TreeNode m1(3);
    m1.left = new TreeNode(4);
    m1.left->right = new TreeNode(3);
    m1.left->left = new TreeNode(1);
    m1.right = new TreeNode(5);
    m1.right->right = new TreeNode(1);

    std::cout << rob(&m1) << std::endl;
    std::cout << rob2(&m1) << std::endl;

    TreeNode n1(2);
    n1.left = new TreeNode(1);
    n1.right = new TreeNode(3);
    n1.left->right = new TreeNode(4);

    std::cout << rob(&n1) << std::endl;
    std::cout << rob2(&n1) << std::endl;

    return 0;
}
