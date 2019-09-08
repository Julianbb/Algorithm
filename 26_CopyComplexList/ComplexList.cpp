#include "ComplexList.h"

ComplexListNode* CreateNode(int value)
{
    ComplexListNode* node = new ComplexListNode();
    node->m_Value = value;
    node->m_pNext = nullptr;
    node->m_pSibling = nullptr;

    return node;
}




void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode == nullptr) return;
    pNode->m_pNext = pNext;
    pNode->m_pSibling = pSibling;

}




void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
	cout << pNode->m_Value << endl;
	if(pNode->m_pSibling != nullptr)
	    cout << "the sibling value is:" << pNode->m_pSibling->m_Value << endl;
	else
	    cout << "has no sibling" << endl;

	cout << endl;
	pNode = pNode->m_pNext;
    }
}
