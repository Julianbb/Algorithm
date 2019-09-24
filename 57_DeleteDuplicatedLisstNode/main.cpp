/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : julian Andrison
#   Email         : 15544925950@163.com
#   File Name     : main.cpp
#   Last Modified : 2019-08-01 09:05
#   Describe      :
#
# ====================================================*/

#include <../Utilities/List.h>
#include <iostream>
using namespace std;

void deleteDuplication(ListNode** pHead)
{
    if(*pHead == nullptr || pHead == nullptr) return;

    ListNode* pNode = *pHead;
    ListNode* pPreNode = NULL;

    while(pNode != NULL)
    {
	ListNode* pNext = pNode->m_pNext;
	bool needDelete = false;

	if(pNext != NULL && pNext->m_Value == pNode->m_Value)
	    needDelete = true;

	if(!needDelete)
	{
	    pPreNode = pNode;
	    pNode = pNode->m_pNext;
	}
	else
	{
	    int value = pNode->m_Value;
	    ListNode* pToBeDel = pNode;
	    while(pToBeDel != NULL && pToBeDel->m_Value == value)
	    {
		pNext = pToBeDel->m_pNext;

		delete pToBeDel;
		pToBeDel = NULL;
		pToBeDel = pNext;
	    }

	    if(pPreNode == NULL)
		*pHead = pNext;
	    else
		pPreNode->m_pNext = pNext;

	    pNode = pNext;
	}
    }
}








// void DeleteNode(ListNode* pPre, ListNode** pNow, int* num)
// {
//    if(pPre == nullptr || pNow== nullptr)
//       return;

//    ListNode* pDelete = *pNow;
//    *pNow = (*pNow)->m_pNext;
//    pPre->m_pNext = *pNow;

//    delete pDelete;
//    pDelete = nullptr;
//    (*num)--;

// }



// void deleteDuplication(ListNode** pHead)
// {
//     if(pHead == nullptr || *pHead == nullptr)
//         return;

//     ListNode* pPre = nullptr;
//     ListNode* pNode = (*pHead);
//     while(pNode != nullptr)
//     {
//         ListNode* pNext = pNode->m_pNext;
//         bool needDelete = false;
//         if(pNext!=nullptr && pNext->m_Value == pNode->m_Value)
//             needDelete = true;

//         if(!needDelete)
//         {
//             pPre = pNode;
//             pNode = pNode->m_pNext;
//         }
//         else
//         {
//             int value = pNode->m_Value;
//             ListNode* pToBeDel = pNode;
//             while(pToBeDel  != nullptr && pToBeDel->m_Value == value)
//             {
//                 pNext = pToBeDel->m_pNext;
//                 delete pToBeDel;
//                 pToBeDel = pNext;
//             }

//             if(pPre == nullptr)
//             {
//                 *pHead = pNext;
//             }
//             else
//                 pPre->m_pNext = pNext;
//             pNode = pNext;
//         }
//     }
// }


// ==================== Test Code ====================
void Test(const char* testName, ListNode** pHead, int* expectedValues, int expectedLength)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    deleteDuplication(pHead);

    int index = 0;
    ListNode* pNode = *pHead;
    while(pNode != NULL && index < expectedLength)
    {
        if(pNode->m_Value != expectedValues[index])
            break;

        pNode = pNode->m_pNext;
        index++;
    }

    if(pNode == NULL && index == expectedLength)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// some nodes are duplicated
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = {1, 2, 5};
    Test("Test1", &pHead, expectedValues, sizeof(expectedValues)/sizeof(int));

    DestroyList(pHead);
}

// all nodes are unique
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test2", &pHead, expectedValues, sizeof(expectedValues)/sizeof(int));

    DestroyList(pHead);
}

// all nodes are duplicated except one
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = {2};
    Test("Test3", &pHead, expectedValues, sizeof(expectedValues)/sizeof(int));

    DestroyList(pHead);
}

// all nodes are duplicated
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    Test("Test4", &pHead, NULL, 0);

    DestroyList(pHead);
}

// all nodes are duplicated in pairs
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(2);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(3);
    ListNode* pNode7 = CreateListNode(4);
    ListNode* pNode8 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    Test("Test5", &pHead, NULL, 0);

    DestroyList(pHead);
}

// nodes are duplicated in pairs except two
void Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);
    ListNode* pNode8 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    int expectedValues[] = {2, 4};
    Test("Test6", &pHead, expectedValues, sizeof(expectedValues)/sizeof(int));

    DestroyList(pHead);
}

// a list with two unique nodes
void Test7()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    int expectedValues[] = {1, 2};
    Test("Test7", &pHead, expectedValues, sizeof(expectedValues)/sizeof(int));

    DestroyList(pHead);
}

// only one node in a list
void Test8()
{
    ListNode* pNode1 = CreateListNode(1);

    ConnectListNodes(pNode1, NULL);

    ListNode* pHead = pNode1;

    int expectedValues[] = {1};
    Test("Test8", &pHead, expectedValues, sizeof(expectedValues)/sizeof(int));

    DestroyList(pHead);
}

// a list with only two duplidated nodes
void Test9()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    Test("Test9", &pHead, NULL, 0);

    DestroyList(pHead);
}

// empty list
void Test10()
{
    ListNode* pHead = NULL;

    Test("Test10", &pHead, NULL, 0);
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
    Test8();
    Test9();
    Test10();

    return 0;
}
