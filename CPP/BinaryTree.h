/**************************************************************/
// gongqb June 6, 2019.
// How to construct a BinaryTree using Chain structure
// In the code blow, I refer to a book on how to name 
// variables and functions
/**************************************************************/
#pragma once

struct BinaryTreeNode
{
	int m_nValue; // Integer Value
	BinaryTreeNode* m_pLeft; // Left Child
	BinaryTreeNode* m_pRight; // Right Child
};

// construct a Node of tree.
BinaryTreeNode* CreateBinaryTreeNode(int value);

// to build BinaryTree by connecting Nodes
void ConnectTreeNoes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);

// to output a BinaryTree
void PrintTreeNode(const BinaryTreeNode* pNode);
void PrintTree(const BinaryTreeNode* pRoot);

// to destroy a BinaryTree
void DestroyTree(BinaryTreeNode* pRoot);
