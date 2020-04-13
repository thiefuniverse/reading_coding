#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    return 0;
}
bool isSubStructureHelper(TreeNode *A, TreeNode *B) {
    if (!A && B) {
        return false;
    }
    if (A && !B) {
        return true;
    }
    if (!A && !B) {
        return true;
    }
    if (A->val == B->val) {
        return isSubStructureHelper(A->left, B->left) && isSubStructureHelper(A->right, B->right);
    } else {
        return false;
    }
}
bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (!A || !B) {
        return false;
    }
    if (A->val == B->val) {
        return isSubStructureHelper(A->left, B->left) && isSubStructureHelper(A->right, B->right);
    } else {
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
}
