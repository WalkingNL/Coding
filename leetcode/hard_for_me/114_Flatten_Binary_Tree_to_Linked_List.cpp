#include <iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void preOrderTraverse(TreeNode* root, TreeNode* linkPoint) {
        if (root == nullptr) return;
        cout << root->val << " ";
        preOrderTraverse(root->left, linkPoint);
        
        preOrderTraverse(root->right, linkPoint);
        if (root->left == nullptr && root->right == nullptr) linkPoint = root;
        if (root->left != nullptr) {
            root->left->right = root->right;
            root->right = root->left;
            root->left = nullptr;

        }
    }
public:
    void flatten(TreeNode* root) {
        preOrderTraverse(root, nullptr);
        cout << endl;
    }
};
