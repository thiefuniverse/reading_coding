#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    return 0;
}

void pathSumHelper(TreeNode *root, int left_sum, vector< int > cur_path, vector< vector< int > > &result) {
    if (!root) {
        return;
    }
    if (root->val == left_sum && !root->left && !root) {
        cur_path.push_back(root->val);
        result.push_back(cur_path);
    }
    pathSumHelper(root->left, left_sum - root->val, result);
    pathSumHelper(root->right, left_sum - root->val, result);
}

vector< vector< int > > pathSum(TreeNode *root, int sum) {
    vector< vector< int > > result;
    pathSumHelper(root, sum, result);
    return result;
}
