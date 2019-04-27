#include <iostream>
#include "../Utilities/List.h"
using namespace std;




ListNode* RevertList(ListNode* head)
{
    if(head == nullptr) return nullptr; //空指针情况

    ListNode* p1 = head;
    ListNode* p2 = head->m_pNext;
    if(p1->m_pNext == nullptr) return p1; //这是一个结点的情况

    head->m_pNext = nullptr; // 这一步很重要，否则最后出现循环
    ListNode* tmp;
    while(p2->m_pNext !=nullptr)
    {
	tmp = p1;
	p1 = p2;
	p2 = p2->m_pNext;

	p1->m_pNext = tmp;
		
    }
    
    p2->m_pNext = p1;


    return p2;
}






//空指针
void Test1(void)
{
    ListNode* tmp = nullptr;
    ListNode* result; 
    result = RevertList(tmp);
    if (result == nullptr)
	cout << "nullptr test passed" << endl;
}


//一个结点
void Test2(void)
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
void Test3(void)
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
    Test1();
    Test2();
    Test3();

    return 0;
}
