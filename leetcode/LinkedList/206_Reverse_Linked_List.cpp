/**
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reverseListR(ListNode** head, ListNode* l1, ListNode* l2) {
    if (l2 == nullptr) {
        return;
    }
    *head = l2;
    l2 = l2->next;
    (*head)->next = l1;
    l1 = *head;
    reverseListR(head, l1, l2);
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* l1 = head;
        ListNode* l2 = head->next;
        l1->next = nullptr;
        reverseListR(&head, l1, l2);

        return head;

        // if (head == nullptr || head->next == nullptr) return head;
        // ListNode* node_head = new ListNode(-5001, head);
        // if (node_head == nullptr) {
        //     cout << "fail to allocate" << endl;
        //     exit(-1);
        // }
        // ListNode* p = head;
        // ListNode* q = head;
        // while (q->next != nullptr) {
        //     q = q->next;
        // }
        // while (node_head->next != q) {
        //     node_head->next = node_head->next->next;
        //     p->next = q->next;
        //     q->next = p;
        //     p = node_head->next;
        // }
        // delete node_head;
        // node_head = nullptr;
        // return q;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}