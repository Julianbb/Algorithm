#include "BinaryTree.h"



void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode!= nullptr)
    {
	cout << "value of this node is:"<< pNode->m_nValue << "  ";


	if(pNode->m_pLeft != nullptr)
	    cout << "left child is:" << pNode->m_pLeft->m_nValue << " ";
	else
	    cout << "left child is : nullptr" << "  "; 


	if(pNode->m_pRight != nullptr)
	    cout << "Right child is:" << pNode->m_pRight->m_nValue << endl;
	else
	    cout << "right child is : nullptr" << endl; 

    }
    else
	cout << "this node is nullptr" << endl;
}

void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);
    if(pRoot != nullptr)
    {
	if(pRoot->m_pLeft != nullptr)
	    PrintTree(pRoot->m_pLeft);
	if(pRoot->m_pRight != nullptr)
	    PrintTree(pRoot->m_pRight);
    }
}


void DestroyTree(const BinaryTreeNode* pRoot)
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
