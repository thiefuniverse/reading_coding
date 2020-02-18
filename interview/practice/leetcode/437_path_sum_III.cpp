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

void pathSumHelper(TreeNode *root, int current_sum, int sum, int &result) {
    if (!root) {
        return;
    }
    current_sum += root->val;
    if (current_sum == sum) {
        result++;
    }
    pathSumHelper(root->left, current_sum, sum, result);
    pathSumHelper(root->right, current_sum, sum, result);
}

int pathSum(TreeNode *root, int sum) {
    if (!root) {
        return 0;
    }
    int result = 0;
    pathSumHelper(root, 0, sum, result);
    result += pathSum(root->left, sum);
    result += pathSum(root->right, sum);
    return result;
}

// version2: coooooool solution from leetcode  :)
int pathSum2_Helper(TreeNode *root, map<int, int> cache, int sum, int cur_sum) {
    if (!root) {
        return 0;
    }
    int result = 0;
    cur_sum += root->val;
    cache[cur_sum]++;
    if (cur_sum == sum) {
        result++;
    }
    if (cache.find(cur_sum - sum) != cache.end()) {
        result += cache[cur_sum - sum];
        if (sum == 0) {
            result--;
        }
    }
    result += pathSum2_Helper(root->left, cache, sum, cur_sum);
    result += pathSum2_Helper(root->right, cache, sum, cur_sum);
    return result;
}

int pathSum(TreeNode *root, int sum) {
    map<int, int> cache_sum;
    return pathSum2_Helper(root, cache_sum, sum, 0);
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
    std::cout << pathSum2(&t1, 8) << std::endl;

    return 0;
}
