#include <cstdio>
// #include <stdlib.h>
#include "../Utilities/BinaryTree.h"

// Sep 19, 2019 I Wrote this part of codes, 
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
	if (pRootOfTree == nullptr)	
		return nullptr;

	Convert(pRootOfTree->m_pLeft);
	Convert(pRootOfTree->m_pRight);
	
	if (pRootOfTree->m_pLeft != nullptr)
	{
		BinaryTreeNode* pNode = pRootOfTree->m_pLeft;
		BinaryTreeNode* pFirst = nullptr; 
		while (pNode->m_pRight != nullptr)
			pNode = pNode->m_pRight;
		
		pNode->m_pRight = pRootOfTree;
		if (pNode != pRootOfTree->m_pLeft)
		{
			pRootOfTree->m_pLeft = pNode;
		}
	}
	
	if (pRootOfTree->m_pRight != nullptr)
	{
		BinaryTreeNode* pNode = pRootOfTree->m_pRight;
		while (pNode->m_pLeft != nullptr)
			pNode = pNode->m_pLeft;
		
		pNode->m_pLeft = pRootOfTree;
		if (pNode != pRootOfTree->m_pRight)
		{
			pRootOfTree->m_pRight = pNode;
		}
	}
}

void PrintDoubleLinkedList(BinaryTreeNode* pHeadList)
{
//	while (pHeadList->m_pLeft != nullptr)
//		pHeadList = pHeadList->m_pLeft;

	BinaryTreeNode* pNode = pHeadList;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->m_nValue);
		pNode = pNode->m_pLeft;
	}
	printf("\n");
}

void Test(char* testName, BinaryTreeNode* pRootOfTree)
{
	if(testName != nullptr)
		printf("%s begins: \n", testName);

	PrintTree(pRootOfTree);
	
	BinaryTreeNode* pHeadOfList = Convert(pRootOfTree);
	PrintDoubleLinkedList(pHeadOfList);
}

void Test1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	BinaryTreeNode* pNode0 = CreateBinaryTreeNode(0);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
	BinaryTreeNode* pNode13 = CreateBinaryTreeNode(13);
	BinaryTreeNode* pNode15 = CreateBinaryTreeNode(15);
	BinaryTreeNode* pNode17 = CreateBinaryTreeNode(17);
	

	ConnectTreeNoes(pNode10, pNode6, pNode14);
	ConnectTreeNoes(pNode6, pNode4, pNode8);
	ConnectTreeNoes(pNode14, pNode12, pNode16);
	
	ConnectTreeNoes(pNode4, pNode0, pNode5);
	ConnectTreeNoes(pNode8, pNode7, pNode9);
	ConnectTreeNoes(pNode12, pNode11, pNode13);
	ConnectTreeNoes(pNode16, pNode15, pNode17);

	Test("Test1", pNode10);
	
//	DestroyList(pNode4);
}

int main(int argc, char* arg[])
{
	Test1();

	return 0;
}


