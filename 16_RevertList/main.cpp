#include <iostream>
#include "../Utilities/List.h"
using namespace std;

typedef ListNode*(FUN)(ListNode*);


ListNode* RecurseNode(ListNode* node1, ListNode* node2)
{
    if(node1 == nullptr) return nullptr;
    if(node1 != nullptr && node2 == nullptr) return node1;


    ListNode* tmp = node2->m_pNext;
    node2->m_pNext = node1;

    ListNode* p = RecurseNode(node2, tmp);

    return p;
}



ListNode* RevertList_recurse(ListNode* head)
{
    if(head == nullptr) return nullptr;

    ListNode* h= RecurseNode(head, head->m_pNext);
    head->m_pNext = nullptr;


    return h;
}


ListNode* RevertList_3p(ListNode* head)
{
    if(head == nullptr) return nullptr;

    ListNode* p1 = head;
    ListNode* p2 = head;
    ListNode* p3 = head;

    if(p2->m_pNext != nullptr)
    {
	 p2 = p2->m_pNext;
	 head->m_pNext = nullptr;
    }
    else
    {
	head->m_pNext = nullptr;
	return head;
    }

    if(p2->m_pNext != nullptr)
	 p3 = p2->m_pNext;
    else
    {
	p1->m_pNext = nullptr;
	p2->m_pNext = p1;
	return p2;
    }


    while(p1 != nullptr && p2!=nullptr && p3 != nullptr)
    {
	p2->m_pNext = p1;
	p1 = p2;
	p2 = p3;
	p3 = p3->m_pNext;
    }
     
    p2->m_pNext = p1;
    return p2;


    
}




//翻转两个结点，然后进行递归
// ListNode* RevertList_TwoNode(ListNode* node1, ListNode* node2)
// {

//     if(node2 == nullptr) return node1;
//     ListNode* tmp = node2->m_pNext;
//     node2->m_pNext = node1;

//     ListNode* p = RevertList_TwoNode(node2, tmp);

//     return p;
// }


//递归实现解法
// ListNode* RevertList_recurse(ListNode* head)
// {
//     if(head == nullptr) return nullptr;

//     ListNode* p1= head;
//     ListNode* p2= head->m_pNext;
//     if(p2 == nullptr) return p1;

//     ListNode* tmp = RevertList_TwoNode(p1, p2);


//     head->m_pNext = nullptr;
//     return tmp;
// }




//使用３个指针的解法
// ListNode* RevertList_3p(ListNode* head)
// {
//     if(head == nullptr) return nullptr; //空指针情况

//     ListNode* p1 = head;
//     ListNode* p2 = head->m_pNext;
//     if(p1->m_pNext == nullptr) return p1; //这是一个结点的情况

//     ListNode* tmp;
//     while(p2->m_pNext !=nullptr)
//     {
//         tmp = p1;
//         p1 = p2;
//         p2 = p2->m_pNext;

//         p1->m_pNext = tmp;

//     }

//     p2->m_pNext = p1;


//     head->m_pNext = nullptr; // 这一步很重要，否则最后出现循环
//     return p2;
// }






//空指针
void Test1(FUN* RevertList)
{
    ListNode* tmp = nullptr;
    ListNode* result; 
    result = RevertList(tmp);
    if (result == nullptr)
	cout << "nullptr test passed" << endl;
}


//一个结点
void Test2(FUN* RevertList)
{
    ListNode* node1 = CreateListNode(1);
    ListNode* result;
    cout << "list is : " ;
    PrintList(node1);
    result = RevertList(node1);
    cout << "after revert list : "; 
    PrintList(result);
    cout << endl;
}



//正常情况
void Test3(FUN* RevertList)
{
    ListNode* node1 = CreateListNode(1);
    ListNode* node2 = CreateListNode(2);
    ListNode* node3 = CreateListNode(2);
    ListNode* node4 = CreateListNode(4);

    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);
    ConnectListNodes(node3, node4);

    ListNode* result;
    cout << "list is : " ;
    PrintList(node1);
    result = RevertList(node1);
    cout << "after revert list : "; 
    PrintList(result);
}




int main(void)
{
    Test1(RevertList_recurse);
    Test2(RevertList_recurse);
    Test3(RevertList_recurse);

    return 0;
}
