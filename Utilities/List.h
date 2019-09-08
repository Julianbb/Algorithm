#ifndef __LIST_H
#define __LIST_H
#include <iostream>
using namespace std;

struct ListNode
{
    int m_Value;
    ListNode* m_pNext;
};




ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* node);
void PrintList(ListNode* head);
void DestroyList(ListNode* head);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);


#endif
