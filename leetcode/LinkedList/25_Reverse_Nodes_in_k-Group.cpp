/**
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 * k is a positive integer and is less than or equal to the length of the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is. 
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* node_head = new ListNode(-1, head);
        if (node_head == nullptr) {
            cout << "allocated failure!" << endl;
            exit(-1);
        }
        ListNode* p = node_head;
        ListNode* q = node_head;
        ListNode* r = nullptr;
        ListNode* s = nullptr;
        int count = 0;
        int count_dec = k;

        while (q != nullptr) {
            if (q != nullptr && count < k) {
                q = q->next;
                count += 1;
                continue;
            }
            if (q == nullptr) {
                break;
            }
            if (p->next == head) head = q;
            if (r == nullptr) r = q->next;
            p = node_head->next;
            if (s == nullptr) s = p;
            if (p != q) {
                node_head->next = node_head->next->next;
                p->next = r;
                r = p;
                q->next = p;
            }

            if (count_dec > 1) {
                count_dec -= 1;
            } else {
                count_dec = k;
                count = 0;
                r = nullptr;
                p = s;
                q = s;
                if (node_head->val == -1) {
                    delete node_head;
                }
                node_head = p;
                s = nullptr;
            }
        }

        return head;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}
