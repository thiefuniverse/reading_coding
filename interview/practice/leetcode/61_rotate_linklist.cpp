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

// k < len of head list
ListNode *rotaterightHelper(ListNode *head, int k) {
    if (!head || k == 0) {
        return head;
    }
    // get new head
    ListNode *nhead = head;
    while (head && k > 0) {
        head = head->next;
        --k;
    }
    ListNode *prehead = nhead;
    while (head->next) {
        prehead = prehead->next;
        head = head->next;
    }
    head->next = nhead;

    ListNode *resulthead = nullptr;
    resulthead = prehead->next;
    prehead->next = nullptr;
    return resulthead;
}

ListNode *rotateRight(ListNode *head, int k) {
    if (!head || k == 0) {
        return head;
    }
    // get new head
    int kf = k;
    ListNode *nhead = head;
    ListNode *resulthead = nullptr;
    int linklen = 0;
    while (head && kf > 0) {
        ++linklen;  // get linklist len
        head = head->next;
        --kf;
    }
    if (head) {
        return rotaterightHelper(nhead, k);
    } else {
        if (kf > 0) {
            k = k % linklen;
            if (k == 0) {
                return nhead;
            } else {
                return rotaterightHelper(nhead, k);
            }
        } else if (kf == 0) {
            return nhead;
        }
    }
    return resulthead;
}
int main() {
    vector< int > a1{1};
    vector< int > a2{5, 6, 4, 3, 2};
    vector< int > a3{};
    vector< int > a4{5, 3, 4, 5};

    auto a1_l = ConstructList(a1);
    auto a2_l = ConstructList(a2);
    auto a3_l = ConstructList(a3);
    auto a4_l = ConstructList(a4);

    a1_l->next = a1_l;
    a4_l->next->next->next->next = a4_l->next;
    auto r1 = rotateRight(a2_l, 7);
    PrintList(r1);

    return 0;
}
