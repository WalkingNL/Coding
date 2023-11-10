
/**
 * Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
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
    void listTovector(vector<int>& arr, ListNode* head) {
        if (head == nullptr) return;
        arr.push_back(head->val);
        listTovector(arr, head->next);
    }
    TreeNode* inOrderedToTree(TreeNode* tree, vector<int> arr, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        tree = new TreeNode(arr[mid]);
        tree->left = inOrderedToTree(tree->left, arr, start, mid-1);
        tree->right = inOrderedToTree(tree->right, arr, mid+1, end);
        return tree;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        listTovector(arr, head);
        TreeNode* root = nullptr;
        if (!arr.empty()) {
            root = inOrderedToTree(root, arr, 0, arr.size()-1);
        }
        return root;   
    }
};