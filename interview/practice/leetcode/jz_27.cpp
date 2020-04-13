#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

TreeNode *mirrorTree(TreeNode *root) {
    if (!root) {
        return root;
    }
    swap(root->left, root->right);
    root->left = mirrorTree(root->left);
    root->right = mirrorTree(root->right);
    return root;
}
int main() {

    return 0;
}
