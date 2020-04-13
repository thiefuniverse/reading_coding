#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    return 0;
}
int maxDepth(TreeNode *root) {
    if (!root) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
