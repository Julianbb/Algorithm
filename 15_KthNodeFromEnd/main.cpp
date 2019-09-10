#include <iostream>
#include "../Utilities/List.h"
using	namespace std;


ListNode* FindKthNode(ListNode* head, int k)
{
    if(head == nullptr || k<=0) return nullptr;

    ListNode* p1 = head;
    ListNode* p2 = head;

    for(int i=0; i<k-1; i++)
    {
	if(p2->m_pNext != nullptr)
	    p2 = p2->m_pNext;
	else
	    return nullptr;
    }

    while(p2->m_pNext != nullptr)
    {
	p1 = p1->m_pNext;
	p2 = p2->m_pNext;
    }

    return p1;

}



// ListNode* FindKthNode(ListNode* head, int k)
// {
//     if(head == nullptr) return nullptr;
//     if(k <=0 ) return nullptr;

//     ListNode* pt1;
//     ListNode* pt2;
//     pt1 = head;
//     pt2 = head;
//     for(int i=0; i<k-1; i++)
//     {
//         pt1 = pt1->m_pNext;
//         if(pt1->m_pNext == nullptr) // K> list.size()
//             return nullptr;
//     }

//     while(pt1->m_pNext != nullptr)// 退出则证明pt1到了最后
//     {
//         pt1 = pt1->m_pNext;
//         pt2 = pt2->m_pNext;
//     }

//     return pt2;
// }









//空指针
void Test1()
{
    ListNode* tmp = new ListNode();
    tmp = FindKthNode(nullptr, 4);
    if(tmp == nullptr)
	cout << "Test1: nullptr situation passed" << endl;

    delete tmp;
}


//Ｋ>链表的结点数
void Test2()
{
    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(3);
    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);

    ListNode* tmp = new ListNode();
    tmp = FindKthNode(node1, 4);
    if(tmp == nullptr)
	cout << "Test2: K>list.size() situation passed" << endl;

    delete tmp;
}


//K=0
void Test3()
{
    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(3);
    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);

    ListNode* tmp = new ListNode();
    tmp = FindKthNode(node1, 0);
    if(tmp == nullptr)
	cout << "Test3: K=0 situation passed" << endl;
    delete tmp;
   
}



void Test4()
{
    ListNode* node1 = CreateListNode(1);
    ListNode* tmp ;
    tmp = FindKthNode(node1, 1);
    PrintList(node1);
    cout << "the count backwards 1th :" ;
    PrintListNode(tmp);

}


//正常情况
void Test5()
{
    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(3);
    ListNode* node4 = CreateListNode(4);
    ListNode* node5 = CreateListNode(5);
    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);
    ConnectListNodes(node3, node4);
    ConnectListNodes(node4, node5);

    ListNode* tmp ;
    tmp = FindKthNode(node1, 3);
    PrintList(node1);
    cout << "the count backwards 3th :" ;
    PrintListNode(tmp);
}




int main(void)
{

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
