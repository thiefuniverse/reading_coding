#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *root = nullptr;
    if (!l1 && !l2) {
        return nullptr;
    }
    if (l1 && !l2) {
        return l1;
    }
    if (l2 && !l1) {
        return l2;
    }
    if (l1->val < l2->val) {
        root = l1;
        l1 = l1->next;
    } else {
        root = l2;
        l2 = l2->next;
    }

    ListNode *head = root;
    while (l1 || l2) {
        if (!l1) {
            root->next = l2;
            break;
        }
        if (!l2) {
            root->next = l1;
            break;
        }
        if (l1->val < l2->val) {
            root->next = l1;
            l1 = l1->next;
            root = root->next;
        } else {
            root->next = l2;
            l2 = l2->next;
            root = root->next;
        }
    }
    return head;
}

// from leetcode
ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
    ListNode root(0);
    ListNode *head = &root;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            head->next = l1;
            l1 = l1->next;
        } else {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }
    if (l1) {
        head->next = l1;
    } else {
        head->next = l2;
    }
    return root.next;
}

int main() {
    vector< int > a1{2, 3, 4};
    vector< int > a2{4, 5, 6};
    vector< int > a3{5, 6, 7, 9, 33};
    vector< int > a4{1, 5, 8, 10};
    vector< int > a5{6};
    vector< int > a6{3};
    vector< int > a7{0};
    vector< int > a8{7, 3};
    vector< int > a9{};
    vector< int > a10{};

    auto a1_l = ConstructList(a1);
    auto a2_l = ConstructList(a2);
    auto a3_l = ConstructList(a3);
    auto a4_l = ConstructList(a4);
    auto a5_l = ConstructList(a5);
    auto a6_l = ConstructList(a6);
    auto a7_l = ConstructList(a7);
    auto a8_l = ConstructList(a8);
    auto a9_l = ConstructList(a9);
    auto a10_l = ConstructList(a10);

    auto m12 = mergeTwoLists2(a1_l, a2_l);
    PrintList(m12);
    auto m34 = mergeTwoLists2(a3_l, a4_l);
    PrintList(m34);
    auto m56 = mergeTwoLists2(a5_l, a6_l);
    PrintList(m56);
    auto m78 = mergeTwoLists2(a7_l, a8_l);
    PrintList(m78);
    auto m910 = mergeTwoLists2(a9_l, a10_l);
    PrintList(m910);

    return 0;
}
