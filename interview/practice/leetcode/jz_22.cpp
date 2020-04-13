#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    return 0;
}
ListNode *getKthFromEnd(ListNode *head, int k) {
    if (!head || k <= 0) {
        return nullptr;
    }
    int n = k - 1;
    ListNode *origin = head;
    while (n > 0 && origin) {
        --n;
        origin = origin->next;
    }
    while (origin->next) {
        origin = origin->next;
        head = head->next;
    }
    return head;
}
