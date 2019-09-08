#include "List.h"


	
ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_Value = value;
    pNode->m_pNext = nullptr;

    return pNode;
}


void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent  == nullptr) return;
    pCurrent->m_pNext = pNext;
}



void PrintListNode(ListNode* node)
{
    if(node != nullptr)
    {
	cout << node->m_Value << endl;
    }
}


void PrintList(ListNode* head)
{
    ListNode* pNode = head;
    while(pNode != nullptr)
    {
	cout << pNode->m_Value << "  ";
	pNode = pNode->m_pNext;
    }
}


void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
	pHead = pHead->m_pNext;
	delete pNode;
	pNode = pHead;
    }

}





void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_Value = value;
    pNew->m_pNext = nullptr;

    if(*pHead == nullptr)
    {
	*pHead = pNew;
    }

    else
    {
	ListNode* pNode = *pHead;
	while(pNode->m_pNext != nullptr)
	{
	    pNode = pNode->m_pNext;
	}
	pNode->m_pNext = pNew;
    }
}



void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead ==nullptr)
	return;

    ListNode* pToBeDeleted = nullptr;

    if((*pHead)->m_Value == value)// 头结点
    {
	pToBeDeleted = *pHead;
	*pHead = (*pHead)->m_pNext;
    }
    else
    {
	ListNode* pNode = *pHead;
	while(pNode->m_pNext != nullptr && pNode->m_pNext->m_Value != value )
	{
	    pNode = pNode->m_pNext;
	}
	if(pNode->m_pNext!=nullptr && pNode->m_pNext->m_Value == value)
	{
	    pToBeDeleted = pNode->m_pNext;
	    pNode->m_pNext = pNode->m_pNext->m_pNext;
	}
    }

    if(pToBeDeleted != nullptr)
    {
	delete pToBeDeleted;
	pToBeDeleted = nullptr;
    }
}

