#include <iostream>

#include "../Utilities/List.h"
using namespace std;

int LengthOfList(ListNode* list)
{
    if(list == nullptr) return 0;
    int count = 0;

    ListNode* node = list;
    while(node != nullptr)
    {
	node = node->m_pNext;
	count++;
    }
    return count;
}



ListNode* FindFirstCommonNode(ListNode* p1, ListNode* p2)
{
    if(p1 == nullptr || p2 == nullptr) return nullptr;

    int l1 = LengthOfList(p1);
    int l2 = LengthOfList(p2);
    ListNode* node1 = p1;
    ListNode* node2 = p2;


    if(l1>l2)
    {
	int diff1 = l1-l2;
	for(int i=0; i<diff1; i++)
	    node1 = node1->m_pNext;
    }
    else
    {
	int diff2 = l2-l1;
	for(int i=0; i<diff2; i++)
	    node2 = node2->m_pNext;
    }


    while(node1 != node2)
    {
	node1 = node1->m_pNext;
	node2 = node2->m_pNext;
    }

    if(node1 == node2 && node1 != nullptr)
	return node1;
    else
	return nullptr;
}





// int GetlengthOfList(const ListNode* pHead)
// {
//     if(pHead == nullptr) return 0;

//     int counter = 0;
//     const ListNode* tmp = pHead;
//     while(tmp != nullptr)
//     {
//         counter++;
//         tmp = tmp->m_pNext;
//     }
//     return counter;
// }



// ListNode* FindFirstCommonNode(ListNode* p1, ListNode* p2)
// {
//     if(p1 == nullptr || p2 == nullptr) return nullptr;

//     int L1 = GetlengthOfList(p1);
//     int L2 = GetlengthOfList(p2);

//     ListNode* tmpLong = p1;
//     ListNode* tmpShort = p2;
//     int gap = L1-L2;
//     if(L2>L1)
//     {
//         tmpLong = p2;
//         tmpShort = p1;
//         gap = L2-L1;
//     }


//     while(gap--) // 先移动长的链表，至于连个链表相等
//     {
//         tmpLong = tmpLong->m_pNext;
//     }


//     while(tmpLong != tmpShort )
//     {
//         tmpLong = tmpLong->m_pNext;
//         tmpShort = tmpShort->m_pNext;
//     }

//     if(tmpLong == tmpShort && tmpLong != nullptr)
//         return tmpLong;
//     else
//         return nullptr;

// }




// =============================测试代码==================================
void DestroyNode(ListNode* pNode)
{
    delete pNode;
    pNode = nullptr;
}

void Test(const char* testName, ListNode* pHead1, ListNode* pHead2, ListNode* pExpected)
{
    if(testName != nullptr)
	cout << testName << ":";

    ListNode* pResult = FindFirstCommonNode(pHead1, pHead2);
    if(pResult == pExpected)
        cout << "Passed" << endl;
    else
	cout << "failed"<< endl;
}


// 第一个公共结点在链表中间
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1()
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
    ConnectListNodes(pNode3, pNode6);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test1", pNode1, pNode4, pNode6);
	
    DestroyNode(pNode1);
    DestroyNode(pNode2);
    DestroyNode(pNode3);
    DestroyNode(pNode4);
    DestroyNode(pNode5);
    DestroyNode(pNode6);
    DestroyNode(pNode7);
}



// 没有公共结点
// 1 - 2 - 3 - 4
//
// 5 - 6 - 7
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
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test2", pNode1, pNode5, nullptr);

    DestroyList(pNode1);
    DestroyList(pNode5);
}


// 公共结点是最后一个结点
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
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
    ConnectListNodes(pNode4, pNode7);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test3", pNode1, pNode5, pNode7);

    DestroyList(pNode1);
    DestroyNode(pNode5);
    DestroyNode(pNode6);
}

 

// 公共结点是第一个结点
// 1 - 2 - 3 - 4 - 5
// 两个链表完全重合
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

    Test("Test4", pNode1, pNode1, pNode1);

    DestroyList(pNode1);
}


// 输入的两个链表有一个空链表
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

    Test("Test5", nullptr, pNode1, nullptr);

    DestroyList(pNode1);

}



void Test6()
{
    Test("Test6", nullptr, nullptr, nullptr);
}


int main(void)
{

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
}
