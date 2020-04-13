#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
ListNode *deleteNode(ListNode *head, int val) {
    if (!head) {
        return nullptr;
    }
    // head is deleted
    if (head->val == val) {
        ListNode *nextHead = head->next;
        head->next = nullptr;
        return nextHead;
    }
    ListNode *pre = head;
    ListNode *oldHead = head;
    head = head->next;
    while (head) {
        if (head->val == val) {
            pre->next = head->next;
            head->next = nullptr;
            break;
        }
        pre = head;
        head = head->next;
    }
    return oldHead;
}

int main() {

    return 0;
}
