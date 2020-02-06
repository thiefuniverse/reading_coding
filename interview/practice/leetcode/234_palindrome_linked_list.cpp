#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *ConstructList(vector< int > &v) {
    ListNode *result = nullptr;
    ListNode *head = nullptr;
    if (v.size() > 0) {
        head = new ListNode(v[0]);
    }
    result = head;
    for (int i = 1; i < v.size(); i++) {
        head->next = new ListNode(v[i]);
        head = head->next;
    }
    return result;
}

void FreeList(ListNode *l) {
    ListNode *old_n = l;
    ListNode *n = l;
    while (n) {
        old_n = n;
        n = n->next;
        delete old_n;
    }
}
void PrintList(ListNode *l) {
    ListNode *n = l;
    std::cout << "list: ";
    while (n) {
        std::cout << n->val << " ";
        n = n->next;
    }
    std::cout << std::endl;
}

// steal idea from leetcode
// reverse half, compare, restore list.
bool isPalindrome(ListNode *head) {
    if (!head || !head->next) {
        return true;
    }
    int len = 0;
    ListNode *root_head = head;
    while (root_head) {
        len++;
        root_head = root_head->next;
    }
    int mid_len = len / 2;
    root_head = head;

    // reverse half list
    ListNode *new_head = nullptr;
    int new_half_len = 0;
    while (root_head) {
        ListNode *cur = root_head->next;
        root_head->next = new_head;
        new_head = root_head;
        root_head = cur;
        new_half_len++;
        if (new_half_len == mid_len) {
            break;
        }
    }
    // left: new_head
    ListNode *mid_head = root_head;
    if (len % 2) {
        root_head = root_head->next;
    }
    bool result = true;
    // compare
    while (new_head && root_head) {
        if (new_head->val != root_head->val) {
            result = false;
            break;
        }
        new_head = new_head->next;
        root_head = root_head->next;
    }
    if (!new_head && !root_head) {
        result = true;
    } else {
        result = false;
    }

    // restore list
    ListNode *result_head = mid_head;
    while (new_head) {
        ListNode *cur = new_head->next;
        new_head->next = result_head;
        result_head = new_head;
        new_head = cur;
    }
    return result;
}

// recursion, so graceful.
ListNode *tmp_head = nullptr;
bool check(ListNode *head) {
    if (!head) {
        return true;
    }
    bool isPal = check(head->next) & head->val == tmp_head->val;
    tmp_head = tmp_head->next;
    return isPal;
}
bool isPalindrome2(ListNode *head) {
    tmp_head = head;
    return check(head);
}

int main() {
    vector< int > a1{1};
    vector< int > a2{5, 6, 4, 6, 5};
    vector< int > a3{};
    vector< int > a4{5, 3, 3};

    auto a1_l = ConstructList(a1);
    auto a2_l = ConstructList(a2);
    auto a3_l = ConstructList(a3);
    auto a4_l = ConstructList(a4);
    std::cout << isPalindrome2(a1_l) << std::endl;
    std::cout << isPalindrome2(a2_l) << std::endl;
    std::cout << isPalindrome2(a3_l) << std::endl;
    std::cout << isPalindrome2(a4_l) << std::endl;

    return 0;
}
