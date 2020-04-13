#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    return 0;
}
ListNode *reverseList(ListNode *head) {
    if (!head) {
        return head;
    }
    ListNode *newHead = nullptr;
    while (head) {
        ListNode *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}
