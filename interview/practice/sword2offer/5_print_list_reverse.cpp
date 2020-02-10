#include <iostream>
#include <stack>
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

// recursion
void printListReverse(ListNode *head) {
    if (!head) {
        return;
    }
    printListReverse(head->next);
    std::cout << head->val << " ";
}

// stack
void printListReverse2(ListNode *head) {
    if (!head) {
        return;
    }
    stack< int > list_stack;
    while (head) {
        list_stack.push(head->val);
        head = head->next;
    }
    while (!list_stack.empty()) {
        auto top = list_stack.top();
        std::cout << top << " ";
        list_stack.pop();
    }
}

int main() {
    vector< int > a1{2, 3, 4};
    vector< int > a2{4, 5, 6, 7, 9, 20};

    auto a1_l = ConstructList(a1);
    auto a2_l = ConstructList(a2);
    printListReverse(a1_l);
    std::cout << std::endl;
    printListReverse2(a1_l);
    std::cout << std::endl;
    printListReverse(a2_l);
    std::cout << std::endl;
    printListReverse2(a2_l);
    std::cout << std::endl;

    return 0;
}
