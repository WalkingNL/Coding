#include <iostream>
using namespace std;

/**
 * Given a linked list, swap every two adjacent nodes and return its head. 
 * You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* ex_node = new ListNode(0, head);
        ListNode* p = ex_node;
        ListNode* q = head;
        while (q->next != nullptr) {
            // ListNode* tmp = q->next;
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = q;
            p = q;
            q = q->next;
            if (q == nullptr) break;
        }
        head = ex_node->next;
        delete ex_node;
        return head;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}
