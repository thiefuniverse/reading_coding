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

ListNode *ConstructList(vector<int> &v) {
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
        return nullptr;
    }
    int lenA = 0, lenB = 0;
    ListNode *ha = headA, *hb = headB;
    while (headA) {
        lenA++;
        headA = headA->next;
    }
    while (headB) {
        lenB++;
        headB = headB->next;
    }
    if (lenB > lenA) {
        while (lenB > lenA) {
            hb = hb->next;
            lenB--;
        }
    } else {
        while (lenA > lenB) {
            ha = ha->next;
            lenA--;
        }
    }
    while (ha && hb) {
        if (ha == hb) {
            return ha;
        } else {
            ha = ha->next;
            hb = hb->next;
        }
    }
    return nullptr;
}

// steal cool solution from leetcode
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
        return nullptr;
    }
    ListNode *ha = headA, *hb = headB;
    if (ha == hb) {
        return ha;
    }
    while (ha != hb) {
        ha = ha->next;
        hb = hb->next;
        if (ha == hb) {
            return ha;
        }
        if (ha == nullptr) {
            ha = headB;
        }
        if (hb == nullptr) {
            hb = headA;
        }
    }
    return ha;
}
int main() {
    vector<int> a1{1};
    vector<int> a2{5, 6, 4, 3, 2};
    vector<int> a3{};
    vector<int> a4{5, 3, 4, 5};

    auto a1_l = ConstructList(a1);
    auto a2_l = ConstructList(a2);
    auto a3_l = ConstructList(a3);
    auto a4_l = ConstructList(a4);

    a1_l->next = a4_l->next->next;
    //    a4_l->next->next->next->next = a4_l->next;
    std::cout << getIntersectionNode(a1_l, a4_l)->val << std::endl;

    return 0;
}
