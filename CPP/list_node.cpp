#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void reverseListR(ListNode** head, ListNode* l1, ListNode* l2) {
    if (l2 == nullptr) {
        return;
    }
    *head = l2;
    l2 = l2->next;
    (*head)->next = l1;
    l1 = *head;
    // cout << (*head)->val << " " << (*head)->next->val << endl;
    reverseListR(head, l1, l2);
    // l1->next = nullptr;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* l1 = head;
        ListNode* l2 = head->next;
        l1->next = nullptr;
        reverseListR(&head, l1, l2);
        // while(l2 != nullptr && l1 != nullptr) {
        //     head = l2;
        //     l2 = l2->next;
        //     head->next = l1;
        //     l1 = head;
        // }
        // ListNode* h = head;
        // while (h != nullptr) {
        //     cout << h->val << " ";
        //     h = h->next;
        // }
        // cout << endl;

        return head;
    }

};

void mod_node(ListNode* head) {
    head->val = 100;
    head->next->val = 2000;
    cout << "****" << endl;
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void reverse(ListNode* head, ListNode* l1, ListNode* l2) {
    if (l2 == nullptr) {
        return;
    }
    head = l2;
    l2 = l2->next;
    head->next = l1;
    l1 = head;
    // cout << (*head)->val << " " << (*head)->next->val << endl;
    reverse(head, l1, l2);
    // l1->next = nullptr;
}

// void reverse(ListNode** head, ListNode* l1, ListNode* l2) {
//     if (l2 == nullptr) {
//         return;
//     }
//     (*head) = l2;
//     l2 = l2->next;
//     (*head)->next = l1;
//     l1 = *head;
//     // cout << (*head)->val << " " << (*head)->next->val << endl;
//     reverse(head, l1, l2);
//     // l1->next = nullptr;
// }

int main(int argc, char* argv[]) {

    ListNode l5(5, nullptr);
    ListNode l4(4, &l5);
    ListNode l3(3, &l4);
    ListNode l2(2, &l3);
    ListNode l1(1, &l2);

    ListNode* head = &l1;

    cout << "before: " << head->val << endl;
    mod_node(head);
    cout << "after: " << head->val << endl;

    ListNode* list1 = head;
    ListNode* list2 = head->next;
    list1->next = nullptr;
    reverse(head, list1, list2);
    // reverse(&head, list1, list2);

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}