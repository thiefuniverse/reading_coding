#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< vector< int > > levelOrder(TreeNode *root) {
    if (!root) {
        return {};
    }
    queue< TreeNode * > q;
    vector< vector< int > > result;
    q.push(root);
    bool rever = true;
    while (!q.empty()) {
        auto size = q.size();
        vector< int > oneLevel;
        for (int i = 0; i < size; ++i) {
            auto f = q.front();
            q.pop();
            oneLevel.push_back(f->val);
            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
        }
        if (!rever) {
            reverse(oneLevel.begin(), oneLevel.end());
        }
        result.push_back(oneLevel);
        rever = !rever;
    }
    return result;
}
int main() {

    return 0;
}
