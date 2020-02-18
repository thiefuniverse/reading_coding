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

ListNode *detectCycle(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    ListNode *slow = head, *fast = head->next;
    while (slow != fast && fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    } else if (slow == fast) {
        ListNode *current_flag = fast;
        int counter = 1;
        fast = fast->next;
        while (current_flag != fast) {
            counter++;
            fast = fast->next;
        }

        fast = head;
        while (counter > 0) {
            fast = fast->next;
            counter--;
        }
        while (head != fast) {
            head = head->next;
            fast = fast->next;
        }
        return head;
    }
    return nullptr;
}

// version 2: remove counter
ListNode *detectCycle(ListNode *head) {
    if (!head || head->next == nullptr) {
        return nullptr;
    }
    ListNode *slow = head, *fast = head;
    do {
        fast = fast->next->next;
        slow = slow->next;
    } while (slow != fast && fast != nullptr && fast->next != nullptr);

    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    } else if (slow == fast) {
        while (fast != head) {
            head = head->next;
            fast = fast->next;
        }
        return head;
    }
    return nullptr;
}
int main() {
    vector<int> a1{1};
    vector<int> a2{5, 6, 4, 3, 2};
    vector<int> a3{};
    vector<int> a4{2, 3, 4, 5};

    auto a1_l = ConstructList(a1);
    auto a2_l = ConstructList(a2);
    auto a3_l = ConstructList(a3);
    auto a4_l = ConstructList(a4);

    a1_l->next = a1_l;
    a4_l->next->next->next->next = a4_l->next;
    //    std::cout << detectCycle2(a1_l)->val << std::endl;
    std::cout << detectCycle2(a4_l)->val << std::endl;

    return 0;
}
