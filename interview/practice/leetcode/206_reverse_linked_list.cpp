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

// recursion version
ListNode *reverseListImpl(ListNode *head, ListNode *&real_head) {
    if (!head) {
        return nullptr;
    }
    ListNode *new_head = reverseListImpl(head->next, real_head);
    if (!new_head) {
        real_head = head;
        return head;
    } else {
        new_head->next = head;
        head->next = nullptr;
    }
    return head;
}

ListNode *reverseList(ListNode *head) {
    ListNode *real_head = nullptr;
    reverseListImpl(head, real_head);
    return real_head;
}

// iteration version
ListNode *reverseList2(ListNode *head) {
    ListNode root(0);
    ListNode *new_head = &root, *fake_root = nullptr;

    while (head) {
        fake_root = head;
        head = head->next;
        fake_root->next = new_head->next;
        new_head->next = fake_root;
    }
    return new_head->next;
}

// iteration version, no need one node instantiation
ListNode *reverseList3(ListNode *head) {
    ListNode *new_head = nullptr, *fake_root = nullptr;
    ListNode *real_head = nullptr;
    while (head) {
        // get head node
        fake_root = head;
        head = head->next;

        if (!new_head) {
            new_head = fake_root;
            new_head->next = nullptr;
        } else {
            fake_root->next = new_head;
            new_head = fake_root;
        }
    }
    return new_head;
}

// steal from leetcode
ListNode *reverseList4(ListNode *head) {
    ListNode *new_head = nullptr, *cur_head = nullptr;
    while (head) {
        cur_head = head->next;
        head->next = new_head;
        new_head = head;
        head = cur_head;
    }
    return new_head;
}
// beautiful recuision
ListNode *reverseList5(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *new_head = reverseList5(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

int main() {
    vector< int > a1{1};
    vector< int > a2{5, 6, 4, 3, 2};
    vector< int > a3{};
    vector< int > a4{5, 3, 4, 5};

    auto a1_l = ConstructList(a1);
    auto a2_l = ConstructList(a2);
    auto a3_l = ConstructList(a3);
    auto a4_l = ConstructList(a4);

    PrintList(reverseList5(a1_l));
    PrintList(reverseList5(a2_l));
    PrintList(reverseList5(a3_l));
    PrintList(reverseList5(a4_l));

    FreeList(a1_l);
    FreeList(a2_l);
    FreeList(a3_l);
    FreeList(a4_l);
    return 0;
}
