/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-07-31 10:30
#   Describe      :
#
# ====================================================*/

#include "../Utilities/List.h"
#include <iostream>
using namespace std;

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(pHead == nullptr) return nullptr;
    if(pHead->m_pNext == nullptr) return nullptr;

    ListNode* p1 = pHead;
    ListNode* p2 = pHead;

    p1 = p1->m_pNext;
    p2 = p2->m_pNext;
    p2 = p2->m_pNext;

    while(p1 != p2) // p1每次前进一个， p2每次前进2个，得到第一个相会点
    {
	if(p1->m_pNext == nullptr || p2->m_pNext == nullptr || p1 == nullptr || p2 == nullptr) return nullptr;

	p1 = p1->m_pNext;
	p2 = p2->m_pNext;
	p2 = p2->m_pNext;
    }

    p2 = pHead; // p1 不变， p2= head, 两者每次都走一步，相遇便是入口
    while(p1 != p2)
    {
	p1 = p1->m_pNext;
	p2 = p2->m_pNext;
    }

    return p1;

}

// int GetNumOfNodesInLoop(ListNode* pHead)
// {
//     if(pHead == nullptr)
//         return 0;

//     ListNode* p1 = pHead;
//     ListNode* p2 = pHead;


//     while(p2 != nullptr && p2->m_pNext != nullptr)
//     {
//         p1 = p1->m_pNext;
//         p2 = p2->m_pNext->m_pNext;

//         if(p1 == p2)
//             break;
//     }

//     if(p2->m_pNext == nullptr || p2 == nullptr)
//         return 0;

//     int number = 1;
//     if(p1 == p2)
//     {
//         p2 = p2->m_pNext;
//         while(p1 != p2)
//         {
//             number++;
//             p2 = p2->m_pNext;
//         }
//     }
//     return number;
// }



// ListNode* EntryNodeOfLoop(ListNode* pHead)
// {
//     if(pHead == nullptr)
//         return nullptr;

//     int num = GetNumOfNodesInLoop(pHead);
//     if(num == 0) return nullptr;

//     ListNode* p1 = pHead;
//     ListNode* p2 = pHead;

//     for(int i=0; i<num; i++) // 先将２号指针往后移num，再同时移动1,2，再相见便是loop入口
//     {
//         p2 = p2->m_pNext;
//     }

//     while(p1 != p2)
//     {
//         p1 = p1->m_pNext;
//         p2 = p2->m_pNext;
//     }

//     if(p1 == p2)
//     {
//         return p1;
//     }
// }



// ==================== Test Code ====================
void Test(const char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test1", pNode1, NULL);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = NULL;
}

// A list has multiple nodes, with a loop
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = NULL;
    delete pNode2;
    pNode2 = NULL;
    delete pNode3;
    pNode3 = NULL;
    delete pNode4;
    pNode4 = NULL;
    delete pNode5;
    pNode5 = NULL;
}

// A list has multiple nodes, with a loop
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = NULL;
    delete pNode2;
    pNode2 = NULL;
    delete pNode3;
    pNode3 = NULL;
    delete pNode4;
    pNode4 = NULL;
    delete pNode5;
    pNode5 = NULL;
}

// A list has multiple nodes, with a loop
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = NULL;
    delete pNode2;
    pNode2 = NULL;
    delete pNode3;
    pNode3 = NULL;
    delete pNode4;
    pNode4 = NULL;
    delete pNode5;
    pNode5 = NULL;
}

// A list has multiple nodes, without a loop
void Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test6", pNode1, NULL);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", NULL, NULL);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
