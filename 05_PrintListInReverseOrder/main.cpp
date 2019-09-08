/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-09-08 09:05
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include "../Utilities/List.h"
#include <stack>
using namespace std;

//栈
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    if(pHead == nullptr)
        return;
    
    stack<int> array;

    ListNode* tmp = pHead;
    while(tmp != nullptr)
    {
        array.push(tmp->m_Value);
        tmp = tmp->m_pNext;
    }

    while(array.size() != 0)
    {
        int num = array.top();
        cout << num << " ";
        array.pop();
    }  
}

//递归
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead == nullptr)
        return;

    if(pHead->m_pNext != nullptr)
    {
        PrintListReversingly_Recursively(pHead->m_pNext);
    }
    cout << pHead->m_Value << " ";
}

// ====================测试代码====================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    printf("\n");
    printf("\n");
    PrintListReversingly_Iteratively(pHead);
    printf("\n");
    PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins.\n");

    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

// 空链表
void Test3()
{
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
