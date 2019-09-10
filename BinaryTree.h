#pragma once

struct BinaryTreeNode
{
	int m_nValue; // Integer Value
	BinaryTreeNode* m_pLeft; // Left Child
	BinaryTreeNode* m_pRight; // Right Child
};

BinaryTreeNode* CreateBinaryTreeNode(int value);

void ConnectTreeNoes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);

void PrintTreeNode(const BinaryTreeNode* pNode);

void PrintTree(const BinaryTreeNode* pRoot);

void DestroyTree(BinaryTreeNode* pRoot);
