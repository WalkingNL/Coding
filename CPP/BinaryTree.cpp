/*****************************************************************************/
// gongqb June 6, 2019.
// how to construct a BinaryTree
/*****************************************************************************/

#include <cstdio>
#include "BinaryTree.h"

// to create a BinaryTreeNode
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value; // assign value to m_nValue
	pNode->m_pLeft = nullptr; // * assign nullptr to m_pLeft
	pNode->m_pRight = nullptr; // * assign nullptr to m_pRight

	return pNode; // return pNode
}

// to construct BinaryTree. these nodes created in CreateBinaryTreeNode() are connected to form a Binary Tree
void ConnectTreeNoes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if(pParent != nullptr) // is nullptr
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

// to output operation
void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if(pNode != nullptr)
	{
		printf("value of this node is: %d.\n", pNode->m_nValue);

		if(pNode->m_pLeft != nullptr)
			printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
		else
			printf("left child is nullptr.\n");

		if(pNode->m_pRight != nullptr)
			printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
		else
			printf("right child is nullptr.\n");
	}
	else
	{
		printf("this node is nullptr.\n");
	}

	printf("\n");
}

void PrintTree(const BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if(pRoot != nullptr)
	{
		if(pRoot->m_pLeft != nullptr)
		{
			PrintTreeNode(pRoot->m_pLeft);	
		}

		if(pRoot->m_pRight != nullptr)
		{
			PrintTreeNode(pRoot->m_pRight);	
		}
	}
}

// to destroy a binary tree. the destruction operation includes two steps:
// (1) to move the pointer to his two child nodes repectively
// (2) delete operation and assign nullptr to it
void DestroyTree(BinaryTreeNode* pRoot)
{
	if(pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

