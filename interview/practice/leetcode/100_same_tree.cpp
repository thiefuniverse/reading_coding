#include <deque>
#include <iostream>
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
// version1, recursion
bool isSameTree(TreeNode *p, TreeNode *q) {
    if ((!p && q) || (!q && p)) {
        return false;
    }
    if (!p && !q) {
        return true;
    }
    bool result = false;
    if (p->val == q->val) {
        result = true;
    }
    return result && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// version2, iteration
bool isSameTree2(TreeNode *p, TreeNode *q) {
    deque< pair< TreeNode *, TreeNode * > > all_nodes;
    all_nodes.push_back(make_pair(p, q));
    while (!all_nodes.empty()) {
        auto one = all_nodes.front();
        all_nodes.pop_front();
        if (!one.first && !one.second) {
            continue;
        }
        if ((!one.first && one.second) || (one.first && !one.second)) {
            return false;
        } else {
            if (one.first->val == one.second->val) {
                all_nodes.push_back(make_pair(one.first->left, one.second->left));
                all_nodes.push_back(make_pair(one.first->right, one.second->right));
            } else {
                return false;
            }
        }
    }
    return true;
}
int main() {
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(1);
    TreeNode t5(2);
    TreeNode t6(3);
    t1.left = &t2;
    //    t1.right = &t3;
    t4.left = &t5;
    t4.right = &t6;

    std::cout << isSameTree2(nullptr, nullptr) << std::endl;
    std::cout << isSameTree2(&t1, &t4) << std::endl;
    return 0;
}
