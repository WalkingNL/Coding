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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        bool b = true;
        TreeNode* p = root;
        TreeNode* q = root;
        isSymmetricReverse(p, q, b);

        return b;
        
    }
private:
    void isSymmetricReverse(TreeNode* p, TreeNode* q, bool& b) {
        // if (b) {
        //     b = false;
        //     return;
        // }

        if (p == nullptr && q == nullptr) return;

        if ((p==nullptr && q!=nullptr) || (q==nullptr && p!=nullptr)) {
            b = false;
            return;
        }
        if (p != nullptr && q != nullptr && p->val != q->val) {
            b = false;
            return;
        }

        isSymmetricReverse(p->left, q->right, b);
        isSymmetricReverse(p->right, q->left, b);
        if (p == q && p != nullptr) {
            // if (!b) 
            return;
        }
    }
};

/**
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        TreeNode* p = root;
        TreeNode* q = root;
        stack<TreeNode*> stk_p;
        stack<TreeNode*> stk_q;
        while ((p != nullptr && q != nullptr) || (!stk_p.empty() && !stk_q.empty())) {
            while (p != nullptr && q != nullptr) {
                if (p->val != q->val) return false;
                stk_p.push(p);
                stk_q.push(q);
                p = p->left;
                q = q->right;
            }
            if ((p==nullptr && q!=nullptr) || (q==nullptr && p!=nullptr)) {
                return false;
            }
            p = stk_p.top();
            q = stk_q.top();
            if (q==p) break;
            stk_p.pop();
            stk_q.pop();
            p = p->right;
            q = q->left;
        }
        return true;
    }
};
*/
