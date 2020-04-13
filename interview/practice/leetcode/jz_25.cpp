#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    return 0;
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    ListNode *head = nullptr;
    if (l1->val > l2->val) {
        head = l2;
        l2 = l2->next;
    } else {
        head = l1;
        l1 = l1->next;
    }
    ListNode *origin = head;
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
    return origin;
}
