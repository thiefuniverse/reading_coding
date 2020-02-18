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

bool hasCycle(ListNode *head) {
    if (!head) {
        return false;
    }
    ListNode *slow = head, *fast = head->next;
    while (slow != fast && fast != nullptr && fast->next != nullptr) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    if (fast == nullptr) {
        return false;
    } else if (slow == fast) {
        return true;
    }
    return false;
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

    a1_l->next = a1_l;
    a4_l->next->next->next->next = a4_l->next;
    std::cout << hasCycle(a1_l) << std::endl;
    std::cout << hasCycle(a2_l) << std::endl;
    std::cout << hasCycle(a4_l) << std::endl;

    return 0;
}
