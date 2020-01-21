#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// this method will change l1 and l2.
ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2) {
    ListNode *result = l1;
    bool carry_flag = false;
    ListNode *old_l1 = l1, *old_l2 = l2;
    ListNode *forward_ptr = result;
    ListNode *old_forward_ptr = result;
    while (l1 || l2) {
        if (l1 && l2) {
            forward_ptr->val = l1->val + l2->val + int(carry_flag);
        }
        if (l1 && !l2) {
            forward_ptr->val = l1->val + int(carry_flag);
        }
        if (!l1 && l2) {
            old_forward_ptr->next = l2;
            forward_ptr = l2;
            forward_ptr->val = l2->val + int(carry_flag);
        }

        carry_flag = false;
        if (forward_ptr->val >= 10) {
            forward_ptr->val %= 10;
            carry_flag = true;
        }
        if (l1) {
            old_l1 = l1;
            l1 = l1->next;
        }

        if (l2) {
            old_l2 = l2;
            l2 = l2->next;
        }
        old_forward_ptr = forward_ptr;
        forward_ptr = forward_ptr->next;
    }
    if (!l1 && !l2) {
        if (carry_flag) {
            old_forward_ptr->next = new ListNode(1);
        }
    }

    return result;
}
// now we create new nodes for result.
ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
    bool carry_flag = false;
    ListNode head_node{0};
    ListNode *forward_ptr = &head_node;
    int sum = 0;
    while (l1 || l2) {
        int v_l1 = 0, v_l2 = 0;
        if (l1) {
            v_l1 = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            v_l2 = l2->val;
            l2 = l2->next;
        }
        sum = v_l1 + v_l2 + ( int )carry_flag;
        carry_flag = false;
        if (sum >= 10) {
            sum %= 10;
            carry_flag = true;
        }
        forward_ptr->next = new ListNode(sum);
        forward_ptr = forward_ptr->next;
    }
    if (!l1 && !l2) {
        if (carry_flag) {
            forward_ptr->next = new ListNode(1);
        }
    }

    return head_node.next;
}

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

int main() {
    vector< int > a1{2, 4, 3};
    vector< int > a2{5, 6, 4};
    vector< int > a3{5, 6, 4};
    vector< int > a4{5, 3, 5};
    vector< int > a5{6};
    vector< int > a6{3};
    vector< int > a7{0};
    vector< int > a8{7, 3};

    auto a1_l = ConstructList(a1);
    auto a2_l = ConstructList(a2);
    auto a3_l = ConstructList(a3);
    auto a4_l = ConstructList(a4);
    auto a5_l = ConstructList(a5);
    auto a6_l = ConstructList(a6);
    auto a7_l = ConstructList(a7);
    auto a8_l = ConstructList(a8);
    PrintList(addTwoNumbers2(a1_l, a2_l));
    PrintList(addTwoNumbers2(a3_l, a4_l));
    PrintList(addTwoNumbers2(a5_l, a6_l));
    PrintList(addTwoNumbers2(a7_l, nullptr));

    return 0;
}
