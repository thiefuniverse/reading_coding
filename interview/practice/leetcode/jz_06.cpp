#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector< int > reversePrint(ListNode *head) {
    vector< int > result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    reverse(result.begin(), result.end());
}
int main() {

    return 0;
}
