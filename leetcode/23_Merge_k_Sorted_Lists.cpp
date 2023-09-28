#include <iostream>
#include <vector>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() <= 0) return nullptr;
        ListNode* head = nullptr;
        for (int i=0; i<lists.size(); i++) {
            head = lists[i];
            if (head == nullptr) continue;

            for (int j=i+1; j<lists.size(); j++) {
                ListNode* head_cmp = lists[j];
                if (head_cmp == nullptr) continue;

                ListNode* p1 = head;
                ListNode* p2 = p1;

                ListNode* q1 = head_cmp;
                ListNode* q2 = q1;
                
                while (p1 != nullptr) {
                    while (q1 != nullptr && p1 != nullptr) {
                        if (p1->val >= q1->val) {
                            if (q2 != q1) q2 = q1;
                            q1 = q1->next;
                        } else {
                            if (q1 != q2) {
                                p1 = p1->next;
                                break;
                            }
                            if (p2->next == p1) p2 = p1;
                            p1 = p1->next;
                        }
                    }
                    
                    if (q1 != q2) {
                        if (p2->val >= q2->val) {
                            q2->next = p2;
                            if (head == lists[i]) lists[i] = head_cmp;
                        } else {
                            q2->next = p2->next;
                            p2->next = head_cmp;
                            p2 = q2->next;
                        }
                        if (q1 == nullptr) {
                            break;
                        }
                        if (p1 == nullptr) {
                            p2->next = q1;
                            break;
                        }
                        head_cmp = q1;
                        q2 = q1;
                    } else {
                        if (p1 != p2) {
                            p2->next = q1;
                        }
                    }
                }
                if (head != lists[i]) {
                    head =lists[i];
                }
            }
            break;
        }

        return head;
    }
};

int main(int argc, char* argv[]) {
    
    return 0;
}
