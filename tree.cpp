/************************************************************************************/
// gongqb June 7, 2019
// To translate a Binary Search Tree to a sorted double linked list.
/************************************************************************************/


#include <cstdio>
#include "../Utilities/BinaryTree.h"

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
	BinaryTreeNode* pLastNodeInList = nullptr;
	ConvertNode(pRootOfTree, &pLastNodeInList);

	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while(pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
		pHeadOfList = pHeadOfList->m_pLeft;

	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
	if(pNode == nullptr)
		return;

	BinaryTreeNode* pCurrent = pNode;

	if(pCurrent->m_pLeft != nullptr)
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
	
	pCurrent->m_pLeft = *pLastNodeInList;
	if(*pLastNodeInList != nullptr)
		(*pLastNodeInList)->m_pRight = pCurrent;

	*pLastNodeInList = pCurrent;

	if(pCurrent->m_pRight != nullptr)
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}

// to print the double Linked list after translation
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;

	printf("the nodes from left to right are:\n");
	while(pNode != NULL)
	{
		printf("%d\t", pNode->m_nValue);

		if(pNode->m_pRight == NULL)
			break;

		pNode = pNode->m_pRight;
	}

	printf("the nodes from right to left are:\n");
	while(pNode != NULL)
	{
		printf("%d\t", pNode->m_nValue);

		if(pNode->m_pLeft == NULL)
			break;

		pNode = pNode->m_pLeft;
	}

	printf("\n");
	
}

// to destroy
void DestroyList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;
	while(pNode != NULL)
	{
		BinaryTreeNode* pNext = pNode->m_pRight;	
	}
}

void Case(char* testName, BinaryTreeNode* pRootOfTree)
{
	if(testName != nullptr)
		printf("%s begins: \n", testName);

	PrintTree(pRootOfTree); // orginal Binary Tree
	
	// the operation of translation
	BinaryTreeNode* pHeadOfList = Convert(pRootOfTree);
	
	// the operation of output
	PrintDoubleLinkedList(pHeadOfList);
}

// It's a test case
// to construct a binary tree
// to test, "Case()"
// to destroy()
void MyCase1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNoes(pNode10, pNode6, pNode14);
	ConnectTreeNoes(pNode6, pNode4, pNode8);
	ConnectTreeNoes(pNode14, pNode12, pNode16);

	Case("MyCase1", pNode10);
	
	DestroyList(pNode4);
}

// main method
int main(int argc, char* arg[])
{
	MyCase1();	

	return 0;
}


