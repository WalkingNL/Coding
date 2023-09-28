#include <iostream>

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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* q = head;
        head = new ListNode(head->val, head);
        ListNode* p = head;
        
        while (q->next != nullptr) {
            if (q->val <= q->next->val) {
                q = q->next;
                continue;
            }
            while (p->next != q->next) {
                if (p->next->val > q->next->val) {
                    if (p->next == q) {
                        int tmp = p->next->val;
                        p->next->val = q->next->val;
                        q->next->val = tmp;
                        q = q->next;
                        break;
                    }
                    ListNode* r = q->next;
                    q->next = q->next->next;
                    
                    r->next = p->next;
                    p->next = r;
                    break;
                }
                p = p->next;
            }
            if (p != head) p = head;
        }
        head = head->next;
        p->next = nullptr;
        delete p;

        return head;
    }
};

int main(int argc, char* argv[]) {

    

    return 0;
}
