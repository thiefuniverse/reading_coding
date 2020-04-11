#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

TreeNode *buildTreeHelper(vector< int > &preorder, int pstart, int pend, vector< int > &inorder, int istart, int iend) {
    if (pstart > pend) {
        return nullptr;
    }
    int flag = preorder[pstart];
    TreeNode *newRoot = new TreeNode(flag);
    int mid = -1;
    for (int i = istart; i <= iend; ++i) {
        if (inorder[i] == flag) {
            mid = i;
            break;
        }
    }
    int leftSize = mid - istart;
    int rightSize = iend - mid;
    if (leftSize > 0) {
        newRoot->left = buildTreeHelper(preorder, pstart + 1, pstart + leftSize, inorder, istart, istart + leftSize - 1);
    }
    if (rightSize > 0) {
        newRoot->right = buildTreeHelper(preorder, pstart + leftSize + 1, pend, inorder, mid + 1, iend);
    }
    return newRoot;
}
TreeNode *buildTree(vector< int > &preorder, vector< int > &inorder) {
    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}
int main() {

    return 0;
}
