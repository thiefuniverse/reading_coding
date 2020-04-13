#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< int > levelOrder(TreeNode *root) {
    if (!root) {
        return {};
    }
    queue< TreeNode * > q;
    vector< int > result;
    q.push(root);
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        result.push_back(f->val);
        if (f->left) {
            q.push(f->left);
        }
        if (f->right) {
            q.push(f->right);
        }
    }
    return result;
}
int main() {

    return 0;
}
