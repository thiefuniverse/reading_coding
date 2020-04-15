#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Encodes a tree to a single string.
string serialize(TreeNode *root) {
    if (!root) {
        return "null,";
    }
    vector< string > result;
    queue< TreeNode * > q;
    result.push_back(std::to_string(root->val));
    q.push(root);
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        if (f == nullptr) {
            result.push_back("null");
        } else {
            if (f->left) {
                result.push_back(std::to_string(f->left->val));
                q.push(f->left);
            } else {
                result.push_back("null");
            }
            if (f->right) {
                result.push_back(std::to_string(f->right->val));
                q.push(f->right);
            } else {
                result.push_back("null");
            }
        }
    }
    string result_str;
    for (auto &str : result) {
        result_str += str;
        result_str += ",";
    }
    return result_str;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data) {
    vector< string > result;
    string word;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == ',') {
            if (!word.empty()) {
                result.push_back(word);
                word.clear();
            }
        } else {
            word += data[i];
        }
    }
    if (result[0] == "null") {
        return nullptr;
    }
    TreeNode *root = new TreeNode(std::atoi(result[0].c_str()));
    int flag = 1;
    queue< TreeNode * > q;
    q.push(root);
    while (flag < result.size()) {
        auto f = q.front();
        q.pop();

        if (result[flag] == "null") {
            f->left = nullptr;
        } else {
            f->left = new TreeNode(std::atoi(result[flag].c_str()));
            q.push(f->left);
        }
        ++flag;
        if (result[flag] == "null") {
            f->right = nullptr;
        } else {
            f->right = new TreeNode(std::atoi(result[flag].c_str()));
            q.push(f->right);
        }
        ++flag;
    }
    return root;
}
int main() {

    return 0;
}
