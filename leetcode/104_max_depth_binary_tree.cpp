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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        TreeNode* p = root;
        stack<TreeNode*> stk;

        cout << p->val << " ";
        // stk.push(p);
        // p = p->left;
        // cout << p->val << endl;

        cout << "-----------------" << endl;

      
        int count = 0;
        while (p!=nullptr || !stk.empty()) {
            if (p != nullptr) {
                stk.push(p);
                cout << p->val << " ";
                count++;
                p = p->left;
                // cout << p->val << endl;
            }
            cout << "start: " << count << endl;

            break;

        //     p = stk.top();
        //     stk.pop();
        //     p = p->right;
        //     if (p == nullptr) count--;
        //     else count++;
        //     cout << "end: " << count << endl;
        }
        return count;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(3);
    TreeNode* l1 = new TreeNode(9);
    TreeNode* r1 = new TreeNode(20);
    TreeNode* r2 = new TreeNode(15);
    TreeNode* r3 = new TreeNode(7);
    root->left = l1;
    root->right = r1;
    r1->left = r2;
    r1->right = r3;

    Solution sln;
    cout << sln.maxDepth(root) << endl;

    return 0;
}
