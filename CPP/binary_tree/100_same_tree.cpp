#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool rv = true;
        isSameTreeReverse(p, q, rv);
        return rv;
    }
private:
    void isSameTreeReverse(TreeNode* p, TreeNode* q, bool& rv) {
        if (!rv) return;
        if ((p!=nullptr && q==nullptr) || (p==nullptr && q!=nullptr)) {
            rv = false;
            return;
        }

        if (p==nullptr && q==nullptr) {
            rv = true;
            return;
        }

        if (p!=nullptr && q!=nullptr) {
            if (p->val != q->val) {
                rv = false;
                cout << p->val << " : " << q->val << endl;
                return;
            }
        }

        isSameTreeReverse(p->left, q->left, rv);
        isSameTreeReverse(p->right, q->right, rv);
    }
};

/**
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        stack<TreeNode*> stk_p;
        stack<TreeNode*> stk_q;
        TreeNode* cur_p = p;
        TreeNode* cur_q = q;;

        while ((cur_p && cur_q) || (!stk_p.empty() && !stk_q.empty())) {
            while (cur_p && cur_q) {
                if (cur_p->val == cur_q->val) {
                    stk_p.push(cur_p);
                    stk_q.push(cur_q);
                } else {
                    return false;
                }
                cur_p = cur_p->left;
                cur_q = cur_q->left;
            }
            if ((cur_p==nullptr && cur_q!=nullptr) || (cur_p!=nullptr && cur_q==nullptr)) {
                return false;
            }
            cur_p = stk_p.top();
            cur_q = stk_q.top();
            stk_p.pop();
            stk_q.pop();
            cur_p = cur_p->right;
            cur_q = cur_q->right;
        }
        if ((cur_p==nullptr && cur_q!=nullptr) || (cur_p!=nullptr && cur_q==nullptr)) {
            return false;
        }
        return true;
    }
};

*/
