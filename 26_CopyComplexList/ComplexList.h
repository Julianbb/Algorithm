#pragma once
#include <iostream>
using namespace std;

struct ComplexListNode
{
    int m_Value;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};



ComplexListNode* CreateNode(int value);
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling);
void PrintList(ComplexListNode* pHead);
