#include <iostream>
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        int differ =  differ_left_right(root);
        cout << "differ: " << differ << endl;
        if (differ > 1) return false;
        else return true;
    }
private:
    int differ_left_right(TreeNode* root) {

        if (root == nullptr) return 0;

        // int left_depth = 1 + differ_left_right(root->left);
        // int right_depth = 1 + differ_left_right(root->right);

        return (1 + differ_left_right(root->left)) - (1 + differ_left_right(root->right));
        // cout << "left_depth: " << left_depth << endl;
        // cout << "right_depth: " << right_depth << endl;
        // // cout << (left_depth - right_depth) << endl;
        // int diff = left_depth - right_depth;
        // cout << "diff: " << diff << endl;
        // return abs(left_depth);
        // return abs(left_depth - right_depth);
    }
};

int main(int argc, char* argv[]) {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);

    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    
    Solution s;


    s.isBalanced(root);
    
    return 0;
}
