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

TreeNode *reconstructfrontBT(vector< int > &front, int f_start, int f_end, vector< int > &mid, int m_start, int m_end) {
    if (f_end - f_start != m_end - m_start) {
        std::cout << "two vector size doesn't match" << std::endl;
        assert(false);
        return nullptr;
    }
    if (f_start > f_end || m_start > m_end) {
        return nullptr;
    }
    auto current_head = new TreeNode(front[f_start]);
    int mid_flag = m_start;
    for (; mid_flag <= m_end; mid_flag++) {
        if (mid[mid_flag] == front[f_start]) {
            break;
        }
    }
    int left_mid_end = mid_flag - 1;
    int left_mid_start = m_start;
    int right_mid_start = mid_flag + 1;
    int right_mid_end = m_end;

    int left_size = mid_flag - m_start;
    int right_size = m_end - mid_flag;

    int left_front_end = f_start + left_size;
    int left_front_start = f_start + 1;
    int right_front_start = f_start + left_size + 1;
    int right_front_end = f_end;

    current_head->left = reconstructfrontBT(front, left_front_start, left_front_end, mid, left_mid_start, left_mid_end);
    current_head->right = reconstructfrontBT(front, right_front_start, right_front_end, mid, right_mid_start, right_mid_end);
    return current_head;
}

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
// 中序
void midBT(TreeNode *root) {
    if (!root) {
        return;
    }
    midBT(root->left);
    std::cout << root->val << " ";
    midBT(root->right);
}

void test(vector< int > &f1, vector< int > &f2) {
    std::cout << "begin test one" << std::endl;
    auto c_l = reconstructfrontBT(f1, 0, f1.size() - 1, f2, 0, f2.size() - 1);
    frontBT(c_l);
    std::cout << std::endl;
    midBT(c_l);
    std::cout << std::endl;
    std::cout << "done test one" << std::endl;
}
int main() {
    TreeNode t1(10);
    TreeNode t2(6);
    TreeNode t3(14);
    TreeNode t4(4);
    TreeNode t5(8);
    TreeNode t6(12);
    TreeNode t7(16);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;

    frontBT(&t1);
    std::cout << std::endl;
    midBT(&t1);
    std::cout << std::endl;
    vector< int > f1{1, 2, 4, 7, 3, 5, 6, 8};
    vector< int > f2{4, 7, 2, 1, 5, 3, 8, 6};
    vector< int > f3{1, 2, 4, 5, 3, 6, 7};
    vector< int > f4{4, 2, 5, 1, 6, 3, 7};
    vector< int > f5{1, 2, 4, 5, 7, 3, 6};
    vector< int > f6{4, 2, 7, 5, 1, 3, 6};
    vector< int > f7{1, 2, 3, 4};
    vector< int > f8{4, 3, 2, 1};
    test(f1, f2);
    test(f3, f4);
    test(f5, f6);
    test(f7, f7);
    test(f7, f8);
    return 0;
}
